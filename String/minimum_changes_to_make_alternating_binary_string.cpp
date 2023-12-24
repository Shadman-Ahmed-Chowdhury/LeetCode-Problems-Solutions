// Problem link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

// My solution:
class Solution {
public:
    int minOperations(string s) {
        int startZero = 0;
        int length = s.size();
        for(int i = 0; i < length; i++) {
            if(i % 2 == 0) {
                if(s[i] == '1') startZero++;
            } else {
                if(s[i] == '0') startZero++;
            }
        }
        return min(startZero, length - startZero);
    }
};