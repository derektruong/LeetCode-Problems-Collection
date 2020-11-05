/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lenDays = days.size();
        vector< int > dp( days[lenDays-1] + 1, 10000 );
        vector< int > pass = {1, 7, 30};
        dp[0] = 0;
        int cnt = 0;
        for(int i = 1; i <= days[lenDays-1]; ++i){
            if( i != days[cnt] ){
                dp[i] = dp[i-1];
                continue;
            }
            cnt++;
            for(int j = 0; j < costs.size(); ++j){
                
                dp[i] = min( dp[i], (i - pass[j] <= 0 ? 0 : dp[i - pass[j]]) + costs[j]) ;
                    
            }
        }
        return dp[days[lenDays-1]];
    }
};
// @lc code=end

