class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        if(size % groupSize != 0) return false;
        
        unordered_map<int,int> um;
        for(int &card : hand){
            um[card] += 1;
        }
        vector<int> uniqueKeys;
        for(auto &pair: um){
            uniqueKeys.push_back(pair.first);
        }
        sort(uniqueKeys.begin(), uniqueKeys.end());

        for(int &key: uniqueKeys){
            // cout << key << endl;
            if(um[key] != 0){
                int count = um[key];
                for(int i=key; i<key+groupSize;i++){
                    // cout << i << endl;
                    // cout << um[i] << " " << count <<endl;

                    if(um[i] < count) return false;
                    um[i] -= count;
                }
            }
            // cout<<"========"<<endl;
        }

        return true;
        // 1 2 2 3 3 4 6 7 8 


    }
};