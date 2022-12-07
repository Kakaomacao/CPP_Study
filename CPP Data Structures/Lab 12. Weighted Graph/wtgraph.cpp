//--------------------------------------------------------------------
//
//  Laboratory 13                                          wtgraph.cpp
//
//  Implementation of the Weighted Graph ADT
//
//--------------------------------------------------------------------
#include "wtgraph.h"

//--------------------------------------------------------------------

WtGraph::WtGraph(int maxNumber)
{
	size = 0;
	maxSize = maxNumber;
	vertexList = new Vertex[maxSize];
    adjMatrix = new int[maxSize * maxSize];

    for (int i = 0; i < maxSize; i++)
        for (int j = 0; j < maxSize; j++)
            adjMatrix[i * maxSize + j] = infiniteEdgeWt;

    pathMatrix = new int[maxSize * maxSize];

    for (int i = 0; i < maxSize; i++)
        for (int j = 0; j < maxSize; j++)
            pathMatrix[i * maxSize + j] = 0;
}

WtGraph::~WtGraph()
{
    delete vertexList;
    delete adjMatrix;
    delete pathMatrix;
}

//--------------------------------------------------------------------

int WtGraph::getIndex(char* v)
{
	for (int i = 0; i < size; i++)
	{
		if (*vertexList[i].label == *v)
			return i;
	}
}

int WtGraph::getEdge(int row, int col)
{
    return adjMatrix[row * size + col];
}

void WtGraph::setEdge(int row, int col, int wt) 
{
    adjMatrix[row * size + col] = wt;

}

//--------------------------------------------------------------------

void WtGraph::insertVertex(Vertex newVertex)
{
    vertexList[size] = newVertex;
    size++;
}

void WtGraph::insertEdge(char* v1, char* v2, int wt)
{
    int a = 0, b = 0;

    for (int i = 0; i < size; i++)
    {
        if (*vertexList[i].label == *v1)
            a = i;
    }

    for (int j = 0; j < size; j++)
    {
        if (*vertexList[j].label == *v2)
            b = j;
    }

    adjMatrix[a * size + b] = wt;
    adjMatrix[b * size + a] = wt;

}

//--------------------------------------------------------------------

bool WtGraph::retrieveVertex(char* v, Vertex& vData)
{
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (*vertexList[i].label == *v)
        {
            vData = vertexList[i];
            found = true;
        }
    }

    return found;
}

bool WtGraph::getEdgeWeight(char* v1, char* v2, int& wt)
{
    bool found1 = false;
    bool found2 = false;

    int a = 0, b = 0;

    for (int i = 0; i < size; i++)
    {
        if (*vertexList[i].label == *v1)
        {
            a = i;
            found1 = true;
        }

        if (*vertexList[i].label == *v2)
        {
            b = i;
            found2 = true;
        }
    }

    wt = adjMatrix[a * size + b];

    return found1 * found2;
}

//--------------------------------------------------------------------

void WtGraph::removeVertex(char* v)
{
    int n = 0;

    for (int i = 0; i < size; i++)
    {
        if (*vertexList[i].label == *v)
        {
            n = i;

            // vertexList 조정
            for (int j = 0; j < size - i - 1; j++)
            {
                vertexList[n + j] = vertexList[n + j + 1];
            }
        }
    }

    for (int i = 0; i < size * size; i++)
    {
        int a = i / size;
        int b = i % size;
        
        if (a < n && b < n)
            adjMatrix[a * (size - 1) + b] = adjMatrix[i];

        else if (b > n && a < n)
            adjMatrix[a * (size - 1) + b - 1] = adjMatrix[i];

        else if (a > n && b < n)
            adjMatrix[(a - 1) * (size - 1) + b] = adjMatrix[i];

        else if (a > n && b > n)
            adjMatrix[(a - 1) * (size - 1) + b - 1] = adjMatrix[i];
    }

    size--;
}

void WtGraph::removeEdge(char* v1, char* v2)
{
    int a = 0, b = 0;

    for (int i = 0; i < size; i++)
    {
        if (*vertexList[i].label == *v1)
        {
            a = i;
        }

        if (*vertexList[i].label == *v2)
        {
            b = i;
        }
    }

    adjMatrix[a * size + b] = infiniteEdgeWt;
    adjMatrix[b * size + a] = infiniteEdgeWt;
}

//--------------------------------------------------------------------

void WtGraph::clear()
{
    size = 0;
}

bool WtGraph::isEmpty() const
{
	return (size == 0);
}

bool WtGraph::isFull() const
{
	return (size == maxSize);
}

//--------------------------------------------------------------------

void WtGraph::showStructure()
{
    int wt,         // Edge weight
        row, col;   // Loop counters

    if (size == 0)
        cout << "Empty graph" << endl;
    else
    {
        cout << endl << "Vertex list : " << endl;
        for (row = 0; row < size; row++)
            cout << row << '\t' << vertexList[row].label << endl;

        cout << endl << "Edge matrix : " << endl << '\t';
        for (col = 0; col < size; col++)
            cout << col << '\t';
        cout << endl;
        for (row = 0; row < size; row++)
        {
            cout << row << '\t';
            for (col = 0; col < size; col++)
            {
                wt = getEdge(row, col);
                if (wt == infiniteEdgeWt)
                    cout << "- \t";
                else
                    cout << wt << '\t';
            }
            cout << endl;
        }

        cout << endl << "Path matrix : " << endl << '\t';
        for (col = 0; col < size; col++)
            cout << col << '\t';
        cout << endl;
        for (row = 0; row < size; row++)
        {
            cout << row << '\t';
            for (col = 0; col < size; col++)
            {
                wt = getPath(row, col);
                if (wt == infiniteEdgeWt)
                    cout << "- \t";
                else
                    cout << wt << '\t';
            }
            cout << endl;
        }
    }
}

//--------------------------------------------------------------------

// In-lab 1 functions
int WtGraph::getPath(int row, int col)
{
    return pathMatrix[row * size + col];
}

void WtGraph::setPath(int row, int col, int wt)
{
    pathMatrix[row * size + col] = wt;
}

void WtGraph::computePaths() 
{
    // path에 adj 복사
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            pathMatrix[i * size + j] = adjMatrix[i * size + j];

    // 자기 자신은 0으로 설정
    for (int i = 0; i < size; i++)
        pathMatrix[i * size + i] = 0;

    int m, j, k;

    for (m = 0; m < size; m++)
    {
        for (j = 0; j < size; j++)
        {
            for (k = 0; k < size; k++)
            {
                // j to m 존재 && m to k 존재시
                if (pathMatrix[j * size + m] != infiniteEdgeWt && pathMatrix[m * size + k] != infiniteEdgeWt)
                {
                    if (pathMatrix[j * size + k] > pathMatrix[j * size + m] + pathMatrix[m * size + k])
                    {
                        pathMatrix[j * size + k] = pathMatrix[j * size + m] + pathMatrix[m * size + k];
                    }
                }
            }
        }
    }
}

