class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        int sum =0;
        for(string z: tokens){
            if(z == "+" || z == "-" || z == "*" || z == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (z == "+") st.push(a + b);
                else if (z == "-") st.push(a - b);
                else if (z == "*") st.push(a * b);
                else st.push(a / b);
            }else{
                st.push(stoi(z));
            }
        }
        return st.top();
    }
};