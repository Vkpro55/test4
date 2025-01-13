class Solution
{
public:
    int minimumLength(string s)
    {
        /* === Hashmap to remember the freq of the elements=== */
        unordered_map<int, int> freq;
        for (int i = 0; i < s.length(); i++)
        {
            freq[s[i]] = freq[s[i]] + 1;
        }

        /*=== Perform opeartion===*/
        int count = 0;
        for (auto it : freq)
        {
            if (it.second >= 3)
            {
                /* === Even ===*/
                if (it.second % 2 == 0)
                {
                    int op = (it.second / 2) - 1;
                    count = count + op * 2;
                }
                else
                {
                    /* === Odd ===*/
                    int op = (it.second / 2);
                    count = count + op * 2;
                }
            }
        }

        return s.length() - count;
    }
};