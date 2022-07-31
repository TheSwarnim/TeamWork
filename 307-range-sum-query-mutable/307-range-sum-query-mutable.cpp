class FenWickTree{
public:
    vector<int> cnt;
    FenWickTree(int n): cnt(n+1, 0){
        
    }
    
    void update(int i, int delt){
        while(i < cnt.size()){
            cnt[i] += delt;
            i += lowbit(i);
        }
    }
    
    int query(int a){
        int sum = 0;
        while(a > 0){
            sum += cnt[a];
            a -= lowbit(a);
        }
        return sum;
    }
    
    int lowbit(int x){
        return x & (-x);
    }
};

class NumArray {
public:
    FenWickTree fw;
    vector<int> nums;
    NumArray(vector<int>& nums):fw(nums.size()) {
        this->nums = nums;
        for(int i = 0; i < nums.size(); i++){
            fw.update(i+1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        fw.update(index+1, val - nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return fw.query(right+1) - fw.query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */