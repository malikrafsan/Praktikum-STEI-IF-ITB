#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

boolean validateN(long long n) {
  if (n <= 0) return false;
  else {
    long long valid = 1;
    while (valid < n) {
      valid *= 2;
    }
    return (valid == n);
  }
}

void solve(long long n) {
  BinTree * arr = (BinTree*) malloc(sizeof(BinTree)*n);

  long long input;

  for (long long i = 0; i < n; i++) {
    scanf("%d", &input);
    arr[i] = newTreeNode(input);
  }

  long long input1, input2;
  while (true) {
    if (n <= 1) break;
    else {
      long long counter = 0;
      for (long long i=0;i<n;i += 2) {
        arr[counter] = NewTree(ROOT(arr[i]) + ROOT(arr[i+1]), arr[i], arr[i+1]);
        counter++;
      }
      n /= 2;
    }   
  }
  printTree(arr[0],2);
}

int main () {
  long long n;

  scanf("%lld", &n);
  if (validateN(n)) {
    solve(n);
  }
  else {
    printf("Jumlah masukan tidak sesuai\n");
  }

  return 0;
}