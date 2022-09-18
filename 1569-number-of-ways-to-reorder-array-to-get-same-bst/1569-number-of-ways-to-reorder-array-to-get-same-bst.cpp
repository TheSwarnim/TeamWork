class Solution {
public:
    typedef long long ll;
    typedef vector<int> vi;
    typedef vector<vector<ll>> vvi;
    
    vvi table;
    int mod = 1e9 + 7;
    
    ll sum(ll a, ll b){
        return (a+b)%mod;
    }
    
    ll mult(ll a, ll b){
        return ( (a%mod) * (b%mod) ) % mod;
    }
    
    ll sub(ll a, ll b){
        return (a - b + mod) % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        table.resize(n+1);
        for(int i = 0; i <= n; i++){
            table[i] = vector<ll>(i+1, 1);
            
            for(int j = 1; j < i; j++){
                table[i][j] = sum(table[i-1][j-1], table[i-1][j]);
            }
        }
        
        return sub(dfs(nums), 1);
    }
    
    ll dfs(vi &nums){
        int n = nums.size();
        if(n <= 2){
            return 1;
        }
        
        vi left, right;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[0]) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        
        ll left_res = dfs(left);
        ll right_res = dfs(right);
        
        int left_len = left.size();
        
        return mult( mult(left_res, right_res),
                     table[n-1][left_len]);
    }
};