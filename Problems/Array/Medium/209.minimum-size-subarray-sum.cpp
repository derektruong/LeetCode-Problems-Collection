/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (38.70%)
 * Likes:    3001
 * Dislikes: 126
 * Total Accepted:    308.3K
 * Total Submissions: 793.6K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 * 
 * Example: 
 * 
 * 
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if( nums.empty() ) return 0;
        if( nums.size() < 2 ) return nums[0] >= s ? 1 : 0;
        set<int> se;
        int i_st = 0, i_en = 1;
        if( nums[0] >= s || nums.back() >= s ) return 1;
        
        int sum = nums[0] + nums[1], len = 2;
        
        if( nums[i_st] + nums[i_en] >= s ) return 2;
        
        while( true ){
            while( sum < s ){
                i_en++;
                
                if( i_en >= nums.size() ){
                    i_en = nums.size() - 1;
                    break;  
                }
                
                sum += nums[i_en];
                len++; 
                
            }
            if( sum >= s )
                se.insert( len);
            if( sum < s ) break;
            while( sum >= s ){
                if( i_st == i_en ) break;
                sum -= nums[i_st];
                i_st++;
                len--;
                if( sum >= s ) se.insert(len);
                
            }
            
            if( i_st == i_en && nums[i_st] >= s ) return 1;
            if( i_st == nums.size() - 2 ) break;
        }
        
        return se.empty() ? 0 : *se.begin();
        
    }
};
// @lc code=end

