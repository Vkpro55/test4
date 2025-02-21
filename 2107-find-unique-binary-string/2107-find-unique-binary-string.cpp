class Solution {
public:
    string solve(unordered_map<string, int> &store, int index, string temp, int n)
    {
        /*== Base Case ==*/
        if (index >= n)
        {
            if (store.find(temp) == store.end())  // If the generated string is unique
            {
                return temp;
            }
            return "";  // If not unique, return empty string
        }

        /*== Try both '0' and '1' at the current index ==*/
        for (int i = 0; i < 2; i++)
        {
            temp += to_string(i);
            string res = solve(store, index + 1, temp, n);
            
            /*== If we find a valid result, return it immediately ==*/
            if (!res.empty()) return res;
            
            /*== Backtrack ==*/
            temp.pop_back();
        }
        
        return "";  // No valid string found
    }

    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_map<string, int> store;
        int n = nums.size();

        // Store all existing binary strings
        for (const string &s : nums)
        {
            store[s]++;
        }

        // Start searching from an empty string
        return solve(store, 0, "", n);
    }
};
