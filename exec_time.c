/*****************************************************
 * This program calls the multiply procedure a large *
 * number of times and prints the execution time.    *
 *****************************************************/

#include <stdio.h>
#include <time.h>

long mult(int a, int b)
{
  long product = 0;
  int i = 0;

  for ( i = 0; i < 16; i++ )
  {
    if (b & 1)
      product += a;
    a <<= 1;
    b >>= 1;
  }
  return product;
}

int main( void )
{
  clock_t start, finish;
  int value1 = 1000, value2 = 4096;
  int i, j, n;

  printf("Please input repeat count: ");
  scanf("%d", &n);

  start = clock(); /* start the clock */
  for ( j = 0; j < n; j++ )
    for ( i = 0; i < 1000000; i++ )
      mult(value1, value2);
  finish = clock(); /* stop the clock */

  printf("Multiplication took %f seconds to finish.\n",
	 ((double)(finish-start))/CLOCKS_PER_SEC);

  return 0;
}
