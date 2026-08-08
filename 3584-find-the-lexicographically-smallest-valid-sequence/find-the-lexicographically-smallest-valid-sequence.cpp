class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        // dp[i]->> will tell that what is the max lenght of the subseq we can
        // make from i to n in word1 matching dp[i] character from the last of
        // word2
        int n = word1.size();
        int idx = word2.size() - 1;
        vector<int> dp(n + 1, 0);
        for (int i = word1.size() - 1; i >= 0; i--) {
            if (idx >= 0 && word1[i] == word2[idx]) {
                dp[i] = 1 + dp[i + 1];
                idx--;
            } else
                dp[i] = dp[i + 1];
        }

        //for (auto i : dp)
          //  cout << i << " ";
        // now if i am stading at some index i then i will have the dp[i+1] to
        // tell that max how much element can i match in the remaining word1 so
        // suppose we use the operation of changing the char if it does not
        // match then if the remaining length of the word2 > dp[i+1] the we can
        // safely return {} as we can never match all the remaining character of
        // the word2 string
        vector<int> ans;
        bool changed = false;
        int j = 0;

        for (int i = 0; i < word1.size() && j < word2.size(); i++) {
            if (word1[i] == word2[j]) {
                 
                ans.push_back(i);
                j++;
            } else if (!changed && dp[i + 1] >= word2.size() - 1 - j) {
                // Safe to use our one mismatch
                ans.push_back(i);
                changed = true;
                j++;
            }
             
        }

        if (ans.size() != word2.size())
            return {};
        return ans;
    }
};