/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort( tokens.begin(), tokens.end() );
        
        int score = 0, max = 0, i = 0;
        while( i < tokens.size() ){
            if( P >= tokens[i]  ){
                score++;
                if( score > max ) max = score;
                
                P -= tokens[i];
            }
            
            else if( P < tokens[i] && score > 0 ){
                P += tokens[ tokens.size() - 1 ];
                tokens.pop_back();
                score--;
                continue;
            }
            else return max;
            
            ++i;
            
        }
        
        return max;
    }
};
// @lc code=end

