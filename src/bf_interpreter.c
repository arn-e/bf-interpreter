#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ptr_operations.h"

#define MAX_DATA 5000

char instructions[MAX_DATA];
int memory[3000];
int *mem_ptr = memory;
char *read_ptr = instructions;
int running = 1;

void jump_forward(){
  while (*read_ptr){
    if (strncmp(read_ptr, "]", 1) == 0 ) { ++read_ptr; break;}
    ++read_ptr;
  }
  return;
}

void jump_back() {
  while (*read_ptr){
    if (strncmp(read_ptr, "[", 1) == 0) { break;}
    --read_ptr;
  }
  return;
}


void parse_cmd(char cmd)
{
  switch(cmd)
  {
    case '>':
      PTR_RIGHT;
      return;
    case '<':
      PTR_LEFT;
      return;
    case '+':
      INCREMENT;
      return;
    case '-':
      DECREMENT;
      return;
    case '.':
      PRINT_CHAR;
      return;
    case '[':
      if (*mem_ptr == 0){
        jump_forward();  
      }
      return;
    case ']':
      if (*mem_ptr > 0){
        jump_back();  
      }
      return;
    case ',':
      GET_CHAR;
      return;
  };
}

void read_instructions()
{
  while (running){
    if (*read_ptr == 0) { running = 0; }
    parse_cmd(*read_ptr);
    read_ptr ++;
  }
}

int main(int argc, char const *argv[])
{
  int i;
  char *input = NULL;

  printf("Instruction Set : \n");
  input = fgets(instructions, MAX_DATA-1, stdin);
  read_ptr = instructions;
  
  for (int i = 0; i < strlen(instructions); i ++){
    if (instructions[i] == '\n') { instructions[i] = '\0'; }

  }
  read_instructions();
  return 0;
}
