//BFS
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int> has;
        set<string> vis;
        for(int i=0;i<deadends.size();++i){
            has[deadends[i]]=1;
        }
        if(has.find("0000") != has.end()) return -1;
        queue<string> tra;
        
        int step=-1;
        
        tra.push("0000");
        vis.insert("0000");
        
        while(!tra.empty()){
            step+=1;
            
            int size=tra.size();
            
            for(int i=0;i<size;++i){
                string crr=tra.front();
                if(crr==target) return step;
                char k=crr[0],l=crr[1],m=crr[2],n=crr[3];
                int a=int(k)-48+1,b=int(l)-48+1,c=int(m)-48+1,d=int(n)-48+1;
                a=a==10?0:a;
                b=b==10?0:b;
                c=c==10?0:c;
                d=d==10?0:d;
                string temp=crr;
                temp.replace(0,1,std::to_string(a));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                
                temp=crr;
                temp.replace(1,1,std::to_string(b));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                temp=crr;
                temp.replace( 2, 1,std::to_string(c) );
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                temp=crr;
                temp.replace(3,1,std::to_string(d));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                
                a=int(k)-48-1,b=int(l)-48-1,c=int(m)-48-1,d=int(n)-48-1;
                a=a==-1?9:a;
                b=b==-1?9:b;
                c=c==-1?9:c;
                d=d==-1?9:d;
                temp=crr;
                temp.replace(0,1,std::to_string(a));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                temp=crr;
                temp.replace(1,1,std::to_string(b));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                temp=crr;
                temp.replace(2,1,std::to_string(c));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                temp=crr;
                temp.replace(3,1,std::to_string(d));
                if(has.find(temp) == has.end() && vis.find(temp) == vis.end()){ 
                    tra.push(temp);
                    vis.insert(temp);
                }
                tra.pop();
            }
            
        }
        return -1;
    }
};