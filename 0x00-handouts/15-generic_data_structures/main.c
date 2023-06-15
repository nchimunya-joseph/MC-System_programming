#include <stdio.h>
#include <stdlib.h>

int (*sumPtr)(int, int);
int sum(int x, int y)
{
  return x + y;
}
int main(int argc, char *argv[])
{
  int a = 10;
  int b = 30;

  sumPtr = sum;
  int result = sumPtr(a, b);
  printf("Result: %d\n", result);
  return EXIT_SUCCESS;
}
