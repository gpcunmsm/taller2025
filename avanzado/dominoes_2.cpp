#include <iostream>
#include <vector>
#define VISITED 1

using namespace std;

vector<vector<int>> AL;
vector<int> visited;

void dfs(int u) {
  visited[u] = VISITED;
  for(int i=0; i<AL[u].size(); i++) {
    int v = AL[u][i];
    if ( visited[v] != VISITED ) {
      dfs(v);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, m, l;
    cin >> n >> m >> l;
    visited = vector<int>(n, 0);
    AL = vector<vector<int>>();
    for(int i=0; i<n; i++) {
      vector<int> tmp(0);
      AL.push_back(tmp);
    }

    while(m--) {
      int x, y;
      cin >> x >> y;
      AL[x-1].push_back(y-1);
    }

    vector<int> initPoints;
    while(l--) {
      int tmp;
      cin >> tmp;
      initPoints.push_back(tmp-1);
    }

    for(auto init : initPoints) {
      dfs(init);
    }

    int sum=0;
    for(auto s : visited) {
      sum += s;
    }

    cout << sum;
  }
}
