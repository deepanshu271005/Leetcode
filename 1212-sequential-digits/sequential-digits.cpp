class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> list;
        
        
        for (int i = 1; i <= 9; i++) {
            long long num = i;           // Start with the first digit
            int next_digit = i + 1;      // The next digit in the sequence
            
             
            while (num <= high && next_digit <= 9) {
                 
                num = num * 10 + next_digit;
                
                 
                if (num >= low && num <= high) {
                    list.push_back(num);
                }
                
                
                next_digit++;
            }
        }
        
       
        sort(list.begin(), list.end());
        
        return list;
    }
};