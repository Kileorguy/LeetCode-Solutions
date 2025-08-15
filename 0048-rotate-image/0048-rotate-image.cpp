class Solution {
public:

    void rotate(vector<vector<int>>& matrix) {
        int maxI = matrix.size();
        int maxJ = matrix[0].size();
        
        int temp;

        for (int i = 0; i < maxI / 2; i++) {
            for (int j = i; j < maxJ - i - 1; j++) {
                temp = matrix[i][j]; 

                matrix[i][j] = matrix[maxI - 1 - j][i];
                matrix[maxI - 1 - j][i] = matrix[maxI - 1 - i][maxJ - 1 - j];
                matrix[maxI - 1 - i][maxJ - 1 - j] = matrix[j][maxJ - 1 - i];
                matrix[j][maxJ - 1 - i] = temp;
        }
}



    }
};