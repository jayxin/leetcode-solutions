#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
  int compute(int x) {
    return x;
  }
};

int main(int argc, char *argv[])
{
  Solution s;
  int n;
  scanf("%d", &n);
  printf("%d\n", s.compute(n));
  return EXIT_SUCCESS;
}
