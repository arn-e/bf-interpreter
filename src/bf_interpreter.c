#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char input[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
int memory[1000];
int *mem_ptr = memory;
char *read_ptr = input;
int running = 1;

void ptr_right()
{
  ++mem_ptr;
  return;
}

void ptr_left()
{
  --mem_ptr;
  return;
}

void increment()
{
  ++*mem_ptr;
  return;
}

void decrement()
{
  --*mem_ptr;
  return;
}

void print_char()
{
  putchar(*mem_ptr);
  return;
}

void get_char()
{
  *mem_ptr = getchar();  
  return;
}

void jump_forward(){
  while (*read_ptr){
    if (strncmp(read_ptr, "]", 1) == 0 ) { ++read_ptr; break;}
    ++read_ptr;

  }
s  return;
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
      ptr_right();
      return;
    case '<':
      ptr_left();
      return;
    case '+':
      increment();
      return;
    case '-':
      decrement();
      return;
    case '.':
      print_char();
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
      get_char();
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

  while (i != EOF) {

  }
  read_instructions();
  return 0;
}