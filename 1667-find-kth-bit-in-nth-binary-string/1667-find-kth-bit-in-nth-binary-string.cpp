class Solution {
public:

string invert(string str){   
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1'){
            str[i] = '0';
        }
        else{
            str[i] = '1';
        }
    }
    return str;
}

string reverse(string str){
    int low = 0, high = str.size() - 1;
    while (low < high){
        swap(str[low], str[high]);
        low++, high--;
    }
    return str;
}

char findKthBit(int n, int k) {

    vector<string> dp(n);
    dp[0] = "0";
    
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i-1] + "1" + reverse(invert(dp[i-1]));
    }
    
    return dp[n-1][k-1];
}
};