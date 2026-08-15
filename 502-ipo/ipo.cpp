class Solution {
public: 

 
 
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

      int n=profits.size();

      vector<pair<int,int>>store;
      for(int i=0;i<n;i++){
        store.push_back({capital[i],profits[i]});
      }

      sort(store.begin(),store.end());
      priority_queue<int>pq;
      int i=0;
     
     while (k--) { 
            
            while (i < n && w >= store[i].first) {
                pq.push(store[i].second);
                i++;  
            }
            
            
            if (pq.empty()) break;
            
            w += pq.top();
            pq.pop(); 
        }
        
        return w;

    }
};