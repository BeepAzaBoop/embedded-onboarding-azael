# 2. Memory Tracker

## Goal: Simulate and track dynamic memory allocations using structs

You’ll build a simple system that logs every memory allocation made, stores their metadata, and allows manual deletion by ID. This helps you practice pointers, dynamic arrays, and memory-safe programming.

## Required Features:

Define a struct:

```C
typedef struct {
  int id;            // Unique identifier for this allocation
  size_t size;       // Size in bytes
  void* addr;        // Address returned by malloc
} allocation_t;
```

### Implement at least:

`add_allocation`: Allocates memory and stores metadata in a dynamic array

`remove_allocation`: Frees memory and removes the corresponding struct by ID

`print_allocations`: Lists all active allocations with address and size

### Internally:

Use `malloc` and `free` for memory

Use `realloc` to grow the dynamic array of `allocation_t`

Manually shift array elements when removing

Use simple integer IDs to track which allocation is which.

# Test Harness:

In `main()`, hardcode a sequence of operations:

- Add 3 allocations

- Print all

- Remove one by ID

- Print again

- Free all at the end

- Optional Features:

- Add lookup by ID function

- Automatically assign IDs

- Add safety checks for double-free or invalid IDs

### Instructions and requirements that apply to all projects:

- You must link your project as a submodule within your forked copy of the repository

- Your code must be modular. You must write header files for each source file you write. You must also keep source files in a subdirectory called `src` and header files in a subdirectory called `inc`.

- This goes without saying, but you may only use the C language.

  - If you so choose, you may use inline assembly. This is optional.
  - You must have comments. Minimum 1 multi-line comment per function.

- You must use the _Make_ build system and you must write your own `makefile`. Requirements for build system:

  - It must place build output files in a subdirectory called `build`.
  - It should support `make clean`, which cleans the `build` folder.
  - It should support `make run`, which runs the built executable.

- Create a GitHub Actions workflow in `.github/workflows/build.yml`. Your workflow must:

  - Run on `ubuntu-latest`

  - Perform the following:

  - Checkout the repository

  - Initialize and update submodules

  - Run make and confirm a clean build

  - (Optional bonus) Run make run and check for expected output

- You must have a minimum of 7 **well-named, significant** commits. If you think your project can be finished under 7 commits, it is not hard enough.

  - Pull requests for merging features on branches is not required.

- Create a `README.md` that aptly describes what your project does. Your `README.md` must also contain **all** of the following:

  - A directory tree: use the `tree` command line tool
  - A short explanation of each module

- If you need help, I have created an example project that satisfies all of the conditions (except module explanations and comments). View it [here](https://github.com/wxkim/julia).

  - Note: Your project should be significantly **less** complex than the example.

- Finally, your project must work. It should build, and functionality error should be minimal, if not zero.
  - You do not have to make this project cross-platform.
