# Stack pet project - implementation stack on **C** language

## 📋 Description
My stack support a basics functions as:
- **push** - add a value on top
- **pop** - delete a value from top
- **top** - get a value from top
- **clean** - full stack clear
- **size** - get a amount of values in stack
- **is_empty** - check if stack is empty


**main.c** and **Makefile** needed to check the functionality of the stack implementation. 

## ⚙️ Installation
To add this repository you need to:
```bash
git clone https://github.com/ImishgunI/Stack.git
cd Stack
```

Okey, now you already can use this code.
```bash
gcc -Wall -Werror -Wextra -std=c11 ./src/stack.c ./src/main.c -o main
```

If you wanna do a static or dynemic library, you should do:

### On Windows:
Install MinGW if not installed and put **gcc** in PATH 
```bash
gcc -c ./src/stack.c -o stack.o
ar rcs libstack.a stack.o
```
Write a simple code:
```c
#include "./src/stack.h"

int main() {
    stack* myStack = NULL;
    push(&myStack, 10);
    push(&myStack, 20);
    printf("%d", top(myStack));
    clean(&myStack);
    return 0;
}
```

And then compile and start a program with static lib
```bash
gcc ./src/main.c -L. -lstack -o main.exe
./main.exe
```

For dynamic lib:
```bash
gcc -c -fPIC ./src/stack.c -o stack.o
gcc -shared -o libstack.dll stack.o
gcc ./src/main.c -L. -lstack -o main.exe
./main.exe
```

### On UNIX:
```bash
gcc -c ./src/stack.c -o stack.o
ar rcs libstack.a stack.o
```

You can use code from top, cause i skip step with write code

```bash
gcc ./src/main.c -L. -lstack -o main
./main
```

For dynamic lib:
```bash
gcc -c -fPIC ./src/stack.c -o stack.o
gcc -shared -o libstack.so stack.o
gcc ./src/main.c -o main -L. -lstack -Wl,-rpath,.
./main
```
if you have an error with dynamic lib do that:
```bash
export LD_LIBRARY_PATH=path/to/lib
./main
```
