#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

int main() {
  startWord();

  while (!endWord) {
    for (int i = 0; i <currentWord.length;i++) {
      printf("%c",currentWord.contents[i]);
    }
    printf("\n");
    advWord();
  }
  return 0;
}