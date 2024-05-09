class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int time = 0;
        long long sum = 0;
        for(int i=0; i<k; i++){
            int index = happiness.size()-i-1;
            int next = 0;
            if((happiness[index] - (time))>0)
                next = happiness[index] - (time++);
            sum+=next;
        }
        return sum;
    }

};
