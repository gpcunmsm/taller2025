#include<iostream>
#include<queue>
#include<vector>

#define SIZE 10
#define NOT_VISITED 1
#define EXPLORING 2
#define VISITED 3
using namespace std;

int AM[SIZE][SIZE];

void printPaths(vector<int> &parent, int s, int v) {
  if ( s == v ) {
    cout << s << ", ";
    return;
  }

  if ( parent[v] == -1 ) {
    cout << "no path" << endl;
    return;
  }

  printPaths(parent, s, parent[v]);
  cout << v << ", ";
}

void bfs(int source) {
  queue<int> Q;
  vector<int> colored(SIZE, NOT_VISITED);
  vector<int> dist(SIZE, -1);
  vector<int> parent(SIZE, -1);
  dist[source] = 0;
  colored[source] = EXPLORING;
  Q.push(source);
  while(!Q.empty()) {
    int u = Q.front();
    cout << "u: " << u << endl;
    for(int i=0; i<SIZE; i++) {
      if ( AM[u][i] == 0 ) continue;
      int v = i;
      cout << " adj v: " << v << endl;
      if( colored[v] == NOT_VISITED ) { // no visitado aun
        dist[v] = dist[u] + 1;
        parent[v] = u;
        colored[v] = EXPLORING;
        cout << " adding to the queue: " << v << endl;
        Q.push(v);
      }
      colored[u] = VISITED;
    }
    Q.pop();
  }


  cout << "distancias : ";
  for(int i=0; i<SIZE; i++) cout << "("<< i << ":" << dist[i] << ") ";
  cout << endl;

  cout << "colores : ";
  for(int i=0; i<SIZE; i++) cout << "("<< i << ":" << colored[i] << ") ";
  cout << endl;

  cout << "parents : ";
  for(int i=0; i<SIZE; i++) cout << "("<< i << ":" << parent[i] << ") " ;
  cout << endl;


  cout << "printing path" << endl;
  printPaths(parent, source, 7);
  cout << endl;
  printPaths(parent, source, 3);
  cout << endl;
  printPaths(parent, source, 9);
  cout << endl;
}

int main() {
  // manually setting the graph
  AM[0][1] = 1;
  AM[1][0] = 1;
  AM[0][5] = 1;
  AM[5][0] = 1;
  AM[5][6] = 1;
  AM[6][5] = 1;
  AM[5][4] = 1;
  AM[4][5] = 1;
  AM[8][4] = 1;
  AM[4][8] = 1;
  AM[8][7] = 1;
  AM[7][8] = 1;

  AM[5][3] = 1;
  AM[3][5] = 1;

  AM[1][3] = 1;
  AM[3][1] = 1;

  AM[2][3] = 1;
  AM[3][2] = 1;

  AM[2][1] = 1;
  AM[1][2] = 1;
  bfs(0);
}
