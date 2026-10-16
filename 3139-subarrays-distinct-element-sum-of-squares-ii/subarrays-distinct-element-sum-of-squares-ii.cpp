class Solution {
    int MOD = 1e9 + 7;
    vector<long long> sumTree;
    vector<long long> sqTree;
    vector<long long> lazy;
    
    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;
            long long val = lazy[node];
            
            // Update left child
            long long leftLen = mid - start + 1;
            sqTree[leftChild] = (sqTree[leftChild] + 2 * val * sumTree[leftChild] % MOD + val * val % MOD * leftLen % MOD) % MOD;
            sumTree[leftChild] = (sumTree[leftChild] + val * leftLen % MOD) % MOD;
            lazy[leftChild] = (lazy[leftChild] + val) % MOD;
            
            // Update right child
            long long rightLen = end - mid;
            sqTree[rightChild] = (sqTree[rightChild] + 2 * val * sumTree[rightChild] % MOD + val * val % MOD * rightLen % MOD) % MOD;
            sumTree[rightChild] = (sumTree[rightChild] + val * rightLen % MOD) % MOD;
            lazy[rightChild] = (lazy[rightChild] + val) % MOD;
            
            lazy[node] = 0;
        }
    }
    
    void update(int node, int start, int end, int l, int r, long long val) {
        if (start > end || start > r || end < l) return;
        
        if (start >= l && end <= r) {
            long long len = end - start + 1;
            sqTree[node] = (sqTree[node] + 2 * val * sumTree[node] % MOD + val * val % MOD * len % MOD) % MOD;
            sumTree[node] = (sumTree[node] + val * len % MOD) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        
        pushDown(node, start, end);
        
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        sumTree[node] = (sumTree[2 * node] + sumTree[2 * node + 1]) % MOD;
        sqTree[node] = (sqTree[2 * node] + sqTree[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        // The segment tree needs arrays roughly 4 times the size of N
        sumTree.assign(4 * n, 0);
        sqTree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> last_pos;
        long long total_ans = 0;
        
        for (int j = 0; j < n; j++) {
            // If the number was seen before, update from the index right after it. Otherwise, start from 0.
            int start_idx = last_pos.count(nums[j]) ? last_pos[nums[j]] + 1 : 0;
            
            // Add 1 to the distinct counts of all subarrays starting in the range [start_idx, j]
            update(1, 0, n - 1, start_idx, j, 1);
            
            // The root of sqTree (index 1) holds the sum of squares for all subarrays ending at current index j
            total_ans = (total_ans + sqTree[1]) % MOD;
            
            // Update the last seen position of the current element
            last_pos[nums[j]] = j;
        }
        
        return total_ans;
    }
};