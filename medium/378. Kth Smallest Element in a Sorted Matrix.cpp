class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int _size = matrix.size();
        int min = matrix[0][0], max = matrix[_size-1][_size-1];
        while(min < max){
            int mid = min + (max-min)/2;
            int pos = compare_Kth(matrix, mid);
            if(pos < k)
                min = mid+1;
            else
                max = mid;
        }
        return min;
    }
    int compare_Kth(vector<vector<int>>& matrix, int mid){
        int _size = matrix.size(), i = _size-1, j = 0;
        int count = 0;
        while(i >= 0 && j < _size){
            if(mid >= matrix[i][j]){
                count+=(i+1);
                j++;
            }else
                i--;
        }
        return count;
    }
};
