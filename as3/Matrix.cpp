#include <Matrix.h>
#include <string>

Matrix::Matrix(unsigned int m, unsigned int n) // constuctor of MxN matrix of 0's
{
    this->m_ = m; // set the rows
    this->n_ = n; // set the columns
    
    data = new int*[m]; // create a row of pointers that is m long (row length), 
    //so right now it looks like if m=5, xxxxx , where each x points down (this is how im visualizing it atleast, its literally just an array of pointers in reality)

    for(unsigned int i = 0; i < m; i++)
    {
        data[i] = new int[n]; // allocate the column length to each row (going down in this visual example)

        for (unsigned int j = 0; j < n; j++) //fill in all our data with 0's
        { 
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &mat): m_(mat.m_) , n_(mat.n_) // the copy function, so we grab all the data and allocate it
{
    //PROBLEM: the initializer list does not contain data(mat.data)
    // this is because that would make a shallow copy
    // so this matrixs data pointer would point to another matrix altogether
    // and if the other matrix was deleted, then wed get a bunch of errors which is really bad
    // so instead, we make a deep copy, by just iterating through each value and setting the memory for in here
    // that way we get 0 memory errors
    data = new int*[m_];

    for (unsigned int i = 0; i < m_; i++) 
    {
        data[i] = new int[n_];
        for (unsigned int j = 0; j < n_; j++) 
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::Matrix ( int ** array , unsigned int m , unsigned int n ) : m_(m) , n_(n) // this is for passing in a 2d array pointer 
{
    // once again, we would get the same issue as the copy function, where if that array was killed, we would have pointers leading 
    // to data that doesnt exist, so instead we take the m and n with the initializer list, and make data a deep copy

    data = new int*[m_];

    for (unsigned int i = 0; i < m_; i++) 
    {
        data[i] = new int[n_];
        for (unsigned int j = 0; j < n_; j++) 
        {
            data[i][j] = array[i][j];
        }
    }
}

unsigned int Matrix::rows() const
{
    return this->m_;
}
unsigned int Matrix::columns() const
{
    return this->n_;
}
int Matrix::get(unsigned i, unsigned j) const
{
    if (i >= m_ || j >= n_|| i < 0 || j < 0 ) // check if were going to be out of bounds
    { 
        return NULL; // out of bounds value isnt defined by the ca, but ill return NULL here 
    }
    return data[i][j];
}               
void Matrix::set(unsigned i, unsigned j, int value)
{
    if (i >= m_ || j >= n_|| i < 0 || j < 0 ) { // check if were going to be out of bounds
        return;
    }
    data[i][j] = value;
}          

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
    
    return result;  //return by value
}

Matrix Matrix::operator-(const Matrix &mat)
{
    // same informamation about my code as +

    Matrix result(m_, n_);

    if (m_ != mat.m_ || n_ != mat.n_) 
    {
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
Matrix Matrix::operator*(const Matrix &mat)
{
    // same informamation about my code as +

    Matrix result(m_, mat.n_);

    if (n_ != mat.m_)  // it needs to be able to multiply, so n  has to be the same as m 
    {
        return result;
    }
    
    for (unsigned int i = 0; i < m_; i++) {
        for (unsigned int j = 0; j < mat.n_; j++) {
            
            int sum = 0; // dot product calculator
            for (unsigned int k = 0; k < n_; k++) // use k to read across row / column for dot product
            {
                sum += this->data[i][k] * mat.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
}

Matrix Matrix::operator~() const
{
    Matrix result(n_, m_);  // when we declare this , we are gonna swap row and columns as were transposing
    
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

bool Matrix::operator==(const Matrix &mat)
{
    // check if the 2 values are the same
    // not a literal check if the memory location is the same 

    if (n_ != mat.n_ || m_ != mat.m_ )  
    {
        return false;
    }
    
    for (unsigned int i = 0; i < m_; i++) 
    {
        for (unsigned int j = 0; j < mat.n_; j++) 
        {
            
            if( data[i][j] != mat.data[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

std::string Matrix::toStr()
{
    // turn the matrix into a string

    // the first thing im going to do is find the maximum value in the entire thing, so we know how much spacing to do
    for (unsigned int i = 0; i < m_; i++) 
    {
        for (unsigned int j = 0; j < n_; j++) 
        {
            
        }
    }
    std::string result = "";
    for (unsigned int i = 0; i < m_; i++) 
    {
        std::string row = "";
        for (unsigned int j = 0; j < n_; j++) 
        {
            row += std::to_string(data[i][j]);

        }
    }

}