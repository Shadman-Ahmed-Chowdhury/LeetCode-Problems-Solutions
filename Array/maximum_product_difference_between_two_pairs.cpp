// Problem link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/

// My solution:
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // O (nlogn) solution.
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);

        // O(n) solution: 
        int largest = 0, secondLargest = 0, smallest = 10001, secondSmallest = 10001;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            } else {
                if(nums[i] > secondLargest) {
                    secondLargest = nums[i];
                }
            }

            if(nums[i] < smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            } else {
                if(nums[i] < secondSmallest) {
                    secondSmallest = nums[i];
                }
            }
        }
        return (largest * secondLargest) - (smallest * secondSmallest);
    }
};