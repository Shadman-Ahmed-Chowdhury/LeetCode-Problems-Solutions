// Problem link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/

// My solution:
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        if(n == 1) {
            return true;
        }
        map <char, int> counter;
        int totalCharacters = 0;
        for(int i = 0; i < n; i++) {
            string str = words[i];
            totalCharacters += str.length();
            for(int j = 0; j < str.length(); j++) {
                counter[str[j]]++;
            }
        }
        if(totalCharacters % n != 0) {
            return false;
        }
        for(auto itr : counter) {
            if(itr.second % n != 0) {
                return false;
            }
        }
        return true;
    }
};