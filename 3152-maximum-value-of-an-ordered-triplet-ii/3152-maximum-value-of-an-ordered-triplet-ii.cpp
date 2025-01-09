class Solution {
public:
    long long maximumTripletValue(vector<int>& arr) {
        long long ans = 0;
    long long max_so_far = max(arr[0], arr[1]);

    vector<long long> pref(arr.size(), 0);
    pref[1] = arr[0] - arr[1];

    for (int k = 2; k < arr.size(); k++)
    {
        /* Set the value for next ietarion*/
        pref[k] = max(pref[k - 1], max_so_far - arr[k]);

        long long v1 = (long long)(pref[k - 1] * arr[k]);
        ans = max(ans, v1);

        max_so_far= max( max_so_far, (long long)(arr[k]));
    }

    return ans > 0 ? ans : 0;
    }
};