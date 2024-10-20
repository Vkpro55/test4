class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return parseExpr(expression, index);
    }
    
private:
    bool parseExpr(const string& expr, int& index) {
        char c = expr[index++];
        
        if (c == 't') return true;
        if (c == 'f') return false;
        
        bool result = (c == '|') ? false : true;
        index++; // Skip '('
        
        while (expr[index] != ')') {
            bool value = parseExpr(expr, index);
            if (c == '!') {
                result = !value;
                break;  // NOT operation should only have one operand
            }
            if (c == '&') result &= value;
            if (c == '|') result |= value;
            if (expr[index] == ',') index++;
        }
        
        index++; // Skip ')'
        return result;
    }
};