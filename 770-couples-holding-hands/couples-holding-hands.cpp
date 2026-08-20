class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      int cnt=0;
      int sec=0;
      int coupes=row.size()/2;
    

      for(int i=0;i<row.size();i+=2){
        
        int partner=row[i]^1;
        int next=row[i+1];
        if(next==partner)continue;
        for(int j=i+2;j<row.size();j+=2){
            if(row[j]==partner){
               swap(row[i+1],row[j]);
               cnt++;
            }
            else if(row[j+1]==partner){
                swap(row[i+1],row[j+1]);
                cnt++;
            }
        }
         
      }

      return cnt;

    }
};