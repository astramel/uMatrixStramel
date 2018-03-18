//main.cpp
//Sasha Stramel
//uMatrix Project
//Due 3/18/2018
//Cosc 2030 Section 1

#include <sstream>
#include <math.h>
#include <vector>
#include <iostream>
#include <string>
#include "Matrix.hpp"

using std::cout;
using std::cin;
using std::endl;


int main(int argc, const char * argv[])
{

    //Read in Matrix A, Matrix B and Scalar from Command Line
    /* https://stackoverflow.com/questions/5446161/reading-piped-input-with-c */
    
    std::string MatrixA, MatrixB, Scalar;
    getline(cin,MatrixA);
    getline(cin,MatrixB);
    getline(cin,Scalar);
    
    //Parse Matrix A. Create vector from input. Convert to array.
    /* https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring */
    
    std::stringstream ssA(MatrixA);
    std::vector<int> vectorA;
    while( ssA.good() )
    {
        std::string num;
        getline( ssA, num, ',' );
        vectorA.push_back( stoi(num));
    }
    int* a = &vectorA[0]; /* https://stackoverflow.com/questions/2923272/how-to-convert-vector-to-array-in-c */
    
    //Parse Matrix B. Create vector from input. Convert to array.
    std::stringstream ssB(MatrixB);
    std::vector<int> vectorB;
    while( ssB.good() )
    {
        std::string num;
        getline( ssB, num, ',' );
        vectorB.push_back( stoi(num));
    }
    int* b = &vectorB[0];
    
    //Parse Scalar.
    /* http://en.cppreference.com/w/cpp/string/basic_string/stol */
    int S= std::stoi(Scalar);
    
  
    //Matrix Size

    cout<< "Size of Matrix is "<< vectorA.size() << endl;
    cout<< "Size of Matrix is "<< vectorB.size()<< endl;
    

    //uMatrix A
    cout<< "uMatrix A: " << endl;
    int a_size= vectorA.size();
    uMatrix A (a,a_size);
    A.print();
    
    
    //uMatrix B
    cout<< "uMatrix B: " << endl;
    uMatrix B (b,vectorB.size());
    B.print();
    
    //S: Scalar
    cout<< "Scalar: " << endl;
    cout<< S << "\n"<< endl;
    
    //MMf: Matrix Mutiplication Fast
    auto start_MMf = std::chrono::system_clock::now();
    cout<<"Matrix Mutiplication Fast: A*B"<<endl;
    uMatrix D= A.MMf(B);
    auto end_MMf = std::chrono::system_clock::now();
    std::chrono::duration<double> time_MMf = end_MMf-start_MMf;
    D.print();
    cout<< "Time Ran; " << time_MMf.count() << "s\n";
    
    //MM: Matrix Mutiplication Slow
    auto start_MM = std::chrono::system_clock::now();
    cout<<"Matrix Mutiplication Slow: A*B"<<endl;
    uMatrix DS= A.MM(B);
    auto end_MM = std::chrono::system_clock::now();
    std::chrono::duration<double> time_MM= end_MM-start_MM;
    DS.print();
    cout<< "Time Ran; " <<time_MM.count() << "s\n";
    
    
    //MAf: Matrix Addition Fast
    auto start_MAf = std::chrono::system_clock::now();
    cout<<"Matrix Addition Fast: A+B "<<endl;
    uMatrix C= A.MAf(B);
    auto end_MAf = std::chrono::system_clock::now();
    std::chrono::duration<double> time_MAf= end_MAf-start_MAf;
    C.print();
    cout<< "Time Ran; " <<time_MAf.count() << "s\n";
    
    //MA: Matrix Addition Slow
     auto start_MA = std::chrono::system_clock::now();
    cout<<"Matrix Addition Slow: A+B"<<endl;
    uMatrix CS= A.MA(B);
    auto end_MA = std::chrono::system_clock::now();
    std::chrono::duration<double> time_MA= end_MA-start_MA;
    CS.print();
    cout<< "Time Ran; " <<time_MA.count() << "s\n";
    
    //SM: Scalar Mutiplication Slow
     auto start_SM = std::chrono::system_clock::now();
    cout<<"Scalar Mutiplication Slow: A*"<< S <<endl;
    uMatrix ES= A.SM(S);
    auto end_SM = std::chrono::system_clock::now();
    std::chrono::duration<double> time_SM= end_SM-start_SM;
    ES.print();
    cout<< "Time Ran; " <<time_SM.count() << "s\n";
    
    //SMf: Scalar Mutiplication Fast
     auto start_SMf = std::chrono::system_clock::now();
    cout<<"Scalar Multipilcation Fast: A*"<< S <<endl;
    uMatrix E= A.SMf(S);
    auto end_SMf = std::chrono::system_clock::now();
    std::chrono::duration<double> time_SMf= end_SMf-start_SMf;
    E.print();
    cout<< "Time Ran; " <<time_SMf.count() << "s\n";
    
    //SA: Scalar Addition Slow
     auto start_SA = std::chrono::system_clock::now();
    cout<<"Scalar Addition Slow: A+"<< S <<endl;
    uMatrix F= A.SA(S);
    auto end_SA = std::chrono::system_clock::now();
    std::chrono::duration<double> time_SA= end_SA-start_SA;
    F.print();
    cout<< "Time Ran; " <<time_SA.count() << "s\n";

    //SAf: Scalar Addition Fast
     auto start_SAf = std::chrono::system_clock::now();
    cout<<"Scalar Addition Fast: A+"<< S <<endl;
    uMatrix FS= A.SAf(S);
    auto end_SAf = std::chrono::system_clock::now();
    std::chrono::duration<double> time_SAf= end_SAf-start_SAf;
    FS.print();
    cout<< "Time Ran; " <<time_SAf.count() << "s\n";
    
    }
