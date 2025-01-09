class Solution {
public:
    int maxOperations(vector<int> &nums, int k)
{
    unordered_map<int, int> store; /* === ele, freq ===*/
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        /* === Needed Value===*/
        int val = k - nums[i];
        if (store.find(val) != store.end())
        {
            cout << i << endl;

            count = count + 1;
            store[val]--;

            if (store[val] <= 0)
            {
                store.erase(val);
            }
        }
        else
        {
            store[nums[i]] = store[nums[i]] + 1;
        }
    }
    return count;
}
};