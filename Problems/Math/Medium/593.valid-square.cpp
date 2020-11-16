/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 *
 * https://leetcode.com/problems/valid-square/description/
 *
 * algorithms
 * Medium (43.36%)
 * Likes:    306
 * Dislikes: 462
 * Total Accepted:    40K
 * Total Submissions: 92.2K
 * Testcase Example:  '[0,0]\n[1,1]\n[1,0]\n[0,1]'
 *
 * Given the coordinates of four points in 2D space, return whether the four
 * points could construct a square.
 * 
 * The coordinate (x,y) of a point is represented by an integer array with two
 * integers.
 * 
 * Example:
 * 
 * 
 * Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
 * Output: True
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal
 * angles (90-degree angles).
 * Input points have no order.
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> square = {p1, p2, p3, p4};
        set<vector<int>> se;
        se.insert(p1);
        se.insert(p2);
        se.insert(p3);
        se.insert(p4);
        if( se.size() < 4 ) return false;
        sort( square.begin(), square.end(), []( const vector<int>& f, const vector<int>& s ){ return f[0] < s[0]; } );

        if( square[0][0] == square[1][0] ){
            if( square[0][1] > square[1][1] ) swap( square[0], square[1] );
        }
        if( square[2][0] == square[3][0] ){
            if( square[2][1] > square[3][1] ) swap( square[2], square[3] );
        }
        ll l1 = CalLen( square[0][0], square[0][1], square[1][0], square[1][1] );
        ll l2 = CalLen( square[0][0], square[0][1], square[2][0], square[2][1] );
        ll l3 = CalLen( square[3][0], square[3][1], square[1][0], square[1][1] );
        ll l4 = CalLen( square[3][0], square[3][1], square[2][0], square[2][1] );

        if( l1 != l2 || l3 != l4 || l2 != l3 ) return false;

        ll diagonal1 = CalLen( square[1][0], square[1][1], square[2][0], square[2][1] );
        ll diagonal2 = CalLen( square[0][0], square[0][1], square[3][0], square[3][1] );

        if( l1 + l2 != diagonal1 || l3 + l4 != diagonal1 ) return false;
        if( l1 + l3 != diagonal2 || l2 + l4 != diagonal2 ) return false;

        return true;
    }
    ll CalLen( int x1, int y1, int x2, int y2 ){
        return ll(pow( x1 - x2, 2 ) + pow( y1 - y2, 2 ));
    }
};

// @lc code=end

