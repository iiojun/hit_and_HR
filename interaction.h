#define ITERATION	5
#define ITER_MSGS { "1st", "2nd", "3rd", "4th", "5th" }
#define CLEAR_SCREEN "\033[2J\033[0;0H"
#define INIT_MSG \
"Welcome to the hit-and-HR game.\n\
I have a secret four-digit number where every digit is different.\n\n\
Guess the number.\n\
There are %d opportunities to submit an answer.\n\n\
Every time you enter a number, I will give you some clues.\n\
'hit' means that the numbers are correct but in different positions.\n\
'HR' means that both the numbers and their positions are identical.\n\n\
Example:\n\
  If the number you entered is '1470' and the secret number is '7481,'\n\
  the message I give you will be 'two hits (for 1 and 7)\
 and one HR (for 4).'\n\n\
Let's try!\n"

void print_init_message();
unsigned int user_input();
void print_hints(unsigned int, unsigned int);
