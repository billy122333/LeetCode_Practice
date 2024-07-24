class Solution {
public:
    bool isCycle(vector<vector<int>>& adj_list, vector<int>& taked, int index){
        // cycle happened
        if(taked[index]==1) return true;
        if(taked[index]==2) return false;
        
        else if(taked[index]==0){
            taked[index] = 1;
            for(auto course: adj_list[index]){
                // cycle happend
                if(isCycle(adj_list, taked, course)) return true;
            }
            taked[index] = 2;
        }
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses, vector<int>());
        // 0 not visit, 1 is visiting, 2 visited 
        vector<int> taked(numCourses, 0);
        for(auto x: prerequisites){
            int course = x[0];
            int haveToTake = x[1];
            adj_list[course].push_back(haveToTake);
        }
        for(int i=0; i<numCourses; i++){
            if(isCycle(adj_list, taked, i)) return false;
        }
        return true;
        
    }
};
