AUTHORING: 

Ravindu Gunasekara

CMSC313 @ 14:30 Mo/We


PURPOSE OF SOFTWARE: 

Perform the matrix calculation, D = A + 3B * C^T in both C++ and C99.


FILES:

matrix.c (C99 implementation)

matrix.cpp (C++ implementation)

README.md (homework description)


BUILD INSTRUCTIONS:

Run these in MSYS2 UCRT64:


C++: gcc -o matrixcpp matrix.cpp -lstdc++

C: gcc -o matrixc matrix.c


Then ./matrixcpp or ./matrixc


TESTING METHODOLOGY:

I first solved the calculation by hand to know what
the matrix D is supposed to be. Then ran the code
in https://www.onlinegdb.com/. After getting the 
right answer, I made the commands to compile the
code. I then ran those commands and madde sure 
the answer was the same as I had found before.

ADDITIONAL INFORMATION:
When building, I ran into an error for the C++
file when not using -lstdc++. Found out through 
here: https://stackoverflow.com/questions/3178342/compiling-a-c-program-with-gcc that it's cause I
used the standard library(vectors). Also where I 
found the -lstdc++ fix.
