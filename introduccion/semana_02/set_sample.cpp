#include<set>
#include<vector>
#include<iostream>

using namespace std;

int main(){
  set<int> S;
  S.insert(7);
  S.insert(3);
  S.insert(7);
  S.insert(7);
  S.insert(7);
  S.insert(7);
  S.insert(9);
  S.insert(7);
  S.insert(7);
  for (set<int>::iterator it = S.begin(); it != S.end() ; it++) {
    cout << *it << endl;
  }
  cout << endl;
  cout << S[0] << endl;
  for (auto it : S){
    cout << it << endl;
  }

  vector<int> V;
  V.push_back(5);
  V.push_back(3);
  cout << V[0] << endl;
  for (vector<int>::iterator it = V.begin(); it != V.end() ; it++) {
    cout << *it << endl;
  }
  cout << endl;
  for (auto it : V){
    cout << it << endl;
  }
}
