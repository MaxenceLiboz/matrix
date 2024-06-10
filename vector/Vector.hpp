#ifndef VECTOR_HPP

#define VECTOR_HPP

#include <vector>
#include <iostream>
#include <array>
#include <cmath>

template <class>
class Matrix;

template <class T>
class Vector {
    private:
        std::vector<T> data;
        long nDims;
    
    public:
        // Constructor and Destructor
        Vector();
        Vector(std::initializer_list<T> inputData);
        Vector(long nDims, T value);
        Vector(const Vector & v);
        ~Vector();

        // Member Functions
        int getDims() const;
        T getElement(int index) const;
        Matrix<T> toMatrix(int rows, int cols) const;
        T abs(long index) const;
        T sqrt(T value) const;

        // Add, sub and scalling function
        Vector<T> add(const Vector<T> & v);
        Vector<T> sub(const Vector<T> & v);
        Vector<T> scl(const T & scalar);

        // Linear combination
        template <class U, size_t S>
        friend Vector<U> linear_combination(std::array<Vector<U>, S> &vectors, std::array<U, S> &scalars);

        // Linear interpolation
        template <class U>
        friend Vector<U> lerp(Vector<U> v1, Vector<U> v2, U t);

        // Dot product
        T dot(const Vector<T> v) const;

        // Manahatan norm, Euclidean norm, supremum norm
        T norm_1() const;
        T norm() const;
        T norm_inf() const;

        // angle_cos
        template <class U>
        friend U angle_cos(Vector<U> &v1, Vector<U> &v2);

        // Cross product
        template <class U>
        friend Vector<U> cross_product(Vector<U> &v1, Vector<U> &v2);

        // Matrix multiplication of vector
        friend Vector<T> Matrix<T>::mul_vec(Vector<T> & v) const;
};

// Overload the << operator in order to print the vector
template <class T>
std::ostream & operator<<( std::ostream & o, Vector<T> const & src ) {
    if (src.getDims() == 0) {
        o << "[]" << std::endl;
        return o;
    }
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
Vector<T>::Vector(std::initializer_list<T> inputData) {
    data = std::vector<T>(inputData);
    nDims = data.size();
}

template <class T>
Vector<T>::Vector(long nDims, T value) {
    data = std::vector<T>(nDims, value);
    this->nDims = nDims;
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

template <class T>
T Vector<T>::abs(long index) const {
    return data[index] < 0 ? -data[index] : data[index];
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
Vector<T> linear_combination(std::array<Vector<T>, S> &vectors, std::array<T, S> &scalars) {
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
    Vector<T> result = Vector<T>(nDims, 0);
    for (int i = 0; i < nDims; i++) {
        for (int j = 0; j < S; j++) {
            result.data.at(i) += vectors[j].getElement(i) * scalars[j];
        }
    }
    return result;
}

/***************************************
 * Linear interpolation
 * The goal is to transform the vector v1 into v2, however we will stop at a specific time t (between 0 and 1)
 * For each point [i] in the vector, we will start at v1[i] and go to v2[i] at a specific time t
 * *************************************/

template <class T>
Vector<T> lerp(Vector<T> v1, Vector<T> v2, T t) {
    if (v1.getDims() != v2.getDims()) {
        std::cout << "The vectors must have the same dimensions" << std::endl;
        return v1;
    }
    int nDims = v1.getDims();
    Vector<T> result = Vector<T>(nDims, 0);
    for (int i = 0; i < nDims; i++) {
        result.data.at(i) = v1.getElement(i) + t * (v2.getElement(i) - v1.getElement(i));
    }
    return result;
}

/***************************************
 * Dot product
 * *************************************/

template <class T>
T Vector<T>::dot(const Vector<T> v) const {
    if (nDims != v.nDims) {
        std::cout << "The vectors must have the same dimensions" << std::endl;
        return 0;
    }
    T result = 0;
    for (int i = 0; i < nDims; i++) {
        result += data[i] * v.data[i];
    }
    return result;
}

/***************************************
 * Manahatan norm, Euclidean norm, supremum norm
 * *************************************/
template <class T>
T Vector<T>::norm_1() const {
    T result = 0;
    for (int i = 0; i < nDims; i++) {
        result += abs(i);
    }
    return result;
}

template <class T>
T Vector<T>::norm() const {
    T result = 0;
    for (int i = 0; i < nDims; i++) {
        result += abs(i) * abs(i);
    }
    return std::pow(result, 0.5);
}

template <class T>
T Vector<T>::norm_inf() const {
    T result = 0;
    for (int i = 0; i < nDims; i++) {
        result = abs(i) > result ? abs(i) : result;
    }
    return result;
}

/***************************************
 * angle_cos
 * *************************************/

template <class T>
T angle_cos(Vector<T> &v1, Vector<T> &v2) {
    if (v1.getDims() != v2.getDims()) {
        std::cout << "The vectors must have the same dimensions" << std::endl;
        return 0;
    }
    T dot = v1.dot(v2);
    T norm_v1 = v1.norm();
    T norm_v2 = v2.norm();
    return dot / (norm_v1 * norm_v2);
}

/***************************************
 * Cross product
 * *************************************/
template <class T>
Vector<T> cross_product(Vector<T> &v1, Vector<T> &v2) {
    if (v1.getDims() != 3 || v2.getDims() != 3) {
        std::cout << "The vectors must have 3 dimensions" << std::endl;
        return Vector<T>();
    }
    Vector<T> result = Vector<T>({v1.getElement(1) * v2.getElement(2) - v1.getElement(2) * v2.getElement(1),
                                   v1.getElement(2) * v2.getElement(0) - v1.getElement(0) * v2.getElement(2),
                                   v1.getElement(0) * v2.getElement(1) - v1.getElement(1) * v2.getElement(0)});
    return result;
}

#endif 