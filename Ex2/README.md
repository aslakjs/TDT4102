# TDT4102 - Assignment 2
<b>ObjectOrientedC++</b>
A <i>somewhat reasonable</i> way of solving assignment 2.

<br>

<b>¡Note!</b>
Some files are requred to run this program:
- /Library/tdt4102/**
    - Can be found @ /Extra/tdt4102.zip

Task 5: Draw figure w/ Simple_window tend to freeze screen. Unknown if only on certain computers.
<b>!etoN¡</b>
<br>

<b> Instructions:</b>
On startup you'll run into the main menu. 
From here you can select a task to run. 
<i>Menu navigation should be self explainatory...</i>
- [?] Indicates which sign to enter for selection
- [ i ] Shows copy-right info

<br>
The following sub-tasks have their own menu-system:
- Task 2 
    - Includes selections from Task 3 & 4
- Task 6

The rest of the tasks will run through sub-tasks step by step.

<br>

Easy debug of functions:
- ./main.h:
    - Change "#Define DEBUG 0" to "#Define DEBUG 1"
- ./main.cpp:
    - At top of main-function: 
        - add the function call for the function you want
        - Make sure it's between "#if DEBUG" and "#endif"
        - Comments in code should show placement

<br>

If files are moved into a basic folder structure as shown below:
- /head/.h-files
- /src/.cpp-files

Then change main.h -> "#define FOLDER 0" to "#define FODLER 1"
And manually change "#include ".h""-files on top of all .cpp files