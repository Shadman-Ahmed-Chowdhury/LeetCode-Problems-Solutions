class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector <int> temp;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }
        }
        int q = m * n;
        for(int i = 0; i < k; i++) {
            int t = temp[q - 1];
            for (int j = q - 1; j > 0; j--) {
                temp[j] = temp[j - 1];
            }
            temp[0] = t;
        }
        reverse(temp.begin(), temp.end());

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                grid[i][j] = temp.back();
                temp.pop_back();
            }
        }
        return grid;
    }
};