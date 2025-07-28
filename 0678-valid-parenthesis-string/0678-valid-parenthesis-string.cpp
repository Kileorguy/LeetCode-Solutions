class Solution {
public:
    bool checkValidString(string s) {
        stack<int> oSt, anySt;
        int anyCount = 0;
        int idx = 0;

        for(char c: s){
            if(c == '(') oSt.push(idx);
            else if(c == '*'){
                if(!oSt.empty() && oSt.size() < anySt.size()){
                    oSt.pop();
                }else{
                    anySt.push(idx);
                }
            }
            else{
                if(!oSt.empty()) oSt.pop();
                else if(!anySt.empty()) anySt.pop();
                else return false;
            }
            idx++;
        }

        while(!oSt.empty() && !anySt.empty()){
            // cout << oSt.top() << " " << anySt.top() << endl;
            if(oSt.top() < anySt.top()){
                
                oSt.pop(); anySt.pop();
            }else{
                return false;
            }
        }

        if(oSt.empty()) return true;
        return false;

    }
};