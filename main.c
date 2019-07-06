#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gennumber.h"
#include "interaction.h"

#define ITERATION	5

int main() {
  char ctr = 1;
  unsigned int d;
  unsigned int hidden_number;

  /* After setting a seed for the random number generator,
     a secret four-digit number is set to 'hidden_number.' */
  srand48((unsigned char)time(NULL));
  hidden_number = gennumber();

  do {
    char flag = 0;
    printf("#%d try...\n", ctr);

    /* Iterations until acquiring an appropriate four-digit number. */
    do {
      printf("Enter a four-digit number: ");
      scanf("%d", &d);
      flag = check_digits(d); /* expecting the flag becomes 1(true). */

      if (flag == 0) { /* Note: this can be written as 'if (!flag) {' */ 
        printf("Please enter an appropriate number.\n"); 
      }
    } while (flag == 0); /* this should be '} while (!flag);' */

    /* Confirm whether the user's input hits the correct answer or not.
       If the user does not reach the answer, this provides some hints
       for the next trial. */
    if (hidden_number == d) {
      break;
      /* Note: The value of 'ctr' would remain less than ITERATION,
         if you find the correct number before 'ctr' reaches ITERATION. */ 
    } else {
      print_hints(d, hidden_number);
    }

  /* User's trials are limited within the ITERATION times. */
  } while (ctr++ < ITERATION);

  printf("My secret number was %04d.\n", hidden_number);
  printf((ctr > ITERATION) ? "You lose.\n" : "BINGO! You win!\n"); 
/*
  if (ctr > ITERATION) {
    printf("You lose.\n");
  } else {
    printf("BINGO! You win!\n");
  }
*/

  return 0;
}
