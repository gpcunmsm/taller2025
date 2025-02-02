#include <iostream>
#include <vector>
#define SIZE 10
#define VISITED 1

using namespace std;

int AM[SIZE][SIZE];
int t = 0;
vector<int> visited(SIZE, -1);
vector<int> discovery(SIZE, -1);
vector<int> finish(SIZE, -1);
vector<int> parent(SIZE, -1);

// version recursiva
void dfs(int u) {
  visited[u] = VISITED;
  discovery[u] = t++;

  for(int i=0; i<SIZE; i++) {
    if( AM[u][i] == 0 ) continue;
    int v = i;

    if ( visited[v] != VISITED ) {
      parent[v] = u;
      dfs(v);
    }
  }
  finish[u] = t++;
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
  dfs(6);

  cout << "visited vector:" << endl;
  for(int i=0; i<SIZE; i++) cout << "(i:" << i << " v:" << visited[i] << ") ";
  cout << endl;

  cout << "discovery vector:" << endl;
  for(int i=0; i<SIZE; i++) cout << "(i:" << i << " d:" << discovery[i] << ") ";
  cout << endl;

  cout << "finish vector:" << endl;
  for(int i=0; i<SIZE; i++) cout << "(i:" << i << " f:" << finish[i] << ") ";
  cout << endl;

  cout << "parent vector:" << endl;
  for(int i=0; i<SIZE; i++) cout << "(i:" << i << " p:" << parent[i] << ") ";
  cout << endl;
}
