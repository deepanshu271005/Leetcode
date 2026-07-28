class Solution {
public:
    string smallestPalindrome(string s) {
        //so the size of string can either be even or odd 
        // if even then the freq of the element in it is basically even too as its pallindrome 
        //if odd then there will be one element with odd freq

         int size=s.size();
         int mid;
         if(size%2==0){
            //even
            mid=-1;
         }
         else {
            //odd
            mid=((size+1)/2)-1;
         }
       string ans(size,'0');
       int l=0,r=size-1;
         map<char,int>freq;
         for(auto i:s){
            freq[i]++;
         }
         for(auto i:freq){
            if(mid==-1){
                char c=i.first;
                int cnt=i.second;
                while(cnt){
                    ans[l]=c;
                    ans[r]=c;
                    l++;r--;
                    cnt-=2;
                }
            }
            else {
                //odd 
                char c=i.first;
                int cnt=i.second;
                while(cnt){
                    if(cnt%2){
                        ans[mid]=c;
                        cnt--;
                    }
                 else  { ans[l]=c;
                    ans[r]=c;
                    l++;r--;
                    cnt-=2;}
                     

                }
                
            }
         }

   return ans;
    }
};