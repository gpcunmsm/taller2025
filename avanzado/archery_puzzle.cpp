#include<iostream>
#include<vector>

using namespace std;

void debug(vector<int> &x, int s, int idx) {
  cout << "S: " << s << "=> ";
  for(int i=0; i<x.size(); i++)
    cout << x[i] << " ";
  cout << "idx: " << idx << endl;
}

int countArrows(vector<int> &k) {
  int totalArrows = 0;
  for(int i=0; i<k.size(); i++) {
    totalArrows += k[i];
  }
  return totalArrows;
}

int minSolSize = 10000;
vector<vector<pair<int,int>>> sols;

void saveSol(vector<int> &k) {
  vector<pair<int,int>> tmp; // arrow i is needed k[i] times
  int solSize = 0;
  for(int i=k.size()-1; i>=0; i--) {
    if (k[i] != 0) {
      tmp.push_back(make_pair(i, k[i]));
      solSize += k[i];
    }
  }

  if ( minSolSize > solSize )
    minSolSize = solSize;

  // cout << "minSolSize so far " << minSolSize << endl;
  sols.push_back(tmp);
}

bool backtrack(vector<int> &p, vector<int> &k, int S, int idx){
  if ( S == 0 ) {
    // debug(k, S);
    saveSol(k);
    return true;
  }

  if ( S < 0 ) 
    return false;

  bool isPossible = false;

  k[idx]++;
  int c = countArrows(k);
  
  if ( c > minSolSize ) {
    k[idx]--;
    return isPossible;
  }

  for(int i=idx; i>=0; i--) {
    isPossible |= backtrack(p, k, S-p[idx], i);
  }
  k[idx]--;
  return isPossible;
}

int main(){
  int t;
  cin >> t;
  for(int testCase=1; testCase<=t; testCase++) {
    int n, s;
    cin >> n >> s;
    vector<int> p;
    for(int i=0; i<n; i++) {
      int tmp;
      cin >> tmp;
      p.push_back(tmp);
    }

    minSolSize = 10000;
    sols.clear();
    // vector<int> minK(p.size(), 0);
    int minK;
    int totalArrows = 0;
    int minTotalArrows = 10000;

    bool sol = false;
    for(int counter=p.size()-1; counter>=0; counter--) {
    //for(int counter=0; counter<p.size(); counter++) {
      vector<int> k(p.size(), 0);
      sol |= backtrack(p, k, s, counter); // choose last one first
    }

    for(int i=0; i<sols.size(); i++) {
      totalArrows = 0;
      for(int j=0; j<sols[i].size(); j++){
          totalArrows += sols[i][j].second;
      }
      if ( minTotalArrows > totalArrows ) {
        minTotalArrows = totalArrows;
        minK = i;
      }
    }

    if ( sol ) {
      cout << "Case " << testCase << ": [" << minTotalArrows << "]";
      for(int i=0; i<sols[minK].size(); i++) {
        for(int j=0; j<sols[minK][i].second; j++)
          cout << " " << p[sols[minK][i].first];
      }
      cout << endl;
    } else {
      cout << "Case " << testCase << ": impossible" << endl;
    }
  }
}
