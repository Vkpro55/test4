class Solution {
public:
   
   void helper(int idx, vector<string> &folder, unordered_set<string> &unique_path){
        if (idx >= folder.size()){
            return;
        }
        // loop the current string to check that is a sub folder or not
        string currStr= folder[idx];
        string t="";
        bool flag= false;
        int n= currStr.size();
        for (int i=0; i<n; i++){
                t= t+ currStr[i];
                if(i==n-1 && unique_path.find(t) != unique_path.end()){
                    // call to the next string, ignore currStr
                    flag= true;
                    helper(idx+1, folder, unique_path);
                }
                else if (unique_path.find(t) != unique_path.end() && currStr[i+1]=='/'){
                    flag= true;
                    helper(idx+1, folder, unique_path);
                }
        }

        // means they not find this as sub-folder-> put this as unique_path str
        if(flag== false){
            unique_path.insert(t);
            helper(idx+1, folder, unique_path);
        }
        
   }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        unordered_set<string> unique_path;

        helper(0, folder, unique_path);

        return vector<string>(unique_path.begin(), unique_path.end());
    }
};