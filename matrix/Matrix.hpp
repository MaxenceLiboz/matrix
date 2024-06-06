#ifndef MATRIX_HPP

#define MATRIX_HPP
#include <iostream>
#include <array>

template <class T>
class Matrix {
    private:
       int nRows, nCols, nElements;
       T * matrix;

    public:
        // Constructor and Destructor
        Matrix();
        Matrix(int rows, int cols);
        Matrix(std::initializer_list<std::initializer_list<T>> inputmatrix);
        Matrix(const Matrix & m);
        ~Matrix();

        // Member Functions
        int getRows() const;
        int getCols() const;
        std::array<int, 2> getShape() const;
        T getElement(int row, int col) const;
        Vector<T> toVector() const;

        // Add, sub and scalling function
        Matrix<T> add(const Matrix<T> & m);
        Matrix<T> sub(const Matrix<T> & m);
        Matrix<T> scl(T scalar);

        // Linear interpolation
        template <class U>
        friend Matrix<U> lerp(Matrix<U> m1, Matrix<U> m2, U t);

        // Vector and matrix multiplication
        Vector<T> mul_vec(Vector<T> & v) const;
        Matrix<T> mul_mat(const Matrix<T> & m);
};

// Overload the << operator in order to print the matrix
template <class T>
std::ostream & operator<<( std::ostream & o, Matrix<T> const & src ) {
    o << "[ ";
    for (int raw = 0; raw < src.getRows(); raw++) {
        if (raw != 0 && raw != src.getRows() -1){
            o << "| ";
        } else if (raw == src.getRows() - 1 && raw != 0) {
            o << "[ ";
        }
        for (int col = 0; col < src.getCols(); col++) {
            o << src.getElement(raw, col) << " ";
        }
        if (raw != 0 && raw != src.getRows() -1){
            o << "|" << std::endl;
        }
        else {
            o << "]" << std::endl;
        }
    }
    return o;
}

/***************************************
 * Constructor and Destructor
 * *************************************/

template <class T>
Matrix<T>::Matrix() {
    nRows = 1;
    nCols = 1;
    nElements = 1;
    matrix = new T[nElements];
    matrix[0] = 0.0;

};

template <class T>
Matrix<T>::Matrix(int rows, int cols) {
    nRows = rows;
    nCols = cols;
    nElements = rows * cols;
    matrix = new T[nElements];
    for (int i = 0; i < nElements; i++) {
        matrix[i] = 0.0;
    }
};

template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> inputmatrix) {
    nRows = inputmatrix.size();
    nCols = inputmatrix.begin()->size();
    nElements = nRows * nCols;
    matrix = new T[nElements];
    int i = 0;
    for (std::initializer_list<T> row : inputmatrix) {
        for (T element : row) {
            if (row.size() != nCols) {
                std::cout << "All rows must have the same number of columns, empty matrix created" << std::endl;
                delete[] matrix;
                nRows = 1;
                nCols = 1;
                nElements = 1;
                matrix = new T[nElements];
                matrix[0] = 0.0;
                return;
            }
            matrix[i] = element;
            i++;
        }
    }
};

template <class T>
Matrix<T>::Matrix(const Matrix & m) {
    nRows = m.nRows;
    nCols = m.nCols;
    nElements = m.nElements;
    matrix = new T[nElements];
    for (int i = 0; i < nElements; i++) {
        matrix[i] = m.matrix[i];
    }
};

template <class T>
Matrix<T>::~Matrix() {
    delete[] matrix;
    nRows = 0;
    nCols = 0;
    nElements = 0;
};

/***************************************
 * Member Functions
 * *************************************/
template <class T>
int Matrix<T>::getRows() const {
    return nRows;
};

template <class T>
int Matrix<T>::getCols() const {
    return nCols;
};

template <class T>
std::array<int, 2> Matrix<T>::getShape() const {
    return {nRows, nCols};
};

template <class T>
T Matrix<T>::getElement(int row, int col) const {
    return matrix[row * nCols + col];
};

template <class T>
Vector<T> Matrix<T>::toVector() const {
    std::vector<T> data = std::vector<T>();
    for (int i = 0; i < nElements; i++) {
        data.push_back(matrix[i]);
    }
    return Vector<T>(data);
};

/***************************************
 * Add, sub and scalling function
 * *************************************/
template <class T>
Matrix<T> Matrix<T>::add(const Matrix<T> & m) {
    if (nRows != m.nRows || nCols != m.nCols) {
        std::cout << "The matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (int i = 0; i < nElements; i++) {
        matrix[i] += m.matrix[i];
    }
    return *this;
};

