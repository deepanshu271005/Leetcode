class Solution {
private:
    unordered_map<string, vector<int>> memo;

    vector<int> helper(const string& expression) {
        // 1. Check cache
        if (memo.count(expression)) return memo[expression];
        
        vector<int> res;
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            
            // 2. Pivot on operators
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = helper(expression.substr(0, i));
                vector<int> right = helper(expression.substr(i + 1));
                
                // 3. Combine results
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else if (c == '*') res.push_back(l * r);
                    }
                }
            }
        }
        
        // 4. Base case
        if (res.empty()) res.push_back(stoi(expression));
        
        // 5. Cache and return
        return memo[expression] = res;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        // Main function is now just a clean entry point
        return helper(expression);
    }
};