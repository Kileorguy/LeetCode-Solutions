class Solution {
public:
    struct myclass {
        bool operator() (vector<int> &i,vector<int> &j) { return (i[0]<j[0]);}
    } myobject;


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),myobject);
        int count = 0;
        int size = intervals.size();

        for(int i=1;i<size;i++){
            if(intervals[i-1][1] > intervals[i][0]){
                if(intervals[i-1][1] < intervals[i][1]){
                    intervals[i][1] = intervals[i-1][1];
                }
                count++;
            }
        }
        

        return count;
    }
};