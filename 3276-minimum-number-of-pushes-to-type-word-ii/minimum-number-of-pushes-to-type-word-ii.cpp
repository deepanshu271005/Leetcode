class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>m;
        for(auto i:word){
            m[i]++;
        }
     
     vector<int>freq;
     for(auto i:m){
         
        int f=i.second;
        freq.push_back(f);
     }
      sort(freq.begin(),freq.end());
     reverse(freq.begin(),freq.end());
     int ans=0;
     int cost=1;
     int limit=8;
     int idx=0;
     while(idx<freq.size()){
     
     for(int i=1;i<=8;i++){
        if(idx>=freq.size())break;
        ans+=cost*freq[idx];
        idx++;
     }
     cost++;
     }
     return ans;

    }
};