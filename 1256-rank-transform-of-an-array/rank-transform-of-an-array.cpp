class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>m;
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        vector<int>ans(arr.size());
        int counter=1;
         
        for(int i=0;i<arr.size();i++){
            if(m.count(temp[i])==0){
                m[temp[i]]=counter++;
            }
        }

        for(int i=0;i<arr.size();i++){
            ans[i]=m[arr[i]];
        }
        return ans;
    }
};