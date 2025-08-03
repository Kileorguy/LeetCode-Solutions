class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> key = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> res;
        queue<pair<int, string>> q;
        q.push({0, ""});

        while (!q.empty()) {
            auto [idx, curr] = q.front();
            q.pop();

            if (idx == digits.size()) {
                res.push_back(curr);
                continue;
            }

            char digit = digits[idx];
            for (char c : key[digit]) {
                q.push({idx + 1, curr + c});
            }
        }

        return res;
    }
};
