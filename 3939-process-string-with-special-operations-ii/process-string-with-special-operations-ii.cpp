class Solution {
public:
    char processStr(string s, long long k) {
        /*

        * -> remove last;
        # -> duplicate
        % ->reverse

        */

        vector<long long> length(s.size(),0);
        long long curr_length = 0;
       for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                curr_length--;
                if (curr_length < 0) curr_length = 0;
            } else if (s[i] == '%') {
                // length unchanged
            } else if (s[i] == '#') {
                curr_length *= 2;
            } else {
                curr_length++;
            }
            length[i] = curr_length;  
        }

        if (length.empty() || k >= length.back()) {
            return '.';
        }

        // the lenght is now formed
        long long idx = k;
        // idx is the index that is underobservation or it is the index that i
        // am finding that where it came from

        for (int i = length.size() - 1; i >= 0; i--) {
            long long prevLength = (i > 0) ? length[i - 1] : 0;
            long long afterLength = length[i];
            char operation = s[i];

            if (operation == '#') {
                 
                    idx = idx % prevLength; // this will take the idx to the
                                            // last index before duplicate
            } else if (operation == '%') {
                idx = afterLength - idx -
                      1; // this will move the index from the front to fast
            } else if (operation == '*') {
                // obv the elment remved could not be my index underobservation
                // do nothing
            } else {
                // its a lowercase letter
                // check if its the same index that we are checking or not
                if (afterLength - 1 == idx) {
                    return s[i];
                }
            }
        }
        return s[0]; // fallback condition
    }
};