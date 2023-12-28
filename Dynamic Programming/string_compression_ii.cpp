// Problem link: https://leetcode.com/problems/string-compression-ii/description

// My solution:
int dp[101][27][101][101] ; 
class Solution {
public:

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size() ; 
        memset(dp , -1, sizeof(dp)) ;
        return helperFunction(s, 0, 26, k, 0) ;
    }
private:
    int helperFunction(string& s, int index, int prev, int k, int count){
        if(k < 0) 
            return 1e9 ;

        if(index >= s.size()){
           return 0 ;
        }
        if(dp[index][prev][k][count] != -1){
            return dp[index][prev][k][count] ;
        }
        int res = INT_MAX ;
        int del = helperFunction(s, index+1, prev, k-1, count) ; 

        if(prev + 'a' == s[index]){
            if(count == 1 || count == 9 || count == 99){
                res =  1 + helperFunction(s, index+1, prev, k, count+1) ; 
            }
            else{
                res =  helperFunction(s, index+1, prev, k, count+1) ; 
            }
        }
        else{
            res =  1 + helperFunction(s, index+1, s[index] - 'a', k, 1) ; 
        }

        
        return dp[index][prev][k][count] = min(del, res) ;
    }
};