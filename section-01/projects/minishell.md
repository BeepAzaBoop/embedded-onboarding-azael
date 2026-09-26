# 3. Mini Shell

## Goal: Interactive REPL that dispatches commands based on string input

A read–eval–print loop (REPL), also termed an interactive toplevel or language shell, is a simple interactive computer programming environment that takes single user inputs, executes them, and returns the result to the user; a program written in a REPL environment is executed piecewise.

## Required Features:

Maintain a command table:

```C
typedef struct {
  const char* name;
  void (*func)(void);
} command_t;
```

Implement at least:

- help: list all commands

- greet: print greeting

- add: take two user-input ints and print sum

- exit: exit loop

Use fgets() and strcmp() to interpret commands

Run in a loop until exit

Add timestamp and uptime

Optional: ASCII art commands

## Test Harness:

Show interaction.

Use print statements to demonstrate internal behavior.

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
