# define ll long long
const int MOD = 1e9+7;

class Solution {
public:
    static bool myCompare(int a, int b){
        return a > b;
    }
    ll sum(ll a){
        ll ans = 0;
        ans = ((a+1)*a)/2;
        return ans;
    }
    
    int maxProfit(vector<int>& inventory, int orders) {
        
        sort(inventory.begin(),inventory.end(),myCompare);
        inventory.push_back(0);
        ll ans = 0;
        ll gain = 0;
        int i = 0;
        // int count = 0;
        
        while( orders && i < inventory.size()){
            if(inventory[i] != inventory[i + 1]){
                ll width = i + 1 ;
                ll range = inventory[i] -(inventory[i + 1]);
                ll a = width * range;
                if(orders >= a){
                    orders -= a;
                    gain = (width * (sum(inventory[i]) - sum(inventory[i + 1]))) % MOD;
                   
                }else{
                    //greedy
                    ll q = orders / width;
                    ll r = orders % width;
                    gain = (width * (sum(inventory[i]) - sum(inventory[i] - q))) % MOD;
                    gain +=  r*(inventory[i]-q) % MOD;
                   
                    orders = 0;
                }
                 ans = (ans + gain) % MOD; 
            }
            i++;
            
        }
         return ans;  

        }
        
};
