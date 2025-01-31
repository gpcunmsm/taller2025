#include<queue>
#include<iostream>
#include<cmath>
#include<functional>

using namespace std;

struct point {
  int x, y;
};

bool compare(point p1, point p2)
{
    float d1 = sqrt(p1.x*p1.x + p1.y*p1.y);
    float d2 = sqrt(p2.x*p2.x + p2.y*p2.y);
    return d1 < d2 ;
}
int main() {
  priority_queue<point, vector<point>, function<bool(point, point)>> Q(compare);

  point p1 = {2, 3};
  point p2 = {5, 10};
  point p3 = {100, 100};
  point p4 = {1, 1};
  Q.push(p1);
  Q.push(p2);
  Q.push(p3);
  Q.push(p4);
  // vector<int> V;
  // priority_queue<int> Q; // la prioridad esta definida por el mismo numero por default
  // Q.push(6);
  // Q.push(2);

  // Q.push(9);
  // Q.push(8); // 9, 6, 2
  while ( ! Q.empty() ){
    point tmp = Q.top();
    cout << tmp.x << " " << tmp.y << endl;
    Q.pop();
  }
}
