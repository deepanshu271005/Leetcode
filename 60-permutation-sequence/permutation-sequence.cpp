class Solution {
public:
    void f(int n, string& s, string& curr, vector<string>& store,
           vector<bool>& visited, int idx,int k) {
            if(store.size()>=k)return;
        if (curr.size() == n) {
            store.push_back(curr);
            return;
        }
        if (idx == n)
            return;

        if (visited[idx] == false) {
            visited[idx] = true;
            curr.push_back(s[idx]);
            f(n, s, curr, store, visited, 0,k);
            visited[idx] = false;
            curr.pop_back();
        }
        f(n, s, curr, store, visited, idx + 1,k);
        return;
    }

    string getPermutation(int n, int k) {
        // first  i will try to build all the valid permutation

        vector<string> store;
        vector<bool> visited(n + 1, false);
        string curr = "";
        string s = "";
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        //   for(auto i:s)cout<<s;
        //   cout<<endl;

       vector<int>factorial(10);
       factorial[0]=factorial[1]=1;
       for(int i=2;i<10;i++){
        factorial[i]=factorial[i-1]*i;
       }

       int per=0;
       int i=1;
       while(true){
          per+=factorial[n-1];
          if(per>=k){per-=factorial[n-1];break;}
          i++;
       }
           k-=per;
        f(n, s, curr, store, visited, i-1,k);
       //   for(auto i:store)cout<<i<<endl;
         
        return store[k-1];
    }
};