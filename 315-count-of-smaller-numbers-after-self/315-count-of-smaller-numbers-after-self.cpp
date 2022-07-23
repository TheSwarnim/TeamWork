#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    // use policy based data structures with a pair to compare with 
    // second value when nums[i] == nums[j] and index the current   
    // element as lower_bound position so that we can only count the 
    // nums[k] for all k > i && j > i that are smaller than nums[i]
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set st;
        int n = nums.size();
        vector<int> res(n);
        for(int i = n-1; i >= 0; i--){
            res[i] = st.order_of_key({nums[i], i});
            st.insert({nums[i], i});
        }
        return res;
    }
};