# CSC4005

This is a collection of code for CSC4005

If you think the code needs improvement, you can open an issue or pull request.

# How to run the code? (Mac)

In terminal, change directory to where the code file exists.

For programs with single file:

input

`mpicc -o <executable_file_name> <code_file_name>`

to compile the code, and input 

`mpirun -np <num_of_processes> <executable_file_name>`

to run the program.

For programs with more than one file:

Using makefile is recommended.

I wrote a makefile for 'trapezoid rule'.

Input `make` in terminal, files will be compiled according to the rules written in the makefile file.

Then use the same command to run the program.

About how to write a makefile file, please refer to google.

# Other

尽管有些测试数据恶臭无比，也请不要修改它们！

Although some test data is stinking, please do not modify them!

テストデータはくさい、しかし変更しないで下さい！



