class Solution {
public:
    bool isPalindrome(int x) {
    //    string s=to_string(x);
    //    int i=0;
    //    int j=s.size()-1;
    //      while(i<=j){
    //         if(s[i]!=s[j])return false;
    //         i++;j--;
    //      }
    //      return true;
      if(x<0)return false;
      int n=0;
      int t=x;
      while(t){
        t=t/10;
        n++;
      } 
       bool odd=false;
       if(n%2==1)odd=1;
        n=n/2;
         stack<int>s;
        while(n--){
         s.push(x%10);
         x=x/10;
        }
        if(odd)x/=10;//removing the common char
        while(x){
            int last=x%10;
            if(last!=s.top())return false;
            s.pop();
            x=x/10;
        }
        return true;
         
    }
};