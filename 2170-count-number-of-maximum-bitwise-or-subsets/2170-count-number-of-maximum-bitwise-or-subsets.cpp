class Solution {
public:
    int maxOR= 0;
    int cnt=0;

    void solve(int ind, int currOR, vector<int> &nums) {
    // Base case: When we have processed all the elements
    if (ind >= nums.size()) {
        if (currOR == maxOR) {
            cnt = cnt + 1;  // Count if the current OR is equal to the maximum OR
        }
        return;  // Missing return statement to stop further recursion
    }

    // Exclude the current element
    solve(ind + 1, currOR, nums);

    // Include the current element
    solve(ind + 1, currOR | nums[ind], nums);
}


    int countMaxOrSubsets(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            maxOR = maxOR | nums[i];
        }

        int currOR= 0;
        solve(0, currOR, nums);
        
        return cnt;
    }
};