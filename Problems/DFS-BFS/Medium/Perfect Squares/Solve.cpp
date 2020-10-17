class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> tra;
        unordered_map<int,int> vis;
        int k=1;
        while(pow(k,2)<=n){
            if(!(n-pow(k,2))) return 1;
            tra.push({n-pow(k,2),k});
            k++;
        }
        
        int cnt=0;
        
        while(!tra.empty()){
            cnt+=1;
            int size=tra.size();
            
            for(int i=0;i<size;++i){
                pair<int,int> crr=tra.front();
                if(!crr.first) return cnt;
                for(int j = crr.second;pow(j,2)<=crr.first;++j){
                    if(!(crr.first-pow(j,2))) return cnt+1;
                    tra.push({crr.first-pow(j,2),j});
                }
                tra.pop();
            }
        }
        return -1;
    }
};