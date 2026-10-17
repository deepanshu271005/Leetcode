// class Solution {
// public:
//     int minSwaps(vector<int>& nums) {
//         vector<int>a;
//         for(auto i:nums){
//             int sum=0;
//             while(i){
//                 sum+=i%10;
//                 i/=10;
//             }
//             a.push_back(sum);
//         }
       
//        vector<vector<int>>order;
//        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
//        for(int i=0;i<nums.size();i++){
//         pq.push({a[i],nums[i],i});
//        }
//        while(!pq.empty()){
//         order.push_back(pq.top());
//         pq.pop();
//        }
  
//       for( auto i:order){
//         for(auto j:i){
//             cout<<j<<" ";
//             }
//             cout<<endl;
//       }
//        int cnt=0;
//        int curridx=0;
//        while(curridx<nums.size()){
//          if(number!=nums[curridx]){
//             swap(nums[idx],nums[curridx]);
//             cnt++;
//          }
//          curridx++
//        }

//        return cnt;

//     }
// };
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> order;

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;

            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }

            order.push_back({sum, nums[i], i});
        }

        sort(order.begin(), order.end());

        vector<bool> vis(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || order[i][2] == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!vis[j]) {
                vis[j] = true;
                j = order[j][2];
                cycle_size++;
            }

            if (cycle_size > 1)
                cnt += cycle_size - 1;
        }

        return cnt;
    }
};