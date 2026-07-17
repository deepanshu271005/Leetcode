 class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int n = nums.size();
        int maxi=INT_MIN;
        for(auto i:nums){
            maxi=max(maxi,i);
        }
        maxi++;

        /*this is O(N2) soltion*/

        //   vector<int>gcdPairs;
        //  for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         gcdPairs.push_back(gcd(nums[i],nums[j]));
        //     }
        //  }

        //  //now the gcd pairs has all the pairsGCD stored in it
        //  sort(gcdPairs.begin(),gcdPairs.end());
        //  map<int,int>m;//index -> val
        //  for(int i=0;i<gcdPairs.size();i++){
        //     m[i]=gcdPairs[i];
        //  }
        //  vector<int>ans;
        //  for(auto i:queries){
        //     ans.push_back(m[i]);
        //  }
        //   return ans;

        // now we use something like the prefix and something like instead of
        // directly comparing we do something with the multiple and not
        // maintaining the physical array of pairs


        // for(int i=1;i<5;i++){
        //     cout<<cnt[i]<<" ";
        // }
        // cout<<endl<<endl;

        vector<long long> cnt(maxi, 0);
        for (auto i : nums) {
            cnt[i]++;
        }

        //  for(int i=1;i<5;i++){
        //     cout<<i<<":";
        //     cout<<cnt[i]<<"  ";
        // }
        //  cout<<endl<<endl;

        // nwo we have the cnt array so now we do not need the nums for any
        // reason
        vector<long long> multiple(maxi,
                             0); // to store the multiple list like whcih number
                                 // ar mulpile of i is stored in  miltiple[i]
        for (long long i = 1; i < maxi; i++) {
            for (long long j = i; j < maxi; j = j + i) {
                if (cnt[j] == 0)
                    continue;
                else {
                    multiple[i] += cnt[j]; // this number is divisible by i
                }
            }
        }

        //  for(int i=1;i<5;i++){
        //     cout<<i<<":";
        //     cout<<multiple[i]<<" ";
        // }
        // cout<<endl<<endl;

        // now build the gcdPair with the help of multiple from traversing
        // backward (last to start)

        // mulilple[x]->give me the cnt of the elemnt present in the array which
        // are divisible by x but it does not mean that its the gcd it may be
        // but fro acutal we need to kind if there are pair whcih have the gcd >
        // than X so we are traversing backward to precompute the pair wich
        // could have the gcd>x and then subtract all the pair with gcd atleast
        // x with its >>

        vector<long long> prefix(
            maxi, 0); // prefix[i] will tell me how much pair have the gcd = i
        // if multiple[x]=n;then there can be total n(n-1)/2 pairs total which
        // means all these have gcd = x if we are at the last
        for (long long i = multiple.size() - 1; i >= 0; i--) {

            if (multiple[i] == 0)
                continue; // there is not element that is multiple so no benfit
                          // in exporing anyting
            long long count = multiple[i];
            long long total_pairs = (count * (count - 1)) / 2;
            long long already_counted = 0;
            for (long long j = i; j < maxi; j = j + i) {
                already_counted += prefix[j];
            }
            // prefix[j]is already counted as we are tracking backward
            long long new_count = total_pairs - already_counted;
            prefix[i] = new_count;
        }

        // now the prefix is builted too
        // prefix[i]->gives how many pair have the gcd=i;

        //  for(int i=1;i<5;i++){
        //      cout<<i<<":";
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<endl<<endl;

        vector<long long> index;
        vector<long long> gcd_value;
        long long curr_index = 0;
        for (int i = 1; i < maxi; i++) {
            if (prefix[i] == 0)
                continue; // no pair have the gcd=i;
            long long  freq_of_pair = prefix[i];
            long long gcd = i;
            gcd_value.push_back(gcd);
            index.push_back(curr_index);
            curr_index += freq_of_pair;
        }
        //  for(int i=0;i<index.size();i++){
        //      cout<<i<<":";
        //     cout<<index[i]<<" ";
        // }
        // cout<<endl<<endl;

        //  for(int i=0;i<gcd_value.size();i++){
        //      cout<<i<<":";
        //     cout<<gcd_value[i]<<" ";
        // }
        // cout<<endl<<endl;

        vector<int> ans;

        for (auto i : queries) {
            // find this index in the index array;
            auto it = upper_bound(index.begin(), index.end(), i);
            long long actual_index = (it - index.begin()) - 1;

            ans.push_back(gcd_value[actual_index]);
        }

        return ans;
    }
};

//->>> example
// // 2 4 6 8 10 12
// p[12]=0;
// p[10]=0;
// p[8]=0;
// p[6]=1;
// p[4]=3;
// p[2]=15;
// 2->4;2->6;2->8;2->10;2->12;
// 4->6;4->10; 4->8 4->12 counted in the p[4]as the gcd is 4
// 6->8;6->10;
// 8->10;
// 10->12;