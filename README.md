# Printf_IMPROVED
Best version of Printf clone

## Description
This is a second version of Printf_Mimic that I have on another repo.
This version is very optimized and the code is more readable and maintainable compared to the previous one which is a complete rubbish.

## What is improved?
### Global Variables:
In the previous version I used local variable and I had to pass pointers to those variables to every function and the code looked like crap.
In this version I used Global variables in the header file which made it easy for me to access and apdate those variables from anywhere.
I also used normal variables instead of pointers which saved me the pain of allocating and freeing memory all the time.

### Boolean Functions:
In the previous version I had too many unclear conditions that would make nosense to someone reading the code.
In this version I used Extracted those conditions into boolean functions like is_negative(), is_pointer()...etc which made the code more readable.

### Recursion:
In this project you are required to convert numbers into strings and hexadecimal strings.
In the previous version I used iteration to achieve this which took me 3 functions per conversion and each function had 25 lines of crappy code.
Now I used recursive approach and I could narrow down the code to one function with 12 lines of code. check numbr_tostr() and numbr_tohex() in helpers.c file.

