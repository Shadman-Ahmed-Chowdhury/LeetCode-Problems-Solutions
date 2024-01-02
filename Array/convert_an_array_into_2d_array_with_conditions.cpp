// Problem link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description

// My solution:
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector <int> counter(nums.size() + 1);

        vector<vector <int>> res;

        for(int i = 0; i < nums.size(); i++) {
            if(counter[nums[i]] >= res.size())
                res.push_back({});
            res[counter[nums[i]]].push_back(nums[i]);
            counter[nums[i]]++;
        }

        return res;
    }
};