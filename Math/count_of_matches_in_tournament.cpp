// Problem link: https://leetcode.com/problems/count-of-matches-in-tournament/description/

// My solution:
class Solution {
public:
    int numberOfMatches(int n) {
        int matches = 0;
        int teams = n;
        while(teams > 1) {
            matches += (teams / 2);
            teams = (teams / 2) + (teams % 2);
        }
        return matches;
    }
};