[![GitHub issues](https://img.shields.io/github/issues/xioperez01/simple_shell)](https://github.com/xioperez01/simple_shell/issues)
[![GitHub forks](https://img.shields.io/github/forks/xioperez01/simple_shell?color=orange)](https://github.com/xioperez01/simple_shell/network)
[![GitHub stars](https://img.shields.io/github/stars/xioperez01/simple_shell?color=blueviolet)](https://github.com/xioperez01/simple_shell/stargazers)
# Simple Shell :shell: #
[](https://img-a.udemycdn.com/course/750x422/1349660_ecfb_4.jpg)
This repository contains our own version of a mini Shell

A **Unix shell** is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.
Shells may be used interactively or non-interactively. In interactive mode, they accept input typed from the keyboard. When executing non-interactively, shells execute commands read from a file.

Our shell is a simple version that has basic functionality. You can create / write / read / open / delete folders, print things in terminal, change directories, etc.


## How To Install & Compile :computer: ##
To have this repository and its content, you must execute the following on your terminal:
~~~
$ git clone https://github.com/xioperez01/simple_shell.git
$ cd simple_shell/
~~~
You do not need to create a main function as it is already in our files.

To compile and run type the following in your terminal:

~~~
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
$ ./hsh
MAXIO~$
~~~


## Description of the files contained.:books: ##

| File  name   | Description   |
| ------------- |:-------------:|
| shell.h | Header file. It contains the necessary standard libraries and the prototypes used in all the functions of the program. |
| main.c | Contains the main function that execute our own shell |
| aux_func.c | Contains helper functions that compare, concatenate, or return the length of strings |
| built_ins.c | Contains the functions that the built-in commands execute, such as cd, exit, help, env |
| convert.c | Contains function that creates a copy of string from input and reemplaces the character '\n' to '\0' |
| execute.c | Contains function that creates a child process |
| get_env.c | Contains function that gets an enviroment variable |
| parse.c  |  Contains function that split the commands line |
| _path.c | Contains the functions that creates the final path of the executable |
| read_line.c | Contains function that reads the command line |
| signal_handler.c | Contains the function with the signal controller SIGINT (Ctl + C) |
| man_1_simple_shell | Custom manual for our own shell |
| AUTHORS | Contains the list of repository authors |


## Note ##
If you want to review the manual of our _printf function you can execute
in your terminal:
~~~
$ man ./man_1_simple_shell
~~~


## How it works ##
If you want to know how our shell works (a simple shell), we invite you to visit [our blog](https://www.linkedin.com/posts/martin-corredor-a631151b0_what-happens-when-you-type-ls-l-in-a-shell-activity-6701692741946028032-JD78)


## Execution examples of our shell ##

In interactive mode
~~~
$ ./hsh
MAXIO~$ /bin/ls
AUTHORS  README.md  aux_func.c	 convert.c  get_env.c  man_1_simple_shell  read_line.c	shell.h
LICENSE  _path.c    built_ins.c  execute.c  main.c     parse.c		   shell	signal_handler.c
MAXIO~$
MAXIO~$ exit
$
~~~


In non-interactive mode
~~~
$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  aux_func.c	 convert.c  get_env.c  man_1_simple_shell  read_line.c	shell.h
LICENSE  _path.c    built_ins.c  execute.c  main.c     parse.c		   shell	signal_handler.c
$
~~~

## Environment ##
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)
### Autors ##
* Martín Corredor [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/Richi_Corredor)
 * Angie Pérez [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/xiommyperez)
