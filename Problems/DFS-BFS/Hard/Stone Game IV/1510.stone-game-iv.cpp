/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution {
public:
    bool winnerSquareGame(int n) {
        if( checkSq(n) ) return true;
        
        if( dp[n] >= 0 ) return dp[n];
        bool win = false;
        for( int i = 1; i*i <= n; ++i){
            if( !winnerSquareGame( n - i*i ) ){
                win = true;
                break;
            }
        }
        
        return dp[n] = win;
        
    }
    bool checkSq( int n){
        return ( int(sqrt(n)) * int(sqrt(n)) == n );
    }
private:
    vector<int> dp = vector(100001, -1);
    
};
// @lc code=end

