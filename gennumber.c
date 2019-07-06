#include <stdlib.h>

#define ITER 10000

/* This is a helper function used only in this file.
   This shuffles the array of ten characters pointed
   by the parameter '*str.' */
void
shuffle(unsigned char *str) {
  unsigned char p, q, tmp;
  unsigned int i;

  /* Swap the characters located at 'p' and 'q,' ITER-times. */
  for (i = 0; i < ITER; i++) {
    p = (unsigned char)(drand48()*10);
    q = (unsigned char)(drand48()*10);
    tmp = str[p];
    str[p] = str[q];
    str[q] = tmp;
  }
}

/* This function makes a four-digit number,
   which has different numbers in each digit. */
unsigned int
gennumber() {
  unsigned char str[] = "0123456789";
  unsigned int i, d;
  shuffle(str);

  /* 'str[x]' has the value of the character code of '0' to '9.'
     Therefore, subtracting the character code of '0' from 'str[x]'
     results in the numerical value from 0 to 9. */
  d = (str[0]-'0')*1000+(str[1]-'0')*100+(str[2]-'0')*10+(str[3]-'0');
  return d;
}
