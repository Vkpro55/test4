class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector<int> ans;
        int n= expression.size();

        for (int i=0; i<n; i++){
            // stop at every operator 
            char ch= expression[i];
            if (ch == '+' || ch == '-' || ch == '*'){
                vector<int> a= diffWaysToCompute(expression.substr(0, i));
                vector<int> b= diffWaysToCompute(expression.substr(i+1));

                // do computation
                for ( auto x: a){
                    for (auto y: b){

                        if (ch== '+'){
                            ans.push_back(x+y);
                        }
                        else if (ch== '-'){
                            ans.push_back(x-y);
                        }
                        else{
                            ans.push_back(x*y);
                        }
                    }
                }
            }

        }

        //base case leaf node
        if(ans.empty()) ans.push_back(stoi(expression));

        return ans;
    }
};