template <class T>
Matrix<T> Matrix<T>::sub(const Matrix<T> & m) {
    if (nRows != m.nRows || nCols != m.nCols) {
        std::cout << "The matrices must have the same dimensions" << std::endl;
        return *this;
    }
    for (int i = 0; i < nElements; i++) {
        matrix[i] -= m.matrix[i];
    }
    return *this;
};

template <class T>
Matrix<T> Matrix<T>::scl(T scalar) {
    for (int i = 0; i < nElements; i++) {
        matrix[i] *= scalar;
    }
    return *this;
};

/***************************************
 * Linear interpolation
 * The goal is to transform the matrix m1 into m2, however we will stop at a specific time t (between 0 and 1)
 * For each point [i] of the matrix we will start from m1[i] to go to m2[i] at a specific time t
 * *************************************/
template <class T>
Matrix<T> lerp(Matrix<T> m1, Matrix<T> m2, T t) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols) {
        std::cout << "The matrices must have the same dimensions" << std::endl;
        return Matrix<T>();
    }
    Matrix<T> result = Matrix<T>(m1);
    for (int i = 0; i < m1.nElements; i++) {
        result.matrix[i] = m1.matrix[i] + t * (m2.matrix[i] - m1.matrix[i]);
    }
    return result;
};

/***************************************
 * Vector and matrix multiplication
 * Matrix A (4x3)    Vector B (3x1)        Result Vector (4x1)
 *          (nxm)             (mx1)                      (nx1)
 * 
 * | a11 a12 a13 |   | b11 |     | r11 |
 * | a21 a22 a23 | x | b21 |  =  | r21 |
 * | a31 a32 a33 |   | b31 |     | r31 |
 * | a41 a42 a43 |   | b41 |     | r41 |
 * 
 * r11 = a11*b11 + a12*b21 + a13*b31
 * [ ...]
 * r41 = a41*b11 + a42*b21 + a43*b31
 * 
 * *************************************/
template <class T>
Vector<T> Matrix<T>::mul_vec(Vector<T> & v) const {
    // Verify the input, return an empty Vector if invalid
    if (nCols != v.getDims()) {
        std::cout << "The number of columns of the matrix must be equal to the dimention of the vector" << std::endl;
        return Vector<T>();
    }

    Vector<T> result = Vector<T>(nRows, 0);
    // Iterate over each row in the matrix
    for (int raw = 0; raw < nRows; raw++) {
        // For each row, iterate over each column in the matrix
        for (int col = 0; col < nCols; col++) {
            // For each pair of row and column, calculate the dot product
            result.data.at(raw) += matrix[raw * nCols + col] * v.getElement(col);
        }
    }
    return result;
};

/*
Matrix A (4x3)    Matrix B (3x4)        Result Matrix (4x4)
         (nxm)             (mxp)                      (nxp)

| a11 a12 a13 |   | b11 b12 b13 b14|     | r11 r12 r13 r14|
| a21 a22 a23 | x | b21 b22 b23 b24|  =  | r21 r22 r23 r24|
| a31 a32 a33 |   | b31 b32 b33 b34|     | r31 r32 r33 r34|
| a41 a42 a43 |                          | r41 r42 r43 r44|

r11 = a11*b11 + a12*b21 + a13*b31
[ ... ]
r14 = a11*b14 + a12*b24 + a13*b34
r21 = a21*b11 + a22*b21 + a23*b31
[ ... ]
r24 = a21*b14 + a22*b24 + a23*b34
[ ... ]
r44 = a41*b14 + a42*b24 + a43*b34
*/
template <class T>
Matrix<T> Matrix<T>::mul_mat(const Matrix<T> & m) {
    // Verify the input, return an empty Matrix if invalid
    if (nCols != m.nRows) {
        std::cout << "The number of columns of the first matrix must be equal to the number of rows of the second matrix" << std::endl;
        return Matrix<T>();
    }

    Matrix<T> result(nRows, m.nCols);
    // Iterate over each row in the first matrix
    for (int row = 0; row < nRows; row++) {
        // For each row, iterate over each column in the second matrix
        for (int col = 0; col < m.nCols; col++) {
            // For each pair of row and column, calculate the dot product
            for (int inner = 0; inner < nCols; inner++) {
                // Add the product of the current elements of the first and second matrix to the result
                result.matrix[row * m.nCols + col] += matrix[row * nCols + inner] * m.matrix[inner * m.nCols + col];
            }
        }
    }
    return result;
};

#endif