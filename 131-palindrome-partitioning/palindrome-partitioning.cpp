class Solution {
public: 
     

      bool checkPalindrone(string s){
        int l=0,h=s.size()-1;
        while(l<=h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;h--;
        }
        return true;
      }
      
        void f(vector<vector<string>>&ans,int idx,vector<string> & curr,string &s,vector<vector<bool>>&check){
            if(idx==s.size()){
                ans.push_back(curr);
                
               return;
            }
           
              for(int i=idx;i<s.size();i++){
                  if(check[idx][i]){
                    string temp=s.substr(idx,i-idx+1);
                    curr.push_back(temp);
                    f(ans,i+1,curr,s,check);
                    curr.pop_back();
                  }
              }
              return;
             
        }


    vector<vector<string>> partition(string s) {
         int n=s.size();
         vector<vector<bool>>ispalindrome(n,vector<bool>(n,false));
         for(int i=0;i<n;i++){
            ispalindrome[i][i]=1;
         }
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                  string temp=s.substr(i,j-i+1);
                  ispalindrome[i][j]=checkPalindrone(temp);
            }
         }
      
         
         //now is palidrome[i][j] has the the bool to tell if the string from i to j is palindrom or not
        //  for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         cout<<i<<" "<<j<<" "<<ispalindrome[i][j]<<endl;
        //     }
        //  } 
       vector<string>path;   vector<vector<string>>ans;
        f(ans,0,path,s,ispalindrome);

    
        return ans;

    }
};