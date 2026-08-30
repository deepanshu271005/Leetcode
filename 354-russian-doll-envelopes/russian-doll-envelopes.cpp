class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {

        // sort(nums.begin(), nums.end(),
        //      [](const vector<int>& a, const vector<int>& b) {
        //          if (a[0] == b[0])
        //              return a[1] > b[1];
        //          return a[0] < b[0];
        //      });

        // custom sort to sort the first element in the assendiign order and the
        // seond element in the dexcendin order


    for(auto &i:nums){
        i[1]=i[1]*(-1);
    }
    sort(nums.begin(),nums.end());
        vector<int> LIS;
        for (auto & i : nums) {
            LIS.push_back(-1*i[1]);
        }
        vector<int> tail;

        for (auto & i : LIS) {

            auto  it = lower_bound(tail.begin(), tail.end(), i);
            if (it == tail.end())
                tail.push_back(i);
            else
                *it = i;
        }

        return tail.size();
    }
};