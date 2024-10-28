class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans=-1;
        map<int, int> dp; // dp[x]-> maz length of subsequnce whose length is x

        for(int num : nums){
            int sq= sqrt(num);
            if(sq*sq == num && dp.find(sq)!=dp.end()){
                dp[num]= dp[sq]+1;
                ans= max(ans, dp[num]);
            }
            else{
                dp[num]=1;
            }
        }

        return ans;
    }
};