class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> list;
        
        
        for (int i = 1; i <= 9; i++) {
            long long num = i;           // Start with the first digit
            int next_digit = i + 1;      // The next digit in the sequence
            
             
            while (num <= 1e9 && next_digit <= 9) {
                 
                num = num * 10 + next_digit;
                
                 
                // if (num >= low && num <= high) {
                //     list.push_back(num);
                // }
                
                 list.push_back(num);
                next_digit++;
            }
        }
        
       
        sort(list.begin(), list.end());
        vector<int>ans;
        for(auto i:list){
            if(i>=low && i<=high)ans.push_back(i);
        }
        
        return ans;;
    }
};