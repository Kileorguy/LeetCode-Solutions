class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int spare = 0;
        digits[digits.size()-1] += 1;

        for(int i=digits.size()-1; i>=0;i--){
            digits[i] += spare;
            spare = 0;
            if(digits[i] / 10 == 1){
                spare = 1;
            }
            digits[i] = digits[i] % 10;
        }

        if(spare != 0){
            digits.insert(digits.begin(), spare);
        }
        return digits;

    }
};