#pragma once

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <typename T>
class Matrix
{
public:
    using MatrixDataType = std::vector<std::vector<T>>;

    Matrix() = delete;
    Matrix(const std::size_t rows, const std::size_t cols);
    Matrix(const std::size_t rows, const std::size_t cols, const T value);
    ~Matrix() noexcept = default;

    Matrix(const Matrix &other) = default;
    Matrix &operator=(const Matrix &other) = default;
    Matrix(Matrix &&other) noexcept = default;
    Matrix &operator=(Matrix &&other) noexcept = default;

    Matrix operator+(const Matrix &rhs) const;
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs) const;
    Matrix &operator-=(const Matrix &rhs);

    Matrix operator*(const T &scalar) const;
    Matrix &operator*=(const T &scalar);
    Matrix operator/(const T &scalar) const;
    Matrix &operator/=(const T &scalar);

    Matrix operator*(const Matrix &rhs) const;
    Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;
};

template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols)
{
    if (rows == 0 || cols == 0)
    {
        throw std::invalid_argument("Matrix dimensions must be greater than zero.");
    }

    m_rows = rows;
    m_cols = cols;

    m_data.resize(m_rows);
    for (auto &row : m_data)
    {
        row.resize(m_cols);
    }
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        for (std::size_t j = 0; j < m_cols; ++j)
        {
            m_data[i][j] = T();
        }
    }
    // Initialize the matrix with default values
}

template <typename T>
Matrix<T>::Matrix(const std::size_t rows, const std::size_t cols, const T value)
{
    if (rows == 0 || cols == 0)
    {
        throw std::invalid_argument("Matrix dimensions must be greater than zero.");
    }

    m_rows = rows;
    m_cols = cols;

    m_data.resize(m_rows);
    for (auto &row : m_data)
    {
        row.resize(m_cols);
    }
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        for (std::size_t j = 0; j < m_cols; ++j)
        {
            m_data[i][j] = value;
        }
    }
    // Initialize the matrix with the specified value
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const
{
    // Add the two matrices
    // and store the result in a new matrix
    // Return the result
    // Note: This assumes that the matrices are of the same size
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    auto result = Matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::plus<T>());
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       m_data[i].begin(),
                       std::plus<T>());
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const
{
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for subtraction.");
    }

    auto result = Matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::minus<T>());
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    if (m_rows != rhs.m_rows || m_cols != rhs.m_cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for subtraction.");
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       m_data[i].begin(),
                       std::minus<T>());
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar) const
{
    auto result = Matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       result.m_data[i].begin(),
                       [&scalar](const T &value) { return value * scalar; });
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       m_data[i].begin(),
                       [&scalar](const T &value) { return value * scalar; });
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar) const
{
    if (scalar == T())
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    auto result = Matrix(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       result.m_data[i].begin(),
                       [&scalar](const T &value) { return value / scalar; });
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
    if (scalar == T())
    {
        throw std::invalid_argument("Division by zero is not allowed.");
    }

    for (std::size_t i = 0; i < m_rows; ++i)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       m_data[i].begin(),
                       [&scalar](const T &value) { return value / scalar; });
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const
{
    if (m_cols != rhs.m_rows)
    {
        throw std::invalid_argument("Matrix dimensions must be compatible for multiplication.");
    }

    auto result = Matrix(m_rows, rhs.m_cols);
    for (std::size_t i = 0; i < m_rows; ++i)
    {
        for (std::size_t j = 0; j < rhs.m_cols; ++j)
        {
            T sum = T();
            for (std::size_t k = 0; k < m_cols; ++k)
            {
                sum += m_data[i][k] * rhs.m_data[k][j];
            }
            result.m_data[i][j] = sum;
        }
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
{
    *this = *this * rhs;
    return *this;
}

template <typename T>
void Matrix<T>::print_matrix() const
{
    for (const auto &row : m_data)
    {
        for (const auto val : row)
        {
            std::cout << val << ", ";
        }

        std::cout << '\n';
    }
}

template <typename T>
std::size_t Matrix<T>::num_rows() const
{
    return m_rows;
}

template <typename T>
std::size_t Matrix<T>::num_cols() const
{
    return m_cols;
}
