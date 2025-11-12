
#include <string>

class Matrix
{

private:
    int **data;      // this is the actual data for the matrix
    unsigned int m_; // rows
    unsigned int n_; // colums

public: // this is all the assingment declared variables copied in 1:1
    ////////////////////////////////////////////////////////////////////
    //                           Constructors                         //
    ////////////////////////////////////////////////////////////////////

    Matrix(unsigned int m, unsigned int n);              // m*n matrix filled with 0's
    Matrix(const Matrix &mat);                           // copy constructor
    Matrix(int **array, unsigned int m, unsigned int n); // pass in 2d array with m and n constructor

    ////////////////////////////////////////////////////////////////////
    //                              Getter                            //
    ////////////////////////////////////////////////////////////////////

    unsigned int rows() const;                   // get rows (n_)
    unsigned int columns() const;                // get columns (m_)
    int get(unsigned i, unsigned j) const;       // get value in data at data[i][j]
    void set(unsigned i, unsigned j, int value); // set value in data at data[i][j]

    ////////////////////////////////////////////////////////////////////
    //                       Operation Overloading                    //
    ////////////////////////////////////////////////////////////////////

    Matrix operator+(const Matrix &mat);
    Matrix operator-(const Matrix &mat);
    Matrix operator*(const Matrix &mat);
    Matrix operator~() const;
    bool operator==(const Matrix &mat);

    ////////////////////////////////////////////////////////////////////
    //                             toString                           //
    ////////////////////////////////////////////////////////////////////

    std::string toStr();

public:
    ~Matrix(); // destructor, not defined in ca sheet but good for safety C:
};
