class Solution {
public:

     bool f(string & temp,string &b){
        int n=temp.size();
        int m=b.size();
        
        for(int i=0;i<n;i++){
            if(temp[i]==b[0]){
                int it=0;
                bool flag=true;
                while(it<m){
                    if(temp[it+i]!=b[it]){
                        flag=false;
                        break;
                    }
                    it++;
                }
                if(flag==true)return true;
            }
        }
        return false;

     }
 
    int repeatedStringMatch(string a, string b) {
        // if(b=="")return 0;int ans=0;
        // vector<int>freq1(26,0);
        // vector<int>freq2(26,0);
        // for(auto i:a){
        //     freq1[i-'a']++;
        // }
        // for(auto i:b){
        //     freq2[i-'a']++;
        // }

        string temp;
        int cnt=0;
        int limit=0;
        while(true){
          temp+=a;
          cnt++;
          if(temp.size()>=b.size()){
           if(f(temp,b)){
            return cnt;
           } 
           limit++;
          }
           if(limit==2)break;
        }
        
        return -1;
      
    }
};