#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;


typedef Eigen::Matrix<float, 3, 3> MyMatrix33f; // Defines a 3x3 matrix with floating point data
typedef Eigen::Matrix<float, 3, 1> MyVector3f; // Devines a 3x1 column vector with floating point data
typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> MyMatrix; // Defines a matrix with double data and dynamic dimensions

int main() {
    /*

    // Declaring variables

    MyMatrix33f a;
    MyVector3f v;
    MyMatrix m(10,15);

    // Initialization
    a = MyMatrix33f::Zero(); // This fills the matrix with 0's

    std::cout << "Zero matrix:\n" << a << std::endl;

    a = MyMatrix33f::Identity(); // This makes the matrix the identity matrix
    std::cout << "Identity matrix:\n" << a << std::endl;

    v = MyVector3f::Random(); // This fills the matrix with random values
    std::cout <<"Random vector:\n" << v << std::endl;

    a << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    std::cout << "Comma initialized matrix:\n" << a << std::endl;

    a(0, 0) = 3;
    std::cout << "After changing the first element to 3:\n" << a << std::endl;

    // Using the object of the Map type to wrap an existent C++ array/vector in the Matrix type object.

    // Mapping a row vector to an array
    int data[] = {1, 2, 3, 4};
    Map<RowVectorXi> v_map(data, 4);
    std::cout << "Row vector mapped to array:\n" << v_map << std::endl;

    // Mapping a matrix to an array
    std::vector<float> vdata = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Eigen::Map<MyMatrix33f> a_map(vdata.data());
    std::cout << "Matrix mapped to array:\n" << a_map << std::endl;

    */

    /*
    // Arithmetic Practice

    Eigen::Matrix2d a;
    a << 1, 2, 3, 4;

    Eigen::Matrix2d b;
    b << 1, 2, 3, 4;

    // Elemement-wise operations

    // Element-wise multiplication
    Matrix2d result = a.array() * b.array();
    std::cout << "Element-wise multiplication gives:  \n" << result << std::endl;

    // Element-wise division
    result = a.array() / b.array();
    std::cout << "Element-wise division gives:  \n" << result << std::endl;

    // Element-wise scalar multiplication

    a = b.array()*4;

    std::cout << "element wise a = b*4 : \n" << a << std::endl;

    a << 1, 2, 3, 4;

    std::cout << "Reset a: \n" << a << std::endl;


    // Matrix Operations

        // Fast element-wise addition
        result = a + b;
        std::cout << "Matrices a + b:\n" << result << std::endl;

        // Fast element-wise addition with redefinition
        a += b;

        std::cout << "Matrices a+= b: \n" << result << std::endl;

        a << 1, 2, 3, 4;

        // Matrix Multiplication
        result = a * b;
        std::cout << "Matrices a*b: \n" << result << std::endl;
    */


    /*
        // Performing operations on only part of a matrix NOTE... ROWS AND COLUMNS HAVE INDEX STARTING AT ZERO

        MatrixXf m = Eigen::MatrixXf::Random(4, 4);
        std::cout <<"Random 4x4 matrix: \n" << m << std::endl;

        Matrix2f c = m.block(1, 1, 2, 2); // Copying the middle part of matrix

        std::cout <<"This is c, which is the middle 2x2 of m: \n" << c << std::endl;

        m.block(1, 1, 2, 2) *= 0; // Change values in original matrix

        std::cout <<"This is m now, with the middle 2x2 of it zeroed out: \n" << m << std::endl;

        m.row(1).array() += 3; // This adds 3 to each element in row 2 of m
        std::cout << "Modified row of 4x4 matrix :\n" << m << std::endl;

        m.col(2).array() /= 4; // This divides every element of column 3 of m by 4
        std::cout << "Modified column of 4x4 matrix :\n" << m << std::endl;
    */

    // Broadcasting - adding a vector to each column of a matrix

    MatrixXf mat = MatrixXf::Random(2, 4);
    std::cout << "Random 2x4 matrix :\n" << mat << std::endl;

    VectorXf v(2); // column vector
    v << 100, 100;
    mat.colwise() += v;
    std::cout << "Sum broadcasted over columns: \n" << mat << std::endl;




    return 0;


}
