/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if( !poured ) return 0.0;
        
        float dp[101][101] = {0.0};
        
        dp[0][0] = float(poured);
        
        for( int row = 0; row <= query_row; ++row ){
            for( int col = 0; col <= row; ++col ){
                float div = ( dp[row][col] - 1.0 ) / 2.0;
                if( div > 0.0 ){
                    dp[row + 1][col] += div;
                    dp[row + 1][col+1] += div;
                }
            }
        }
        return dp[query_row][query_glass] > 1.0 ? 1.0 : dp[query_row][query_glass];
        
    }
};
// @lc code=end

