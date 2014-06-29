/*
A generic stack datatype in C using macros.
*/
#ifndef _L_STACK_H
#define _L_STACK_H

#include <stdlib.h>

/*
Creates a named struct which represents a stack. 
This would be called if you wanted to write functions 
that accepted these stack types.
*/
#define LSTACK_CREATE_DATATYPE(name, type)	\
	struct name				\
	{					\
		size_t size, capacity;		\
		type *array;			\
	};

/*
Used to declare a variable of type stack by creating
an anonymous struct representing a stack.
*/
#define lstack_t(type) struct { size_t size, capacity; type *array; }

/*
Initializes a stack variable.
*/
#define lstack_init(s) ((s).size = 0, (s).capacity = 8, (s).array = malloc((s).capacity * sizeof(*(s).array)))

/*
Frees up memory occupied by a stack.
*/
#define lstack_del(s) free((s).array)

/*
Pushes an item onto the stack.
*/
#define lstack_push(item, s)					\
	do							\
	{							\
		if((s).size == (s).capacity)			\
		{						\
			(s).capacity = (s).capacity << 1;	\
			(s).array = realloc((s).array, (s).capacity * sizeof(*(s).array));	\
		}						\
		(s).array[(s).size++] = (item);			\
	} while(0)

/*
Pops an item off of the stack.
*/
#define lstack_pop(s) ((s).array[--(s).size])

/*
Looks at the top item of the stack.
*/
#define lstack_peek(s) ((s).array[(s).size - 1])

/*
Checks to see if the stack is empty.
*/
#define lstack_empty(s) ((s).size == 0)

/*
Returns the size of the stack.
*/
#define lstack_size(s) ((s).size)

/*
Applies a function to each element of the stack. 
*/
#define lstack_foreach(func, s)			\
	do					\
	{					\
		int i;				\
		for(i = 0; i < (s).size; i++)	\
		{				\
			func((s).array[i]);	\
		}				\
	} while(0)

#endif

