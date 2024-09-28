class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> res;
        deque<int> q;

        int i=0;
        while(i<n){

            // check for current window from front
            while (!q.empty() && q.front()<= i-k){
                q.pop_front();
            }

            // for element right pos delete from back
            while (!q.empty() && nums[q.back()]<= nums[i]){
                q.pop_back();
            }

            q.push_back(i);

            // check for each window
            if (i >= k-1){
                int g= q.front();
                res.push_back(nums[g]);
            }

            i++;
        }
        
        return res;
    }
};