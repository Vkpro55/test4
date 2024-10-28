class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n= word.length();
        long long total=1;
        const long long mod= 1e9+7;

        vector<int> segments;
        int cnt=1;

        // For example, if word = "aaabbc", segments will store [3, 2, 1]

        for (int i=1; i<n; i++){
            if(word[i] != word[i-1]){
                segments.push_back(cnt);
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        segments.push_back(cnt); // Add the last segment count
        
        // This represents the total possible combinations considering each segment individually
        for (int i=0; i<segments.size(); i++){
           total= (total*segments[i]) %mod;
        }


        // Step 3: Initialize the first row of dynamic programming table `prev_row`
        // `prev_row[x]` represents the number of ways to form a valid substring
        // ending with `x` characters from the first segment.
        
        // sequnces you want is size or sum < k
        vector<int> prev_row(k+1, 0);
        for (int i=1; i<=min(segments[0], k-1); i++){
            prev_row[i] =1;
        }

        vector<int> curr_row(k + 1, 0);
        vector<int> prefix(k + 1, 0);

        // Step 4: Process each subsequent segment up to `k` segments (to avoid over-calculation)
        int a= segments.size();
        for (int i=1; i<min(a, k); i++){
            prefix[0] = prev_row[0];

            for (int x=1; x<=k; x++){
                prefix[x]= (prefix[x-1] + prev_row[x]) %mod;
            }

            for (int x = 1; x <= k; x++) {
                int prev_point = max(x - segments[i], i);
                // Calculate ways for current position x using the prefix array
                curr_row[x] = (prefix[x - 1] - prefix[prev_point - 1] + mod) % mod;
            }
            prev_row = curr_row;
        }

        long long t2 = 0;
        for (int i = 0; i < k; i++) {
            t2 = (t2 + prev_row[i]) % mod;
        }

        // Step 6: Return the result as (total - t2) modulo `mod`
        // `total` is all combinations, and `t2` removes those not meeting the criteria
        return (total - t2 + mod) % mod;

    }
};