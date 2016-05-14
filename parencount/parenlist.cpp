#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

long pList(int n, string before = "", string after = "");

int main(int argCount, char** argList)
{
  int n = -1;
  char description[] =
    "Description:\n"
    "\n"
    "  Given a number of parenthese pairs, this function will enumerate each\n"
    "  permutation and print the count of how many balanced permutations of that\n"
    "  many pairs there are.\n";

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
    printf("ERROR:  You must provide an integer greater than 0\n");
    PRINT_USAGE;
    return 2;
  }

  printf("Pairs:        %d\n", n);
  printf("Permutations: %ld\n", pList(n));  // Old wrong implementation

  return 0;
}

/**
 * Prints each permutation of closed parentheses and returns the count
 *
 * @note this was later found to be wrong as it was based on wrong
 *   assumptions
 *
 * @param n - Number of parenthese pairs
 * @param before - Printed before permutations
 * @param after - Printed after permutations
 */
long pList(int n, string before, string after)
{
  long permutations = 0;

  // Base cases
  if (n < 1)
    return 0;
  if (n == 1) {
    cout << before << "()" << after << endl;
    return 1;
  }

  // @note This is wrong logic, but here for seeing what it was trying to do
  // The set of permutations for this number can be expressed in terms of lower
  // permutations:
  //   "(" + pList(n-1) + ")"
  //   "()" + pList(n-1)
  //   "(())" + pList(n-2)
  //   "((()))" + pList(n-3)
  //   ...
  // @note: The correct set of expressions is
  //   "(" + pList(n-1) + ")"
  //   "()" + pList(n-1)
  //   "(" + pList(1) + ")" + pList(n-2)
  //   "(" + pList(2) + ")" + pList(n-3)
  //   ...
  //   "(" + pList(n-2) + ")" + pList(1)
  // I didn't want to figure out how to implement printing all permutations the
  // correct way...
  permutations += pList(n-1, before + "(", ")" + after);

  for (int i = 1; i < n; i++) {
    string newBefore = before + string(i, '(') + string(i, ')');
    permutations += pList(n-i, newBefore, after);
  }
  return permutations;
}

