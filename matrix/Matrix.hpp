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
        Matrix(int rows, int cols, const T * inputmatrix);
        Matrix(const Matrix & m);
        ~Matrix();

        // Member Functions
        int getRows() const;
        int getCols() const;
        std::array<int, 2> getShape() const;
        T getElement(int row, int col) const;
        Vector<T> toVector() const;

        // Operator overloading
        Matrix<T> operator+(const Matrix<T> & m);
        Matrix<T> operator-(const Matrix<T> & m);
        Matrix<T> operator*(const Matrix<T> & m);
};

// Overload the << operator in order to print the matrix
template <class T>
std::ostream & operator<<( std::ostream & o, Matrix<T> const & src ) {
    o << "Matrix: [ ";
    for (int raw = 0; raw < src.getRows(); raw++) {
        if (raw != 0 && raw != src.getRows() -1){
            o << "\t| ";
        } else if (raw == src.getRows() - 1) {
            o << "\t[ ";
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
Matrix<T>::Matrix(int rows, int cols, const T * inputmatrix) {
    nRows = rows;
    nCols = cols;
    nElements = rows * cols;
    matrix = new T[nElements];
    if (sizeof(inputmatrix) != sizeof(matrix)) {
        std::cout << "The input matrix does not have the same number of elements as the matrix" << std::endl;
        delete[] matrix;
        return;
    }
    for (int i = 0; i < nElements; i++) {
        matrix[i] = inputmatrix[i];
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

#endif