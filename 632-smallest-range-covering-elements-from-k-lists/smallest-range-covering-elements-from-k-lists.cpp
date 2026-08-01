class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap stores vectors of size 3: {value, list_index, element_index_in_list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        int currentMax = INT_MIN;
        
         
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], i, 0});
            currentMax = max(currentMax, nums[i][0]);
        }
        
       
        int rangeStart = 0;
        int rangeEnd = INT_MAX;
        
         while (!minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();
            
            int currentMin = current[0];
            int listIdx = current[1];
            int elemIdx = current[2];
           
            if (currentMax - currentMin < (long long)rangeEnd - rangeStart) {
                rangeStart = currentMin;
                rangeEnd = currentMax;
            }
            
            if (elemIdx + 1 == nums[listIdx].size()) {
                break;
            }
            
            
            int nextVal = nums[listIdx][elemIdx + 1];
            minHeap.push({nextVal, listIdx, elemIdx + 1});
            
           
            currentMax = max(currentMax, nextVal);
        }
        
        return {rangeStart, rangeEnd};
    }
};