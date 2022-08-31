#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank() {
   while (currentChar == BLANK) {
      adv();
   }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void startToken() {
   start();
   ignoreBlank();

   if (currentChar == MARK) {
      endToken = true;
   } else {
      endToken = false;
      advToken();
   }
}
/* I.S. : currentChar sembarang 
   F.S. : endToken = true, dan currentChar = MARK; 
          atau endToken = false, currentToken adalah Token yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir Token */

void advToken() {
   ignoreBlank();
   if (currentChar == MARK) {
      endToken = true;
   } else {
      salinToken();
      ignoreBlank();
   }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentToken adalah Token terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, maka endToken = true		  
   Proses : Akuisisi kata menggunakan procedure salinToken */

void salinToken() {
   if ((currentChar >= 48) && (currentChar <= 57)) {
      currentToken.tkn = 'b';
      currentToken.val = 0;
      do {
         currentToken.val = (currentToken.val * 10) + (currentChar - 48);
         adv();
      } while ((currentChar >= 48) && (currentChar <= 57));
   } else {
      currentToken.val = -1;
      currentToken.tkn = currentChar;
      adv();
   }
   // if ((currentChar >= 48) && (currentChar <= 57)) {
   //    currentToken.tkn = 'b';
   //    if (currentToken.val == -1) {
   //       currentToken.val = currentChar - 48;
   //    } else {
   //       currentToken.val = (currentToken.val * 10) + (currentChar - 48);
   //    }
   // } else {
   //    currentToken.val = -1;
   //    currentToken.tkn = currentChar;
   // }
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam currentToken
   I.S. : currentChar adalah karakter pertama dari Token
   F.S. : currentToken berisi Token yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata "dipotong" */
