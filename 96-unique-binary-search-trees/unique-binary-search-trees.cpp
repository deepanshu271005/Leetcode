class Solution {
public:
    int numTrees(int n) {
        // so i figured out something that is for n<=19 there will be 19! permuatation that we can feed the number to create binary tree
        //now the ans is not 19! as the except the end points all the middle number will have same tree formed like 
        // 213 and 231 
        // so for a number x  ( 1<=X<=n) the whole premuation does not matter what only matter is the permuation of the number smaller than this and number greater than this 
        //like number of tree with root X =permutaion of numsmaller than this *number of premuation of numnber greater than this 
        // but there is still some flaw in this logic 
        

        // so almost on point what i do is dp[i]=unique subtree with smaller than this * uniquesubtree with grater than this (instead of permuation)
 
          //dp[i]-> no of unique BST using i nodes

           vector<int>dp(n+1,0);
           dp[0]=1;
           dp[1]=1;
           for(int i=2;i<=n;i++){
               for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
               }
           }
        return dp[n];
    }
};