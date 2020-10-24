/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector< vector< int > > con = { {A[0]}, {B[0]}, {B[0]}, {A[0]} };
        vector< int > res = {0, 1, 0, 1};
        vector< bool > check( 4, true );

        for( int i = 1; i < A.size(); ++i ){
            if( check[0] ){
                if( A[i] != con[0][0] ){
                    if( B[i] == con[0][0] ){
                        res[0]++;
                    }
                    else check[0] = false;
                }
            }
            if( check[1] ){
                if( A[i] != con[1][0] ){
                    if( B[i] == con[1][0] ){
                        res[1]++;
                    }
                    else check[1] = false;
                }
            }
            if( check[2] ){
                if( B[i] != con[2][0] ){
                    if( A[i] == con[2][0] ){
                        res[2]++;
                    }
                    else check[2] = false;
                }
            }
            if( check[3] ){
                if( B[i] != con[3][0] ){
                    if( A[i] == con[3][0] ){
                        res[3]++;
                    }
                    else check[3] = false;
                }
            }
            
        }
        
        int min = 20002;
        for( int i = 0; i < 4; ++i ){
            if( check[i] && res[i] < min ) min = res[i];
        }
        
        return min == 20002 ? -1 : min;
    }
};
// @lc code=end

