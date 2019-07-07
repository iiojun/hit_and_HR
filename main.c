#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gennumber.h"
#include "interaction.h"

#define ITERATION	5

int main() {
  char ctr = 0;
  unsigned int fourdigit_number;
  unsigned int hidden_number;
  char *iter_msg[ITERATION] = { "1st", "2nd", "3rd", "4th", "5th" };

  /* After setting a seed for the random number generator,
     a secret four-digit number is set to 'hidden_number.' */
  srand48((unsigned char)time(NULL));
  hidden_number = gennumber();

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
         "'HR' means that both the number and its position are identical.\n\n"
         "Let's try!\n\n", ITERATION);
 
  /* Iterations until acquiring an appropriate four-digit number. */
  do {
    printf("%s try...\n", iter_msg[ctr]);
    fourdigit_number = user_input();
    /* Confirm whether the user's input hits the correct answer or not.
       If the user does not reach the answer, this provides some hints
       for the next trial. 
       Note: The value of 'ctr' would remain less than ITERATION,
       if you find the correct number before 'ctr' reaches ITERATION. */ 
    if (hidden_number == fourdigit_number) { break; }
    print_hints(fourdigit_number, hidden_number);
    
  /* User can try guessing the number until the counter reaches ITERATION. */
  } while (++ctr < ITERATION);

  printf("My secret number was %04d.\n", hidden_number);
  printf((ctr == ITERATION) ? "You lose.\n" : "BINGO! You win!\n"); 

  return 0;
}
