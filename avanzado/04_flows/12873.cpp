#include<iostream>
#include<vector>
#include<queue>
#include<map>
#define INFINITE 10000000

using namespace std;

vector<map<int,int>> AL; // lista de adyacencia: capacidad
vector<map<int,int>> Gf; // red residual: vertice a flujo (residual o utilizado)

void printAL() {
  for(int i=0; i<AL.size(); i++) {
    // for(int j=0; j<AL[i].size(); j++) {
    //   cout << "(" << AL[i][j].first << "," << AL[i][j].second << ") ";
    // }
    cout << i << ": " ;
    for ( auto &[v, c] : AL[i] ) 
      cout << "(" << c << "," << v << ") ";
    cout << endl;
  }
}

void printGf() {
  cout << "residual graph: " << endl;
  for(int i=0; i<Gf.size(); i++) {
    // for(int j=0; j<Gf[i].size(); j++) {
    //   cout << "(" << Gf[i][j].first << "," << Gf[i][j].second << ") ";
    // }
    cout << i << ": " ;
    for ( auto &[v, c] : Gf[i] ) 
      cout << "(" << c << "," << v << ") ";
    cout << endl;
  }
}

void bfs(int s, int p, vector<pair<int,int>> &path) {
  // cout << "running bfs..." << endl;
  int source = 0;
  int sink = AL.size()-1;
  vector<int> visited(s+p+2, 0);
  vector<int> parent(s+p+2);
  queue<int> Q;
  Q.push(source);
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for ( auto &[v, c] : Gf[u] ) {
      //int c = Gf[u][i].first;
      if ( c <= 0 )
        continue;
      //int v = Gf[u][i].second;
      if( visited[v] == 0 ) {
        visited[v] = 1;
        parent[v] = u;
        // if( v == sink ) // TODO: 
          // break;
        Q.push(v);
      }
    }
  }
  // for(auto it = visited.begin(); it != visited.end(); it++)
  //   cout << *it << " ";
  // cout << endl;
  // for(auto it = parent.begin(); it != parent.end(); it++)
  //   cout << *it << " ";
  // cout << endl;

  if ( parent[sink] == source ) // no hay camino
    return;

  int i = sink;
  while( i != source ) {
    path.push_back(make_pair(i, parent[i]));
    i = parent[i];
  }
}

int minWeightInPath(vector<pair<int,int>> &path) {
  int minWeigth = 100000;
  for(int i=0; i<path.size(); i++) {
    int u = path[i].first;
    int v = path[i].second;
    int edgeWeigth = Gf[v][u];
    if ( edgeWeigth < minWeigth ) {
      minWeigth = edgeWeigth;
    }
  }
  return minWeigth;
}

void edmondKarp(int s, int p){
  while( 1 ){
    vector<pair<int,int>> path;
    bfs(s, p, path);
    if ( path.size() == 0 ) 
      break;

    // hallar la capacidad residual en el augmenting path
    int cf = minWeightInPath(path); 

    // aumentar la red residual Gf en cf unidades
    for(int i=0; i<path.size(); i++) {
      int u = path[i].first;
      int v = path[i].second;

      Gf[u][v] += cf;
      Gf[v][u] -= cf;
    }
  }
}

// TODO
// void dinitz(int s, int p){
//   while( 1 ){
//     vector<pair<int,int>> GL;
//     bfs2(s, p, GL);
//     if ( GL.size() == 0 ) 
//       break;
// 
//     // DFS
//     int cf = dfs(GL);
//     
//     for(int i=0; i<GL.size(); i++) {
//       int u = GL[i].first;
//       int v = GL[i].second;
// 
//       Gf[u][v] += cf;
//       Gf[v][u] -= cf;
//     }
//   }
// }

int getFlow(int s, int p) {
  int flow = 0;
  int sink = AL.size()-1;
  for( auto &[v, f]: Gf[sink] )
    flow += f;
  return flow;
}

int main() { 
  int n;
  cin >> n;
  while(n--) {
    AL.clear();
    Gf.clear();
    int p, s, c, m;
    cin >> p >> s >> c >> m;
    for(int i=0; i<p+s+2; i++){
      map<int,int> tmp;
      AL.push_back(tmp);
      Gf.push_back(tmp);
    }
    while(m--) {
      int x, y;
      cin >> x >> y;
      // AL[x].push_back(make_pair(INFINITE, y+p));
      // Gf[x].push_back(make_pair(INFINITE, y+p));
      // Gf[y+p].push_back(make_pair(0, x));
      AL[x][y+p] = INFINITE;
      Gf[x][y+p] = INFINITE;
      Gf[y+p][x] = 0;
    }

    int source = 0, sink = AL.size()-1;
    // conectamos la fuente a todos los participantes:
    for(int i=0; i<p; i++) {
      // AL[source].push_back(make_pair(1, i+1));
      // Gf[source].push_back(make_pair(1, i+1));
      // Gf[i+1].push_back(make_pair(0, source));
      AL[source][i+1] = 1;
      Gf[source][i+1] = 1;
      Gf[i+1][source] = 0;
    }
  
    // conectamos todos los locales al destino:
    for(int i=0; i<s; i++) {
      // AL[i+p+1].push_back(make_pair(c, sink));
      // Gf[i+p+1].push_back(make_pair(c, sink));
      // Gf[sink].push_back(make_pair(0, i+p+1));
      AL[i+p+1][sink] = c;
      Gf[i+p+1][sink] = c;
      Gf[sink][i+p+1] = 0;
    }

    // printGf();
    // cout << "=== " << endl;
    edmondKarp(s, p);
    cout << getFlow(s, p) << endl;
  }
}
