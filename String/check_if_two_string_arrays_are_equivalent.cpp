// Problem link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// My Solution: 

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = "";
        string w2 = "";
        for (int i = 0; i < word1.size(); i++) {
            w1 += word1[i];
        }
        for (int i = 0; i < word2.size(); i++) {
            w2 += word2[i];
        }
        return (w1 == w2) ? true : false;
    }
};