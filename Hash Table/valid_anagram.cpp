// Problem link: https://leetcode.com/problems/valid-anagram/description/

// My solution: 
class Solution {
public:
    bool isAnagram(string s, string t) {
        // O(nlogn)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        // O(n)
        if (s.length() != t.length()) {
            return false;
        }
        int counter[26] = {0};
        for(int i = 0 ; i < s.length(); i++) {
            counter[s[i] - 'a']++;
            counter[t[i] - 'a']--;
        }
        for(int val : counter) {
            if(val != 0) 
                return false;
        }
        return true;
    }
};