#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gennumber.h"
#include "interaction.h"

#define ITERATION	5
#define ITER_MSGS { "1st", "2nd", "3rd", "4th", "5th" }

int main() {
  char ctr = 0;
  unsigned int fourdigit_number;
  unsigned int hidden_number;
  char *iter_msg[ITERATION] = ITER_MSGS;

  /* After setting a seed for the random number generator,
     a secret four-digit number is set to 'hidden_number.' */
  srand48((unsigned char)time(NULL));
  hidden_number = gennumber();
  print_init_message();
 
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
