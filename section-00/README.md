> Tags: embedded systems, git, github, version control, shell commands

# Reading for section 00: Intro to Embedded systems, Git, and the shell

## Concept 1: Introduction to Embedded Systems

An embedded system is a specialized computer system. A combination of a computer processor, computer memory, and input/output peripheral devices that has a dedicated function within a larger mechanical or electronic system.

In our case within Dallas Formula Racing, this can be anything, from the dashboard display, data acquistition system, battery management system (EV) and many other smaller projects that support our development.

In embedded software development, and unlike ordinary software development, your code doesn’t run on your computer. It runs on a microcontroller instead. This means we’ll write firmware in C or C++ (right now just C), compile it using a toolchain like arm-none-eabi-gcc, and flash it onto the hardware using tools like `st-flash` and `openocd`. We’ll cover this process later, but know that the command line plays a big role here too. \*More on this later.

### What is a microcontroller?

A microcontroller is a tiny computer built into a single chip. Unlike the processor in your laptop, a microcontroller is designed to run one specific task, over and over again, without needing an operating system. It includes a processor, memory, and input/output pins all in one package so it can read sensors, control motors, or blink LEDs directly.

What that being said, microcontrollers (MCU) are not very powerful. At least, not compared to the CPUs in your PC and phone. MCUs run at lower clock speeds, have significantly less memory (cache, RAM). This is partially because they are designed to use significantly less power than normal CPUs.

This is not to say that microcontrollers are not capable. Microcontrollers are what power the hidden intelligence in everyday electronics: from your car’s dashboard to your microwave’s timer, and definitely the systems on our Formula SAE cars. Microcontrollers drive things from coffee pots to entire robots. Tesla, DJI (the drone company, also the parent company that runs the Robomaster competition), and a lot of hard drive producers use ST Microelectronics MCUs in their products.

