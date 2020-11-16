/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (44.53%)
 * Likes:    1386
 * Dislikes: 275
 * Total Accepted:    161.4K
 * Total Submissions: 361.4K
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, write a method that returns the "pivot"
 * index of this array.
 * 
 * We define the pivot index as the index where the sum of all the numbers to
 * the left of the index is equal to the sum of all the numbers to the right of
 * the index.
 * 
 * If no such index exists, we should return -1. If there are multiple pivot
 * indexes, you should return the left-most pivot index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the
 * sum of numbers to the right of index 3.
 * Also, 3 is the first index where this occurs.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem
 * statement.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of nums will be in the range [0, 10000].
 * Each element nums[i] will be an integer in the range [-1000, 1000].
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len = nums.size();
        if( !len ) return -1;
        if( len == 1 ) return 0;
        if( len == 2 && nums[0] && nums[1] ) return -1;
        vector<int> left(len), right(len);

        int l = 0, r = len - 1;
        while( l < len ){
            left[l] = l == 0 ? nums[l] : left[l - 1] + nums[l];
            right[r] = r == len - 1 ? nums[r] : right[r + 1] + nums[r];
            l++; r--;
        }
        if( !right[1] ) return 0;
        
        for( int i = 1; i < len - 1; ++i ){
            if( left[i - 1] == right[i + 1] ) return i;
        }
        
        if( !left[len - 2] ) return len - 1;

        return -1;

    }
};
// @lc code=end

