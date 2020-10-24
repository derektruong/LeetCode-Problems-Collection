/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> res = { asteroids[0] };

        for(int i = 1; i < asteroids.size(); ++i){
            if( res.empty() || check( res[res.size() - 1], asteroids[i] ) == 2 ) {
                res.push_back(asteroids[i]);
                continue;
            }
            else if( check( res[res.size() - 1], asteroids[i] ) == 1 ){
                continue;
            }
            else if( check( res[res.size() - 1], asteroids[i] ) == 0 ){
                res.pop_back();
                continue;
            }
            
            int crr =  asteroids[i];
            while( !res.empty() ){
                int flag = 0;
                
                int ch = check( res[res.size() - 1], crr );
                switch( ch ){
                    case -1:
                        flag = -2;
                        res.pop_back();
                        break;
                    case 0:
                        flag = -1;
                        break;
                    case 1:
                        flag = 1;
                        break;
                    case 2:
                        flag = 2;
                        break;

                }

                if( flag == -1 ) {
                    res.pop_back();
                    break;
                }
                if( flag == 1 ) {
                    break;
                }
                if( flag == 2 || (flag == -2 && res.empty()) ) {
                    res.push_back(crr);
                    break;
                }

            }
            
        }

        return res;
        
    }

    int check( int left, int right ){//2: No change, 1: remove right, 0: left + right = 0, -1: remove left
        if( left * right <= 0 ) {
            
            if( right >= 0 ) return 2;
            if( left + right == 0 ) return 0;
            else {

                if( abs(right) < abs(left) ) 
                    return 1;
                else return -1;
            }
        }

        return 2;
    }
};
// @lc code=end

