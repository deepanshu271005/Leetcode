class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
        int n=num.size();
        vector<int>new_num;
        for(auto i:num)new_num.push_back(i);
        for(auto i:num)new_num.push_back(i);

          stack<int>s;
          vector<int>ans(num.size(),-1);
           for(int i=0;i<new_num.size();i++){
                 if(s.empty() && ans[i % n]==-1)s.push(i);
               //  else if(ans[i % n]!=-1)s.pop();
                 else {
                        int curr=new_num[i];
                        int top=new_num[s.top()];
                        if(top<curr){
                            while(!s.empty() && new_num[s.top()]<curr){
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