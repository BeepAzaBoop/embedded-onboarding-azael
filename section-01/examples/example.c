#include <stdio.h>
#include <stdlib.h>

// This define macro will disappear after preprocessing
#define add(x, y) ((x) + (y))

// This is a simple C program that prints "Hello, world!" and
// lists any command-line arguments provided by the user.

int main(int argc, char **argv) {
  printf("Hello, world!\n");
  printf("The sum of 3 and 4 is: %d\n", add(3, 4));
  // Check if any command-line arguments were provided

// This will be removed by the preprocessor as well,
// it will turn into a single line with no conditionals
#ifdef DEBUG
  printf("Debug mode is enabled.\n");
#else
  printf("Debug mode is disabled.\n");
#endif

  if (argc > 1) {
    printf("You provided %d argument(s):\n", argc - 1);
    for (int i = 1; i < argc; i++) {
      printf("Argument %d: %s\n", i, argv[i]);
    }
  } else {
    printf("No additional arguments provided.\n");
  }

  // All is good.
  return 0;
}