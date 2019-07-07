#include <stdio.h>         // for printf() and scanf()
#include <math.h>          // for pow()
#include "interaction.h"   // for ITERATION

/* Get the n-th digit. 
   'pow(10, n-1)' means '10^(n-1).' */
unsigned char 
n_digit(unsigned int d, unsigned int n) {
  return ((d / (int)pow(10, n-1)) % 10);
}

/* If parameter d contains four different digits,
   this function returns 1(true), 
   otherwise this returns 0(false) */
char 
check_digits(unsigned int d) {
  int flag = 0;

  if (d < 9999) {
    unsigned char d1 = n_digit(d, 4);
    unsigned char d2 = n_digit(d, 3);
    unsigned char d3 = n_digit(d, 2);
    unsigned char d4 = n_digit(d, 1);
    flag = (d1-d2) * (d1-d3) * (d1-d4) * (d2-d3) * (d2-d4) * (d3-d4);
    /* Note: 'if (flag) {...}' means 'if (flag != 0) {...}'. */
    if (flag) { 
      printf("The number you gave me is %d%d%d%d.\n",d1,d2,d3,d4);
    }
  }
  /* Note: if the value of 'flag' is non-zero, the comparison (flag != 0) 
     returns 1(true), otherwise it returns 0(false). */
  return (flag != 0);
}

/* This function makes initial message. */
void
print_init_message() {
  /* Clear the screen and move the cursor to (0, 0) */
  printf("\033[2J\033[0;0H"); 
  printf("Welcome to the hit-and-HR game.\n"
         "I have a secret four-digit number "
           "where every digit is different.\n\n"
         "Guess the number.\n"
         "You have %d opportunities.\n\n"
         "Every time you enter a number, I will give you some clues.\n"
         "'hit' means that the numbers are correct "
           "but in different positions.\n"
         "'HR' means that both the numbers and "
           "their positions are identical.\n\n"
         "Let's try!\n\n", ITERATION);
}

/* This function requests the user to enter 
   a four-digit number in the proper format. */
unsigned int
user_input() {
  unsigned int fourdigit_number;
  unsigned char flag = 0;

  while (flag == 0) { /* this should be 'while (!flag) {' */
    printf("Enter a four-digit number: ");
    scanf("%d", &fourdigit_number);
    /* Check the appropriateness of the user's input, 
       expecting the flag becomes 1(true). */    
    flag = check_digits(fourdigit_number);
    if (flag == 0) { /* Note: this can be written as 'if (!flag) {' */ 
      printf("Please enter an appropriate number.\n"); 
    }
  }  
  return fourdigit_number;
}

/* This function shows some hints according to 
   the comparison of the two four-digit numbers 
   provided as parameters, 'user' and 'system.' */
void 
print_hints(unsigned int user, unsigned int system) {
  unsigned char u[4], s[4], i, j, hr = 0, hit = 0;

  for (i = 0; i < 4; i++) {
    u[i] = n_digit(user, 4-i);
    s[i] = n_digit(system, 4-i);
  }
  printf("Umm..., ");
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (u[i] == s[j]) {
        if (i == j) { hr++; } else { hit++; }
        break; 
        /* Note: this statement would break out only from the inner loop. */
      }
    }
  }
  printf("%d hit(s) and %d HR(s).\n\n", hit, hr);
}
