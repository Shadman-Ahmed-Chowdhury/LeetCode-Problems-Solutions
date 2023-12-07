// Problem link: https://leetcode.com/problems/largest-odd-number-in-string/description/

// My solution:
class Solution {
public:
    string largestOddNumber(string num) {
        int pos = -1;
        for(int i = num.size() - 1; i >=0 ; i--) {
            if((num[i] - '0') % 2 == 1) {
                pos = i;
                break;
            }
        }
        string res;
        if(pos >= 0) {
          res = num.substr(0, pos + 1);
        }
        return res;
    }
};