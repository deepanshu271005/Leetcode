class Solution {
public:
    long long sumAndMultiply(int n) {
        
        vector<int>num;
        while(n){
            num.push_back(n%10);
            n=n/10;
        }
        reverse(num.begin(),num.end());
        for(auto i:num)cout<<i;
       // return 0;
       vector<int>x;
       long long sum=0;
       for(auto i:num){
        if(i!=0){x.push_back(i);sum+=i;}
       }
       if(x.size()==0)return 0;
       long long y = 0; 
for (int i = 0; i < x.size(); i++) {
    y = (y * 10) + x[i];
}
        return sum*y;

    }
};