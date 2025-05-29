class Solution {
public:
    bool binary(vector<vector<int>> &matrix, int left, int right, int target,  int nSize){
        if(right<left) return false;
        int middle = left + (right-left)/2;
        if(matrix[floor(middle / nSize)][middle%nSize] == target) return true;
        else if(target < matrix[floor(middle / nSize)][middle%nSize]) return binary(matrix, left, middle-1, target, nSize);
        else return binary(matrix, middle+1, right, target, nSize);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int mSize = matrix.size();
        int nSize = matrix[0].size();
        // int length = mSize * nSize;
        // cout << floor(i / (nSize)) << " " + to_string(i%nSize)<< endl;



        return binary(matrix, 0, matrix.size() * nSize - 1, target, nSize);
    }
};