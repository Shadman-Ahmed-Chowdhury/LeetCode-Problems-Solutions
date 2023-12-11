// Problem link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

// My solution: 
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map <int, int> counter;
        int n = arr.size();
        int limit = n / 4;
        for(int i = 0; i < n; i++) {
            counter[arr[i]]++;
            if(counter[arr[i]] > limit) {
                return arr[i];
            }
        }
        return 0;
    }
};