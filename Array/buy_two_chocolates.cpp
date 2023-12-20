// Problem link: https://leetcode.com/problems/buy-two-chocolates/description/

// My solution:
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest = 1001;
        int secondSmallest = 1001;

        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < smallest) {
                secondSmallest = smallest;
                smallest = prices[i];
                
            } 
            else if(prices[i] < secondSmallest) {
                secondSmallest = prices[i];
            }
        }
        return (money - (smallest + secondSmallest) < 0) ? money : money - (smallest + secondSmallest);
    }
};