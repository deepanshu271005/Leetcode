class Solution {
public:

     void f(int idx,string &curr,vector<string>&ans,vector<vector<char>>&mapping,string&digits){
        if(idx==digits.size()){
            ans.push_back(curr);
            //cout<<curr<<" ";
            return ;
        }

       for(auto i:mapping[digits[idx]-'0']){
        curr+=i;
        f(idx+1,curr,ans,mapping,digits);
        curr.pop_back();
       }  
    
      return ;

     }

    vector<string> letterCombinations(string digits) {
        vector<vector<char>>mapping(10);
        mapping[2]={'a','b','c'};
        mapping[3]={'d','e','f'};
        mapping[4]={'g','h','i'};
        mapping[5]={'j','k','l'};
        mapping[6]={'m','n','o'};
        mapping[7]={'p','q','r','s'};
        mapping[8]={'t','u','v'};
        mapping[9]={'w','x','y','z'};


        vector<string>ans;
        int i=0;string curr="";
        f(i,curr,ans,mapping,digits);
 
        return ans;

    }
};