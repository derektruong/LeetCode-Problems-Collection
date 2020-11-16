/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (47.35%)
 * Likes:    2368
 * Dislikes: 67
 * Total Accepted:    391.6K
 * Total Submissions: 820.5K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<int> status(len);
        vector<int> sub;
        
        set<string> vis;

        backTrack(nums, sub, vis, status, 0, "");

        return res;

    }

    void backTrack( vector<int> nums, vector<int> sub, set<string>& vis, vector<int> status, int cnt, string sum){
        if( cnt == nums.size() && vis.find(sum) == vis.end() ){
            vis.insert(sum);
            res.push_back( sub );
            return;
        }

        for( int i = 0; i < nums.size(); ++i ){
            if( !status[ i ] ){
                status[ i ] = 1;
                sub.push_back(nums[i]);
                string num = nums[i] < 0 ? "-" + to_string(abs(nums[i]) + 48) : to_string(abs(nums[i]) + 48);
                backTrack( nums, sub, vis, status, cnt + 1, sum + num );
                status[ i ] = 0;
                sub.pop_back();
            }
        }
    }

    vector<vector<int>> res;

};
// @lc code=end

