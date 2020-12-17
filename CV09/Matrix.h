#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
public:
	Matrix(int row, int column);
	Matrix(const Matrix<T>& matrix);
	~Matrix();
	void SetElement(int row, int column, T value);
	void SetMatrix(T* pole);
	T& GetElement(int row,int column);
	const T& GetElement(int row, int column) const;
	template<typename R>
	Matrix<R> Retype() const;
	Matrix<T> Transposition() const;
	Matrix<T> Product(const Matrix& matrix) const;
	Matrix<T> Product(T skalar) const;
	Matrix<T> Sum(const Matrix& matrix)const;
	Matrix<T> Sum(T skalar)const;
	bool isSame(const Matrix& mmatrix) const;
	void Print() const;
private:
	void allocSpace();
	T** elements;
	int rows;
	int columns;
};

template<typename T>
inline Matrix<T>::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	allocSpace();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = 0;
		}
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& matrix)
{
	rows = matrix.rows;
	columns = matrix.columns;
	allocSpace();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = matrix.elements[i][j];
		}
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete elements[i];
	}
	delete[] elements;
}

template<typename T>
void inline Matrix<T>::SetElement(int row, int column, T value)
{
	if (row >= rows || column >= columns) {
		throw out_of_range("index not valid");
	}
	elements[row][column] = value;
}

template<typename T>
inline void Matrix<T>::SetMatrix(T* array)
{
	int index = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			elements[i][j] = array[index];
			index++;
		}
	}
}

template<typename T>
inline T& Matrix<T>::GetElement(int row, int column)
{
	if (row >= rows || column >= columns) {
		throw out_of_range("index not valid");
	}
	return elements[row][column];
}

template<typename T>
inline const T& Matrix<T>::GetElement(int row, int column) const
{
	if (row >= rows || column >= columns) {
		throw out_of_range("index not valid");
	}
	return elements[row][column];
}

template<typename T>
template<typename R>
inline Matrix<R> Matrix<T>::Retype() const
{
	Matrix<R> matrix = Matrix<R>(rows,columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix.SetElement(i, j, elements[i][j]);
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Transposition() const
{
	Matrix matrix = Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix.elements[i][j] = elements[j][i];
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Product(const Matrix& m) const
{
	Matrix newMatrix = Matrix(rows, columns);
	if (m.columns != columns) {
		throw out_of_range("index not valid");
	}
	int rowM = max(m.rows, rows);
	T sum = 0;
	for (int i = 0; i < rowM; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			for (int k = 0; k < rowM; k++)
			{
				sum += elements[i][k] * m.elements[k][j];
			}
			newMatrix.elements[i][j] = sum;
			sum = 0;
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Product(T skalar) const
{
	Matrix matrix = Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix.elements[i][j] = elements[i][j]*skalar;
		}
	}
	return matrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Sum(const Matrix& m) const
{
	Matrix newMatrix = Matrix(rows, columns);
	if (m.rows != rows || m.columns != columns) {
		throw out_of_range("index not valid");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			newMatrix.elements[i][j] = elements[i][j]+m.elements[i][j];
		}
	}
	return newMatrix;
}

template<typename T>
inline Matrix<T> Matrix<T>::Sum(T skalar) const
{
	Matrix matrix = Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matrix.elements[i][j] = elements[i][j] + skalar;
		}
	}
	return matrix;
}

template<typename T>
inline bool Matrix<T>::isSame(const Matrix& matrix) const
{
	if (rows != matrix.rows || columns != matrix.columns) {
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (elements[i][j] != matrix.elements[i][j])
				return false;
		}
	}
	return true;
}

template<typename T>
inline void Matrix<T>::Print() const
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << elements[i][j] << " ";
		}
		cout << endl;
	}
}
template<typename T>
inline void Matrix<T>::allocSpace()
{
	elements = new T* [rows];
	for (int i = 0; i < rows; ++i) {
		elements[i] = new T[columns];
	}
}
#endif // !MATRIX_H

