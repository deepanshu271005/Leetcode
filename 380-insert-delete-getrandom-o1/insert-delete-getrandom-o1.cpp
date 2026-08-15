class RandomizedSet {
public:
     
      vector<int>store;
      unordered_map<int,int>m;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end()){
            store.push_back(val);
            m[val]=store.size()-1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
         
         if(m.find(val)==m.end())return false;
         else {
             int idx=m[val];
             store[idx]=store[store.size()-1];
              m[store[idx]]=idx; 
             store.pop_back();
              m.erase(val);
           
            return true;
         }

    }
    
    int getRandom() {
         return store[rand()%(store.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */