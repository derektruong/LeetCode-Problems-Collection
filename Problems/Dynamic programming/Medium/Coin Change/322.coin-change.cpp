/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector< ll > dp( amount + 1, INT_MAX);
        
        dp[0] = 0;
        for( ll i = 1; i <= amount; ++i ){
            for( ll j = 0; j < coins.size(); ++j ){
                ll mon = coins[j];
                if( i - mon >= 0 ){
                    dp[i] = min( dp[i], dp[i - mon] + 1 );
                }
            }
        }
        if( dp[amount] > 100001 ) return -1;
        return dp[amount];
    }
};
// @lc code=end

