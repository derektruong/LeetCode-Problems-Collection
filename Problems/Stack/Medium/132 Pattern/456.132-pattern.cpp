/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        stack <int> st;
        int second =  INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < second)
                return true;
            while (st.size() > 0 && nums[i] > st.top()){
                second = st.top ();
                st.pop();
            }
                
            st.push(nums[i]);
        }
        return false;
        
    }
};
// @lc code=end

