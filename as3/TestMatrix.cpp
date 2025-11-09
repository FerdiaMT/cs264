#include <iostream>
#include "Matrix.h"

using namespace std;

// ========== Constructor(m, n) Tests ==========
void Test_Case_1_Constructor_Basic() {
    cout << "Test Case 1 - Constructor(m, n) - Basic: ";
    Matrix* mat = new Matrix(3, 4);
    if (mat->rows() == 3 && mat->columns() == 4 && mat->get(0, 0) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_2_Constructor_Square() {
    cout << "Test Case 2 - Constructor(m, n) - Square Matrix: ";
    Matrix* mat = new Matrix(5, 5);
    bool passed = true;
    for (unsigned int i = 0; i < 5; i++) {
        for (unsigned int j = 0; j < 5; j++) {
            if (mat->get(i, j) != 0) {
                passed = false;
                break;
            }
        }
    }
    if (passed && mat->rows() == 5 && mat->columns() == 5) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_3_Constructor_Single_Element() {
    cout << "Test Case 3 - Constructor(m, n) - 1x1 Matrix: ";
    Matrix* mat = new Matrix(1, 1);
    if (mat->rows() == 1 && mat->columns() == 1 && mat->get(0, 0) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// ========== Copy Constructor Tests ==========
void Test_Case_4_Copy_Constructor_Basic() {
    cout << "Test Case 4 - Copy Constructor - Basic: ";
    Matrix* mat1 = new Matrix(2, 2);
    mat1->set(0, 0, 5);
    mat1->set(1, 1, 10);
    
    Matrix* mat2 = new Matrix(*mat1);
    if (mat2->get(0, 0) == 5 && mat2->get(1, 1) == 10 && 
        mat2->rows() == 2 && mat2->columns() == 2) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_5_Copy_Constructor_Deep_Copy() {
    cout << "Test Case 5 - Copy Constructor - Deep Copy Test: ";
    Matrix* mat1 = new Matrix(2, 2);
    mat1->set(0, 0, 100);
    
    Matrix* mat2 = new Matrix(*mat1);
    mat1->set(0, 0, 999);  // Modify original
    
    // mat2 should still have 100, not 999 (proves deep copy)
    if (mat2->get(0, 0) == 100 && mat1->get(0, 0) == 999) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_6_Copy_Constructor_Large() {
    cout << "Test Case 6 - Copy Constructor - Large Matrix: ";
    Matrix* mat1 = new Matrix(10, 10);
    for (unsigned int i = 0; i < 10; i++) {
        mat1->set(i, i, i * 10);
    }
    
    Matrix* mat2 = new Matrix(*mat1);
    bool passed = true;
    for (unsigned int i = 0; i < 10; i++) {
        if (mat2->get(i, i) != (int)(i * 10)) {
            passed = false;
            break;
        }
    }
    
    if (passed) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// ========== Array Constructor Tests ==========
void Test_Case_7_Array_Constructor_Basic() {
    cout << "Test Case 7 - Constructor(array, m, n) - Basic: ";
    
    int** arr = new int*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new int[3];
    }
    arr[0][0] = 1; arr[0][1] = 2; arr[0][2] = 3;
    arr[1][0] = 4; arr[1][1] = 5; arr[1][2] = 6;
    
    Matrix* mat = new Matrix(arr, 2, 3);
    
    bool passed = (mat->get(0, 0) == 1 && mat->get(0, 2) == 3 && 
                   mat->get(1, 1) == 5 && mat->rows() == 2 && mat->columns() == 3);
    
    for (int i = 0; i < 2; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;
    
    if (passed) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}

void Test_Case_8_Array_Constructor_Independence() {
    cout << "Test Case 8 - Constructor(array, m, n) - Independence: ";
    
    int** arr = new int*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new int[2];
    }
    arr[0][0] = 50; arr[0][1] = 60;
    arr[1][0] = 70; arr[1][1] = 80;
    
    Matrix* mat = new Matrix(arr, 2, 2);
    
    // Modify original array
    arr[0][0] = 999;
    
    // Matrix should still have 50
    bool passed = (mat->get(0, 0) == 50);
    
    for (int i = 0; i < 2; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;
    
    if (passed) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}

void Test_Case_9_Array_Constructor_Negative() {
    cout << "Test Case 9 - Constructor(array, m, n) - Negative Values: ";
    
    int** arr = new int*[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new int[2];
    }
    arr[0][0] = -5; arr[0][1] = -10;
    arr[1][0] = 15; arr[1][1] = -20;
    
    Matrix* mat = new Matrix(arr, 2, 2);
    
    bool passed = (mat->get(0, 0) == -5 && mat->get(0, 1) == -10 && 
                   mat->get(1, 0) == 15 && mat->get(1, 1) == -20);
    
    for (int i = 0; i < 2; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete mat;
    
    if (passed) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}

// ========== rows() Tests ==========
void Test_Case_10_Rows_Basic() {
    cout << "Test Case 10 - rows() - Basic: ";
    Matrix* mat = new Matrix(5, 3);
    if (mat->rows() == 5) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_11_Rows_Square() {
    cout << "Test Case 11 - rows() - Square Matrix: ";
    Matrix* mat = new Matrix(7, 7);
    if (mat->rows() == 7) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// ========== columns() Tests ==========
void Test_Case_12_Columns_Basic() {
    cout << "Test Case 12 - columns() - Basic: ";
    Matrix* mat = new Matrix(5, 7);
    if (mat->columns() == 7) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_13_Columns_Single() {
    cout << "Test Case 13 - columns() - Single Column: ";
    Matrix* mat = new Matrix(10, 1);
    if (mat->columns() == 1) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// ========== get() Tests ==========
void Test_Case_14_Get_Basic() {
    cout << "Test Case 14 - get() - Basic: ";
    Matrix* mat = new Matrix(3, 3);
    mat->set(1, 2, 42);
    if (mat->get(1, 2) == 42) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_15_Get_Zero() {
    cout << "Test Case 15 - get() - Default Zero: ";
    Matrix* mat = new Matrix(3, 3);
    if (mat->get(0, 0) == 0 && mat->get(2, 2) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_16_Get_Negative() {
    cout << "Test Case 16 - get() - Negative Value: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(1, 1, -999);
    if (mat->get(1, 1) == -999) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// ========== set() Tests ==========
void Test_Case_17_Set_Basic() {
    cout << "Test Case 17 - set() - Basic: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(0, 1, 99);
    mat->set(1, 0, -5);
    if (mat->get(0, 1) == 99 && mat->get(1, 0) == -5) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_18_Set_Overwrite() {
    cout << "Test Case 18 - set() - Overwrite: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(0, 0, 100);
    mat->set(0, 0, 200);
    if (mat->get(0, 0) == 200) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_19_Set_Multiple() {
    cout << "Test Case 19 - set() - Multiple Values: ";
    Matrix* mat = new Matrix(3, 3);
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            mat->set(i, j, i * 3 + j);
        }
    }
    
    bool passed = true;
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            if (mat->get(i, j) != (int)(i * 3 + j)) {
                passed = false;
                break;
            }
        }
    }
    
    if (passed) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// ========== Addition Tests ==========
void Test_Case_20_Addition_Basic() {
    cout << "Test Case 20 - operator+ - Basic: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 1); mat1->set(0, 1, 2);
    mat1->set(1, 0, 3); mat1->set(1, 1, 4);
    
    mat2->set(0, 0, 5); mat2->set(0, 1, 6);
    mat2->set(1, 0, 7); mat2->set(1, 1, 8);
    
    Matrix* result = new Matrix(*mat1 + *mat2);
    
    if (result->get(0, 0) == 6 && result->get(0, 1) == 8 &&
        result->get(1, 0) == 10 && result->get(1, 1) == 12) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_21_Addition_Negative() {
    cout << "Test Case 21 - operator+ - Negative Values: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, -5); mat1->set(0, 1, 10);
    mat2->set(0, 0, 3); mat2->set(0, 1, -2);
    
    Matrix* result = new Matrix(*mat1 + *mat2);
    
    if (result->get(0, 0) == -2 && result->get(0, 1) == 8) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_22_Addition_Zero() {
    cout << "Test Case 22 - operator+ - Add Zero Matrix: ";
    Matrix* mat1 = new Matrix(3, 3);
    Matrix* mat2 = new Matrix(3, 3);  // All zeros
    
    mat1->set(0, 0, 5);
    mat1->set(1, 1, 10);
    mat1->set(2, 2, 15);
    
    Matrix* result = new Matrix(*mat1 + *mat2);
    
    if (result->get(0, 0) == 5 && result->get(1, 1) == 10 && result->get(2, 2) == 15) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

// ========== Subtraction Tests ==========
void Test_Case_23_Subtraction_Basic() {
    cout << "Test Case 23 - operator- - Basic: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 10); mat1->set(0, 1, 20);
    mat1->set(1, 0, 30); mat1->set(1, 1, 40);
    
    mat2->set(0, 0, 1); mat2->set(0, 1, 2);
    mat2->set(1, 0, 3); mat2->set(1, 1, 4);
    
    Matrix* result = new Matrix(*mat1 - *mat2);
    
    if (result->get(0, 0) == 9 && result->get(0, 1) == 18 &&
        result->get(1, 0) == 27 && result->get(1, 1) == 36) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_24_Subtraction_Negative_Result() {
    cout << "Test Case 24 - operator- - Negative Result: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 5);
    mat2->set(0, 0, 10);
    
    Matrix* result = new Matrix(*mat1 - *mat2);
    
    if (result->get(0, 0) == -5) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_25_Subtraction_Self() {
    cout << "Test Case 25 - operator- - Subtract Self (Zero): ";
    Matrix* mat1 = new Matrix(3, 3);
    mat1->set(0, 0, 100);
    mat1->set(1, 1, 200);
    mat1->set(2, 2, 300);
    
    Matrix* result = new Matrix(*mat1 - *mat1);
    
    if (result->get(0, 0) == 0 && result->get(1, 1) == 0 && result->get(2, 2) == 0) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete result;
}

// ========== Multiplication Tests ==========
void Test_Case_26_Multiplication_Basic() {
    cout << "Test Case 26 - operator* - Basic: ";
    Matrix* mat1 = new Matrix(2, 3);
    Matrix* mat2 = new Matrix(3, 2);
    
    mat1->set(0, 0, 1); mat1->set(0, 1, 2); mat1->set(0, 2, 3);
    mat1->set(1, 0, 4); mat1->set(1, 1, 5); mat1->set(1, 2, 6);
    
    mat2->set(0, 0, 7); mat2->set(0, 1, 8);
    mat2->set(1, 0, 9); mat2->set(1, 1, 10);
    mat2->set(2, 0, 11); mat2->set(2, 1, 12);
    
    Matrix* result = new Matrix(*mat1 * *mat2);
    
    if (result->rows() == 2 && result->columns() == 2 &&
        result->get(0, 0) == 58 && result->get(0, 1) == 64 &&
        result->get(1, 0) == 139 && result->get(1, 1) == 154) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_27_Multiplication_Square() {
    cout << "Test Case 27 - operator* - Square Matrices: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 1); mat1->set(0, 1, 2);
    mat1->set(1, 0, 3); mat1->set(1, 1, 4);
    
    mat2->set(0, 0, 2); mat2->set(0, 1, 0);
    mat2->set(1, 0, 1); mat2->set(1, 1, 2);
    
    Matrix* result = new Matrix(*mat1 * *mat2);
    
    // [1,2] * [2,0] = [4, 4]
    // [3,4]   [1,2]   [10,8]
    if (result->get(0, 0) == 4 && result->get(0, 1) == 4 &&
        result->get(1, 0) == 10 && result->get(1, 1) == 8) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
    delete result;
}

void Test_Case_28_Multiplication_Identity() {
    cout << "Test Case 28 - operator* - Identity Matrix: ";
    Matrix* mat1 = new Matrix(3, 3);
    Matrix* identity = new Matrix(3, 3);
    
    mat1->set(0, 0, 5); mat1->set(0, 1, 10); mat1->set(0, 2, 15);
    mat1->set(1, 0, 20); mat1->set(1, 1, 25); mat1->set(1, 2, 30);
    mat1->set(2, 0, 35); mat1->set(2, 1, 40); mat1->set(2, 2, 45);
    
    identity->set(0, 0, 1);
    identity->set(1, 1, 1);
    identity->set(2, 2, 1);
    
    Matrix* result = new Matrix(*mat1 * *identity);
    
    if (result->get(0, 0) == 5 && result->get(1, 1) == 25 && result->get(2, 2) == 45) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete identity;
    delete result;
}

// ========== Transpose Tests ==========
void Test_Case_29_Transpose_Basic() {
    cout << "Test Case 29 - operator~ - Basic: ";
    Matrix* mat = new Matrix(2, 3);
    
    mat->set(0, 0, 1); mat->set(0, 1, 2); mat->set(0, 2, 3);
    mat->set(1, 0, 4); mat->set(1, 1, 5); mat->set(1, 2, 6);
    
    Matrix* result = new Matrix(~(*mat));
    
    if (result->rows() == 3 && result->columns() == 2 &&
        result->get(0, 0) == 1 && result->get(0, 1) == 4 &&
        result->get(1, 0) == 2 && result->get(1, 1) == 5 &&
        result->get(2, 0) == 3 && result->get(2, 1) == 6) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

void Test_Case_30_Transpose_Square() {
    cout << "Test Case 30 - operator~ - Square Matrix: ";
    Matrix* mat = new Matrix(3, 3);
    
    mat->set(0, 1, 10);
    mat->set(1, 0, 20);
    mat->set(1, 2, 30);
    mat->set(2, 1, 40);
    
    Matrix* result = new Matrix(~(*mat));
    
    if (result->get(1, 0) == 10 && result->get(0, 1) == 20 &&
        result->get(2, 1) == 30 && result->get(1, 2) == 40) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

void Test_Case_31_Transpose_Double() {
    cout << "Test Case 31 - operator~ - Double Transpose: ";
    Matrix* mat = new Matrix(2, 3);
    
    mat->set(0, 0, 1); mat->set(0, 1, 2); mat->set(0, 2, 3);
    mat->set(1, 0, 4); mat->set(1, 1, 5); mat->set(1, 2, 6);
    
    Matrix temp1 = ~(*mat);
    Matrix* result = new Matrix(~temp1);
    
    if (result->rows() == 2 && result->columns() == 3 &&
        result->get(0, 0) == 1 && result->get(1, 2) == 6) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
    delete result;
}

// ========== Equality Tests ==========
void Test_Case_32_Equality_Same() {
    cout << "Test Case 32 - operator== - Identical Matrices: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 1); mat1->set(0, 1, 2);
    mat1->set(1, 0, 3); mat1->set(1, 1, 4);
    
    mat2->set(0, 0, 1); mat2->set(0, 1, 2);
    mat2->set(1, 0, 3); mat2->set(1, 1, 4);
    
    if (*mat1 == *mat2) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_33_Equality_Different_Values() {
    cout << "Test Case 33 - operator== - Different Values: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 2);
    
    mat1->set(0, 0, 1);
    mat2->set(0, 0, 2);
    
    if (!(*mat1 == *mat2)) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_34_Equality_Different_Dimensions() {
    cout << "Test Case 34 - operator== - Different Dimensions: ";
    Matrix* mat1 = new Matrix(2, 2);
    Matrix* mat2 = new Matrix(2, 3);
    
    if (!(*mat1 == *mat2)) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

void Test_Case_35_Equality_Zero_Matrices() {
    cout << "Test Case 35 - operator== - Zero Matrices: ";
    Matrix* mat1 = new Matrix(3, 3);
    Matrix* mat2 = new Matrix(3, 3);
    
    if (*mat1 == *mat2) {
        cout << "PASSED" << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat1;
    delete mat2;
}

// ========== toString Tests ==========
void Test_Case_36_ToString_Basic() {
    cout << "Test Case 36 - toStr() - Basic: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(0, 0, 1); mat->set(0, 1, 2);
    mat->set(1, 0, 3); mat->set(1, 1, 4);
    
    string str = mat->toStr();
    std::cout<<str<<std::endl;
    if (str.length() > 0 && str.find('1') != string::npos && 
        str.find('4') != string::npos) {
        cout << "PASSED" << endl;
        cout << "  Output:\n" << str << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_37_ToString_Negative() {
    cout << "Test Case 37 - toStr() - Negative Values: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(0, 0, -10);
    mat->set(1, 1, -20);
    
    string str = mat->toStr();
    
    if (str.find('-') != string::npos) {
        cout << "PASSED" << endl;
        cout << "  Output:\n" << str << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

void Test_Case_38_ToString_Large_Numbers() {
    cout << "Test Case 38 - toStr() - Large Numbers: ";
    Matrix* mat = new Matrix(2, 2);
    mat->set(0, 0, 1234);
    mat->set(1, 1, 5678);
    
    string str = mat->toStr();
    
    if (str.find("1234") != string::npos && str.find("5678") != string::npos) {
        cout << "PASSED" << endl;
        cout << "  Output:\n" << str << endl;
    } else {
        cout << "FAILED" << endl;
    }
    delete mat;
}

// Main test runner
int main() {
    cout << "=====================================" << endl;
    cout << "      Matrix Class Test Suite       " << endl;
    cout << "=====================================" << endl << endl;
    
    cout << "--- Constructor Tests ---" << endl;
    Test_Case_1_Constructor_Basic();
    Test_Case_2_Constructor_Square();
    Test_Case_3_Constructor_Single_Element();
    
    cout << "\n--- Copy Constructor Tests ---" << endl;
    Test_Case_4_Copy_Constructor_Basic();
    Test_Case_5_Copy_Constructor_Deep_Copy();
    Test_Case_6_Copy_Constructor_Large();
    
    cout << "\n--- Array Constructor Tests ---" << endl;
    Test_Case_7_Array_Constructor_Basic();
    Test_Case_8_Array_Constructor_Independence();
    Test_Case_9_Array_Constructor_Negative();
    
    cout << "\n--- rows() Tests ---" << endl;
    Test_Case_10_Rows_Basic();
    Test_Case_11_Rows_Square();
    
    cout << "\n--- columns() Tests ---" << endl;
    Test_Case_12_Columns_Basic();
    Test_Case_13_Columns_Single();
    
    cout << "\n--- get() Tests ---" << endl;
    Test_Case_14_Get_Basic();
    Test_Case_15_Get_Zero();
    Test_Case_16_Get_Negative();
    
    cout << "\n--- set() Tests ---" << endl;
    Test_Case_17_Set_Basic();
    Test_Case_18_Set_Overwrite();
    Test_Case_19_Set_Multiple();
    
    cout << "\n--- Addition Tests ---" << endl;
    Test_Case_20_Addition_Basic();
    Test_Case_21_Addition_Negative();
    Test_Case_22_Addition_Zero();
    
    cout << "\n--- Subtraction Tests ---" << endl;
    Test_Case_23_Subtraction_Basic();
    Test_Case_24_Subtraction_Negative_Result();
    Test_Case_25_Subtraction_Self();
    
    cout << "\n--- Multiplication Tests ---" << endl;
    Test_Case_26_Multiplication_Basic();
    Test_Case_27_Multiplication_Square();
    Test_Case_28_Multiplication_Identity();
    
    cout << "\n--- Transpose Tests ---" << endl;
    Test_Case_29_Transpose_Basic();
    Test_Case_30_Transpose_Square();
    Test_Case_31_Transpose_Double();
    
    cout << "\n--- Equality Tests ---" << endl;
    Test_Case_32_Equality_Same();
    Test_Case_33_Equality_Different_Values();
    Test_Case_34_Equality_Different_Dimensions();
    Test_Case_35_Equality_Zero_Matrices();
    
    cout << "\n--- toString Tests ---" << endl;
    Test_Case_36_ToString_Basic();
    Test_Case_37_ToString_Negative();
    Test_Case_38_ToString_Large_Numbers();
    
    cout << "\n=====================================" << endl;
    cout << "         All Tests Complete!         " << endl;
    cout << "=====================================" << endl;
    
    return 0;
}