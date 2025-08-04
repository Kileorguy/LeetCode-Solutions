class Solution {
public:

    bool checkPalindrome(string &s){
        int left = 0;
        int right = s.length()-1;
        // cout << s << endl;

        while(left<=right && left < s.length() && right < s.length()){
            // cout << left << " asd " << right << endl;
            // cout << s[left] << " = " << s[right] << endl;
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    void recursive(vector<vector<string>> &ans, vector<string> & subs, string &s, int idx, int max){
        if(idx == max){
            ans.push_back(subs);
            return;
        }
        string a ="";
        for(int i=idx; i<max; i++){ // substring
            a += s[i];
            if(checkPalindrome(a)){
                subs.push_back(a);
                recursive(ans, subs,s, i+1, max);
                subs.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subs;

        recursive(ans, subs,s, 0, s.length());

        return ans;
    }
};