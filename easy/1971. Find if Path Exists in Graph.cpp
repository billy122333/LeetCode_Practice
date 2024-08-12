class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent;
        vector<int> rank(n, 1);
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        
        for(auto edge: edges){
            _union(parent, rank, edge[0], edge[1]);
        }
        return find(parent, source) == find(parent, destination);
    }
    
    void _union(vector<int>& parent, vector<int>& rank, int a, int b){
        int par_A = find(parent, a);
        int par_B = find(parent, b);
        
        if(par_A == par_B) return;
        
        int rk_A = rank[par_A];
        int rk_B = rank[par_B];
        if(rk_A > rk_B){
            parent[par_A] = par_B;
        }
        else if(rk_A < rk_B){
            parent[par_B] = par_A;
        }else{
            parent[par_A] = par_B;
            rank[par_A]++;
        }
    }
    
    int find(vector<int>& parent, int x){
        if(parent[x] == x)
            return parent[x];
        else
            parent[x] = find(parent, parent[x]);    
            
        return parent[x];
    }
};
