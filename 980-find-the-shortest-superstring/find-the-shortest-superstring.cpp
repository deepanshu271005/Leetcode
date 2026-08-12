class Solution {
public:
    // Helper function to calculate the cost of appending s2 to s1
    int calCost(const string& s1, const string& s2) {
        int limit = min(s1.size(), s2.size());
        for (int k = limit; k >= 1; k--) {
            // If suffix of s1 matches prefix of s2
            if (s1.substr(s1.size() - k) == s2.substr(0, k)) {
                return s2.size() - k; // Return number of NEW characters added
            }
        }
        return s2.size(); // No overlap, add full length of s2
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        
        // // 1. PRECOMPUTE COSTS
        // // cost[i][j] = cost of appending words[j] to words[i]
        // vector<vector<int>> cost(n, vector<int>(n, 0));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i != j) {
        //             cost[i][j] = calCost(words[i], words[j]);
        //         }
        //     }
        // }

        // // 2. BITMASK DP
        // // dp[mask][i] = min length of superstring using subset 'mask', ending with word 'i'
        // vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));
        // // parent[mask][i] = the word that came before 'i' in this optimal path (used to rebuild the string)
        // vector<vector<int>> parent(1 << n, vector<int>(n, -1));

        // // Base case: using only a single word costs the length of that word
        // for (int i = 0; i < n; i++) {
        //     dp[1 << i][i] = words[i].size();
        // }

        // // Iterate through all possible subsets (masks)
        // for (int mask = 1; mask < (1 << n); mask++) {
        //     for (int i = 0; i < n; i++) {
        //         // If word 'i' is NOT in the current mask, skip it
        //         if ((mask & (1 << i)) == 0) continue; 

        //         for (int j = 0; j < n; j++) {
        //             // If word 'j' IS already in the mask, we can't visit it again
        //             if ((mask & (1 << j)) != 0) continue; 

        //             // Next state if we add word 'j' to our current mask
        //             int next_mask = mask | (1 << j);
                    
        //             // If this new path is cheaper, update it!
        //             if (dp[mask][i] + cost[i][j] < dp[next_mask][j]) {
        //                 dp[next_mask][j] = dp[mask][i] + cost[i][j];
        //                 parent[next_mask][j] = i; // Remember that we came from 'i'
        //             }
        //         }
        //     }
        // }

        // // 3. PATH RECONSTRUCTION
        // // Find which word should be at the very end to give the absolute minimum length
        // int full_mask = (1 << n) - 1;
        // int min_len = 1e9;
        // int last_word = -1;
        // for (int i = 0; i < n; i++) {
        //     if (dp[full_mask][i] < min_len) {
        //         min_len = dp[full_mask][i];
        //         last_word = i;
        //     }
        // }

        // // Trace backwards through the parent array to get the order of words
        // vector<int> path;
        // int curr_mask = full_mask;
        // while (last_word != -1) {
        //     path.push_back(last_word);
        //     int prev_word = parent[curr_mask][last_word];
            
        //     // Remove the last_word from the mask to step backwards
        //     curr_mask ^= (1 << last_word); 
        //     last_word = prev_word;
        // }
        
        // // We traced backwards, so flip it to get the correct left-to-right order
        // reverse(path.begin(), path.end()); 

        // // 4. BUILD THE FINAL STRING
        // string res = words[path[0]];
        // for (int i = 1; i < path.size(); i++) {
        //     int prev = path[i - 1];
        //     int curr = path[i];
            
        //     int c = cost[prev][curr]; // Find out how many new characters we actually need to add
            
        //     // Append only the non-overlapping part of the current word
        //     res += words[curr].substr(words[curr].size() - c);
        // }

        // return res;


       // int n = words.size();
        
        // 1. PRECOMPUTE COSTS
        // cost[i][j] = characters to add if we append words[j] to words[i]
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int len_i = words[i].size();
                int len_j = words[j].size();
                cost[i][j] = len_j; // Max cost is appending the whole string
                
                // Find maximum overlap
                for (int k = 1; k <= min(len_i, len_j); k++) {
                    if (words[i].substr(len_i - k) == words[j].substr(0, k)) {
                        cost[i][j] = len_j - k; 
                    }
                }
            }
        }

        // 2. BITMASK DP
        // dp[mask][i] = min length of superstring using subset 'mask', ending with word 'i'
        vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));

        // Base case: using only a single word costs the length of that word
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = words[i].size();
        }

        // Iterate through all possible subsets (masks)
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                // If the i-th word is NOT in the current mask, skip
                if ((mask & (1 << i)) == 0) continue; 
                
                for (int j = 0; j < n; j++) {
                    // If the j-th word is ALREADY in the mask, skip
                    if (mask & (1 << j)) continue; 
                    
                    int next_mask = mask | (1 << j);
                    dp[next_mask][j] = min(dp[next_mask][j], dp[mask][i] + cost[i][j]);
                }
            }
        }

        // 3. FIND OPTIMAL ENDING WORD
        int final_mask = (1 << n) - 1;
        int best_last = 0;
        int min_len = 1e9;
        
        for (int i = 0; i < n; i++) {
            if (dp[final_mask][i] < min_len) {
                min_len = dp[final_mask][i];
                best_last = i;
            }
        }

        // 4. PATH RECONSTRUCTION (WITHOUT PARENT ARRAY)
        int curr = best_last;
        int mask = final_mask;
        vector<int> path;
        
        while (mask > 0) {
            path.push_back(curr);
            int prev_mask = mask ^ (1 << curr); // Turn off the current bit
            
            if (prev_mask == 0) break; // We've reached the very first word
            
            // Find the predecessor 'j'
            for (int j = 0; j < n; j++) {
                if (prev_mask & (1 << j)) {
                    // Check if this 'j' was the optimal transition
                    if (dp[mask][curr] == dp[prev_mask][j] + cost[j][curr]) {
                        curr = j;
                        mask = prev_mask;
                        break; 
                    }
                }
            }
        }
        
        // We traced backwards, so flip it to get the correct left-to-right order
        reverse(path.begin(), path.end()); 

        // 5. BUILD THE FINAL STRING
        string res = words[path[0]];
        for (int i = 1; i < path.size(); i++) {
            int prev = path[i - 1];
            int current = path[i];
            
            int c = cost[prev][current]; 
            res += words[current].substr(words[current].size() - c);
        }
        
        return res;




    }
};