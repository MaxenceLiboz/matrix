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

#endif