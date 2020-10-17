class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if( s.size() <= 10 ) return {};
        unordered_map< string, int > sub;
        vector<string> res;
        
        for( int i = 0; i < s.size() - 9; ++i ){
            if( sub.find(s.substr( i, 10 )) == sub.end() ){
                sub[s.substr( i, 10 ) ] = 0;
            }
            else{
                if( !sub[s.substr( i, 10 ) ] ){
                    res.push_back(s.substr( i, 10 ));
                    sub[s.substr( i, 10 ) ]++;
                }  
            } 
        }
        
        return res; 
    }
};