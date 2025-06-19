class Solution {
public:

    string minWindow(string s, string t) {
        int lenS = s.length();
        int lenT = t.length();
        
        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        int len = INT_MAX;
        int minL, minR;


        for(int i=0;i<lenT;i++){
            tMap[t[i]]++;
        }
        int have = 0, need = tMap.size(); 

        if(sMap == tMap) return s.substr(0,lenT);

        int left = 0;

        for(int i=0; i<lenS; i++){
            char c = s[i];
            sMap[c]++;

            if(tMap.count(c) && tMap[c] == sMap[c]){
                have++;
            }

            while(have == need){

                if(len > i-left+1){
                    len = i - left + 1;
                    minL = left; minR = i;

                }

                char a = s[left];

                sMap[a]--;
                if (tMap.count(a) && sMap[a] < tMap[a]) {
                    have--;
                }

                left++;
            }
        }
        if(len == INT_MAX) return "";
        else return s.substr(minL, len);
    }
};