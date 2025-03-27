# Libft

## 📚 Overview

**Libft** is a custom implementation of standard C library functions. It re-creates many of the common string, memory, character, and utility functions typically found in `<string.h>`, `<stdlib.h>`, and `<ctype.h>`. This project is a foundation for many other C projects, such as `ft_printf`, `get_next_line`, and `push_swap`.

## ✨ Features

### 🔹 Standard Library Reimplementations

#### Memory Handling
- `ft_memset` – Fill a block of memory with a specific byte.
- `ft_memcpy` – Copy memory from one location to another.
- `ft_memmove` – Copy memory safely, handling overlap.
- `ft_memcmp` – Compare memory areas.
- `ft_bzero` – Set a memory block to zero.
- `ft_calloc` – Allocate and zero-initialize memory.

#### String Manipulation
- `ft_strlen` – Calculate the length of a string.
- `ft_strlcpy`, `ft_strlcat` – Safer versions of `strcpy`/`strcat`.
- `ft_strncmp` – Compare strings up to `n` characters.
- `ft_strdup` – Duplicate a string.
- `ft_strchr`, `ft_strrchr` – Locate characters in a string.
- `ft_strnstr` – Locate a substring within a string.

#### Character Checks
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`
- `ft_isascii`, `ft_isprint`
- `ft_tolower`, `ft_toupper`

### 🔹 Custom Utility Functions

#### String Utilities
- `ft_substr` – Extract a substring.
- `ft_strjoin` – Concatenate two strings.
- `ft_strtrim` – Trim characters from start/end.
- `ft_split` – Split a string into an array based on a delimiter.

#### Numerical Conversions
- `ft_itoa` – Convert integer to string.
- `ft_atoi` – Convert string to integer.

#### File Descriptor Output
- `ft_putchar_fd` – Print a character to a file descriptor.
- `ft_putstr_fd` – Print a string to a file descriptor.
- `ft_putendl_fd` – Print a string with newline.
- `ft_putnbr_fd` – Print a number.

---

## 🛠️ Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/libft.git
cd libft
make

📁 Project Structure
libft.h – Header file with all function prototypes.

*.c – Function source files.

Makefile – To build the library (libft.a).

✅ Notes
Norm-compliant.

No memory leaks.

Designed to be reused across other 42 projects like ft_printf, get_next_line, push_swap, etc.


