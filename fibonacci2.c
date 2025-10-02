#include <stdio.h>

typedef int index;
int fibonacci2(int n) {
  index i;
  int *f = (int*)malloc(sizeof(int)*n);
  f[0] = 0;
  if(n > 0) {
    f[1] = 1;
    for(i=2;i<=n;++i) {
      f[i] = f[i-1] + f[i-2];
    }
  }
  free(f);
  return f[n];
}
