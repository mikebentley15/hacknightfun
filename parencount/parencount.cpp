#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <vector>

long pCount(int n);
long pCount2(int n);


int main(int argCount, char** argList)
{
  int n = -1;
  char description[] =
    "Description:\n"
    "\n"
    "  Given a number of parenthese pairs, this function will find the number of\n"
    "  balanced permutations one can make.\n";

#define PRINT_USAGE \
  printf("Usage:  %s <paren-pairs>\n", argList[0]); \
  printf("%s", description)

  if (argCount < 2)
  {
    printf("ERROR: Not enough arguments\n");
    PRINT_USAGE;
    return 1;
  }

  if (strcmp(argList[1], "-h") == 0 || strcmp(argList[1], "--help") == 0)
  {
    PRINT_USAGE;
    return 0;
  }

  n = atoi(argList[1]);
  if (n < 1)
  {
    PRINT_USAGE;
    return 2;
  }

  printf("Pairs:        %d\n", n);
  //printf("Permutations: %ld\n", pCount(n));  // Old wrong implementation
  printf("Permutations: %ld\n", pCount2(n));

  return 0;
}

/**
 * Returns the number of permutations of valid sets of parentheses
 *
 * @note this was later found to be wrong as it was based on wrong
 *   assumptions
 *
 * @param n - Number of parenthese pairs
 */
long pCount(int n)
{
  if (n <= 2)
    return n;

  // @note This is wrong logic, but here for seeing what it was trying to do
  // The set of permutations for this number can be expressed in terms of lower
  // permutations:
  //   "(" + pList(n-1) + ")"
  //   "()" + pList(n-1)
  //   "(())" + pList(n-2)
  //   "((()))" + pList(n-3)
  //   ...
  // Here we use dynamic programming building up to all n counts.
  std::vector<long> memoized(n, 1);
  memoized[0] = 1;
  memoized[1] = 2;
  for (int i = 2; i < n; i++)
  {
    memoized[i] = 3 * memoized[i-1] - memoized[i-2];
  }

  return memoized[n - 1];
}

/**
 * Returns the number of permutations of valid sets of parentheses
 *
 * @note this seems like the correct algorithm comparing against a brute force
 *   implementation
 *
 * @param n - Number of parenthese pairs
 */
long pCount2(int n)
{
  if (n <= 2)
    return n;

  // The set of permutations for this number can be expressed in terms of lower
  // permutations:
  //   "(" + perms(n-1) + ")"
  //   "()" + perms(n-1)
  //   "(" + perms(1) + ")" + perms(n-2)
  //   "(" + perms(2) + ")" + perms(n-3)
  //   ...
  // This turns into a recursive formula
  //   f(i) = 2*f(i-1) + f(1)*f(i-2) + f(2)*f(i-3) + ... + f(i-2)*f(1)
  // Here we use dynamic programming building up to all n counts.
  std::vector<long> memoized(n, 1);
  memoized[0] = 1;
  memoized[1] = 2;
  for (int i = 2; i < n; i++)
  {
    memoized[i] = 2 * memoized[i-1];
    for (int j = 0; j < i-1; j++)
      memoized[i] += memoized[j] * memoized[i-2-j];
  }

  return memoized[n - 1];
}
