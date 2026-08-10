class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
   int n=temperatures.size();
   vector<int>nextG(n,0);
   stack<int>s;
   for(int i=0;i<n;i++){
      if(s.empty())s.push(i);
      else {
        while(!s.empty() && temperatures[s.top()]<temperatures[i]){
            nextG[s.top()]=i;
            s.pop();
        }
        s.push(i);
      }
   }
   for(int i=0;i<n;i++){
    if(nextG[i]==0)continue;
    nextG[i]=nextG[i]-i;
   }
    return nextG;

    }
};