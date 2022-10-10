#include "defines.h"
#include "utils.h"
#include <stdio.h>

char binary[MAX_BINARY_BUFFER_SIZE];
int end_program = 0;

int main() {
  print_introduction();

  while (!end_program) {
    ask_for_number();

    if(check_number()){
      try_again();
      continue;
    }

    convert_number();

    want_another_run();
  }

  print_acknowledgments();

  return 0;
}
