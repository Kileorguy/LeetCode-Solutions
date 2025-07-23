class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int size = gas.size();

        int startPoint = -1;
        
        for(int i=0;i<size;i++){
            diff.push_back(gas[i] - cost[i]);
        }
        
        int start = 0;
        int curr;
        
        int currGas = INT_MIN;
        for(int i=0;i<size*2;i++){
            curr = i % size;
            // cout << "start " << start << endl;
            // cout << "curr " << curr << endl;
            // cout << "currGas " << currGas << endl;
            // cout << " ============ " << endl;

            if(currGas < 0){
                start = curr;
                curr = curr;
                currGas = diff[curr];
                continue;
            }

            if(start == curr){
                if(currGas < 0) return -1;
                else return start;
            }

            currGas += diff[curr];
        }

        return -1;
    }
};