class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        // if the window size >= nums
        if (k >= n) {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, nums[i]);
            }
            return {maxi};
        }

        int l = 0;
        int r = 0;
        map<int, int> m;
        priority_queue<int> pq; // to take care of the max elemnt in the window
        vector<int> ans;
        while (r < k) {
            if (m[nums[r]] == 0)
                pq.push(nums[r]);
            m[nums[r]]++;
            r++;
        }
        while (!pq.empty()) {
            int top = pq.top();
            if (m[top] == 0) {
                pq.pop();
            } else {
                ans.push_back(pq.top());
                break;
            }
        }

        // afet the first while loop exits the value of r=k
        while (r < n) {
            if (m[nums[r]] == 0)
                pq.push(nums[r]); // if this number is already  in the pq skips
            m[nums[r]]++;

            while (r - l + 1 > k) {
               
                m[nums[l]]--;
                l++;
            }

            while (!pq.empty()) {
                int top = pq.top();
                if (m[top] == 0) {
                     
                    pq.pop();
                } else {
                    ans.push_back(pq.top());
                    break;
                }
            }

            r++;
        }

        return ans;
    }
};