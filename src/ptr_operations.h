#ifndef MACROS_H_
#define MACROS_H_

#define PTR_RIGHT (++mem_ptr)
#define PTR_LEFT (--mem_ptr)
#define INCREMENT (++*mem_ptr)
#define DECREMENT (--*mem_ptr)
#define PRINT_CHAR (putchar(*mem_ptr))
#define GET_CHAR (*mem_ptr = getchar())

#endif 
