

int main() {
  int min;
  int n = 5;
  int A[] = {2, 6, 8, 1, 4} ;

  min = A[0];                         // c1
  for( int i = 0; i<n; i++ ) {       // n veces
    if ( A[i] < min ) {                 // c2
      min = A[i];                       // c3
    }
  }

  //            T(n) = c1 + n*(c2+c3) 
  //                 = a  + n*b   // lineal
  printf("%d\n", min);
}
