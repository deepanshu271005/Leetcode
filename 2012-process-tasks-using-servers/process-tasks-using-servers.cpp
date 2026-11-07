
class Solution {
public:
     vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // freeq stores {weight, index}
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> freeq;
        // assignedq stores {free_time, index}
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> assignedq;

        for (int i = 0; i < servers.size(); i++) {
            freeq.push({servers[i], i});
        }

        vector< int> ans;
        long long curr_time = 0;

        for (long long i = 0; i < tasks.size(); i++) {
            // Ensure time is at least the current task's arrival time
            curr_time = max(curr_time, i);

            // If no servers are free, fast-forward time to when the next server finishes
            if (freeq.empty()) {
                curr_time = max(curr_time, assignedq.top().first);
            }

            // Move all servers that have finished their tasks back to freeq
            while (!assignedq.empty() && assignedq.top().first <= curr_time) {
                int idx = assignedq.top().second;
                assignedq.pop();
                freeq.push({servers[idx], idx});
            }

            // Assign the current task to the best available server
            auto [wt, idx] = freeq.top();
            freeq.pop();

            assignedq.push({curr_time + tasks[i], idx});
            ans.push_back(idx);
        }

        return ans;
    }
};