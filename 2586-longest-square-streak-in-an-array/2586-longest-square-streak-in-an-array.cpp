class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=-1, n= nums.size();

        for (int i=0; i<n; i++){
            long long x= 1ll*nums[i];
            long long pwr= x*x;

            if(binary_search(nums.begin(), nums.end(), pwr)){
                int len=1;

                while (binary_search(nums.begin(), nums.end(), pwr)){
                    len++;
                    pwr= pwr*pwr;
                }

                ans= max(ans, len);
            }
        }
        return ans;
    }
};