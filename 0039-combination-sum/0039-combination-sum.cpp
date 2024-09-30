class Solution {
public:
   
   void backtrack(vector<int>& candidates, int target, int index, vector<vector<int>> &ans, vector<int> &temp) {
  
    // base case
    if (target == 0) {
        ans.push_back(temp);
        return;
    }

    if (target<0) return;

    if (index == candidates.size()) {
        return ;
    }

    int candidate = candidates[index];

   // Magical Assumption + // Hypothesis

   // take 
   temp.push_back(candidate);
   backtrack(candidates, target-candidate, index, ans, temp);
   temp.pop_back();   

   // no to take
   backtrack(candidates, target, index+1, ans, temp); 


}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> ans;
          vector<int> temp;
          backtrack(candidates, target, 0, ans, temp);
          return ans;
    }
};


//  3 3 3 
//  3 3 2 1 correct
//  3 3 1 2 incorrect
//  3 3 1 1 1