// Problem link: https://leetcode.com/problems/find-the-difference-of-two-arrays/

// My Solution:
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map <int, int> counter;
        for(int n : nums1) {
            if(!counter.count(n)) 
                counter[n] = 1;
            else {
                auto found = find(nums2.begin(), nums2.end(), n);
                if(found != nums2.end())
                    counter[n] = -1;
            }
        }
        for(int n : nums2) {
            if(!counter.count(n)) 
                counter[n] = 2;
            else {
                auto found = find(nums1.begin(), nums1.end(), n);
                if(found != nums1.end())
                    counter[n] = -1;
            }
                
        }
        vector <vector<int> > answer(2);
        for(auto itr : counter) {
            if(itr.second > 0) {
                answer[itr.second - 1].push_back(itr.first);
            }
        }
        return answer;
    }
};