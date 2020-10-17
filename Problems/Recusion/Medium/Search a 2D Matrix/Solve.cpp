class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.empty() || matrix[0].empty() ) return false;
        
        int res = FindRow( matrix, target, 0, matrix.size() - 1 );
        
        if( res < 0 ) return false;
        for( int i = 0; i < matrix[0].size(); ++i ){
            if( matrix[res][i] == target ) return true; 
        }
        return false;
    }
    
    int FindRow( vector<vector<int>>& matrix, int target, int low, int hei){
        
        if( low <= hei ){
            int mid = low + ( hei - low ) / 2;
            if( target >= matrix[mid][0] && target <= matrix[mid][ matrix[0].size() - 1 ] )
                return mid;
            else if( target <= matrix[mid][0] ) 
                return FindRow( matrix, target, low, mid - 1 );
            return FindRow( matrix, target, mid + 1, hei );
        }
        return -1;
        
    }
};