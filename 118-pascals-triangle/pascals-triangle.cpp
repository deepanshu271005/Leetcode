class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1,1});
        int size=3;
        for(int i=2;i<numRows;i++){
            vector<int>temp(size);
            temp[0]=temp.back()=1;
            for(int j=1;j<size-1;j++){
               
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            size++;
            ans.push_back(temp);
        }
        return ans;
    }
};