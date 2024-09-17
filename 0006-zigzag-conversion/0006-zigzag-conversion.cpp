class Solution {
public:
    string convert(string s, int numRows) {
          int k=0,j=0;
        vector<vector<char>> a(numRows,vector<char>(1005,'0'));
        bool ok=false;
        for(int i=0;i<s.size();)
        {
            for(j=0;j<numRows and i<s.size();j++)
            {
                a[j][k]=s[i];
                i++;
            }
            k++;


            for(j=numRows-2;j>0 and i<s.size();j--)
            {
                a[j][k]=s[i];
                i++;
                ok=true;
            }

            k++;

        }
        string ans;
        for(int i=0;i<numRows;i++)
            for(int j=0;j<1005;j++)
                if(a[i][j]!='0')
                    ans+=a[i][j];
        return ans;
    }
    
};