class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }

        // Custom comparator for sorting strings
        sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // Edge case: if the largest number is "0", return "0"
        if (strs[0] == "0") {
            return "0";
        }
        
        for (auto c: strs){
            cout <<  c << " ";
        }
        cout << endl;
        // Concatenate sorted strings
        string result;
        for (const string &str : strs) {
            result += str;
        }

        return result;
    }
};