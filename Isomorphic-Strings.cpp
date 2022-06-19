class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        map <char, char> mp;
        map <char, char> mp1;

        for(int i = 0; i < s.size(); i++) {
             if(mp.count(s[i]) == 0 && mp1.count(t[i]) == 0) {
                mp[s[i]] = t[i];
                mp1[t[i]] = s[i];
                //cout << mp[s[i]] << endl;
            } else {
                if(mp[s[i]] != t[i] || mp1[t[i]] != s[i]) {
                   return false;
                }
            }
        }
        return true;
    }
};