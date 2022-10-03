#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

//works only with adjacency lists
bool isBipartite(int V, vector<vector<int>> adj, vector<int>& col)
{   
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
  int testCases = 0, nodes = 0, edges = 0, v1, v2; 

  cin >> testCases; 

  while(testCases--){
    nodes = 0; edges = 0; v1 = 0, v2 = 0;
    cin >> nodes >> edges;
    
    //preparing the adjacency list to receive edges
    vector<vector<int>> adj;
    for(int n = 0; n < nodes; n++){
      vector<int> temp;
      adj.push_back(temp);
    }
  
    //pulling in the individual edges and assigning to adj list
    for(int i = 0; i < edges; i++){
      cin >> v1 >> v2;
      adj[v1].push_back(v2);
      adj[v2].push_back(v1);
    }

    cout << endl << endl; 
    
    vector<int> col(nodes, -1);
    int red = 0, blue = 0, guards;
    
    if(isBipartite(nodes, adj, col)){
      //loop through colors and find the number of each color
      for(int i = 0; i < nodes; i++){
        if(col[i] == 0)
          red++;
        else if(col[i] == 1)
          blue++;
      }
      //make guards required the one with fewer guards
      guards = (red >= blue) ? blue : red;
      //dealing with cases where blue=0 and red=1 or vice versa
      if(red == 0)
        guards = blue; 
      if(blue == 0)
        guards = red;
      cout << guards << endl;
    }
    else
      cout << "-1" << endl;
    
  }
}
