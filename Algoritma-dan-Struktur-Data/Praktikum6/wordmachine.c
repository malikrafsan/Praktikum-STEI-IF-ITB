#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank() {
  while (currentChar == BLANK) {
    adv();
  }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startWord() {
  start();
  ignoreBlank();

  if (currentChar == MARK) {
    endWord = true;
  } else {
    endWord = false;
    advWord();
  }
}
/* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void advWord() {
  ignoreBlank();
  if (currentChar == MARK) {
    endWord = true;
  } else {
    copyWord();
    ignoreBlank();
  }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */

void copyWord() {
  int i;

  i = 0;
  while ((currentChar != BLANK) && (currentChar != MARK) && (i != CAPACITY)) {
    // if (i == CAPACITY) {
    //   // char temp = currentChar;
    //   // printf("temp: %c\n", temp);
    //   // while ((currentChar != BLANK) && (currentChar != MARK))
    //   //   adv();
    //   // currentChar = temp;
    //   break;
    // }
    currentWord.contents[i] = currentChar;
    adv();
    i++;
    // if (i == CAPACITY)
    //   printf("test\n");
  }
  // printf("curChar: %c\n", currentChar);
  currentWord.length = (i < CAPACITY) ? i : CAPACITY;
  // printf("length: %d\n",currentWord.length);
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */

