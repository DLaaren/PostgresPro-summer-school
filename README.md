# PostgresPro-summer-school

::HOW TO CREATE EXTENSIONS FOR POSTGRESQL::
1) Go to source code and find dir called "contrib"
2) Now create your extension's dir
3) Create Makefile (look at others extensions for example)
4) my_extension.sql
5) And my_extension.control
6) (optional) my_extension.c
    if you create c functions
7) go to dir "contrib" and open Makefile. Add in SUBDIR you extension's dir
8) Then just 'make' and 'make install' source code again
