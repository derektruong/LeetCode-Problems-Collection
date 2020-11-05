/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        solve(n, k, 1, sub, res);
        return res;
    }

    void solve(int n, int k, int crr, vector<int>& sub,vector<vector<int>>& res ){
        if( !k ){
            res.push_back(sub);
            return;
        }
        if( k < 0 ) return;

        for(int i = crr; i <= n; ++i){
            sub.push_back(i);
            solve(n, k - 1, i + 1, sub, res);
            sub.pop_back();
        }
    }
};
// @lc code=end

