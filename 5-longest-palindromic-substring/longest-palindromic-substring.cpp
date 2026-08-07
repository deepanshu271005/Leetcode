class Solution {
public:
 
    bool check(string & temp){
        int l=0,h=temp.size()-1;
        while(l<=h){
            if(temp[l]!=temp[h])return false;
            l++;h--;
        }
        return true;
    }

    string longestPalindrome(string s) {
          int n=s.size();
          string ans;
         for(int i=0;i<n;i++){
             string temp;
            for(int j=i;j<n;j++){
                   temp.push_back(s[j]);
            if(check(temp) && temp.size()>ans.size()){ans=temp;}
            }
         }
          return ans;
    }
};