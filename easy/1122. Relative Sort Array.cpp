class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // sort(arr1.begin(), arr1.end());
        // sort(arr2.begin(), arr2.end());
        map<int, int> arr1_map;
        vector<int> ans;
        
        for(int i=0; i<arr1.size(); i++){
            arr1_map[arr1[i]]++;
        }
        for(int i=0; i<arr2.size(); i++){
            while(arr1_map[arr2[i]]){
                ans.push_back(arr2[i]);
                arr1_map[arr2[i]]--;
            }
        }
        
        for(auto &t:arr1_map){
            while(t.second--){
                ans.push_back(t.first);
            }
        }
        
        
        return ans;
    }
};
