#include <stdio.h>


/* return 2 if point strictly inside circle, 0 if strictly outside, 1 otherwise */
int circle(int x1, int x2, int r) {
  int l;
  l = x1*x1 + x2*x2;

  if (l < r*r)
    return 2;
  else if (l > r*r)
    return 0;
  else
    return 1;
}


/* count how many integers between 2 and n are divisible by t */
int count(int n, int t) {
  // optional: make t positive
  if (t < 0)
    t = -t;

  if (n < t || n < 2)
    return 0;
  else if (n % t == 0)
    return count(n - 1, t) + 1; // recursive call to count
  else
    return count(n - 1, t);
}


/* count program that prints out recursive calls */
int verbose_count(int n, int t); // function declared, we'll define below


/* test circle and count */
void test_circle(int x1, int x2, int r); // declare function here, define below
void test_count(int n, int t);

int main() {
  // HW2
  printf("HW2 --------------------\n");
  test_circle(2, 4, 5);
  test_circle(4, 4, 5);
  test_circle(3, 4, 5);

  // HW4
  printf("\nHW4 --------------------\n");
  // typical cases
  test_count(10, 3);
  test_count(1000, 17);
  // test case: n < t, should be 0
  test_count(3, 4);
  // test case: t < 0, should be the same as for -t
  test_count(10, -3);
  // test case: t < 0 and n < |t|, should be 0
  test_count(3, -4);

  // Verbose count
  printf("\nVerbose count program for n = 10, t = 3:\n\n");
  verbose_count(10, 3);
}


// TEST FUNCTIONS

/* print different statements depending on the output of circle */
void test_circle(int x1, int x2, int r) {
  int n;
  n = circle(x1, x2, r);

  printf("The point (%d, %d) is ", x1, x2);
  if (n == 2)
    printf("inside");
  else if (n == 0)
    printf("outside");
  else
    printf("on the boundary of");
  printf(" the circle of radius %d.\n", r);
}


/* print the result of count(10, 3) */
void test_count(int n, int t) {
  printf("n = %d, t = %d --> count = %d.\n", n, t, count(n, t));
}


// VERBOSE COUNT
int verbose_count(int n, int t) {
  static int plus_ones = 0; // count number of +1's for print statements
   if (t < 0)
    t = -t;

  if (n < t || n < 2) {
    printf("%d < %d or %d < 2, return 0 + %d\n", n, t, n, plus_ones);
    return 0;
  }
  else if (n % t == 0) {
    ++plus_ones;
    printf("%d divides %d, return count(%d, %d) + %d\n", t, n, n - 1, t, plus_ones);
    return verbose_count(n - 1, t) + 1; // recursive call to count
  }
  else {
    printf("%d does not divide %d, return count(%d, %d) + %d\n", t, n, n - 1, t, plus_ones);
    return verbose_count(n - 1, t);
  }
}
