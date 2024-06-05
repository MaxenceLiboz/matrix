#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <array>

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

        // Add, sub and scalling function
        Vector<T> add(const Vector<T> & v);
        Vector<T> sub(const Vector<T> & v);
        Vector<T> scl(const T & scalar);

        // Linear combination
        template <class U, size_t S>
        friend Vector<U> linear_combination(std::array<Vector<U>, S> vectors, std::array<U, S> scalars);
};

// Overload the << operator in order to print the vector
template <class T>
std::ostream & operator<<( std::ostream & o, Vector<T> const & src ) {
    o << "[ ";
    o << src.getElement(0) << " ]" << std::endl;
    for (int i = 1; i < src.getDims() - 1; i++) {
        o << "| " << src.getElement(i) << " |" << std::endl; 

    }
    o << "[ " << src.getElement(src.getDims() - 1) << " ]" << std::endl;
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
        std::cout << "The dimension of the vector must be equal to the number of elements in the matrix" << std::endl;
        return Matrix<T>();
    }
    return Matrix<T>(rows, cols, data.data());
}

/***************************************
 * Add, sub and scalling function
 * *************************************/
template <class T>
Vector<T> Vector<T>::add(const Vector<T> & v) {
    if (nDims != v.nDims) {
        std::cout << "The vectors must have the same dimensions" << std::endl;
        return *this;
    }
    for (int i = 0; i < nDims; i++) {
        data[i] += v.data[i];
    }
    return *this;
}

template <class T>
Vector<T> Vector<T>::sub(const Vector<T> & v) {
    if (nDims != v.nDims) {
        std::cout << "The vectors must have the same dimensions" << std::endl;
        return *this;
    }
    for (int i = 0; i < nDims; i++) {
        data[i] -= v.data[i];
    }
    return *this;
}

template <class T>
Vector<T> Vector<T>::scl(const T & scalar) {
    for (int i = 0; i < nDims; i++) {
        data[i] *= scalar;
    }
    return *this;
}

/***************************************
 * Linear combination
 *  - It is a computation where all vector are mulitplied by a scalar
 *  and then added together
 * *************************************/
template <class T, size_t S>
Vector<T> linear_combination(std::array<Vector<T>, S> vectors, std::array<T, S> scalars) {
    if (S == 0) {
        std::cout << "The number of vectors must be greater than 0" << std::endl;
        return Vector<T>();
    }
    if (S != scalars.size()) {
        std::cout << "The number of scalars must be equal to the number of vectors" << std::endl;
        return Vector<T>();
    }
    int nDims = vectors[0].getDims();
    for (int i = 1; i < S; i++) {
        if (nDims != vectors[i].getDims()) {
            std::cout << "All vectors must have the same dimensions" << std::endl;
            return Vector<T>();
        }
    }
    Vector<T> result = Vector<T>(std::vector<T>(nDims, 0));
    for (int i = 0; i < nDims; i++) {
        for (int j = 0; j < S; j++) {
            result.data.at(i) += vectors[j].getElement(i) * scalars[j];
        }
    }
    return result;
}


#endif 