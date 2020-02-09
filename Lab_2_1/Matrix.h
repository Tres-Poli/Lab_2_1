#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Edge.h"

class Matrix
{
private: 
	const int _valuesRange = 10000;
	int _columnsNum;
	int _rowsNum;
	int** _matrix;
public:
	Matrix(int columnsNum, int rowsNum, int** matrix)
	{
		_columnsNum = columnsNum;
		_rowsNum = rowsNum;
		_matrix = matrix;
	}
	Matrix(int columnsNum, int rowsNum)
	{
		_columnsNum = columnsNum;
		_rowsNum = rowsNum;
		_matrix = new int*[_columnsNum];
		for (int i = 0; i < _columnsNum; ++i)
		{
			_matrix[i] = new int[_rowsNum];
		}
		srand(time(nullptr));
	}
	~Matrix()
	{
		for (int i = 0; i < _columnsNum; ++i)
		{
			delete [] _matrix[i];
		}
		delete [] _matrix;
	}

	int GetColumnsNum()
	{
		return _columnsNum;
	}

	int GetRowsNum()
	{
		return _rowsNum;
	}

	int GetValueAt(int column, int row)
	{
		return _matrix[column][row];
	}

	void SetValueAt(int column, int row, int value)
	{
		_matrix[column][row] = value;
	}

	void FillMatrixRand()
	{
		for (int i = 0; i < _columnsNum; ++i)
			for (int j = 0; j < _rowsNum; ++j)
				_matrix[i][j] = rand() % _valuesRange;
	}

	Matrix* GetCopy()
	{
		int** matrixCopy = new int* [_columnsNum];
		for (int i = 0; i < _columnsNum; ++i)
		{
			matrixCopy[i] = new int[_rowsNum];
			for (int j = 0; j < _rowsNum; ++j)
				matrixCopy[i][j] = _matrix[i][j];
		}
		return new Matrix(_columnsNum, _rowsNum, matrixCopy);
	}
};

std::istream& operator >>(std::istream& is, Matrix& matrix)
{
	for (int i = 0; i < matrix.GetColumnsNum(); ++i)
	{ 
		for (int j = 0; j < matrix.GetRowsNum(); ++j)
		{
			if (is.eof()) throw new _exception();

			std::string num;
			is >> num;

			matrix.SetValueAt(i, j, std::stoi(num));
		}
	}
	return is;
}

