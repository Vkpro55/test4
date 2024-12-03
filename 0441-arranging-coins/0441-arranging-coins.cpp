class Solution {
public:
    
    /*

    n=8
    
    is it possible to make
    if row=1 -> 1*(1+1)/2= 1 <= n  true
       row=2 -> 2*(2+1)/2= 3 <= n  true
       row=3 -> 3*(3+1)/2= 6 <= n  true
       row=4 -> 4*(4+1)/2= 10 > n  false
       .... false

       t t t f f f ......

       problem is: find the last occurence of true
    */
    bool isPossible(long long int n, long long int noOfRows) {
    return (noOfRows * (noOfRows + 1)) / 2 > n;
}

int arrangeCoins(int n) {
    if (n == 0) return 0;  // Handle edge case
    
    long long int l = 1, r = n;
    int ans = -1;

    while (l <= r) {
        long long int mid = l + (r - l) / 2;

        if (isPossible(n, mid)) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }

    return ans;
}

};