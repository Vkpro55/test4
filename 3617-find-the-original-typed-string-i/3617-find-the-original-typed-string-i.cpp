class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;// full word may be

        for (int i=1; i<word.size(); i++){
            if(word[i] == word[i-1]){
                ans++;
            }
        }

        return ans;
    }
};