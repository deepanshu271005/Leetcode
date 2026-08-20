class Solution {
public:

    
    class Disjoint{
        public:
        vector<int>parent;

        Disjoint(int n){
            parent.resize(n+1);
            for(int i=0;i<=n;i++){
              parent[i]=i;
            }
        }
    
         int findparent(int a){
           if(parent[a]==a)return a;
            return parent[a]=findparent(parent[a]);//path compresion 
         }
     
        void unionBySize(int a,int b){
            int upa=findparent(a);
            int upb=findparent(b);
            parent[upa]=upb;
            return;
        }
        
   

    };
    
  
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          
          int n=edges.size();
                
        Disjoint*d=new Disjoint(edges.size());
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int upa=d->findparent(a);
            int upb=d->findparent(b);
            if(upa==upb){
                return edges[i];
            }
            else d->unionBySize(a,b);
        }
        return {};

    }
};