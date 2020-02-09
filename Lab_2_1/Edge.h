#pragma once
#include <iostream>

class Edge
{
private:
	int _weight;
	int _vertexA;
	int _vertexB;

public:
	Edge(int weight, int pointA, int pointB)
	{
		_weight = weight;
		_vertexA = pointA;
		_vertexB = pointB;
	}

	int GetWeight()
	{
		return _weight;
	}

	std::pair<int, int> GetVertexes()
	{
		return std::pair<int, int>(_vertexA, _vertexB);
	}

	bool Equal(Edge* comparable)
	{
		return comparable->_vertexA == _vertexA &&
			comparable->_vertexB == _vertexB;
	}
};