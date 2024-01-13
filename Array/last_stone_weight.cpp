// Problem link: https://leetcode.com/problems/last-stone-weight/

// My solution:
class Solution {
public:
    int lastStoneWeight(vector <int>& stones)
    {
        if(stones.size() == 1)
            return stones[0];
        for(int i = 0; i < stones.size(); i++) {
            sort(stones.begin(), stones.end(), greater <int>());
            stones[0] = stones[0] - stones[1];
            stones[1] = 0;
        }
        if(stones[0] > 0)
            return stones[0];
        else
            return 0;
    }
};