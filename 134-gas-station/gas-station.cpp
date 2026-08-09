class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tGas=0;
        int cGas=0;
        int tCost=0;
        int  start=0;
        for(int i=0;i<cost.size();i++){
            tGas+=gas[i];
            cGas+=gas[i];
            cGas-=cost[i];
            tCost+=cost[i];
            if(cGas<0){
                //change the starting point 
                start=i+1;
                cGas=0;
            }
        }
        if(tGas<tCost)return -1;
        return start;
    }
};