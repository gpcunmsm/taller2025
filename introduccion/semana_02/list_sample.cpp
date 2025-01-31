#include<list>
#include<iostream>

using namespace std;

int main() {
  list<int> L;
  auto it = L.begin();
  L.insert(L.begin(), 4); // 4
  L.insert(L.begin(), 2); // 2 4
  L.insert(L.begin(), 9); // 9 2 4
  for ( auto itr : L ){
    cout << itr << endl;
  }
}
