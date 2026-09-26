_Author: WK_

## **1. Download Tools:**

### **VSCode:** All operating systems installations can be found [here](https://code.visualstudio.com/download).

If you know what you’re doing, feel free to use another text editor.  
 Instructions in part 3 assume that you are on VSCode.

### **Package Manager -** Easily install packages

Windows users should install [MSYS2](https://www.msys2.org/docs/installer/).  
 Go to [Installers](https://github.com/msys2/msys2-installer/releases/tag/nightly-x86_64) on their GitHub website.  
MacOS users should install [Homebrew](https://brew.sh/).  
Linux (Ub22) already has Adv Package Tool “apt” installed. If not, find it [here](https://security.ubuntu.com/ubuntu/pool/main/a/apt/).

### **MSYS2 MinGW64 SHELL - Windows Users Only**

Install MSYS2 MinGW64 Shell, which you already did in the step above.

Launch MSYS2 MinGW64 Shell.

For Windows, all of the following commands will be run on MinGW64. See:

![](assets/0/msys2.png)

For all other operating systems, run on your preferred terminal.

### **Git -** Is a version control system that allows you to contribute your software.

[Optional] If you are unfamiliar with git, feel free to download GitHub Desktop Client.

> _Do **not** install Git manually from the Git website._

Windows: `pacman -S mingw-w64-x86_64-tools-git  `

MacOS: `brew install git  `

Linux: `sudo apt install git`

### **OpenOCD** - Used for flashing and debugging. Install it using the appropriate package manager by running a command in your terminal.

Windows: `pacman -S mingw-w64-x86_64-openocd  `

MacOS: `brew install openocd`

Linux: `sudo apt install openocd`

### **Arm-Embedded Toolchain** - A collection of tools used to develop software for ARM Cortex MCUs. Install using the same process as OpenOCD.

Windows: `pacman -S mingw-w64-x86_64-arm-none-eabi-gcc  `

MacOS: `brew install --cask gcc-arm-embedded  `

Linux: `sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi`

### **Make** - Automates the build process using a Makefile. 

Windows: `pacman  -S mingw-w64-x86_64-make  `

MacOS:`brew install make `

Linux: `sudo apt install make`

### **Cmake** - Generates build systems for projects that require cross-compilation.

Windows: `pacman -S mingw-w64-x86_64-cmake `

MacOS: `brew install cmake `

Linux: `sudo apt update; sudo apt install cmake`

### **Ninja** - Lightweight and fast builder

Windows: `pacman -S mingw-w64-x86_64-ninja `

MacOS: `brew install ninja  `

Linux: `sudo apt update; sudo apt install ninja-build`

### **ST-Link** - Flashes the firmware to STM32 microcontrollers and enables debugging.

Windows: `pacman -S mingw-w64-x86_64-stlink `

MacOS: `brew install stlink  `

Linux: `sudo apt install stlink-tools`

> Windows: also download [ST Drivers for Windows](https://www.st.com/en/development-tools/stsw-link009.html)

### **Clangd** - A language server and compiler backend that makes your job 10x easier.

Windows: `pacman -S mingw-w64-x86_64-clang  `

MacOS: `brew install llvm  `

Linux: `sudo apt install clangd`

### **Python3** - CMake and other tools may use this as a dependency. Just in case.

Windows: `pacman -S mingw-w64-x86_64-python  `

MacOS: `brew install python  `

Linux: `sudo apt install python3`

### **Known Errors and Fixes:**

If you run into any installation issues, double check the command here:  
 Windows: [https://packages.msys2.org/queue?build_type=mingw64](https://packages.msys2.org/queue?build_type=mingw64)  
 MacOS: [https://formulae.brew.sh/](https://formulae.brew.sh/)  
 Linux: [https://packages.ubuntu.com/](https://packages.ubuntu.com/)

> This section will be expanded to continuously address any issues encountered

## **2. Configuring your PATH variable**

_Your $PATH tells your shell where to look for binaries. One of the consequences of having inaccurate $PATH variables is that shell will not be able to find and execute programs without a full $PATH._

> For this guide's sake, Unix refers to both macOS (OS X) and any Linux distribution.

**Windows:** Follow the instructions from [this article](https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/) to add `C:\msys64\mingw64\bin` and `C:msys64\usr\bin` and other tools to PATH. If system environment does not work, try adding to local user. Also, add git to path the same way, if you haven’t already.

**MacOS:** Use a text editor to add the following line to your shell’s configuration file (e.g., .bashrc, .zshrc): `export PATH="/opt/homebrew/bin:$PATH"`.

**Linux:** edit `~/.profile` (or `~/.bash_profile`), similar to MacOS.

Note: the install location may differ for you, so update your environment variable as necessary.

Make sure everything works by running `<bin> --version` for each tool in the list.  
Then run `which <bin>` or `where<bin>` for Unix or Windows, respectively.  
They should return their paths.

Additionally, Unix users may run `echo $PATH` to verify each binary installation location is in the path. For Windows, `echo $env:Path`.

Linux users may need udev rules to flash via USB. Please see [this guide on configuring udev](https://medium.com/@darshankt/setting-up-the-udev-rules-for-connecting-multiple-external-devices-through-usb-in-linux-28c110cf9251).

Restart your computer.

## **3. Run and Flash**

1. Clone repo.
2. Open in VSCode. Make sure the workspace path is the root of the directory.

3. Connect H7 Nucleo board via USB to USBC.

4. Press CTRL + SHIFT + P. Then select “Tasks: Run Task”. Select “Run All”.

- Alternatively, just press CTRL + SHIFT + **B** to immediately run “Tasks: Run Build Task”.

## **4. Further Readings**

_If you have questions about how something works or want to learn more._

- Intro to Unix Commands: [Essential Unix Commands - GeeksforGeeks](https://www.geeksforgeeks.org/essential-linuxunix-commands/)
- What is git?: [Git](https://git-scm.com/)
- Git commands: [Git cheat sheet | Atlassian Git Tutorial](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)
- SUDO: [sudo(8): Linux man page](https://linux.die.net/man/8/sudo)
- MinGW: [MinGW-w64 - for 32 and 64 bit Windows / Wiki2 / History](https://sourceforge.net/p/mingw-w64/wiki2/History/)
- MSYS2: [MSYS2 | Main](https://www.msys2.org/)
- CMake: [CMake Documentation](https://cmake.org/documentation/), [Intro to CMake](https://youtu.be/7YcbaupsY8I?si=NXbNFzKYfwoqY7wG)
- Makefile: [What is Makefile?](https://opensource.com/article/18/8/what-how-makefile)
- Ninja: [Ninja](https://ninja-build.org/)
- Clangd: [What is clangd?](https://clangd.llvm.org/)
- About VSCode tasks: [Integrate with External Tools via Tasks](https://code.visualstudio.com/docs/editor/tasks)
- What is $PATH?: [PATH (variable) - Wikipedia](<https://en.wikipedia.org/wiki/PATH_(variable)>), [PATH | Microsoft Learn](<https://learn.microsoft.com/en-us/previous-versions/aa922003(v=msdn.10)?redirectedfrom=MSDN>)

## **5. References, Sources**

[1] “STM32 development and debugging using VSCode - Stm32World Wiki,” _Stm32world.com_, 2024. https://stm32world.com/wiki/STM32_development_and_debugging_using_VSCode (accessed Mar. 6, 2025).

[2] “STSW-LINK009 - STMicroelectronics,” _STMicroelectronics_, 2025. https://www.st.com/en/development-tools/stsw-link009.html#documentation (accessed Mar. 10, 2025).

[3] irvingywang, RoboMaster-Club, “GitHub - RoboMaster-Club/Onboarding-Project-1: Part 1 of an onboarding project which introduces students to embedded development and GPIO with STM32.,” _GitHub_, 2024. https://github.com/RoboMaster-Club/Onboarding-Project-1 (accessed Mar. 11, 2025).

[4] “Add to the PATH on Windows 10 and Windows 11 | Architect Ryan,” _Architectryan.com_, 2018. https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/ (accessed Mar. 17, 2025).

‌[5] Eka Susilo, Youtube, “Step-by-Step: STM32 Development Environment with OpenOCD and Visual Studio Code (Linux)” 2025. https://youtu.be/FNDp1G0bYoU?si=MS14O9iSGExgvvjv (accessed Mar. 17, 2025).

‌
