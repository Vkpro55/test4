class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> res;

        priority_queue< pair<int, int>> q;

        for (int i=0; i<n; i++){
            q.push({nums[i], i});

            if (i<k-1) continue;

            while (q.top().second < i-k+1){
                q.pop();
            }

            res.push_back(q.top().first);
        }

        return res;
    }
};