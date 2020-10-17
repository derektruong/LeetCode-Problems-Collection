//BFS
/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size()) return 0;
        queue<pair<int,int>> tra;
        set<pair<int,int>> vis;//visited
        
        for(int i=0;i<grid.size();++i){
            grid[i].push_back('0');
            grid[i].insert(grid[i].begin(),'0');
        }
        vector<char> ne(grid[0].size(),'0');
        grid.push_back(ne);
        grid.insert(grid.begin() , ne);
        
        
        int step=0,row=grid.size(),col=grid[0].size();
        for(int i=1;i<row-1;++i){
            for(int j=1;j<col-1;++j){
                if(vis.find({i,j}) == vis.end() && grid[i][j]=='1'){
                    tra.push({i,j});
                    step+=1;
                    while(!tra.empty()){
                        pair<int,int> crr=tra.front();
                        int fi=crr.first,se=crr.second;
                        if(grid[fi-1][se]=='1' && vis.find({fi-1,se}) == vis.end()){
                            tra.push({fi-1,se}); 
                            vis.insert({fi-1,se});
                        } 
                        if(grid[fi+1][se]=='1' && vis.find({fi+1,se}) == vis.end()){
                            tra.push({fi+1,se}); 
                            vis.insert({fi+1,se});
                        } 
                        if(grid[fi][se-1]=='1' && vis.find({fi,se-1}) == vis.end()){
                            tra.push({fi,se-1}); 
                            vis.insert({fi,se-1});
                        }
                        if(grid[fi][se+1]=='1' && vis.find({fi,se+1}) == vis.end()){
                            tra.push({fi,se+1}); 
                            vis.insert({fi,se+1});
                        }
                        tra.pop();
                    }
                }
            }
        }
        return step;
    }

};*/
//DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nums=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1')
                    nums+=dfs(i,j,grid);
            }
        }
        return nums;
    }
    int dfs(int x, int y, vector<vector<char>>& grid){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0'){
            return 0;
        }
        grid[x][y]='0';
        dfs(x-1,y,grid);
        dfs(x+1,y,grid);
        dfs(x,y-1,grid);
        dfs(x,y+1,grid);
        return 1;
    }
};