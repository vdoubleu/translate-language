#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
  // an example command call to translate would be:
  // tr <targetFile> <translateFile>

  // checks number of arguments is 3
  if (argc != 3) {
    fprintf(stderr, "wrong number of args");
    return 0;
  }

  // tries to open the translation file and store a ptr to that file
  FILE *translateFilePtr;
  if ((translateFilePtr = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "error opening file");
    return -1;
  }

  // reads the content of the translate file line by line
  char line[INT_MAX]; // assumes each line is not longer than INT_MAX
  while (fgets(line, sizeof(line), translateFilePtr)) {
    printf("%s", line);
  }

  fclose(translateFilePtr);

  return 0;
}
