/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (34.62%)
 * Likes:    3048
 * Dislikes: 615
 * Total Accepted:    424.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;
        int row = matrix.size(), col = matrix[0].size();
        int aboveCover = 1, rightCover = col - 1, bottomCover = row - 1, leftCover = 0;

        int r = 0, c = 0, cnt = 0;
        int dim = 1; // 1 Right, 2 Down, 3 Left, 4 Up
        if( col == 1 ){
            for( int i = 0; i < row; ++i ) res.push_back(matrix[i][0]);
            return res;
        }
        while( cnt < row * col ){
            res.push_back( matrix[r][c] );
            
            if( dim == 1 ){
                c++;
                if( c == rightCover ){
                    dim = 2;
                    rightCover--;
                }
            }
            else if( dim == 2 ){
                r++;
                if( r == bottomCover ){
                    dim = 3;
                    bottomCover--;
                }
            }
            else if( dim == 3 ){
                c--;
                if( c == leftCover ){
                    dim = 4;
                    leftCover++;
                }
            }
            else if( dim == 4 ){
                r--;
                if( r == aboveCover ){
                    dim = 1;
                    aboveCover++;
                }
            }
            
            cnt++;
        }

        return res;

    }
};
// @lc code=end

