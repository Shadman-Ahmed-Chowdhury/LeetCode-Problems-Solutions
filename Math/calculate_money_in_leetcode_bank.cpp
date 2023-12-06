// Problem link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/

// My solution: 
class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        for(int i = 0; i < n / 7; i++) {
            // Sum of arithmatic series formula.
            total += (7 * (i + 1 + i + 7)) / 2;
        }
        // Remaining amount.
        int q = n / 7;
        int r = n % 7;
        total += (r * (q + 1 + q + r)) / 2;
        return total;
    }
};