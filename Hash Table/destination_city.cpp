// Problem link: https://leetcode.com/problems/destination-city/description/

// My solution:
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map <string, int> hasOutgoingPath; 

        for(int i = 0; i < paths.size(); i++) {
            hasOutgoingPath[paths[i][0]]++;
        }

        for(int i = 0; i < paths.size(); i++) {
            if(hasOutgoingPath.count(paths[i][1]) == 0) {
                return paths[i][1];
            }
        }

        return "";
    }
};