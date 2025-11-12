#include <iostream>
#include "Matrix.h"

using namespace std;

// this tests the standard constructor, making sure m and n are set right
void Test_Case_1_Constructor_Basic()
{
    cout << "Constructor(m, n), checking m and n set correct";
    Matrix *mat = new Matrix(3, 4);
    if (mat->rows() == 3 && mat->columns() == 4 && mat->get(0, 0) == 0)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// this tests everyhting is initialized to 0's
void Test_Case_2_Constructor_Square()
{
    cout << "Constructor(m, n), checking all 0's";
    Matrix *mat = new Matrix(5, 5);
    for (unsigned int i = 0; i < 5; i++)
    {
        for (unsigned int j = 0; j < 5; j++)
        {
            if (mat->get(i, j) != 0)
            {
                cout << "FAILED" << endl;
                return;
            }
        }
    }
    cout << "PASSED" << endl;
    delete mat;
}

// this is testing a 1x1 matrix
void Test_Case_3_Constructor_Single_Element()
{
    cout << "Constructor(m, n), 1x1 matrix ";
    Matrix *mat = new Matrix(1, 1);
    if (mat->rows() == 1 && mat->columns() == 1 && mat->get(0, 0) == 0)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// basic copy constructor test, making sure it copys the right values in
void Test_Case_4_Copy_Constructor_Basic()
{
    cout << "Copy Constructor, 2x2: ";
    Matrix *mat1 = new Matrix(2, 2);
    mat1->set(0, 0, 5);
    mat1->set(1, 1, 10);

    Matrix *mat2 = new Matrix(*mat1);
    if (mat2->get(0, 0) == 5 && mat2->get(1, 1) == 10 && mat2->rows() == 2 && mat2->columns() == 2)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// this tests the deep copy is working
void Test_Case_5_Copy_Constructor_Deep_Copy()
{
    cout << "Copy Constructor, Deep Copy Test: ";
    Matrix *mat1 = new Matrix(2, 2);
    mat1->set(0, 0, 100);

    Matrix *mat2 = new Matrix(*mat1);
    mat1->set(0, 0, 999);

    // mat2 should still have 100, not 999
    // this is bcus its set to a new value after the copy,
    if (mat2->get(0, 0) == 100 && mat1->get(0, 0) == 999)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// trying copy constructor on a really big matrix
void Test_Case_6_Copy_Constructor_Large()
{
    cout << "Copy Constructor, Large: ";
    Matrix *mat1 = new Matrix(10, 10);
    for (unsigned int i = 0; i < 10; i++)
    {
        mat1->set(i, i, i * 10);
    }

    Matrix *mat2 = new Matrix(*mat1);
    for (unsigned int i = 0; i < 10; i++)
    {
        if (mat2->get(i, i) != (int)(i * 10))
        {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
    delete mat1;
    delete mat2;
}

// using the array constructor, verifying all values are set
void Test_Case_7_Array_Constructor_Basic()
{
    cout << "Array Constructor, checking all values";

    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[3];
    }
    // just gonna set it in increasing order
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[0][2] = 3;
    arr[1][0] = 4;
    arr[1][1] = 5;
    arr[1][2] = 6;

    Matrix *mat = new Matrix(arr, 2, 3);

    bool passed = (mat->get(0, 0) == 1 && mat->get(0, 2) == 3 && mat->get(1, 1) == 5 && mat->rows() == 2 && mat->columns() == 3);

    for (int i = 0; i < 2; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;

    if (passed)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

// making sure it uses the deep copy and not the standard coppy by modifying the inputed 2d pointer
void Test_Case_8_Array_Constructor_DeepCopy()
{
    cout << "Array Constructor, Deep copy test: ";

    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[2];
    }
    arr[0][0] = 50;
    arr[0][1] = 60;
    arr[1][0] = 70;
    arr[1][1] = 80;

    Matrix *mat = new Matrix(arr, 2, 2);

    arr[0][0] = 999;

    bool passed = (mat->get(0, 0) == 50);

    for (int i = 0; i < 2; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;

    if (passed)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

// passing in negative vals and making sure it works
void Test_Case_9_Array_Constructor_Negative()
{
    cout << "Array Constructor, Negative Vals: ";

    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[2];
    }
    arr[0][0] = -5;
    arr[0][1] = -10;
    arr[1][0] = 15;
    arr[1][1] = -20;

    Matrix *mat = new Matrix(arr, 2, 2);

    bool passed = (mat->get(0, 0) == -5 && mat->get(0, 1) == -10 && mat->get(1, 0) == 15 && mat->get(1, 1) == -20);

    for (int i = 0; i < 2; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;

    if (passed)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
}

// basic rows getter
void Test_Case_10_Rows_Basic()
{
    cout << "rows(), basic get test: ";
    Matrix *mat = new Matrix(5, 3);
    if (mat->rows() == 5)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// basic rows getter again but square, not sure what else i can really test on a getter so here you go
void Test_Case_11_Rows_Square()
{
    cout << "rows(), Square ";
    Matrix *mat = new Matrix(7, 7);
    if (mat->rows() == 7)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}
// basic cols getter test
void Test_Case_12_Columns_Basic()
{
    cout << "columns(), basic get test: ";
    Matrix *mat = new Matrix(5, 7);
    if (mat->columns() == 7)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// basic cols getter test
void Test_Case_13_Columns_Single()
{
    cout << "columns(), length 1 ";
    Matrix *mat = new Matrix(10, 1);
    if (mat->columns() == 1)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// get at i , j test
void Test_Case_14_Get_Basic()
{
    cout << "get(), grab val at 3 , 3 : ";
    Matrix *mat = new Matrix(3, 3);
    mat->set(1, 2, 42);
    if (mat->get(1, 2) == 42)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// make sure get works on the default empty
void Test_Case_15_Get_Zero()
{
    cout << "get(), default empty : ";
    Matrix *mat = new Matrix(3, 3);
    if (mat->get(0, 0) == 0 && mat->get(2, 2) == 0)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// get works on negative, basically proving in mot messing up unsigned int for output since im using it for input
void Test_Case_16_Get_Negative()
{
    cout << "get(), negative vals: ";
    Matrix *mat = new Matrix(2, 2);
    mat->set(1, 1, -999);
    if (mat->get(1, 1) == -999)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// basic set() test
void Test_Case_17_Set_Basic()
{
    cout << "set() : ";
    Matrix *mat = new Matrix(2, 2);
    mat->set(0, 1, 99);
    mat->set(1, 0, -5);
    if (mat->get(0, 1) == 99 && mat->get(1, 0) == -5)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// using set to overwrite a value that i already set
void Test_Case_18_Set_Overwrite()
{
    cout << "set(),overwrite: ";
    Matrix *mat = new Matrix(2, 2);
    mat->set(0, 0, 100);
    mat->set(0, 0, 200);
    if (mat->get(0, 0) == 200)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// using set for multiple values
void Test_Case_19_Set_Multiple()
{
    cout << "set(), multiple vals : ";
    Matrix *mat = new Matrix(3, 3);
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            mat->set(i, j, i * 3 + j);
        }
    }
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (mat->get(i, j) != (int)(i * 3 + j))
            {
                cout << "FAILED" << endl;
            }
        }
    }

    cout << "PASSED" << endl;
    delete mat;
}

// addition overide basic add test
void Test_Case_20_Addition_Basic()
{
    cout << "operator+ , basic test : ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 1);
    mat1->set(0, 1, 2);
    mat1->set(1, 0, 3);
    mat1->set(1, 1, 4);

    mat2->set(0, 0, 5);
    mat2->set(0, 1, 6);
    mat2->set(1, 0, 7);
    mat2->set(1, 1, 8);

    Matrix *result = new Matrix(*mat1 + *mat2);

    if (result->get(0, 0) == 6 && result->get(0, 1) == 8 && result->get(1, 0) == 10 && result->get(1, 1) == 12)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// negative addition test
void Test_Case_21_Addition_Negative()
{
    cout << "operator+, negative vals : ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, -5);
    mat1->set(0, 1, 10);
    mat2->set(0, 0, 3);
    mat2->set(0, 1, -2);

    Matrix *result = new Matrix(*mat1 + *mat2);

    if (result->get(0, 0) == -2 && result->get(0, 1) == 8)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// adding zero matrixces
void Test_Case_22_Addition_Zero()
{
    cout << "operator+ , adding zeros: ";
    Matrix *mat1 = new Matrix(3, 3);
    Matrix *mat2 = new Matrix(3, 3);

    mat1->set(0, 0, 5);
    mat1->set(1, 1, 10);
    mat1->set(2, 2, 15);

    Matrix *result = new Matrix(*mat1 + *mat2);

    if (result->get(0, 0) == 5 && result->get(1, 1) == 10 && result->get(2, 2) == 15)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// basic subtraction test
void Test_Case_23_Subtraction_Basic()
{
    cout << "operator- basic test: ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 10);
    mat1->set(0, 1, 20);
    mat1->set(1, 0, 30);
    mat1->set(1, 1, 40);

    mat2->set(0, 0, 1);
    mat2->set(0, 1, 2);
    mat2->set(1, 0, 3);
    mat2->set(1, 1, 4);

    Matrix *result = new Matrix(*mat1 - *mat2);

    if (result->get(0, 0) == 9 && result->get(0, 1) == 18 && result->get(1, 0) == 27 && result->get(1, 1) == 36)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// subtraction overloader where the output is negative
void Test_Case_24_Subtraction_Negative_Result()
{
    cout << "operator- , negative result: ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 5);
    mat2->set(0, 0, 10);

    Matrix *result = new Matrix(*mat1 - *mat2);

    if (result->get(0, 0) == -5)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// subtraction of a matrices from itself (it should result in a zero)
// this could be a useful thing to make a 0,0 matrix of size of the one you have at the moment
void Test_Case_25_Subtraction_Self()
{
    cout << "operator- , subtracting from itself to make zero matrix: ";
    Matrix *mat1 = new Matrix(3, 3);
    mat1->set(0, 0, 100);
    mat1->set(1, 1, 200);
    mat1->set(2, 2, 300);

    Matrix *result = new Matrix(*mat1 - *mat1);

    if (result->get(0, 0) == 0 && result->get(1, 1) == 0 && result->get(2, 2) == 0)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete result;
}

// basic multiplication overloader test
void Test_Case_26_Multiplication_Basic()
{
    cout << "operator* : ";
    Matrix *mat1 = new Matrix(2, 3);
    Matrix *mat2 = new Matrix(3, 2);

    mat1->set(0, 0, 1);
    mat1->set(0, 1, 2);
    mat1->set(0, 2, 3);
    mat1->set(1, 0, 4);
    mat1->set(1, 1, 5);
    mat1->set(1, 2, 6);

    mat2->set(0, 0, 7);
    mat2->set(0, 1, 8);
    mat2->set(1, 0, 9);
    mat2->set(1, 1, 10);
    mat2->set(2, 0, 11);
    mat2->set(2, 1, 12);

    Matrix *result = new Matrix(*mat1 * *mat2);

    if (result->rows() == 2 && result->columns() == 2 && result->get(0, 0) == 58 && result->get(0, 1) == 64 && result->get(1, 0) == 139 && result->get(1, 1) == 154) // big test
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// multiplying a square with the overloader
void Test_Case_27_Multiplication_Square()
{
    cout << "operator*, multiplinig a square: ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 1);
    mat1->set(0, 1, 2);
    mat1->set(1, 0, 3);
    mat1->set(1, 1, 4);

    mat2->set(0, 0, 2);
    mat2->set(0, 1, 0);
    mat2->set(1, 0, 1);
    mat2->set(1, 1, 2);

    Matrix *result = new Matrix(*mat1 * *mat2);
    if (result->get(0, 0) == 4 && result->get(0, 1) == 4 &&
        result->get(1, 0) == 10 && result->get(1, 1) == 8)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// multiplying an identity matrix
void Test_Case_28_Multiplication_Identity()
{
    cout << "operator* , identity matrix: ";
    Matrix *mat1 = new Matrix(3, 3);
    Matrix *identity = new Matrix(3, 3);

    mat1->set(0, 0, 5);
    mat1->set(0, 1, 10);
    mat1->set(0, 2, 15);
    mat1->set(1, 0, 20);
    mat1->set(1, 1, 25);
    mat1->set(1, 2, 30);
    mat1->set(2, 0, 35);
    mat1->set(2, 1, 40);
    mat1->set(2, 2, 45);

    identity->set(0, 0, 1);
    identity->set(1, 1, 1);
    identity->set(2, 2, 1);

    Matrix *result = new Matrix(*mat1 * *identity);

    if (result->get(0, 0) == 5 && result->get(1, 1) == 25 && result->get(2, 2) == 45)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete identity;
    delete result;
}

// basic transpose test
void Test_Case_29_Transpose_Basic()
{
    cout << "operator~ ";
    Matrix *mat = new Matrix(2, 3);

    mat->set(0, 0, 1);
    mat->set(0, 1, 2);
    mat->set(0, 2, 3);
    mat->set(1, 0, 4);
    mat->set(1, 1, 5);
    mat->set(1, 2, 6);

    Matrix *result = new Matrix(~(*mat));

    if (result->rows() == 3 && result->columns() == 2 && result->get(0, 0) == 1 && result->get(0, 1) == 4 && result->get(1, 0) == 2 && result->get(1, 1) == 5 && result->get(2, 0) == 3 && result->get(2, 1) == 6) // sorry i know this is big but no other way
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

// transposing a square matrix
void Test_Case_30_Transpose_Square()
{
    cout << "operator~ , the square matrix transpose: ";
    Matrix *mat = new Matrix(3, 3);

    mat->set(0, 1, 10);
    mat->set(1, 0, 20);
    mat->set(1, 2, 30);
    mat->set(2, 1, 40);

    Matrix *result = new Matrix(~(*mat));

    if (result->get(1, 0) == 10 && result->get(0, 1) == 20 && result->get(2, 1) == 30 && result->get(1, 2) == 40)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

// double transpose
void Test_Case_31_Transpose_Double()
{
    cout << "operator~ , double transpose: ";
    Matrix *mat = new Matrix(2, 3);

    mat->set(0, 0, 1);
    mat->set(0, 1, 2);
    mat->set(0, 2, 3);
    mat->set(1, 0, 4);
    mat->set(1, 1, 5);
    mat->set(1, 2, 6);

    Matrix temp1 = ~(*mat);
    Matrix *result = new Matrix(~temp1);

    if (result->rows() == 2 && result->columns() == 3 && result->get(0, 0) == 1 && result->get(1, 2) == 6)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

// equality operator basic test
void Test_Case_32_Equality_Same()
{
    cout << "operator== , same matrix test: ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 1);
    mat1->set(0, 1, 2);
    mat1->set(1, 0, 3);
    mat1->set(1, 1, 4);

    mat2->set(0, 0, 1);
    mat2->set(0, 1, 2);
    mat2->set(1, 0, 3);
    mat2->set(1, 1, 4);

    if (*mat1 == *mat2)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// equality operator where the 2 vals differ test
void Test_Case_33_Equality_Different_Values()
{
    cout << "operator== differnt vals test ; ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 2);

    mat1->set(0, 0, 1);
    mat2->set(0, 0, 2);

    if (!(*mat1 == *mat2))
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// equality where they both have different dimensions, in this case m is bigger on mat2
void Test_Case_34_Equality_Different_Dimensions()
{
    cout << "operator== , different dimensions: ";
    Matrix *mat1 = new Matrix(2, 2);
    Matrix *mat2 = new Matrix(2, 3);

    if (!(*mat1 == *mat2))
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// equality on 2 zero matrices
void Test_Case_35_Equality_Zero_Matrices()
{
    cout << "operator== , zero matrices check: ";
    Matrix *mat1 = new Matrix(3, 3);
    Matrix *mat2 = new Matrix(3, 3);

    if (*mat1 == *mat2)
    {
        cout << "PASSED" << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_36_ToString_Basic()
{
    cout << "Test Case 36 - toStr() - Basic: ";
    Matrix *mat = new Matrix(2, 2);
    mat->set(0, 0, 1);
    mat->set(0, 1, 2);
    mat->set(1, 0, 3);
    mat->set(1, 1, 4);

    string str = mat->toStr();
    std::cout << str << std::endl;
    if (str.length() > 0 && str.find('1') != string::npos &&
        str.find('4') != string::npos)
    {
        cout << "PASSED" << endl;
        cout << "  Output:\n"
             << str << endl;
    }
    else
    {
        cout << "FAILED" << endl;
    }
    delete mat;
}

int main()
{
    cout << "=====================================" << endl;
    cout << "      Matrix Class Test Suite       " << endl;
    cout << "=====================================" << endl
         << endl;

    cout << "  Constructor Tests " << endl;
    Test_Case_1_Constructor_Basic();
    Test_Case_2_Constructor_Square();
    Test_Case_3_Constructor_Single_Element();

    cout << "\n  Copy Constructor Tests  " << endl;
    Test_Case_4_Copy_Constructor_Basic();
    Test_Case_5_Copy_Constructor_Deep_Copy();
    Test_Case_6_Copy_Constructor_Large();

    cout << "\n  Array Constructor Tests  " << endl;
    Test_Case_7_Array_Constructor_Basic();
    Test_Case_8_Array_Constructor_DeepCopy();
    Test_Case_9_Array_Constructor_Negative();

    cout << "\n  rows() Tests  " << endl;
    Test_Case_10_Rows_Basic();
    Test_Case_11_Rows_Square();

    cout << "\n  columns() Tests  " << endl;
    Test_Case_12_Columns_Basic();
    Test_Case_13_Columns_Single();

    cout << "\n  get() Tests " << endl;
    Test_Case_14_Get_Basic();
    Test_Case_15_Get_Zero();
    Test_Case_16_Get_Negative();

    cout << "\n  set() Tests " << endl;
    Test_Case_17_Set_Basic();
    Test_Case_18_Set_Overwrite();
    Test_Case_19_Set_Multiple();

    cout << "\n  Addition Tests  " << endl;
    Test_Case_20_Addition_Basic();
    Test_Case_21_Addition_Negative();
    Test_Case_22_Addition_Zero();

    cout << "\n  Subtraction Tests  " << endl;
    Test_Case_23_Subtraction_Basic();
    Test_Case_24_Subtraction_Negative_Result();
    Test_Case_25_Subtraction_Self();

    cout << "\n Multiplication Tests  " << endl;
    Test_Case_26_Multiplication_Basic();
    Test_Case_27_Multiplication_Square();
    Test_Case_28_Multiplication_Identity();

    cout << "\n Transpose Tests  " << endl;
    Test_Case_29_Transpose_Basic();
    Test_Case_30_Transpose_Square();
    Test_Case_31_Transpose_Double();

    cout << "\n Equality Tests " << endl;
    Test_Case_32_Equality_Same();
    Test_Case_33_Equality_Different_Values();
    Test_Case_34_Equality_Different_Dimensions();
    Test_Case_35_Equality_Zero_Matrices();

    cout << "\n toString Tests" << endl;
    Test_Case_36_ToString_Basic();

    cout << "        Finished Tests         " << endl;

    return 0;
}
