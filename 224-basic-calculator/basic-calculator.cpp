class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int ans = 0;
        int i = 0;
        int lastSign = 1;
        // if(s[0]=='-')lastSign=-1;
        
        while (i < s.size()) {
            if (s[i] == ' ') {
                i++;
                continue;
            } 
            else if (s[i] == '+' || s[i] == '-') {
                lastSign = (s[i] == '+') ? 1 : -1;
            } 
            else if (s[i] == '(') {
                st.push(lastSign);
                st.push(INT_MAX);
                lastSign = 1;
            } 
            else if (s[i] == ')') {
                long long temp = 0;
                while (st.top() != INT_MAX) {
                    temp += st.top();
                    st.pop();
                }
                st.pop(); 
                
                int signForBracket = st.top();
                st.pop();
                
                st.push(temp * signForBracket); 
            } 
            else if (isdigit(s[i])) {
                string temp;
                while (i < s.size() && isdigit(s[i])) {
                    temp.push_back(s[i]);
                    i++;
                }
                long long t = stoll(temp);
                st.push(lastSign * t);
                lastSign = 0;
                i--;
            }
            i++;
        }
        
        while (!st.empty()) {
            // cout<<st.top()<<" ";
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};