/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 *
 * https://leetcode.com/problems/diagonal-traverse/description/
 *
 * algorithms
 * Medium (48.73%)
 * Likes:    917
 * Dislikes: 358
 * Total Accepted:    97.2K
 * Total Submissions: 198.7K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of M x N elements (M rows, N columns), return all elements of
 * the matrix in diagonal order as shown in the below image.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * Output:  [1,2,4,7,5,3,6,8,9]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The total number of elements of the given matrix will not exceed 10,000.
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size(), col = matrix[0].size();
        int f_row = 0, f_col = 0;
        int s_row = 0, s_col = 0;

        bool UpDown = true;
        while( f_row < row || f_col < col ){
            
            if( UpDown ){
               int i = f_row, j = f_col;
               while( i != s_row && j != s_col ){
                   res.push_back( matrix[i][j] );
                   i--; j++;
               } 
               res.push_back( matrix[i][j] );
            }
            else{
                int i = s_row, j = s_col;
                while( i != f_row && j != f_col ){
                    res.push_back( matrix[i][j] );
                    i++; j--;
                } 
                res.push_back( matrix[i][j] );
            }

            UpDown = !UpDown;
            f_row += f_row == row - 1 ? 0 : 1;
            f_col += f_row == row - 1 ? 1 : 0;
            s_row += s_col == col - 1 ? 1 : 0;
            s_col += s_col == col - 1 ? 0 : 1;
        }      

        return res;
    }
};
// @lc code=end

