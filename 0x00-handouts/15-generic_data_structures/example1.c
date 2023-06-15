#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
  A generic sorting algorithm that works
  for any data type.
*/

/* this works on an array of ints */
int intcmp(const void *x, const void *y)
{
  int a = *(int *)x;
  int b = *(int *)y;
  return (a - b);
}

/* this works on an 2d array of char *'s */
int stringcmp2Darray(const void *x, const void *y)
{
  char *s1 = (char *)x;
  char *s2 = (char *)y;
  return (strcmp(s1, s2));
}

/* this works on an array of char *'s. */
int stringcmp(const void *x, const void *y)
{
  char *s1 = *(char **)x;
  char *s2 = *(char **)y;
  return (strcmp(s1, s2));
}

void printint(int[], int);
void printstring(char **, int);
void printArrayOfString(char[][6], int);

int main(int argc, char *argv[])
{
  int A[] = {46, 67, 12, 10, 54, 90, 32};

  char *B[10];
  for (int i = 0; i < 10; i++)
    B[i] = malloc(10);
  strcpy(B[0], "me");
  strcpy(B[1], "him");
  strcpy(B[2], "andy");
  strcpy(B[3], "guna");

  char C[10][6];
  strcpy(C[0], "me");
  strcpy(C[1], "him");
  strcpy(C[2], "andy");
  strcpy(C[3], "guna");

  /* sorting the arrays */
  qsort(A, 7, sizeof(int), intcmp);
  qsort(B, 4, sizeof(char *), stringcmp);
  qsort(*C, 4, 6, stringcmp2Darray);

  /* printing the arrays */
  printint(A, 7);
  printstring(B, 4);
  printArrayOfString(C, 4);
  return 0;
}

void printint(int A[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", A[i]);
  printf("\n");
}

void printstring(char **A, int n)
{
  for (int i = 0; i < n; i++)
    printf("%s ", A[i]);
  printf("\n");
}

void printArrayOfString(char A[][6], int n)
{
  for (int i = 0; i < n; i++)
    printf("%s ", A[i]);
  printf("\n");
}
