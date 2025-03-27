# 📚 Libft

**Libft** is a foundational project from the 42 curriculum. It involves re-implementing standard C library functions from scratch, offering a deep understanding of memory manipulation, string handling, and general-purpose utilities in C.

This library serves as a base for other essential 42 projects like `ft_printf`, `get_next_line`, and `push_swap`.

---

## ✨ Features

### 🔹 Standard Library Reimplementations

#### 🧠 Memory Handling
- `ft_memset` – Fill a block of memory with a specific byte.
- `ft_memcpy` – Copy memory from one location to another.
- `ft_memmove` – Copy memory safely, handling overlaps.
- `ft_memcmp` – Compare memory areas.
- `ft_bzero` – Set a memory block to zero.
- `ft_calloc` – Allocate and zero-initialize memory.

#### 🔤 String Manipulation
- `ft_strlen` – Calculate the length of a string.
- `ft_strlcpy` / `ft_strlcat` – Safer string copying and concatenation.
- `ft_strncmp` – Compare strings up to `n` characters.
- `ft_strdup` – Duplicate a string.
- `ft_strchr` / `ft_strrchr` – Locate characters in a string.
- `ft_strnstr` – Search for a substring within a string.

#### 🔎 Character Checks
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`
- `ft_isascii`, `ft_isprint`
- `ft_tolower`, `ft_toupper`

---

### 🔹 Custom Utility Functions

#### 🧵 String Utilities
- `ft_substr` – Extract a substring.
- `ft_strjoin` – Concatenate two strings.
- `ft_strtrim` – Trim specific characters from the start and end of a string.
- `ft_split` – Split a string into an array of strings based on a delimiter.

#### 🔢 Numerical Conversions
- `ft_itoa` – Convert an integer to a string.
- `ft_atoi` – Convert a string to an integer.

#### 🖨️ File Descriptor Output
- `ft_putchar_fd` – Output a character to a file descriptor.
- `ft_putstr_fd` – Output a string to a file descriptor.
- `ft_putendl_fd` – Output a string followed by a newline.
- `ft_putnbr_fd` – Output an integer to a file descriptor.

---

## 🛠️ Installation

Clone the repository and compile the static library:

git clone https://github.com/yourusername/libft.git
cd libft
make

---

## 📁 Project Structure

libft/ ├── ft_*.c # Source files for each libft function ├── libft.h # Header file with all function prototypes ├── Makefile # Build system to compile the library └── libft.a # Static library generated after compilation


## ✅ Notes

- ✅ Fully **Norminette-compliant**
- ✅ No **memory leaks**
- ✅ **Modular** and **reusable** across multiple C projects
- ✅ Integral part of core 42 projects:
  - `ft_printf`
  - `get_next_line`
  - `push_swap`
  
