class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans(n,1);
        int depth=0;
        
        for(int i=0;i<n;i++){
            if(seq[i]=='(')depth++;
            ans[i]=depth%2;
            if(seq[i]==')')depth--;
        }
        return ans;
      

    }
};