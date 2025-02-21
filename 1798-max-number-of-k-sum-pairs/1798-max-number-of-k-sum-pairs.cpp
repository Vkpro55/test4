class Solution {
public:
    int maxOperations(vector<int> &nums, int k)
{
    unordered_map<int, int> store, visited; /* ==== ele, freq ==== */
    for (int i = 0; i < nums.size(); i++)
    {
        store[nums[i]] = store[nums[i]] + 1;
    }

    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int number = nums[i];
        int partner = k - nums[i];

        /* To ensure that I can't visited the same element again in different pair*/
        if (visited[number] == 0 && visited[partner] == 0)
        {
            /* ====  1 2 3 4 3 2 3 3  k=6 ====*/
            if (number == partner)
            {
                /* 3-> 4 */
                count += store[number] / 2;
            }
            else
            {
                count += min(store[number], store[partner]);
            }
        }

        visited[number] = 1;
        visited[partner] = 1;
    }

    return count;
}
};