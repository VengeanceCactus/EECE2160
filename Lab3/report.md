# Lab 3 Report

**Team** Andrew Ricci

### Pre-Lab

In the prelab, our main objective was to learn to debug through the use of the gdb command.

The debugging began by using typing "gdb" followed by the executed filename, in this instance person. From there, a number of modifiers can be used to alter the output of the debug.

* The first we used was run. This simply ran the program as it would be run normally. 
* The second command was start. This, in accordance with the step and next commands could be used to go through the program either one line or one function at a time, respectively.
* We also used print, which would display a given variable at a particular time in execution.
* Break was another crucial modifier, which would be set in advance of execution and stop the program after it had reached the specified breaking point. From break, the continue command could be used to run the rest of the program.
* Finally, we used backtrace, which allowed us to show functions that had already been run before a particular break.

Here is an example of a all commands being run on our Person test program:

```
bash-4.2$ gdb person
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-94.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /Users/Student/aricci/lab3-andrewricci/person/person...done.
(gdb) run
Starting program: /Users/Student/aricci/lab3-andrewricci/person/person 
John is 10 years old.
[Inferior 1 (process 11922) exited normally]
(gdb) start
Temporary breakpoint 1 at 0x400ad6: file person.cc, line 13.
Starting program: /Users/Student/aricci/lab3-andrewricci/person/person 

Temporary breakpoint 1, main () at person.cc:13
13	  Person p;
(gdb) next
15	  p.name = "John";
(gdb) next
16	  p.age = 10;
(gdb) next
18	  PrintPerson(&p);
(gdb) print p.age
$1 = 10
(gdb) next
John is 10 years old.
19	  return 0;
(gdb) next
20	}
(gdb) next
__libc_start_main (main=0x400acd <main()>, argc=1, ubp_av=0x7fffffffe5d8, init=<optimized out>, 
    fini=<optimized out>, rtld_fini=<optimized out>, stack_end=0x7fffffffe5c8)
    at ../csu/libc-start.c:308
308	  exit (result);
(gdb) break 16
Breakpoint 2 at 0x7ffff721ba40: file ../csu/libc-start.c, line 16.
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /Users/Student/aricci/lab3-andrewricci/person/person 

Breakpoint 2, __libc_start_main (main=0x400acd <main()>, argc=1, ubp_av=0x7fffffffe5d8, 
    init=0x400bd0 <__libc_csu_init>, fini=0x400c40 <__libc_csu_fini>, 
    rtld_fini=0x7ffff7deba00 <_dl_fini>, stack_end=0x7fffffffe5c8) at ../csu/libc-start.c:134
134	{
(gdb) backtrace
#0  __libc_start_main (main=0x400acd <main()>, argc=1, ubp_av=0x7fffffffe5d8, 
    init=0x400bd0 <__libc_csu_init>, fini=0x400c40 <__libc_csu_fini>, 
    rtld_fini=0x7ffff7deba00 <_dl_fini>, stack_end=0x7fffffffe5c8) at ../csu/libc-start.c:134
#1  0x00000000004009b9 in _start ()
(gdb) up
#1  0x00000000004009b9 in _start ()
(gdb) down
#0  __libc_start_main (main=0x400acd <main()>, argc=1, ubp_av=0x7fffffffe5d8, 
    init=0x400bd0 <__libc_csu_init>, fini=0x400c40 <__libc_csu_fini>, 
    rtld_fini=0x7ffff7deba00 <_dl_fini>, stack_end=0x7fffffffe5c8) at ../csu/libc-start.c:134
134	{
(gdb) down
Bottom (innermost) frame selected; you cannot go down.
(gdb) q
A debugging session is active.

	Inferior 1 [process 11942] will be killed.

Quit anyway? (y or n) y
bash-4.2$ 
```
### Crashing Program

In order to make my program crash, I removed a key bit of code that assigns our tail variable to the temp value given by the append function. This was the result using gdb.

```
(gdb) run
Starting program: /Users/Student/aricci/lab3-andrewricci/crashing/a.out 
Main menu:

	1. Append a person
	2. Find a person
	3. Remove a person
	4. Insert a person
	5. Print the list
	6. Exit
1
Enter the name: Andrew
Enter the age: 21
Main menu:

	1. Append a person
	2. Find a person
	3. Remove a person
	4. Insert a person
	5. Print the list
	6. Exit
1
Enter the name: Alex
Enter the age: 25

Program received signal SIGSEGV, Segmentation fault.
0x0000000000400d0e in ListAppend (list=0x602428 <list>, person=0x6030b0) at listcrash.cc:43
43	      tail->next=temp;
(gdb) print tail
$1 = (Node *) 0x0
```

### Print List

This one didn't work so well!

```
(gdb) break 211
Breakpoint 1 at 0x401238: file list.cc, line 211.
(gdb) run
Starting program: /Users/Student/aricci/lab3-andrewricci/list/a.out 
Main menu:

	1. Append a person
	2. Find a person
	3. Remove a person
	4. Insert a person
	5. Print the list
	6. Exit
1
Enter the name: Andrew
Enter the age: 21

Breakpoint 1, main () at list.cc:215
215	  return 0;
(gdb) print &list
$1 = (List *) 0x602428 <list>
(gdb) print list
$2 = {<No data fields>}
(gdb) print *list
No symbol "operator*" in current context.
(gdb) print &list.head
There is no member or method named head.
```
