class Solution {
public:

    vector<string> ans;

    void parenthesis(int left, int right, string a, int base){
        if(left == right && left+right == base*2){
            ans.push_back(a);
        }

        if(left < base) parenthesis(left+1, right, a +"(", base);
        if(right< left) parenthesis(left, right+1, a +")", base);
        // return ans;
    }

    vector<string> generateParenthesis(int n) {
        parenthesis(0,0, "", n);
        return ans;
    }
};