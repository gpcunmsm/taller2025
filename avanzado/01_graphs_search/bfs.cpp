#include<iostream>
#include<queue>
#include<vector>

#define SIZE 10
#define WHITE 1
#define GRAY 2
#define BLACK 3
using namespace std;

int AM[SIZE][SIZE];

void bfs(int source) {
  queue<int> Q;
  vector<int> colored(SIZE, WHITE);
  vector<int> dist(SIZE, -1);
  vector<int> parent(SIZE, -1);
  dist[source] = 0;
  colored[source] = GRAY;
  Q.push(source);
  while(!Q.empty()) {
    int u = Q.front();
    cout << "u: " << u << endl;
    for(int i=0; i<SIZE; i++) {
      if ( AM[u][i] == 0 ) continue;
      int v = i;
      cout << " adj v: " << v << endl;
      if( colored[v] == WHITE ) { // no visitado aun
        dist[v] = dist[u] + 1;
        parent[v] = u;
        colored[v] = GRAY;
        cout << " adding to the queue: " << v << endl;
        Q.push(v);
      }
      colored[u] = BLACK;
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
