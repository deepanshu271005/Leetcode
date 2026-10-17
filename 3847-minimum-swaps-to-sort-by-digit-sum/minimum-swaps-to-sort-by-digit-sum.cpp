class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> order;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int num = nums[i];
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            order.push_back({sum, nums[i], i});
        }
        sort(order.begin(), order.end());
        vector<int> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || order[i][2] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = order[j][2];
                cycleSize++;
            }

            cnt += cycleSize - 1;
        }

        return cnt;
    }
};