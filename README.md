# get_next_line

## Description
This project implements a function that reads a line from a file descriptor. When called in a loop, get_next_line returns the complete content of a file, one line at a time. This function is particularly useful for parsing files line by line and helps develop a deeper understanding of static variables, memory management, and file operations in C.

## Installation
Clone the repository and include the files in your project:

```bash
git clone https://github.com/Evan-Edwards/get_next_line.git
cd get_next_line
```

The project consists of the following files:
- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper functions
- `get_next_line.h` - Header file with prototypes and definitions

## Usage
To use get_next_line in your project:

1. Include the header in your C files:
```c
#include "get_next_line.h"
```

2. Compile your project with all necessary files:
```bash
gcc your_file.c get_next_line.c get_next_line_utils.c
```

3. Basic usage example:
```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("example.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
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

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- Returns the line that was read (including the newline character if present)
- Returns NULL if there is nothing else to read or if an error occurred

## Buffer Size
The buffer size for reading can be modified during compilation using the `-D BUFFER_SIZE=n` flag:
```bash
gcc -D BUFFER_SIZE=42 your_file.c get_next_line.c get_next_line_utils.c
```

## Implementation Details

### Key Features
- Reads from multiple file descriptors simultaneously
- Handles both small and large buffer sizes efficiently
- Memory-leak free implementation
- Handles reading from files, standard input, and other file descriptors

### Helper Functions
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate character in string
- `ft_strjoin` - Join two strings
- `ft_substr` - Extract substring from string
- `ft_strdup`: Creates a duplicate of the input string by allocating new memory and copying the contents

### Error Handling
- Invalid file descriptor management
- Memory allocation failure handling
- Empty file handling
- End of file handling
- Read error management

---
Created as part of the 42 curriculum.