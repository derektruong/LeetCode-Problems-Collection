/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> clip(n + 1);
        int crr = 1, res = 0;
        for( int i = 2; i <= n; ++i ){
            //Try copy if possible
            if((n - crr) % crr == 0){
                clip[i] = crr;
                res++;
            }
            else clip[i]  = clip[i - 1]; 
            
            //Try paste
            crr += clip[i];
            res++; 
            if( crr == n ) break;
        }
        return res;
    }
};
// @lc code=end

