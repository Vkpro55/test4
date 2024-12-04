class Solution {
public:
/*
   Approach: isSubsequnce by using two ptr: 
   consition: at most one operation: we can choose any set of indexes

   str1= "zca"   str2="ad": check wether str2 is subsequnce of a or not

   if ( str1[i] == str2[j]){
        // "abc"  "azd"
        i++, j++;
   }
   else if (){
      // by operation is its is possible

   }else{
      i++;
   }

   if(j==n) return true;
   else return false;
*/

    bool canMakeSubsequence(string str1, string str2) {
        int i=0, j=0;

        while (i<str1.size() && j<str2.size()){

            if(str1[i]-'a'==str2[j]-'a' || (str1[i]-'a'+1)%26==str2[j]-'a'){
                j++;
            }
            if(j==str2.length()){
                return true;
            }
            i++;
        }

        return false;
    }
};