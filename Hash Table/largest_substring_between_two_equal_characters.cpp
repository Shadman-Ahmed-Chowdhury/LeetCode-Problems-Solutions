// Problem link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// My solution:
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();

        unordered_map <char, int> charMap;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(charMap.find(s[i]) != charMap.end()) {
                ans = max(ans, i - charMap[s[i]] - 1);
            } else {
                charMap[s[i]] = i;
            }
        }
        return ans;
    }
};