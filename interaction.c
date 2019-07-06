#include <stdio.h>
#include <math.h>

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
    unsigned char d1, d2, d3, d4;
    d1 = n_digit(d, 4);
    d2 = n_digit(d, 3);
    d3 = n_digit(d, 2);
    d4 = n_digit(d, 1);


    flag = (d1-d2) * (d1-d3) * (d1-d4) * (d2-d3) * (d2-d4) * (d3-d4);

    /* Note: 'if (flag) {...}' means 'if (flag != 0) {...}'. */
    if (flag) { 
      printf("The number you gave me is %d%d%d%d.\n",d1,d2,d3,d4);
    }
  }
  /* Note: 
     if the value of 'flag' is non-zero, 
     the comparison (flag != 0) returns 1(true), 
     otherwise it returns 0(false). */
  return (flag != 0);
}

/* This function shows some hints according to 
   the comparison of the two four-digit numbers 
   provided as parameters, 'user' and 'system.' */
void 
print_hints(unsigned int user, unsigned int system) {
  unsigned char u[4], s[4];
  unsigned char i, j;
  unsigned char hit = 0, hr = 0;

  for (i = 0; i < 4; i++) {
    u[i] = n_digit(user, 4-i);
    s[i] = n_digit(system, 4-i);
  }
  printf("Umm..., ");
  for (i = 0; i < 4; i++) {
    if (u[i] == s[i]) {
      hr++; continue;
    } else {
      for (j = 0; j < 4; j++) {
        if (j == i) continue;
        if (u[i] == s[j]) { hit++; break; }
      }
    }
  }
  printf("%d hit(s) and %d HR(s).\n", hit, hr);
}
