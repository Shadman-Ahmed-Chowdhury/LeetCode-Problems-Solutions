// Problem link: https://leetcode.com/problems/path-crossing/description/

// My solution:
class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;

        map<pair<int ,int> ,int > mp;
        mp[{0, 0}]++;
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == 'N')
                x++;
            else if(path[i] == 'E') 
                y++;
            else if(path[i] == 'S') 
                x--;
            else 
                y--;
            if(mp.count({x, y}) > 0) 
                return true;
            
            mp[{x, y}]++;
        }
        return false;
    }
};