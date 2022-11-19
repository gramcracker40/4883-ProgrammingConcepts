#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int minDistance(int dist[], bool sptSet[], int numServers) {

  int min = INT_MAX, min_index;

  for (int v = 0; v < numServers; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;

  return min_index;
}

void printSolution(int dist[], int numServers, int source, int endServer) {
  
  int minimum = dist[endServer];

  if(minimum == INT_MAX)
    cout << "Unreachable" << endl; 
  else
    cout << minimum << endl;
  
}

void dijkstra(vector<vector<int>> graph, int src, int numServers, int dist[], int endServer) {
  
  bool sptSet[numServers]; 

  for (int i = 0; i < numServers; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dist[src] = 0;

  for (int count = 0; count < numServers - 1; count++) {

    int u = minDistance(dist, sptSet, numServers);

    sptSet[u] = true;

    for (int v = 0; v < numServers; v++)
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v])
        dist[v] = dist[u] + graph[u][v];
  }
  printSolution(dist, numServers, src, endServer);
}

int main() {
  int testC, numServers, startSer, endSer, numPaths, hopStart, hopEnd, dist;
  vector<vector<int>> edges;

  cin >> testC;

  while (testC--) {
    cin >> numServers >> numPaths >> startSer >> endSer;

    for (int n = 0; n < numServers; n++) {
      vector<int> temp(numServers);
      edges.push_back(temp);
    }

    for (int i = 0; i < numPaths; i++) {
      cin >> hopStart >> hopEnd >> dist;
      edges[hopStart][hopEnd] = dist;
      edges[hopEnd][hopStart] = dist;
    }

    int dist[numServers];
    dijkstra(edges, startSer, numServers, dist, endSer);

    edges.clear();
  }
}
