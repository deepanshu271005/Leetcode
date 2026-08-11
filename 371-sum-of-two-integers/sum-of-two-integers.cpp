class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        
        for (int i = 0; i < 32; i++) {
             int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            
            int current_bit = 0;
            
            // Condition 1 Both bits are 1
            if (bit_a == 1 && bit_b == 1) {
                current_bit = carry; 
                carry = 1;
            } 
            // Condition 2 Both bits are 0
            else if (bit_a == 0 && bit_b == 0) {
                current_bit = carry; 
                carry = 0;          
            } 
            // Condition 3 One bit is 1, the other is 0
            else {
                if (carry == 1) {
                    current_bit = 0; 
                    carry = 1;       
                } else {
                    current_bit = 1; 
                    carry = 0;        
                }
            }
            
            
            if (current_bit == 1) {
                ans |= (1 << i);
            }
        }
        
        return ans;
    }
};