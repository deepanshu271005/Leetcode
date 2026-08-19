class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& nums) {
     //int n=nums.size();
        map<int,vector<int>>m;
        for(auto i:nums){
            m[i[0]].push_back(i[1]);
        }
       
        int total_unconstrained=n-m.size();
        int ans=0;
        ans+=total_unconstrained*2;//each unconstrained can have 2 grps

        for(auto i:m)
        {
           int row=i.first;
           vector<int>con=i.second;
           
            //as the group can only sit at positon 2345 or 4567 or 6789 then now 
            int mask=0;
            for(auto i:con){
               mask= mask|(1<<i);
            }
            // cout<<endl;
            // cout<<mask<<endl;
            // so the current state is stored in mask 
            // for(int k=0;k<11;k++){
            //     cout<< (mask&(1<<k)) <<" ";
            // }
            // cout<<endl;

            int valid1=0;
            for(int j=2;j<=5;j++){
               valid1= valid1|(1<<(j));
            }
            int valid2=0;
            for(int j=4;j<=7;j++){
                valid2=valid2|(1<<(j));
            }
             int valid3=0;
            for(int j=6;j<=9;j++){
               valid3= valid3|(1<<(j));
            }

            if((mask&valid1)==0 && (mask&valid3)==0)ans+=2;
            else if((mask&valid2)==0 || (mask&valid3)==0 || (mask&valid1)==0)ans++;
        }
      
         return ans;
        
            }
};