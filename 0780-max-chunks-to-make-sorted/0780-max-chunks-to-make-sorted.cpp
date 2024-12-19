class Solution {
public:
/*
Chunk will be: subarray and continuos 
[2 0 1] = 1 

// [ 0 to k] = 0 to k only in the range 
[1, 2, 0] =1 k= 3 [0 to 2]

*/
    int maxChunksToSorted(vector<int>& arr) {

        int chunk_max = arr[0];
        int cnt = 0 ;

        for(int i=0;i<arr.size();++i){
            chunk_max = max(chunk_max,arr[i]);

            // [1, 2 0] = ( max =2 and i==2 );
            if(chunk_max == i){
                cnt++;
            }
        }
        return cnt ;
       
    }
};