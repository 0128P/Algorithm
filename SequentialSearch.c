#include <stdio.h>

typedef int keytype;

/*
 * 
 * n : 배열의 크기
 * S : 탐색 대상 배열 (1번 인덱스부터 사용)
 * x : 찾으려는 값
 * location : 결과 위치를 저장할 int형 포인터
 * 
 * */
void seqsearch(int n, const keytype S[], keytype x, int* location) {
  *location = 1;
  while(*location <= n && S[*location] != x) {
    ++(*location);
  }
    if(*location > n) {
      *location = 0;
  }
}

int main() {
  int n = 5;
  keytype S[6] = {0, 3, 7, 2, 5, 8};
  keytype x = 5;
  int loc;

  seqsearch(n,S,x,&loc);
  if(loc != 0) printf("찾음 : 위치 = %d\n",loc);
  else printf("못 찾음\n");
  return 0;
}
