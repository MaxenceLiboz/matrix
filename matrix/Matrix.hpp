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

#endif