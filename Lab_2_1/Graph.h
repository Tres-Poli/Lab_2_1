#pragma once
#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Edge.h"

class Graph
{
private:
	// Every edge in graph has weight and two vertex
	std::vector<Edge> _edges;
	Matrix* _currMatrixInstance;

public:
	~Graph()
	{
		delete _currMatrixInstance;
	}

	void FillGraphWithMatrix(Matrix* matrix)
	{
		_edges.clear();
		_currMatrixInstance = matrix->GetCopy();
		for (int i = 0; i < _currMatrixInstance->GetColumnsNum(); ++i)
		{
			for (int j = 0; j < _currMatrixInstance->GetRowsNum(); ++j)
			{
				if(_currMatrixInstance->GetValueAt(i, j) != 0)
					_edges.emplace_back(_currMatrixInstance->GetValueAt(i, j), i + 1, j + 1);
			}
		}
	}

	std::vector<Edge> GetEdges()
	{
		return _edges;
	}
};