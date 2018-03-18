//Matrix.hpp
//Sasha Stramel
//uMatrix Project
//Due 3/18/2018
//Cosc 2030 Section 1

#ifndef Matrix_hpp
#define Matrix_hpp


class uMatrix
{
    private:
        int size;
        int *fastMatrix;
        int **slowMatrix;
    
    public:
        uMatrix(int numbers[], int length);
        ~uMatrix();
    
    /**
     * @brief print
     * @input one object, self, of type uMatrix A,
     * @output a square representation of the matrix A
     */
    void print();
   
    /**
     * @brief MM Matrix Multiplication
     * @input two objects of type uMatrix self A, and parameter B
     * @output a new object of type uMatrix = A x B what is matrix multiplication?
     * https://en.wikipedia.org/wiki/Matrix_multiplication
     */
    uMatrix MM(uMatrix B);
    
    /**
     * @brief MMf Fast Matrix Multiplication
     * @input two objects of type uMatrix self A, and parameter B
     * @output a new object of type uMatrix = A x B what is matrix multiplication?
     * https://en.wikipedia.org/wiki/Matrix_multiplication
     */
    uMatrix MMf(uMatrix B);
    
    /**
     * @brief MA Matrix Addition
     * @input two objects of type uMatrix self A, and parameter B
     * @output a new object of type uMatrix = A + B
     */
    uMatrix MA(uMatrix B);
    /**
     * @brief MA Fast Matrix Addition
     * @input two objects of type uMatrix, self A, and parameter B
     * @output a new object of type uMatrix = A + B
     */
    uMatrix MAf(uMatrix B);
    
    /**
     * @brief SM Scalar Multiplication
     * @input one object, self, of type uMatrix A, and a scalar value S
     * @output a new object of type uMatrix such that every element in A is multiplied by S
     */
    uMatrix SM(int S);
    /**
     * @brief SMf Fast Scalar Multiplication
     * @input one object, self, of type uMatrix A, and a scalar value S
     * @output a new object of type uMatrix such that every element in A is multiplied by S
     */
    uMatrix SMf(int S);
    
    /**
     * @brief SA Scalar Addition
     * @input one object, self, of type uMatrix A, and a scalar value S
     * @output a new object of type uMatrix such that every element in A is increased by S
     */
    uMatrix SA(int S);
    /**
     * @brief SAf Fast Scalar Addition
     * @input one object, self, of type uMatrix A, and a scalar value S
     * @output a new object of type uMatrix such that every element in A is increased by S
     */
    uMatrix SAf(int S);
    
};

#endif /* Matrix_hpp */
