class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();

        stack<int> s;
        vector<int> next_greater(size2);
        for (int i = 0; i < size2; i++) {
            int curr_element = nums2[i];
            if (s.size() == 0)
                s.push(i);
            else {
                int top_element = nums2[s.top()];
                if (top_element < curr_element) {
                    while (!s.empty() && nums2[s.top()] < curr_element) {
                        next_greater[s.top()] = curr_element;
                        s.pop();
                    }
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            next_greater[s.top()]=-1;
            s.pop();
        }
          for(auto i:next_greater)cout<<i<<" ";

          vector<int>index_map(1e4+1,-1);
          for(int i=0;i<size2;i++){
            index_map[nums2[i]]=i;
          }

          vector<int>ans;
          for(auto i:nums1){
            int index=index_map[i];
            ans.push_back(next_greater[index]);
          }
          return ans;
        
    }
};