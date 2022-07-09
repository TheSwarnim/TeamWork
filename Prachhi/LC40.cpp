class Solution {
public:
    //TOPIC: classic example of backtracking
    set<vector<int>> ans; // to keep away dup vectors
    vector<int> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end()); //sorting the candidates vector
        backtrack(candidates,target,0); //backtrack
        
        //start inserting the value to j vector from set ans;
        vector<vector<int>> j;
        for(auto i:ans)
            j.push_back(i);
        
        return j;
    }
    void backtrack(vector<int>& candidates, int target,int ind){
        if(target==0) //base case if we have got the desired result i.e target = 0
            ans.insert(res);
        if(target<0)  // if target goes negative return back
            return;
        
        for(int i=ind;i<candidates.size();i++){
            //check for duplicates numbers and if current idx doesnt exceed the last idx
            if(i>ind && candidates[i]==candidates[i-1])  
                continue;
            //if the candidate is greater than target break the loop
            if(candidates[i]>target)
                break;
            //push the element, backtrack to next element and then pop
            res.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1);
            res.pop_back();
        }
    }
};
