class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length(); 

        if(len1 > len2) return false;
        unordered_map<char,int> um;
        unordered_map<char,int> cm;

        for(int i=0;i<len1;i++){
            um[s1[i]]++;
            cm[s2[i]]++;
        }

        if(um == cm) return true;
        int left = 0;
        for(int right = len1; right < len2; right++){
            cm[s2[left]]--;
            cm[s2[right]]++;

            if(cm[s2[left]]==0) cm.erase(s2[left]);
            if(cm == um) return true;

            left++;
        }
        return false;
    }
};