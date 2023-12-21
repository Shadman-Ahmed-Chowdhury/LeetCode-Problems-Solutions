// Problem link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/

// My solution:
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int res = 0;

        for(int i = 1; i < points.size(); i++) {
            int diff = points[i][0] - points[i-1][0];
            res = max(diff, res);
        }
        return res;
    }
};