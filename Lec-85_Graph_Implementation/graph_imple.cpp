#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
public:
        unordered_map<int,list<int>>adj;

        void buildEdges(int u, int v , bool direction ){
        //   direction  directed -> 1
        //   undirection  directed -> 0
            
            adj[u].push_back (v);
            
            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printGraph(){
              
              for(auto i: adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
              }
              
        }
         
};

int main(){
     int n ,m;
    cout<<"Enter the number of Nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of Edges"<<endl;
    cin>>m;
graph g;
 cout<<"Enter the Edges"<<endl;
 
    for(int i =0 ; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.buildEdges(u,v,0);
    }
    g.printGraph();
    return 0;

}