// Problem link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/

// My solution:
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        vector <int> counts(26, 0);

        for(char ch : chars) {
            counts[ch - 'a']++;
        }
        
        for(string word : words) {
            vector <int> c(26, 0);
            int flag = 1;
            for(char ch : word) {
                int x = ch - 'a';
                c[x]++;
                if(c[x] > counts[x]) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) 
                res += word.length();
        }
        return res;
    }
};