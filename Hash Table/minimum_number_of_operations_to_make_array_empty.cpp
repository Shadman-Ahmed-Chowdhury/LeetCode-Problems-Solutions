// Problem link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

// My soluton:
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map <int, int> counter;
        for (int num : nums) {
            counter[num]++;
        }
        int res = 0;
        for(auto itr : counter) {
            int count = itr.second;
            if (count == 1) {
                return -1;
            }
            res += count / 3;
            if(count % 3)
                res++;
        }
        return res;
    }
};