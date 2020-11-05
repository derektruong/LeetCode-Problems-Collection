class Solution {
public:
    int rob(vector<int>& nums) {
        if( nums.size() == 1 ) return nums[0];
        if( nums.size() == 2 ) return max( nums[0], nums[1] );
        int len = nums.size();
        
        vector<int> dp1(len - 1, 0);
        vector<int> dp3(len - 2, 0);
        vector<int> dp2(len, 0);
        
        bool check = false;
        //F

        dp1[0] = nums[0];
        dp1[1] = nums[0];   
        for( int i = 2; i < len - 1; ++i ){
            dp1[i] = max( dp1[ i - 1 ], dp1[ i - 2 ] + nums[i] );
        } 
        
        if( len > 3 ){
            dp3[0] = nums[len - 1];
            dp3[1] = nums[len - 1];

            for( int i = 2; i < len - 2; ++i ){
                dp3[i] = max( dp3[ i - 1 ], dp3[ i - 2 ] + nums[i] );
            }  
        }
        
        //S
        dp2[0] = nums[0];
        dp2[1] = nums[1];
        if( len >= 3 ) dp2[2] = nums[1];
        
        for( int i = 3; i < len; ++i ){
            dp2[i] = max( dp2[ i - 1 ], dp2[ i - 2 ] + nums[i] );
        }
        
    
        return max( max(dp1[len - 2], dp3[len - 3]), dp2[len - 1]  );
  
    }
    
};