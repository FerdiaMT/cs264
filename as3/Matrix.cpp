#include "Matrix.h"
#include <string>
#include <iostream>

/**
 * This is the standand constructor that creates an n*m matrix
 * It fills the array with 0's
 * @param m is the width of the amatrix
 * @param n is the height of the matrix
 * @return Matrix which is the matrix class, with local variable data containing the actual numbers
 */

Matrix::Matrix(unsigned int m, unsigned int n) // constuctor of MxN matrix of 0's
{
    this->m_ = m; // set the rows
    this->n_ = n; // set the columns

    data = new int *[m]; // create a row of pointers that is m long (row length),
    // so right now it looks like if m=5, xxxxx , where each x points down (this is how im visualizing it atleast, its literally just an array of pointers in reality)

    for (unsigned int i = 0; i < m; i++)
    {
        data[i] = new int[n]; // allocate the column length to each row (going down in this visual example)

        for (unsigned int j = 0; j < n; j++) // fill in all our data with 0's
        {
            data[i][j] = 0;
        }
    }
}

/**
 * This is the copy constructor
 * We pass in a different matrix class, and this method will intiialize it to have the same values
 * We make a deep copy of the array data, as otherwise we would have an array whos data is stored in a different Matrix
 * And if we deleted said matrix, our pointers would point to data which has now been deleted
 * @param mat is another matrix we pass in
 * @return Matrix which has its values which are copied from the passed in matrix
 */

Matrix::Matrix(const Matrix &mat) : m_(mat.m_), n_(mat.n_) // the copy function, so we grab all the data and allocate it
{
    // PROBLEM: the initializer list does not contain data(mat.data)
    //  this is because that would make a shallow copy
    //  so this matrixs data pointer would point to another matrix altogether
    //  and if the other matrix was deleted, then wed get a bunch of errors which is really bad
    //  so instead, we make a deep copy, by just iterating through each value and setting the memory for in here
    //  that way we get 0 memory errors
    data = new int *[m_];

    for (unsigned int i = 0; i < m_; i++)
    {
        data[i] = new int[n_];
        for (unsigned int j = 0; j < n_; j++)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

/**
 * This is the matrix constructor where we instead pass in a 2d array allongside its width and height for the data
 * our constructor once again deep copys so there are no memory errors
 * @param m matrix width
 * @param n matrix height
 * @param array the 2d array pointer we use to fill in our data for the matrix
 * @return the constructed matrixs
 */
Matrix::Matrix(int **array, unsigned int m, unsigned int n) : m_(m), n_(n) // this is for passing in a 2d array pointer
{
    // once again, we would get the same issue as the copy function, where if that array was killed, we would have pointers leading
    // to data that doesnt exist, so instead we take the m and n with the initializer list, and make data a deep copy

    data = new int *[m_];

    for (unsigned int i = 0; i < m_; i++)
    {
        data[i] = new int[n_];
        for (unsigned int j = 0; j < n_; j++)
        {
            data[i][j] = array[i][j];
        }
    }
}

/**
 * this is a getter for how many rows are in the matrix
 * @return m_ , the amount of rows
 */
unsigned int Matrix::rows() const
{
    return this->m_;
}
/**
 * this is a getter for how many cols are in the matrix
 * @return n_ the amount of cols
 */
unsigned int Matrix::columns() const
{
    return this->n_;
}
/**
 * this is a getter for the value stored in data at a certain indices
 * it will return an error if we go out of bounds in the matrices
 * @param i , what x we use to get the value from the grid
 * @param j , what y we use to get the value from the grid
 * @return data[i][j] , the int value stored in the matrix at i ,j
 */
int Matrix::get(unsigned i, unsigned j) const
{
    if (i >= m_ || j >= n_) // check if were going to be out of bounds
    {
        std::cerr << i << " , " << j << " is out of bounds for matrix whos bounds are " << this->m_ << " , " << this->n_ << std::endl;
        return NULL; // out of bounds value isnt defined by the ca, but ill return NULL here
    }
    return data[i][j];
}
/**
 * This sets the value at i j to a certain value we pass
 * if it is out of bounds we will get an error
 * @param i is the x of the matrix we want to change
 * @param j is the y of the matrix we want to change
 */
void Matrix::set(unsigned i, unsigned j, int value)
{
    if (i >= m_ || j >= n_ || i < 0 || j < 0)
    { // check if were going to be out of bounds
        std::cerr << i << " , " << j << " is out of bounds for matrix whos bounds are " << this->m_ << " , " << this->n_ << std::endl;
        return;
    }
    data[i][j] = value;
}
/**
 * This operator overload is for adding 2 matrices of equal m and n
 * it iterates through the 2 matrices and adds the values together
 * once its done adding the values it then returns the matrix
 * @param mat is the passed in matrix we want to add with
 * @return Matrix which is the result of the addition of the 2 matrixs
 */
Matrix Matrix::operator+(const Matrix &mat) // return matrix that contains addition of the 2 matrices
{

    // Explanation:
    // i am making the matrix here allocated to the stack
    // this is since if i did it as a heap pointer i would get a horrible memory leak
    // and i cant just return the pointer anyway as the function is defined in the ca sheet as returning Matrix
    // so my choice is: change function return type, change allocation, or create extremely unsafe code that will likely crash

    // in the end , the return can be put on the heap anyway (i shall do this) , so we technically still have the matrix data always on the heap
    Matrix result(m_, n_);

    // this is what happens when the 2 arnt compatible size
    // we can just return an empty matrix if it isnt
    if (m_ != mat.m_ || n_ != mat.n_)
    {
        std::cerr << "matrixes m and n are not matching, M1: (" << m_ << "," << n_ << ") M2: (" << mat.m_ << "," << mat.n_ << ")" << std::endl;
        return result;
    }

    // add the 2 elements together
    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < n_; j++)
        {
            result.data[i][j] = this->data[i][j] + mat.data[i][j];
        }
    }

    return result; // return by value
}
/**
 * This operator overload is for subtracting 2 matrices of equal m and n
 * it iterates through the 2 matrices and subtracts  the values
 * once its done subbing the values it then returns the matrix
 * @param mat is the passed in matrix we want to subtract with
 * @return Matrix which is the result of the subtraction of the 2 matrixs
 */

