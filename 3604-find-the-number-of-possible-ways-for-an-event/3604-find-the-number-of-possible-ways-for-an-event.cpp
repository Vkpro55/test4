class Solution {
public:
    long long md = 1e9 + 7;
    
    int numberOfWays(int n, int x, int y) {
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        
        // dp[i][j] -> put i persons in j stages out of x stages and assign them [1--y] number
        dp[1][1] = x; // base case

        for (long long i = 2; i <= n; i++) {
            for (int j = 1; j <= min(x, (int)i); j++) { // Cast i to int
                dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (x - (j - 1))) % md;
            }
        }
        
        long long count = 0;
        long long y1 = y;

        for (int stage = 1; stage <= x; stage++) { // Use int for stage as well
            count = (count + dp[n][stage] * y1) % md; // Add modulus operation here
            
            y1 = (y1 * y) % md;
        }

        return count;
    }
};