class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
         

      /* THIS IS THE BRUTE FORCE */

        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         for(int k=j;k<nums.size();k++){
        //             int n=nums[i]^nums[j]^nums[k];
        //             s.insert(n);
        //         }
        //     }
        // }
        //    return s.size();


        /*OPTMIAL*/
        //REMOVE THE DUPLICATE 
        set<int>s;
        for(auto i:nums){
            s.insert(i);
        }


       // as the max value of n is -> 1500 so the max XOR that we could produce is basically 2047 (2powX-1)
       vector<int>pairXor(2048,0);
       
       for(auto i:s){
        for(auto j:s){
            int new_num=i^j;
            pairXor[new_num]++;
        }
       }
        int ans=0;
        vector<bool>visited(2048,false);
       for(auto i:s){
        for(int j=0;j<=2047;j++){
            if(pairXor[j]==0)continue;
            if(!visited[i^j]){
                visited[i^j]=true;
                ans++;
            }

        }
       }
                       return ans ;
    }
};


// 0110 -> 6
// 0111 -> 7
// 1000 -> 8
// 1001 -> 9

