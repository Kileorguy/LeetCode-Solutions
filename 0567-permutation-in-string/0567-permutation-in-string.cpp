class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length(); 

        if(len1 > len2) return false;
        unordered_map<char,int> um;
        for(int i=0;i<len1;i++){
            um[s1[i]]++;
        }
        
        int left = 0;
        for(int right=len1-1; right<len2; right++){
            unordered_map<char,int> cm;
            for(int i=left; i<=right; i++){
                // cout << s2[i];
                cm[s2[i]]++;
            }
            // cout << endl;
            bool check = true;
            for(auto pair: um){
                // cout << pair.first << endl;
                // cout << cm[pair.first] << " " + to_string(pair.second) << endl;
                if(cm[pair.first] != pair.second){
                    check = false;
                }
            }
            // cout << "==========" << endl;
            if(check) return true;
            left++;
        }
        return false;

    }
};