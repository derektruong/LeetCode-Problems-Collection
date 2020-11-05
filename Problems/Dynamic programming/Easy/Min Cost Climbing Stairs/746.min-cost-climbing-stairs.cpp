/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector< int > dp( len + 1, 0 );
        dp[0] = cost[0]; dp[1] = cost[1];
        for( int i = 2; i <= len; ++i ){
            dp[i] = min( dp[i-1], dp[i-2] ) + ( i == len ? 0 : cost[i] );
        }
        
        return dp[len];
    }
};
// @lc code=end

