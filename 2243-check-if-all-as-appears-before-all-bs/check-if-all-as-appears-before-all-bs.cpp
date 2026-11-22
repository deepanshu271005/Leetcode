class Solution {
public:
    bool checkString(string s) {
        bool found=false;
        for(auto i:s){
            if(i=='b')found=true;
            if(found==true && i=='a')return false;
        }
        return true;
    }
};