#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <vector>
#include <iostream>

template <class>
class Matrix;

template <class T>
class Vector {
    private:
        std::vector<T> data;
        int nDims;
    
    public:
        // Constructor and Destructor
        Vector();
        Vector(std::vector<T> inputData);
        Vector(const Vector & v);
        ~Vector();

        // Member Functions
        int getDims() const;
        T getElement(int index) const;
        Matrix<T> toMatrix(int rows, int cols) const; 

        // Operator overloading
        Vector<T> operator+(const Vector<T> & v);
        Vector<T> operator-(const Vector<T> & v);
        Vector<T> operator*(const Vector<T> & v);
};

// Overload the << operator in order to print the vector
template <class T>
std::ostream & operator<<( std::ostream & o, Vector<T> const & src ) {
    o << "Vector: [ ";
    o << src.getElement(0) << " ]" << std::endl;
    for (int i = 1; i < src.getDims() - 1; i++) {
        o << "\t| " << src.getElement(i) << " |" << std::endl; 

    }
    o << "\t[ " << src.getElement(src.getDims() - 1) << " ]" << std::endl;
    return o;
}

/***************************************
 * Constructor and Destructor
 * *************************************/

template <class T>
Vector<T>::Vector() {
    data = std::vector<T>();
    nDims = 0;
}

template <class T>
Vector<T>::Vector(std::vector<T> inputData) {
    data = inputData;
    nDims = data.size();
}

template <class T>
Vector<T>::Vector(const Vector & v) {
    data = v.data;
    nDims = v.nDims;
}

template <class T>
Vector<T>::~Vector() {
    data.clear();
    nDims = 0;
}


/***************************************
 * Member Functions
 * *************************************/

template <class T>
int Vector<T>::getDims() const {
    return nDims;
}

template <class T>
T Vector<T>::getElement(int index) const {
    if (index < 0 || index >= nDims) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <class T>
Matrix<T> Vector<T>::toMatrix(int rows, int cols) const {
    if (rows * cols != nDims) {
        throw std::invalid_argument("The number of elements in the vector must be equal to the number of elements in the matrix");
    }
    return Matrix<T>(rows, cols, data.data());
}

/***************************************
 * Operator Overloading
 * *************************************/


#endif 