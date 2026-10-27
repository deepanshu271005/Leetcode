class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid;
        for(int i=0;i<m;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+="#";
            }
            grid.push_back(s);
        }
          
         for(int i=0;i<m;i++){
            grid[i][0]='.';
         }
         for(int i=0;i<n;i++){
            grid[m-1][i]='.';
         }

        return grid;

    }
};