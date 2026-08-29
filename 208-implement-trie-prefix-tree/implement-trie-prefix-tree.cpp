class Trie {
public:
 
    class Node{
      public:
      vector<Node*>store;
      bool f;

    Node(){
         store.resize(26);
         for(int i=0;i<26;i++)store[i]=NULL;
         f=false;
      }

    };
    Node*root;
  
    Trie() {
       
        root=new Node();
        
    }
    
    void insert(string word) {
        Node*curr=root;
        for(auto i:word){
            if(curr->store[i-'a']!=NULL){
                curr=curr->store[i-'a'];
            }
            else {
                curr->store[i-'a']=new Node();
                curr=curr->store[i-'a'];
            }
        }
        curr->f=1;
        return;
    }
    
    bool search(string word) {
          Node*curr=root;
        for(auto i:word){
            if(curr->store[i-'a']!=NULL){
                curr=curr->store[i-'a'];
            }
            else {
                return false;
            }
        }
        return curr->f;
    }
    
    bool startsWith(string prefix) {
         Node*curr=root;
        for(auto i:prefix){
            if(curr->store[i-'a']!=NULL){
                curr=curr->store[i-'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */