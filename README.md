CGenericStack
=============

A generic stack in C created with macros.

About:
-----
The C preprocessor is fun to mess with because it's like a mini programming language on top of C. You can use it to create things that look like new syntax and in this case I faked a generic stack. All you need to do is include the header file and you're ready to go!

Example usage:
--------------
```
lstack_t(char) s;     //Create a stack that holds char's
lstack_init(s);       //Initialize the stack
lstack_push('c', s);  //Push and pop elements
lstack_pop(s);
lstack_del(s);        //Clean up
```

Internals:
----------
Internally this stack is an array which starts off with an initial capacity of 8 (arbitrary) and it will double in size whenever the capacity is reached.
