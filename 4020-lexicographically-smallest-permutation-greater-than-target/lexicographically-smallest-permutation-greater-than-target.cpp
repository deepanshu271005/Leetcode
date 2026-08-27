// class Solution {
// public:

//      void f(string & s,string & curr,string & target,string &ans,vector<int>&visited){
        
//       if(curr.size()==target.size()){
//         // cout<<curr<<endl;
//             if(curr>target){ 
//                 if(ans=="")ans=curr;
//                 else
//                 ans=min(ans,curr);
//                 // cout<<ans<<endl<<endl;
//             }
//             return;
//       }
       

//       for(int i=0;i<s.size();i++){
//         if(visited[i]==1)continue;
//          curr.push_back(s[i]);
//          visited[i]=1;
//          f(s,curr,target,ans,visited);
//          visited[i]=0;
//          curr.pop_back();

//       }
//       return ;
        
//       }

//     string lexGreaterPermutation(string s, string target) {
//         string ans="";string curr="";
//          vector<int>visited(s.size(),0); 
//         f(s,curr,target,ans,visited);
//         return ans;
//     }
// };

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // 1. Find the longest matching prefix
        int L = 0;
        vector<int> temp_freq = freq;
        for (int i = 0; i < n; i++) {
            if (temp_freq[target[i] - 'a'] > 0) {
                temp_freq[target[i] - 'a']--;
                L++;
            } else {
                break;
            }
        }

        // 2. Set up the character pool for the backward traversal
        int start_idx = min(L, n - 1);
        vector<int> pool = freq;
        for (int i = 0; i < start_idx; i++) {
            pool[target[i] - 'a']--;
        }

        // 3. Traverse backwards to find the optimal divergence point
        for (int i = start_idx; i >= 0; i--) {
            
            // Try to find the smallest char strictly greater than target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (pool[c] > 0) {
                    
                    // Valid character found! Build the exact answer.
                    string ans = target.substr(0, i);
                    ans += (char)(c + 'a');
                    pool[c]--;
                    
                    // Append all remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (pool[k] > 0) {
                            ans += (char)(k + 'a');
                            pool[k]--;
                        }
                    }
                    return ans;
                }
            }
            
            // If no valid character found, release target[i-1] back into the pool for next loop
            if (i > 0) {
                pool[target[i - 1] - 'a']++;
            }
        }
        
        return "";
    }
};