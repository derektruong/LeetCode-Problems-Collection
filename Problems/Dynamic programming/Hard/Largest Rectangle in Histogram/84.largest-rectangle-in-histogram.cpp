/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if( heights.empty() ) return 0;
        int len = heights.size();
        vector<int> lessLeft(len);
        vector<int> lessRight(len);
        
        lessLeft[0] = -1;
        lessRight[len - 1] = len;

        for (int i = 1; i < len; ++i){
            if( heights[i] > heights[i - 1] )
                lessLeft[i] = i - 1;
            else{
                int j = i - 1;
                while( j >= 0 && heights[j] >= heights[i]) j = lessLeft[j];
                lessLeft[i] = j;
            }
        }   

        for (int i = len - 2; i >= 0; --i){
            if( heights[i] > heights[i + 1] )
                lessRight[i] = i + 1;
            else{
                int j = i + 1;
                while( j < len && heights[j] >= heights[i]) j = lessRight[j];
                lessRight[i] = j;
            }
        } 

        int maxi = 0;

        for(int i = 0; i < len; ++i){
            maxi = max( maxi, heights[i] * ( lessRight[i] - lessLeft[i] - 1 ) );
        }

        return maxi;
    }
};
// @lc code=end

