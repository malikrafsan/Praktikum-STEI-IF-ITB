/* File: driver_time.c */
/* Nama : Malik Akbar Hashemi Rafsanjani */
/* NIM : 13520105 */
/* Tanggal: 1 September 2021 */
/* ***  MAIN DRIVER TIME *** */

#include <stdio.h>
#include "time.h"

int main() {
  // KAMUS
  TIME myTime, yourTime;
  long secInput, seconds;

  // ALGORITMA
  myTime = MakeTIME(1,2,14);
  printf("Input your time: ");
  BacaTIME(&yourTime);
  printf("My time: ");
  TulisTIME(myTime);
  printf("\n");
  printf("Your time: ");
  TulisTIME(yourTime);
  printf("\n");
  printf("Second representation of your time: %ld\n\n",TIMEToDetik(yourTime));

  printf("Input seconds: ");
  while (true) {
    scanf("%ld",&secInput);
    if (secInput >= 0)
      break;
    printf("Second input cannot be negative\n");
    printf("Input seconds: ");
  }
  printf("Time representation of your input: ");
  TulisTIME(DetikToTIME(secInput));
  printf("\n\n");

  if (TEQ(myTime,yourTime))
    printf("My time is equal to yours\n");
  if (TNEQ(myTime,yourTime))
    printf("My time isn't equal to yours\n");
  if (TLT(myTime,yourTime))
    printf("My time is less than yours\n");
  if (TGT(myTime,yourTime))
    printf("My time is greater than yours\n");
  
  printf("Next second of your time: ");
  TulisTIME(NextDetik(yourTime));
  printf("\n");
  printf("Previous second of your time: ");
  TulisTIME(PrevDetik(yourTime));
  printf("\n\n");

  printf("Input second: ");
  scanf("%ld",&seconds);
  printf("Next %ld seconds to your time: ",seconds);
  TulisTIME(NextNDetik(yourTime,seconds));
  printf("\n");
  printf("Previous %ld seconds to your time: ",seconds);
  TulisTIME(PrevNDetik(yourTime,seconds));
  printf("\n");
  printf("Duration between my time and yours: %ld\n", Durasi(myTime,yourTime));

  return 0;
}