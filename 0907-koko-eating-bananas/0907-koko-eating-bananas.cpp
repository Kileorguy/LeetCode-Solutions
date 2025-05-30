class Solution {
public:

    int binary(vector<int> &piles, int left, int right, int h){
        if(right<left) return left;
        int middle = left + (right-left)/2;
        long long int sum = 0;
        for(int x: piles){
            sum += (x + middle - 1) / middle;
        }

        if(sum > h) return binary(piles, middle+1, right, h);
        else return binary(piles,left, middle-1, h);
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = piles[0];
        int size = piles.size();
        for(int i=1; i<size;i++){
            maxVal = max(maxVal, piles[i]);
        }

        return binary(piles, 1, maxVal, h);
    }
};