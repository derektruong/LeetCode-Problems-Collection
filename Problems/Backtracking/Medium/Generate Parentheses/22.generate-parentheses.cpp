/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if( n == 1 ) return{"()"};
        string s = "(";
        vector<char> check(n*n, '0');
        size = n;
        helper(check, s, 1, n - 1, n);
        return res;
    }

    void helper(vector<char> check, string& s, int crr, int st_par, int en_par ){
        if( en_par < st_par || st_par < 0 ) return;
        if( crr == size * 2 && !en_par){
            res.push_back(s);
            s.clear();
            return;
        }

        for(int i = 0; i < str.size(); ++i){
            string tmp;
            int a = str[i] == '(' ? st_par - 1 : st_par;
            int b = str[i] == ')' ? en_par - 1 : en_par;
            if( check[crr] != str[i] ){
                check[crr] = str[i];
                tmp = s + str[i];
                helper(check, tmp, crr + 1, a, b);
                check[crr] = '0';
            }
        }

    }

    int size;
    string str = "()";
    vector<string> res;
};
// @lc code=end

