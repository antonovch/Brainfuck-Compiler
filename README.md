Basic compiler for the Brainfuck language with object-oriented C++.

This program runs code written in Brainfuck language from a provided file,
writing the output to the console. Seven out of eight BF commands are supported 
('+', '-', '<', '>', '[', ']', '.', with the exception of ','). 
All other characters in the file will be ignored, i.e. considered to be comments. 
Comments must not include one of the seven special characters.

Usage: `./main test_files/hello_world.txt`

Test cases are taken from:

1/ https://en.wikipedia.org/wiki/Brainfuck

2/ https://github.com/kavehmz/brainfuck_examples

The compiling process is separated into two steps: creation of the actual model 
(`std::vector` of actions to run based on the BF code) and its execution.