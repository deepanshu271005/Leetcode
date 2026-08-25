class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
      int n=s.size();
      vector<vector<string>>ans(n+1);
      ans[0].push_back("");
      vector<int>dp(n+1,0);  //dp[i]->>tell the number of ways to segment string till i that each part is in the dict
      dp[0]=1;
      map<string,int>dict;
      for(auto i:wordDict){
           reverse(i.begin(),i.end());
          dict[i]++;;
      }

      for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j>=0;j--){
            temp+=s[j];
           if(dict.find(temp)!=dict.end()){
            dp[i+1]+=dp[j];
            string new_find=temp;
            reverse(new_find.begin(),new_find.end());
             for(auto last:ans[j]){
                ans[i+1].push_back(last+" "+new_find);
             }
           }
        }
      }
    
    //    for(auto i:dp)cout<<i<<" ";cout<<endl;
    //    int idx=1;
    //    for(auto i:ans){
    //     cout<<idx++<<" ";
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //    }
    
      for(auto &i:ans[n]){
        string sub=i.substr(1,i.size()-1);
        i=sub;
      }

     return ans[n];

    }
};