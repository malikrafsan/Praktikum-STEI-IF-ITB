/* File: wordmachine.c */
/* Implementasi Word Engine */

#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

/* Word Engine State */
boolean endWord;
Word currentWord;

void ignoreBlank(){
   while (currentChar == BLANK){
      adv();
   }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startWord(){
   start();
   ignoreBlank();
   if (currentChar == MARK){
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

void advWord(){
   ignoreBlank();
   if (currentChar == BLANK && !endWord) {
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

void copyWord(){
   int i=0;
   currentWord.length = 0;
   while (currentChar != MARK && currentChar != BLANK && i != CAPACITY){
      currentWord.contents[i] = currentChar;
      adv();
      i++;
   }
   currentWord.length = (i<CAPACITY)? i : CAPACITY;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
