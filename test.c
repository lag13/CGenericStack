#include <stdio.h>
#include <stdlib.h>

#include "lstack.h"

void printInt(int x)
{
	printf("%d, ", x);
}

#define stackStats(s) 	\
	do {	\
	printf("Stack Size: %zd\nStack Empty: %d\n", lstack_size(s), lstack_empty(s));	\
	if(lstack_size(s) > 0)	{	\
		printf("Last Element: %d\n", lstack_peek(s));	\
		printf("Stack Contents:\n");	\
		lstack_foreach(printInt, s);	\
	}	\
	else {	\
		printf("Stack Contents:\n<Empty>");	\
	}	\
	} while(0)

#define section(headerStr, code)	\
printf("\n##############################################################\n");\
printf("--------------------------------------------------------------\n");\
printf(headerStr);			\
printf("\n--------------------------------------------------------------\n");\
code					\
printf("\n##############################################################\n")

LSTACK_CREATE_DATATYPE(int_stack, int);

int
main(int argc, char **argv)
{
	int i;
	//struct int_stack s;
	lstack_t(int) s;
	lstack_init(s);

	section("Pushing 1 Item onto the Stack", 
		lstack_push(101, s);
		stackStats(s);
	);

	section("Popping 1 Item from the Stack", 
		printf("Item popd: %d\n", lstack_pop(s));
		stackStats(s);
	);

	section("Pushing 1 Item onto the Stack", 
		lstack_push(33, s);
		stackStats(s);
	);

	section("Pushing 100 Items onto the Stack", 
		for(i = 0; i < 100; i++)
		{
			lstack_push(i, s);
		}
		stackStats(s);
	);

	section("Popping 50 Items from the Stack", 
		printf("Items popped\n");
		for(i = 0; i < 50; i++)
		{
			printf("%d, ", lstack_pop(s));
		}
		printf("\n");
		stackStats(s);
	);

	section("Pushing 100 Items onto the Stack", 
		for(i = 100; i < 200; i++)
		{
			lstack_push(i, s);
		}
		stackStats(s);
	);

	section("Deleting the stack", 
		lstack_del(s);
	);
	return 0;
}

