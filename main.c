#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gennumber.h"
#include "interaction.h"

#define ITERATION	5

int main() {
  char ctr = 1;
  unsigned int fourdigit_number;
  unsigned int hidden_number;

  /* After setting a seed for the random number generator,
     a secret four-digit number is set to 'hidden_number.' */
  srand48((unsigned char)time(NULL));
  hidden_number = gennumber();

  /* Clear the screen and move the cursor to (0, 0) */
  printf("\033[2J\033[0;0H"); 
  printf("Welcome to the hit-and-HR game.\n"
         "I have a secret four-digit number whose every digits are different.\n\n"
         "Guess the number.\n"
         "You have %d opportunities.\n\n"
         "Every time you enter a number, I give you some hints.\n"
         "'hit' means that the number is correct but its position is different.\n"
         "'HR' means that both the number and its position are identical.\n\n"
         "Let's try!\n\n", ITERATION);

  do {
    char flag = 0;
    printf("#%d try...\n", ctr);

    /* Iterations until acquiring an appropriate four-digit number. */
    do {
      printf("Enter a four-digit number: ");
      scanf("%d", &fourdigit_number);
      flag = check_digits(fourdigit_number); /* expecting the flag becomes 1(true). */

      if (flag == 0) { /* Note: this can be written as 'if (!flag) {' */ 
        printf("Please enter an appropriate number.\n"); 
      }
    } while (flag == 0); /* this should be '} while (!flag);' */

    /* Confirm whether the user's input hits the correct answer or not.
       If the user does not reach the answer, this provides some hints
       for the next trial. */
    if (hidden_number == fourdigit_number) {
      break;
      /* Note: The value of 'ctr' would remain less than ITERATION,
         if you find the correct number before 'ctr' reaches ITERATION. */ 
    } else {
      print_hints(fourdigit_number, hidden_number);
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