In these tutorials, we will focus specifically on the line of microcontrollers designed by [ST Microelectronics](https://www.st.com/content/st_com/en.html). This is an industry standard line of MCUs and most of the knowledge provided here is very applicable to other MCUs, like Pi, ESP and Arduino.

### MCU vs MPU

You may hear the term microprocessor (MPU) being mixed in with microcontroller in the amateur literature of this field (reddit). To clarify, these are different things.

Broadly speaking, a microprocessor is generally more capable than a microcontroller. Sometimes MPUs need extra peripherals, like external RAM.

[Read this article](https://semiengineering.com/mpu-vs-mcu/) for more information.

## Concept 2: Introducing the shell.

Before writing code, we need to understand how to interact with our own computer. One of the most fundamental tools is the [shell](<https://en.wikipedia.org/wiki/Shell_(computing)>). Normally, we open an application to use the application software. In this case, the shell allows the user to access and use operating system's services. It's called "shell" because it's the outermost layer around the operating system.

To be clear, a shell is a command interpreter and a terminal is the application we type the command into. If I were to run `echo hello`, the program I type it in is the [terminal](https://en.wikipedia.org/wiki/Terminal_emulator), and the program that interprets the command and returns `hello` is the shell.

Understanding the shell is critical because many of the tools we’ll use in embedded development, like Git, compilers, and debugging utilities, are run from the command line.

The most basic shell commands involve navigating your directory. The root directory is the top-level folder in a computer's file system, denoted as `/`.

Your home directory is `~`. Use `pwd` for print working directory, `cd` for change directory, `mkdir` to make directory.

`rm` for removing files or directories; the flags/args for `rm` can be `-r` for recursive and `-f` for force. Using `rm -rf` (you can combine flags like this) will recursively force delete a file directory.

The superuser is admin-privilege special user that has **all rights and permissions** to **all files and programs** in **all modes**. Essentially, they can do anything. You can temporarily invoke this level of privilege by prepending `sudo` to your command.

Thus, by logical deduction, the command below will delete every file and program on your computer, essentially [bricking it](<https://en.wikipedia.org/wiki/Brick_(electronics)>).

```
# DO NOT RUN THIS COMMAND
sudo rm -rf /
# DO NOT RUN THIS COMMAND
```

All shell commands follow a similar structure: `<utility> <flags> <arguments>`. For example, if I wanted to switch to my home directory and create a text file named `bat.txt`, I would run `cd ~` and then `touch bat.txt`.

We can also download software using the shell.

> Try: Open a terminal window and enter `cd ~` then `pwd`.

This will navigate you to your home directory.

> Try: Now enter `cd ..` to move one level up.

You are now in the parent directory of `~`.

> Try: Run `ls -a` (list all) and you should see the name of your home directory.

These are just some (very common) examples of commands you may have to execute in the future. Here are some other ones.

| Command           | Purpose                                     |
| ----------------- | ------------------------------------------- |
| `grep`            | Search for text patterns in files or output |
| `ps aux`          | List all running processes                  |
| `kill`, `killall` | Stop a process by PID or name               |
| `top` / `htop`    | Live system performance monitor             |
| `find`            | Search for files by name/type/attributes    |
| `chmod`           | Change file permissions                     |
| `diff`            | Compare two files line-by-line              |

Before ending this section, there's one very important function of the command line that is extremely useful:

### Piping

Piping lets you take the output of one command and pass it as input to another.

It looks like this: `command1 | command2`.

A common example of piping is looking for error logs in system logs:

`cat system.log | grep "error"`.

For embedded, another example for piping is looking through a live serial monitor, reads live serial output from `/dev/ttyUSB0` and filters only lines containing “ADC”:

`cat /dev/ttyUSB0 | grep "ADC"`.

This is very useful for reading outputs to comb through errors and messages.

## Concept 3: Git, Github and Version Control

As developers, we often collaborate on giant, complex projects that involve all kinds of firmware, configurations and documentation. To manage changes efficiently, we use a version control software. The most popular one out there is called **Git**.

To avoid the common misconception: **[Git](https://git-scm.com/)** services are _hosted_ on [GitHub](https://github.com/). The same way videos are hosted on YouTube. Git runs locally on your machine.

Git, and version control software (VCS) in general, allows developers to:

- revert to earlier versions of your projects in case your project blows up
- see who made what changes and when
- work on new, experimental features outside of the main codebase
- collaborate without writing over others' work
- check if things work before [pushing to production](https://about.gitlab.com/blog/gitlab-dot-com-database-incident/)
- and other quality of life features that makes developing not unbearable

In a way, git gives us embedded developers a safety net, where one bad line of code can (actually and literally) [blow something up](https://en.wikipedia.org/wiki/Ariane_flight_V88). Bad firmware has been responsible [for a lot](https://en.wikipedia.org/wiki/Therac-25#Root_causes) of mess ups.

---

Git ensures that every change is tracked, reversible, and reviewable. With that in mind, let's look at some of the most basic git commands.

| Command                   | What It Does                                                                 |
| ------------------------- | ---------------------------------------------------------------------------- |
| `git init`                | Starts a new Git repository in your current directory                        |
| `git clone <repo link>`   | Copies a remote repository (e.g., from GitHub) to your local machine         |
| `git status`              | Shows the current state of your working directory and staged files           |
| `git add <file>`          | Stages a file (or `.` for all files) for commit                              |
| `git commit -m "message"` | Saves a snapshot of your staged changes with a message describing the change |
| `git log`                 | Displays commit history                                                      |
| `git diff`                | Shows the difference between your files and the last commit                  |
| `git branch`              | Lists branches or creates a new one                                          |
| `git checkout <branch>`   | Switches to a different branch                                               |
| `git merge <branch>`      | Merges another branch into your current one                                  |
| `git pull`                | Fetches and merges changes from the remote repository                        |
| `git push`                | Uploads your commits to the remote repository                                |

## Git Utility Files

Git tracks everything by default, but sometimes it shouldn't.

Projects often include a file called `.gitignore`, which tells Git what not to track. This is where you exclude things like:

- Build artifacts (`/build/`, `*.o`, `*.elf`)

- Logs or temporary files (`*.log`, `*.tmp`)

- System junk (`.DS_Store`, `Thumbs.db`)

- IDE settings (`.vscode/`, `.idea/`)

If you see weird merge conflicts or your repo feels bloated, you probably forgot to ignore something.

Other useful Git utility files include:

- `.gitattributes`: Controls file behavior (e.g., line endings, diff rules)

- `.gitkeep`: A placeholder file to force Git to track an otherwise empty directory (note: it’s just a convention, not a Git feature)

- `.gitconfig`: Your personal Git settings file, usually found in your home directory (~/.gitconfig)

---

## Github Workflow

Generally, most git actions follow this structure within the contributing process:

![img](../assets/0/githubflow.png)

### Navigate to WORK.md in this folder.
