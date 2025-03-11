# Get Next Line

## Overview

**Get Next Line** is a function that reads a line from a file descriptor, returning it as a dynamically allocated string. 
## Features
- Reads a single line from a file descriptor, including newline characters.
- Efficient buffer management to minimize read calls.
- Works with multiple file descriptors simultaneously.
- Proper memory handling to prevent leaks.

## Installation
Clone this repository:
```sh
git clone https://github.com/valeria-pal/getnextline.git
cd getnextline
```

## Usage
Compile the function with your project:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o test
```

Example usage:
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    
    if (fd == -1) {
        perror("Error opening file");
        return (1);
    }
    
    while ((line = get_next_line(fd))) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Function Prototype
```c
char *get_next_line(int fd);
```

## How It Works
1. The function reads from a file descriptor in chunks defined by `BUFFER_SIZE`.
2. It accumulates data in a static variable to handle partial reads.
3. It extracts and returns a full line each time it's called.
4. It properly frees memory when the end of the file is reached or an error occurs.

## Project Files
- `get_next_line.c` - Main function implementation.
- `get_next_line.h` - Header file with function prototype.
- `get_next_line_utils.c` - Helper functions for memory and string operations.

## Notes
- `BUFFER_SIZE` must be defined at compilation time.
- The function returns `NULL` when the end of the file is reached or in case of an err