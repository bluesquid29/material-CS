
## How can I know the version of c? (25-11-4)

There are different IDE, and we want to test the version.

```c
#include <stdio.h>

int main() {
  #if defined __STDC_VERSION__ 
    long version = __STDC_VERSION__;
    if ( version == 199901 ) {
      printf ("version detected : C99\n");
    }
    if ( version == 201112 ) {
      printf ("version detected : C11\n");
    }
    if ( version == 201710 ) {
      printf ("version detected : C17/C18\n");
    }
  #else 
    printf ("version detected : C90\n");
  #endif
}
```

### The result

IF you download [x86_64-8.1.0-release-posix-seh-rt_v6-rev0.7z](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/) to your VScode, the compile result is

```
version detected : C17/C18
```

---

The version of Dev-C++ and CP-Editor are

```
version detected : C90
```

This is a really old version, you might face some problems when create the file name that end with `.c`, EX:

- `for` loop initial declarations are only allowed in C99 or higher mode

you should always use `.cpp`, no matter c/c++.

## The Important Experience of C

- Check your version before editing
	- `for` loop initial declarations are only allowed in C99 or higher mode
- `%d` (and `%lld`, `%f`, etc.) **automatically skip leading whitespace** anyway, but
	- Use space **BEFORE** `%c` to skip whitespace

## Some useful tips

### Loop

#### While

- `while (t--)` means `while (t-- > 0)`, if `t = 5`

>runs the loop until `t` is `0` during checking it's value, since `0` is equally to `false` in a logical context.
>
>Because `t--` is the post decremental operator on `t`, the value of it will be modified after the `while` checks it, so it will be -1 in the end. Therefore, the values of `t` inside the loop will be: 4,3,2,1,0.

### Boolean

```c
int boolean = 1;  // 1 = true, 0 = false
```

- `1` (or any non-zero) = **true**
- `0` = **false**
# Reference

- [How can I know the version of c?](https://stackoverflow.com/questions/36662063/how-can-i-know-the-version-of-c)
- [how to enable C++11 or C++14 in Dev C++ IDE - Stack Overflow](https://stackoverflow.com/questions/64371274/how-to-enable-c11-or-c14-in-dev-c-ide)