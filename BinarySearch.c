#include <stdio.h>

typedef int keytype;
typedef int index;
void binsearch*-(int n, const keytype S[], keytype x, index *location) {
  index low, high, mid;
  low = 1;
  high = n;
  *location = 0;

  while(low <= high && *location == 0) {
    mid = (low + high) / 2;
    if(x == S[mid]) *location = mid;
    else if(x < S[mid]) high = mid - 1;
    else low = mid + 1;
  }
}
