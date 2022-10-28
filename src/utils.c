#include "../include/utils.h"
#include "../include/defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_introduction() {
  printf("******************\n");
  printf("** Hello world! **\n");
  printf("******************\n");

  printf(">> This is an Binary to Decimal Converter!\n");
}

void ask_for_number() {
  extern char binary[MAX_BINARY_BUFFER_SIZE];

  printf(">> Enter a binary number: ");

  scanf("%s", binary);
}

int check_number() {
  extern char binary[MAX_BINARY_BUFFER_SIZE];
  size_t binary_length = strlen(binary);

  for (int i = 0; i < binary_length; i++) {
    if (binary[i] != ONE && binary[i] != ZERO) {
      printf("** Invalid input! **\n");
      printf("In position %d there is a \'%c\' character!\n", i, binary[i]);
      return -1;
    }
  }
  return 0;
}

void try_again() {
  char answer;
  printf(">> Do you want to try again? [y/n]: ");

  scanf("%c", &answer);
  scanf("%c", &answer);

  switch (answer) {
  case 'y':
  case 'Y':
    printf(">> Ok! Let's try it again!\n");
    break;
  case 'n':
  case 'N':
    printf(">> Ending program...\n");
    exit(0);
  default:
    printf(">> Unknown option! Ending program...\n");
    exit(1);
  }
}

int convert_number() {
  extern char binary[MAX_BINARY_BUFFER_SIZE];
  int numberOfBits = strlen(binary);

  int currentPowerOfTwo = 1;
  int decimalNumber = 0;

  for (int i = numberOfBits - 1; i >= 0; i--) {
    if (binary[i] == ONE)
      decimalNumber += currentPowerOfTwo;
    currentPowerOfTwo *= 2;
  }

  printf("%s in decimal is %d\n", binary, decimalNumber);

  return 0;
}

void want_another_run() {
  extern int end_program;

  char answer;
  printf(">> Do you want another run? [y/n]: ");

  scanf("%c", &answer);
  scanf("%c", &answer);

  switch (answer) {
  case 'y':
  case 'Y':
    printf(">> New run!\n\n\n");
    break;
  case 'n':
  case 'N':
    end_program = 1;
    break;
  default:
    printf(">> Unknown option! Ending program...\n");
    exit(1);
  }
}

void print_acknowledgments() {
  printf("\n>> Thank you for using the tool!\n\n");

  printf("********************\n");
  printf("** See you later! **\n");
  printf("********************\n");
}
