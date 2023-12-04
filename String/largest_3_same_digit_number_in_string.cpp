// Problem link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/description

// My solution:
class Solution {
public:
    string largestGoodInteger(string num) {
        vector <int> count (10, 0);

        count[num[0] - '0'] = 1;
        for(int i = 1; i < num.size(); i++) {
            if(num[i-1] != num[i]) { 
                count[num[i] - '0'] = count[num[i] - '0'] >= 3 ? 3 : 1;
            } else {
                count[num[i] - '0']++;
            }
        }
        for(int i = 9; i >= 0; i--) {
            if(count[i] >= 3) 
                return string(3, '0' + i);
        } 
        return "";
    }
};