Matrix Matrix::operator-(const Matrix &mat)
{
    // same informamation about my code as +

    Matrix result(m_, n_);

    if (m_ != mat.m_ || n_ != mat.n_)
    {
        std::cerr << "matrixes m and n are not matching, M1: (" << m_ << "," << n_ << ") M2: (" << mat.m_ << "," << mat.n_ << ")" << std::endl;
        return result;
    }
    // subtract the 2 elements
    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < n_; j++)
        {
            result.data[i][j] = this->data[i][j] - mat.data[i][j];
        }
    }
    return result;
}
/**
 * This operator overload is for multiplying 2 matrices where n is equal to m
 * it iterates through the 2 matrices, and uses a loop (for k) to multiply the rows against the columns
 * once its done multiplying the values it then returns the matrix
 * @param mat is the passed in matrix we want to multiply with
 * @return Matrix which is the result of the multiplication of the 2 matrixs
 */

Matrix Matrix::operator*(const Matrix &mat)
{
    // same informamation about my code as +

    Matrix result(m_, mat.n_);

    if (n_ != mat.m_) // it needs to be able to multiply, so n  has to be the same as m
    {
        std::cerr << "M1 n and M2 m are not matching, M1: (" << m_ << "," << n_ << ") M2: (" << mat.m_ << "," << mat.n_ << ")" << std::endl;
        return result;
    }

    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < mat.n_; j++)
        {

            int sum = 0;                          // dot product calculator
            for (unsigned int k = 0; k < n_; k++) // use k to read across row / column for dot product
            {
                sum += this->data[i][k] * mat.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }

    return result;
}
/**
 * This operator overload is for transposing a matrix
 * It doesnt take in any input, as all it is doing is effectivly rotating the matrix
 * @return Matrix which is the transposed matrix
 */

Matrix Matrix::operator~() const
{
    Matrix result(n_, m_); // when we declare this , we are gonna swap row and columns as were transposing

    // swap the 2
    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < n_; j++)
        {
            result.data[j][i] = this->data[i][j];
        }
    }

    return result;
}
/**
 * This operator overload is for checking if 2 matrices are equal
 * if we used the normal operator ==, it would check if its the same declared object in memory
 * we want an easy way to check if the 2 matrices have the exact same data stored
 * this method does that by going through the 2 array, and making sure m and n are equal
 * @param mat is the passed in matrix
 * @return bool which tells us if they are equal or not
 */

bool Matrix::operator==(const Matrix &mat)
{
    // check if the 2 values are the same
    // not a literal check if the memory location is the same

    if (n_ != mat.n_ || m_ != mat.m_)
    {
        return false;
    }

    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < mat.n_; j++)
        {

            if (data[i][j] != mat.data[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

/**
 * this function turns the currently stored data of the 2d array into a string
 * i like to format this nicely, so the first thing this function does is find the widest length string
 * as in 1234 is length 4, -1234 is length 5 etc
 * then when it makes the matrix, it will pad each numbers width so the matrix will look nice
 * it also surrounds the matrix in - and | in order to make it more readable
 * @return result which contains the graph in string form for printing
 */
std::string Matrix::toStr()
{
    // Find the maximum width needed
    int maxNum = 0;
    for (unsigned int i = 0; i < m_; i++)
    {
        for (unsigned int j = 0; j < n_; j++)
        {
            int dt = data[i][j];
            if (dt < 0)
            {
                dt *= -1; // get absolute value
            }
            if (maxNum < dt)
            {
                maxNum = dt;
            }
        }
    }

    maxNum = std::to_string(maxNum).length();
    maxNum++; // add space between numbers

    std::string result = "";

    std::string line = "-";

    for (int i = 0; i < m_ * (maxNum + 2); i++)
    {
        line += "-";
    }
    result += line;
    result += "\n";
    for (unsigned int i = 0; i < m_; i++)
    {
        std::string row = "";

        result += "| ";
        for (unsigned int j = 0; j < n_; j++)
        {
            std::string num = std::to_string(data[i][j]);

            row += num;
            for (int n = num.length(); n < maxNum; n++)
            {
                row += " ";
            }

            row += "| ";
        }
        result += row;
        result += "\n";
        result += line;
        result += "\n";
    }
    return result;
}
/**
 * this is the destructor
 * its called every time i want to delete the matrix from memory
 * we clear the data individually , then the data itself , as we basically have an array of arrays
 * it returns nothing and takes in nothing
 */
Matrix::~Matrix()
{
    for (unsigned int i = 0; i < m_; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
