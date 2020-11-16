/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (64.78%)
 * Likes:    4765
 * Dislikes: 115
 * Total Accepted:    693.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> status(1000001), sub;

        int min = abs(*min_element(nums.begin(), nums.end()));
        backTrack(nums, sub, status, 0, min);

        return res;

    }

    void backTrack(vector<int> nums, vector<int>& sub,vector<int>& status, int cnt, int min){
        if( cnt == nums.size() ){
            res.push_back(sub);
            return;
        }

        for( int i = 0; i < nums.size(); ++i ){
            if( !status[nums[i] + min] ){
                sub.push_back(nums[i]);
                status[nums[i] + min] = 1;
                backTrack( nums, sub, status, cnt + 1, min );
                status[nums[i] + min] = 0;
                sub.pop_back();
            }
            
        }

    }
    vector<vector<int>> res;
};
// @lc code=end

