#include<map>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

int main() {
  unordered_map<string, int> M;
  M["uno"] = 1;
  M["dos"] = 2;
  M["diez"] = 10;
  M["ciento tres"] = 103;
  for ( auto it : M ){
    cout << it.first << " " << it.second << endl;
  }

  cout << endl;
  for ( unordered_map<string,int>::iterator it = M.begin(); it != M.end(); it++ ){
    cout << (*it).first << " " << it->second << endl;
  }
}

int main2() {
  map<string, int> M;
  M["uno"] = 1;
  M["dos"] = 2;
  M["diez"] = 10;
  M["ciento tres"] = 103;
  for ( auto it : M ){
    cout << it.first << " " << it.second << endl;
  }

  cout << endl;
  for ( map<string,int>::iterator it = M.begin(); it != M.end(); it++ ){
    cout << (*it).first << " " << it->second << endl;
  }
}
