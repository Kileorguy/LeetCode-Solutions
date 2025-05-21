class Solution {
public:
    bool isPalindrome(string s) {
        string valid = "";

        for(char x: s){
            if(isalnum(x)){
                valid += tolower(x);
            }
        }

        int left = 0;
        int right = valid.length()-1;

        while(left < right){
            if(valid[left] != valid[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};