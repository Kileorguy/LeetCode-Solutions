class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};

        for(char x: s){
            count[x-'a']+=1;
        }
        for(char x:t){
            count[x-'a']-=1;
        }

        for(int i: count){
            if(i!=0){
                return false;
            }
        }

        return true;
    }
};