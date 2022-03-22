# 42_pipex_2022

Pipes is a project that reproduces the behavior of the shell pipe | command in C, using the following functions: ***pipe()***, ***fork()***, ***dup2***, access, and ***execve()*** functions. The program will lunch as ***./pipex infile cmd1 cmd2 outfile*** its behavior will be exactly as the following line in shell ***< infile cmd1 | cmd 2 > out file.***

# General idea

With the help of **pipe()** and **dup2()** we set a bridge between file descriptors so that we can write, read and switch them with other file descriptors in order to manipulate as desired the stdin and stdout of our program, as we want to execute two commands sequentially, we need to create two processes with **fork(),** the first one is called the parent process, the other one is the child process.

The parent will represent the cmd2, and the child will represent cmd1. As both processes will try to execute simultaneously, we need to use a **waitpid()** or **wait()** to tell our program that we want to execute the children processes firstly, so cmd1 will execute with their input and output configuration, once finished. cmd2 starts its execution taking as input the output of cmd1 and as output outfile 

# Function’s explanation

- **pipe()**

```c
int pipe(int pipefd[2]);
```

Creates a pipe, a unidirectional data channel that can be used in interprocess communication , the array pipefd is used to return two file descriptors referring to the end of the pipe. **pipefd[0]** refers to the read end of the pipe. **pipefd[1]** refers to write end of the pipe. Data written to the write end of the pipe is buffered by the kernel until it is read from the read part of the pipe. 

Return

On success, zero is returned. On error -1 is returned.

---

- **fork()**

Creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.

**Return value:** On success, the PID of the child process is returned to the parent process, and 0 is returned to the child. On failure, -1 is returned to the parent process, and no parent process is created. 

[Understanding fork() system call for new process creation](https://www.youtube.com/watch?v=PwxTbksJ2fo)

### *Why we use fork?*

As we are trying to execute two shell commands sequentially, one simple option is to create a new process, and carry out different tasks per process.  

---

- **dup2()**

```c
#include <unistd.h>

       int dup2(int oldfd, int newfd);
```

The dup2() system call closes int newfd, creates a copy of the file descriptor **int oldfd**, into the number specified in **int newfd.**  So that newfd will point to oldfd.

Return

On success, return a new file descriptor. On error, -1 is returned.

### Before

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d1afbf69-93a8-4301-bd9f-340a2d10988e/Untitled.png)

### Execution

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/80cc1319-1280-4b59-9c8c-46cf9b7b49c6/Untitled.png)

### After

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/29ff508b-f817-4189-952e-daf0c6b682ba/Untitled.png)

---

- **execve()**

```c
#include <unistd.h>

       int execve(const char *pathname, char *const argv[], char *const envp[]);
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/613a1747-a862-4b32-a22a-7833b614b306/Untitled.png)

execve function will have to try every single path up until it finds the correct one

---

- w**ait() and waitpid()**

```c
#include <sys/types.h>
       #include <sys/wait.h>

       pid_t wait(int *wstatus);

       pid_t waitpid(pid_t pid, int *wstatus, int options);
```

- The **wait** system call suspends execution of the current thread until one of its children terminates.

The call wait(&wstatus) is equivalent to :

waipid(-1, &wstatus, 0);

- The **waitpid()** system call suspends execution of the calling thread until a **child specified by pid** argument has changed stated.

The value of pid can be:

```
   < -1   meaning wait for any child process whose process group ID is equal to the absolute value of pid.

   -1     meaning wait for any child process.

   0      meaning  wait  for  any child process whose process group ID is equal to that of the calling process at
          the time of the call to waitpid().

   > 0    meaning wait for the child whose process ID is equal to the value of pid.

```

---

- **access()**

```c
#include <unistd.h>

       int access(const char *pathname, int mode);
```

Checks whether the calling process can access the file path name.

- **The mode** specifies the accessibility check(s) to be performed, and is either the value F_OK, or  a  mask  consisting  of  the bitwise OR of one or more of R_OK, W_OK, and X_OK.  F_OK tests for the existence of the file.
R_OK, W_OK, and X_OK test whether the file exists and grants read, write,  and  execute  permissions,  respectively.

Return

On success (all requested permission granted, and the file exists), zero is retuned. On error -1 is returned.
