#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Provide two numbers as arguments.\n");
    return 1;
  }

  int a = strtol(argv[1], (char **)NULL, 10);
  int b = strtol(argv[2], (char **)NULL, 10);
  printf("%d + %d = %d\n", a, b, a+b);

  return 0;
}
