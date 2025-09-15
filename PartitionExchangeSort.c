#include <stdio.h>

//의사코드
void partition(index low, index high, index &pivotpoint) {
  index i,j;
  keytype pivotitem;

  pivotitem = S[low];
  j = low;
  for(i=low+1;i<high;++i) {
    if(S[i]<pivotitem) {
      ++j;
      exchange S[i] and S[[j];]
    }
  }
  pivotpoint = j;
  exchange S[low] and S[pivotpoint];
}

int main() {
  printf("%d",4);
  return 0;
}
