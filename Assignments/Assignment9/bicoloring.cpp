#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;

//works only with adjacency lists
bool isBipartite(int V, vector<vector<int>> adj)
{
    //will holds colors of vertex, initialize all values to -1
    vector<int> col(V, -1);
 
    // queue for BFS storing {vertex , colour}
    queue<pair<int, int> > q;
   
      //loop incase graph is not connected
    for (int i = 0; i < V; i++) {
       
      //if not coloured
        if (col[i] == -1) {
           
          //colouring with 0 i.e. red
            q.push({ i, 0 });
            col[i] = 0;
           
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
               
                  //current vertex
                int v = p.first;
                  //colour of current vertex
                int c = p.second;
                 
                  //traversing vertexes connected to current vertex
                  //c++11 added the for loop below, range based. will run over
                  //every element in this specific vector. 
                for (int j : adj[v]) {
                   
                      //if already coloured with parent vertex color
                      //then bipartite graph is not possible
                    if (col[j] == c)
                        return 0;
                   
                      //if uncoloured
                    if (col[j] == -1) {
                      //colouring with opposite color to that of parent
                        col[j] = (c) ? 0 : 1;
                        q.push({ j, col[j] });
                    }
                }
            }
        }
    }
    //if all vertexes are coloured such that
    //no two connected vertex have same colours
    return 1;
}

int main() {
    
    int nodes, edges, counter = 0, v1 = 0, v2 = 0;
     
    
    while(nodes != 0){
      cin >> nodes; 
      
      if(nodes == 0)
        exit(0);
      
      cin >> edges; 
  
      vector<vector<int>> adj;

      //initializing each nodes, vector to store the edges
      for(int i = 0; i < nodes; i++){
        vector<int> place; 
        adj.push_back(place);
      }

      //pulling in the individual edges and 
      //placing in a 2D vector
      for(int i = 0; i < edges; i++) {
          cin >> v1 >> v2;
          adj[v1].push_back(v2);
          adj[v2].push_back(v1);
      }
  
      if(isBipartite(nodes, adj))
        cout << "BICOLORABLE." << endl; 
      else
        cout << "NOT BICOLORABLE." << endl;
  
    }
}
