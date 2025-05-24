class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        unordered_map<char,char> um;
        um[')'] = '(';
        um[']'] = '[';
        um['}'] = '{';
        

        for(char x: s){
            if(x == ')' || x == ']' || x == '}'){
                if(stack.empty()) return false;
                if(stack.top() == um.at(x)){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(x);
            }

        }
        if(stack.empty()) {
            return true;
        }else{
            return false;
        }
    }
};