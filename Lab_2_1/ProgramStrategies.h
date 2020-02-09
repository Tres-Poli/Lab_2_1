#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"

class ProgramStrategies
{
private:
	int _columnsNumConfig = 0;
	int _rowsNumConfig = 0;
	Graph* _graph = new Graph();

	bool ConfigIsValid()
	{
		if (_columnsNumConfig == 0 || _rowsNumConfig == 0)
		{
			std::cout << "Graph config is empty. Define columns and rows num before load graph\n";
			return false;
		}
		return true;
	}

	void InitializedMessage()
	{
		std::vector<Edge> edges = _graph->GetEdges();

		std::cout << "Graph initialized succesfully\n";
		if (edges.size() > 100) return;
		std::cout << "      Weight\tVertex_1\tVertex_2\n";
		for (int i = 0; i < edges.size(); ++i)
		{
			std::pair<int, int> vertexes = edges[i].GetVertexes();
			std::cout << "Edge: " << edges[i].GetWeight() << "\t\t" << vertexes.first << "\t\t" << vertexes.second << "\n";
		}
	}

public:
	~ProgramStrategies()
	{
		delete(_graph);
	}
	void LoadGraphStrategy(std::string fileName)
	{
		if (!ConfigIsValid()) return;
		Matrix* matrix = new Matrix(_columnsNumConfig, _rowsNumConfig);
		std::ifstream fileStream;
		fileStream.open(fileName);
		if (!fileStream.is_open())
		{
			std::cout << "File not found\n";
			return;
		}
		fileStream >> *matrix;
		_graph->FillGraphWithMatrix(matrix);
		delete(matrix);

		InitializedMessage();
	}

	void GenerateGraphStrategy()
	{
		if (!ConfigIsValid()) return;
		Matrix* matrix = new Matrix(_columnsNumConfig, _rowsNumConfig);
		matrix->FillMatrixRand();

		_graph->FillGraphWithMatrix(matrix);
		delete(matrix);

		InitializedMessage();
	}

	void ConfigGraphStrategy(int columnsNum, int rowsNum)
	{
		if (columnsNum <= 0 || rowsNum <= 0)
		{
			std::cout << "Columns num and rows num for matrix can not be less or equal 0\n";
			return;
		}
		_columnsNumConfig = columnsNum;
		_rowsNumConfig = rowsNum;

		std::cout << "Adjacency matrix's config for graph initialized with\n\tColummns num: " << _columnsNumConfig << "\n\tRows num: " << _rowsNumConfig << "\n";
	}
};