# Ft_printf

## Overview

**ft_printf** is a custom implementation of the standard `printf` function in C. This project is commonly used in coding schools like 42 to teach students about variadic functions, formatted output, and handling different data types.

## Features
- Supports multiple format specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
- Handles variable arguments using `va_list`.
- Custom implementation of standard library functions.
- Efficient and optimized output handling.

## Installation
Clone this repository:
```sh
git clone https://github.com/valeria-pal/ft_printf.git
cd ft_printf
```

## Usage
Compile the function with your project:
```sh
gcc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c -o test
```

Example usage:
```c
#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    int num = 42;
    char *str = "Hello, world!";
    
    ft_printf("Number: %d\n", num);
    ft_printf("String: %s\n", str);
    return (0);
}
```

## Function Prototype
```c
int ft_printf(const char *format, ...);
```

## How It Works
1. Parses the format string to detect conversion specifiers.
2. Retrieves variable arguments using `va_list`.
3. Handles and formats different data types accordingly.
4. Writes output to `stdout` efficiently.

## Project Files
- `ft_printf.c` - Main function implementation.
- `ft_printf.h` - Header file with function prototype.
- `ft_printf_utils.c` - Helper functions for formatting and printing.

## Notes
- Supports basic formatting but does not handle floating-point numbers.
- The function returns the total number of characters printed.



