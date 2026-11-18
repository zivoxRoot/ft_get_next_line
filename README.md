*This project has been created as part of the 42 curriculum by tdefeche*

# Get next line

## Description

This project is the creation of an iterator: a function that reads a file descriptor and returns us the next line every time we call it on the same file descriptor.

## Instructions

> [!NOTE]
> For instructions on how to evaluate this project, refer to the [testing section](#testing)

1. Clone the repository
```bash
git clone -depth 1 https://github.com/zivoxRoot/ft_get_next_line.git
cd ft_get_next_line
```

2. Compile the program
```bash
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=2 main.c
```

> [!NOTE]
> Change *BUFFER_SIZE* to verify the behavior of the function depending on it

3. Use the generated executable
```bash
./a.out  # Use stdin as the file descriptor
./a.out test.txt  # Use a file
```

<details>
<summary>

## Algorithm

</summary>

The idea is to use a *static variable* to keep the necessary context between two calls to the `get_next_line` function.

> [!NOTE]
> A static variable keeps its value between two calls to the function containing it

We need to return the next file from the **file descriptor** (**fd**) at each call, for that we will read the **fd** by chunks of size *BUFFER_SIZE*, then return up to the *newline character* (`\n`) and keep the rest of the line in the static variable for the next call to use.

**Known limitations**

- I didn't do the bonus of handling multiple file descriptor, so if the function is called multiple times but passing in different **fd**s it will have undefined behaviors

</details>

## Resources

I used AI to verify edge cases on my program, and a little bit to restructure after my terrible design decisions.

An unsorted list of useful websites and articles

-[Static variables in C](https://www.geeksforgeeks.org/c/static-variables-in-c)
