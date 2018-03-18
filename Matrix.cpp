//Matrix.cpp
//Sasha Stramel
//uMatrix Project
//Due 3/18/2018
//Cosc 2030 Section 1
/*
 Inspired by
 http://www.cplusplus.com/doc/tutorial/arrays/
 
*/


#include "Matrix.hpp"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <iostream>
#include <chrono>
#include <ctime>

using std::cout;
using std::endl;

//Constructor of Matrix
uMatrix::uMatrix(int numbers[], int length)
{
    
    //Size of matrix which is always going to be square
    size = sqrt(length);
    
    //Allocate *fastMatrix so it stores value
    fastMatrix=(int*)malloc(length*sizeof(int));
    for (int idx=0; idx<length; idx++)
    {
        fastMatrix[idx]=numbers[idx];
    }
    
    //Copy numbers into slowMatrix
    slowMatrix=(int**)malloc(size*sizeof(int));
    for (int row=0; row<size; row++)
    {
        slowMatrix[row]=(int*)malloc(size*sizeof(int));
        for (int col=0; col<size; col++) {
            slowMatrix[row][col]=numbers[row*size+col];
        }
    }
}

//Destructor of Matrix
uMatrix::~uMatrix()
{
//    free(fastMatrix);
//    for (int row=0; row<size; row++){
//        free(slowMatrix[row]);
//    }
//    free(slowMatrix);
}

//Print Matrix
void uMatrix::print()
{
    for(int row= 0; row<size; row++)
        {
            for(int col= 0; col < size; col++)
            {
                int idx=row*size+col;
                int val=fastMatrix[idx];
                cout<< val << " ";
            }
            cout<< endl;
        }
        cout << "\n\n";
}

////MM: Matrix Mutiplication Slow
uMatrix uMatrix::MM(uMatrix B)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col<size; col ++)
        {
            int sum=0;
            for (int row_B=0; row_B< size; row_B++) {
                int a_val= slowMatrix[row][row_B];
                int b_val= B.slowMatrix[row_B][col];
                sum+= a_val*b_val;
            }
            c[row*size+col]=sum;
        }
    }
    return uMatrix (c, size*size);

}

//MMf: Matrix Mutiplication Fast
uMatrix uMatrix::MMf(uMatrix B)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col<size; col ++)
        {
            int sum=0;
            for (int row_B=0; row_B< size; row_B++) {
                int A_idx= row*size+row_B;
                int B_idx= row_B*size+col;
                sum+= fastMatrix[A_idx]*B.fastMatrix[B_idx];
            }
            c[row*size+col]=sum;
        }
    }
    return uMatrix (c, size*size);
}

//MAf: Matrix Addition Fast
uMatrix uMatrix::MAf(uMatrix B)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            int a_val=fastMatrix[idx];
            int b_val= B.fastMatrix[idx];
            c[idx]=a_val+b_val;
        }
    }
    return uMatrix (c, size*size);
}


//MA: Matrix Addition Slow
uMatrix uMatrix::MA(uMatrix B)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            c[idx]=slowMatrix[row][col]+B.slowMatrix[row][col];
        }
    }
    return uMatrix (c, size*size);
}

//SM: Scalar Mutiplication Slow
uMatrix uMatrix::SM(int S)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            c[idx]=slowMatrix[row][col]* S;
        }
    }
    return uMatrix (c, size*size);
}

//SMf: Scalar Mutiplication Fast
uMatrix uMatrix::SMf(int S)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            int a_val=fastMatrix[idx];
            c[idx]=a_val*S;
        }
    }
    return uMatrix (c, size*size);
}

//SA: Scalar Addition Slow
uMatrix uMatrix::SA(int S)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            c[idx]=slowMatrix[row][col]+ S;
        }
    }
    return uMatrix (c, size*size);
}

//SAf: Scalar Addition Fast
uMatrix uMatrix::SAf(int S)
{
    int c[size*size];
    for(int row=0; row<size; row++){
        for(int col =0; col <size; col ++)
        {
            int idx=row*size+col;
            int a_val=fastMatrix[idx];
            c[idx]=a_val+S;
        }
    }
    return uMatrix (c, size*size);
}
