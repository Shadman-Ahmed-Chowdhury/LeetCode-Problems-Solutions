class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector <int> result;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            result.push_back(sum);
        }
        int left_sum, right_sum, pivot_index = -1;
        for(int i = 0; i < result.size(); i++) {
            if(i == 0) {
                left_sum = 0;
                right_sum = result[result.size() - 1] - result[i];
            } else if(i == result.size() - 1) {
                right_sum = 0;
                left_sum = result[i - 1];
            } else {
                left_sum = result[i - 1];
                right_sum = result[result.size() - 1] - result[i];
            }
            if(left_sum == right_sum) {
                pivot_index = i;
                break;
            }

        }
        return pivot_index;
    }
};