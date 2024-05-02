class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();
        vector<vector<int>> ans;  
        if(m==0 || n ==0){
            return ans;
        }
        vector<vector<bool>> Pacific(m, vector<bool>(n, false));
        vector<vector<bool>> Atlantic(m, vector<bool>(n,false)); 
        
        for(int i=0; i<m; i++){
            DFS(heights, Pacific, -1, i, 0);
            DFS(heights, Atlantic, -1, i, n-1);
        }
        for(int i=0; i<n; i++){
            DFS(heights, Pacific, -1, 0, i);
            DFS(heights, Atlantic, -1, m-1, i);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(Pacific[i][j]&&Atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
    void DFS(vector<vector<int>>& heights, vector<vector<bool>>& visited, int pre, int i, int j){
        int m = heights.size();
        int n = heights[0].size();

        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || heights[i][j] < pre){
            return;
        }
        int h = heights[i][j];
        visited[i][j] = true;
        DFS(heights, visited, h, i-1, j);
        DFS(heights, visited, h, i+1, j);
        DFS(heights, visited, h, i, j-1);
        DFS(heights, visited, h, i, j+1);
    }
    
};
