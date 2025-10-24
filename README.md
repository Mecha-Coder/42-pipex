```text
 _  _  ____            _                 
| || ||___ \ _   _ __ (_)_ __   _____  __
| || |_ __) (_) | '_ \| | '_ \ / _ \ \/ /
|__   _/ __/ _  | |_) | | |_) |  __/>  < 
   |_||_____(_) | .__/|_| .__/ \___/_/\_\
                |_|     |_|                 
```

### **Overview**

An introduction to pipes (|) and how commands are executed inside a shell.

---

### **Key Learnings**
- Understand file descriptors and how to redirect the flow of data using them
- Learn how pipes enable communication between multiple programs
- Understand how  shell executes commands and child process

---

### **About**

👉 [**Project requirement**](https://github.com/Mecha-Coder/42-pipex/blob/main/demo/en.subject.pdf)

This project serves as a foundation for the later Minishell project.
Pipes are what enable a shell to chain multiple commands, passing the output of one command as the input of the next. Each command in a shell is simply a program.

The core system calls that make piping possible are:
- `pipe()` — creates a communication channel between programs
- `fork()` — spawns a new child process
- `execve()` — replaces the child process with a new program
- `dup2()` — redirects input and output streams of a program

 ![figure1](https://github.com/Mecha-Coder/42-pipex/blob/main/demo/figure1.png)

Since this project focuses on the execution side, the input command structure is simplified.

![figure2](https://github.com/Mecha-Coder/42-pipex/blob/main/demo/figure2.png)

---

### **Demo**

![demo](https://github.com/Mecha-Coder/42-pipex/blob/main/demo/demo.gif)

---

### **How to run**

System requirement: **Debian/Ubuntu/WSL2**


```bash

# Clone the repository
git clone hhttps://github.com/Mecha-Coder/42-pipex
cd 42-pipex

# Build the program
make
# or
make bonus

# Launch the program with correct arguments
# Please find the test cases in /file/test_case.txt
./pipex infile cmd1 cmd2 file2

```
---

### **Resource**

