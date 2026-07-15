class Solution {
public:
    bool freq_match(vector<int>& freq1, unordered_map<char, int>& m) {

        for (auto i : m) {
            char c = i.first;
            int freq = i.second;
            if (freq > freq1[(int)c])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> freq1(150, 0);  // for the s
        unordered_map<char, int> m; // for the t

        for (auto i : t) {
            m[i]++;
        }
        // now we ahve the blueprint of the second string

        int l = 0, r = 0;
        int best_ans = INT_MAX;
        string ans = "";
        int start_index_of_ans=-1;
        int end_index_of_ans=-1;

        while (r < s.size()) {

            freq1[(int)s[r]]++;

            if (r - l + 1 >= t.size() && freq_match(freq1, m)) {
                //  the freq of both matched

                // cout<<"aya hu ";
                // try shinking the window if possible
                while (freq_match(freq1, m)) {
                    // shrink the window
                    freq1[(int)s[l]]--;
                    l++;
                    // cout<<"shrink"<<endl;
                }
                l--;
                freq1[(int)s[l]]++;
                string temp;
                 
                if (r - l + 1 < best_ans) {
                    start_index_of_ans=l;
                    end_index_of_ans=r;
                    best_ans = r - l + 1;
                }
                best_ans = min(best_ans, r - l + 1);
            }

            r++;
        }

        // for(auto i:freq1)cout<<i<<" ";
        // cout<<endl;
        // cout<<endl;
        // cout<<endl;
        // for(auto i:freq2)cout<<i<<" ";
        if(end_index_of_ans==-1 &&  start_index_of_ans==-1)return "";
        for(int i=start_index_of_ans;i<=end_index_of_ans;i++){
            ans+=s[i];
        }
        return ans;
    }
};