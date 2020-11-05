/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
#define MAX 100001
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        int mini;
        for( int i = 1; i < row; ++i){
            for( int j = 0; j < col; ++j ){
                 
                mini = min( A[i-1][j], (j-1 < 0 ? MAX : A[i-1][j-1]) );
                mini = min( mini, (j+1 >= row ? MAX : A[i-1][j+1]) );
                A[i][j] += mini;
            }
        }
        mini = MAX;
        for( int j = 0; j < col; ++j ){
            mini = A[row-1][j] < mini ? A[row-1][j] : mini;
        }
        return mini;
    }
};
// @lc code=end

