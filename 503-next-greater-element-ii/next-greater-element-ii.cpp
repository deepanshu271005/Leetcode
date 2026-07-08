class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& new_num) {
        int n=new_num.size();
        

          stack<int>s;
          vector<int>ans(new_num.size(),-1);
           for(int i=0;i<2*new_num.size();i++){
                 if(s.empty() && ans[i % n]==-1)s.push(i);
                  
                 else {
                        int curr=new_num[i%n];
                        int top=new_num[s.top()%n];
                        if(top<curr){
                            while(!s.empty() && new_num[s.top()%n]<curr){
                                ans[s.top()%n]=curr;
                                s.pop();
                            }
                        }
                        s.push(i);

                 }
           }

         return ans;
       

    }
};