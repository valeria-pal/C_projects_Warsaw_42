ft_printf

Overview

ft_printf is a custom implementation of the standard printf function in C.

Features

Supports multiple format specifiers: %c, %s, %d, %i, %u, %x, %X, and %%.

Handles variable arguments using va_list.

Custom implementation of standard library functions.

Efficient and optimized output handling.

Installation

Clone this repository:

git clone https://github.com/valeria-pal/ft_printf.git
cd ft_printf

Usage

Compile the function with your project:

gcc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c -o test

Example usage:

#include <stdio.h>
#include "ft_printf.h"

int main(void) {
    int num = 42;
    char *str = "Hello, world!";
    
    ft_printf("Number: %d\n", num);
    ft_printf("String: %s\n", str);
    return (0);
}

Function Prototype

int ft_printf(const char *format, ...);

How It Works

Parses the format string to detect conversion specifiers.

Retrieves variable arguments using va_list.

Handles and formats different data types accordingly.

Writes output to stdout efficiently.

Project Files

ft_printf.c - Main function implementation.

ft_printf.h - Header file with function prototype.

ft_printf_utils.c - Helper functions for formatting and printing.

Notes

Supports basic formatting but does not handle floating-point numbers.

The function returns the total number of characters printed.