## IZP project 1 2022

 - dependencies: cmake 3.23 and higher, gcc or preferably clang
 - compile:
```shell
$ cmake -B build -S . && cmake --build build
```
 - run:
```shell
 $ ./build/t9search NUMBER < CONTACT_FILE
 ```
where `NUMBER` is any number combination used on old t9 keyboards
and `CONTACT_FILE` is a file with structure similar to the following example:

```txt
Petr Dvorak
603123456
Jana Novotna
777987654
Bedrich Smetana ml.
541141120
```

- to generate such file run:
```shell
$ python3 generate_contacts.py NUMBER
```
where `NUMBER` dictates how many contacts are created

## Functionality

 - the program takes the command line argument `NUMBER` and searches for contacts that either have the `NUMBER` 
in their number field or in their name according to t9 keyboard, space is not supported.
 - the contacts are matched only if the `NUMBER` matches an exact substring in the contact
 - with no `NUMBER` all contacts are matched
 - with no `CONTACT_FILE` supplied the program awaits input on stdin
 - with dynamic allocation forbidden in this project, the maximum length of a single line is 100 symbols, otherwise an error is raised
