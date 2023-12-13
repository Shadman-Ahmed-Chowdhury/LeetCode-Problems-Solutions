// Problem link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/

// My solution: 
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <int> rowCount(n, 0);
        vector <int> colCount(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        int good = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    if(rowCount[i] == 1 && colCount[j] == 1) {
                        good++;
                    }
                }
            }
        }
        return good;
    }
};