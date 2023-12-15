#pragma once

matrix fillRandomSymmetricMatrix(int size)
{
    matrix matrix(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        vector<int> row(size, 0);
        for (int j = 0; j < size; j++)
        {
            int num = rand() % 2;
            if (i < j)
            {
                row[j] = num;
            }
        }
        matrix[i] = row;;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i > j)
            {
                matrix[i][j] = matrix[j][i];
            }
        }
    }

    return matrix;
}

matrix fillRandomASymmetricMatrix(int size)
{
    matrix matrix(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++)
    {
        vector<int> row(size, 0);
        for (int j = 0; j < size; j++)
        {
            int num = rand() % 2;
            row[j] = num;
        }
        matrix[i] = row;;
    }

    return matrix;
}

void printMatrix(matrix matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void depthFirstSearch(int* visited, int node, matrix matrix)
{
    cout << node << " ";
    visited[node] = 1;

    for (int i = 0; i < matrix[node].size(); i++)
    {
        if (matrix[node][i] == 1 && visited[i] == 0)
        {
            depthFirstSearch(visited, i, matrix);
        }
    }
}

void bypassMatrixDepth(matrix matrix, int startNode)
{
    if (startNode >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    cout << "Path: " << endl;
    depthFirstSearch(visited, startNode, matrix);

    delete[] visited;
}


void breadthFirstSearch(int* visited, int node, matrix matrix)
{
    vector<int> nodes;
    nodes.push_back(node);
    visited[node] = 1;

    int visitNode;
    while (!nodes.empty())
    {
        visitNode = nodes[0];

        cout << visitNode << " ";
        nodes.erase(nodes.begin());

        for (int i = 0; i < matrix[visitNode].size(); i++)
        {
            if (matrix[visitNode][i] == 1 && visited[i] == 0)
            {
                nodes.push_back(i);
                visited[i] = 1;
            }
        }
    }
}

void bypassMatrixWidth(matrix matrix, int startNode)
{
    if (startNode >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    cout << "Path: " << endl;
    breadthFirstSearch(visited, startNode, matrix);

    delete[] visited;
}


void sort(matrix matrix, int node, int* visited, vector<int>& path)
{
    visited[node] = 1;

    for (int i = 0; i < matrix[node].size(); i++)
    {
        if (visited[matrix[node][i]] == 0)
        {
            sort(matrix, matrix[node][i], visited, path);
        }
    }

    path.push_back(node);
}

void topologicalSort(matrix matrix, int node)
{
    if (node >= matrix.size())
    {
        cout << "The node with this number is not defined" << endl;
        return;
    }

    int* visited = new int[matrix.size()];

    for (int i = 0; i < matrix.size(); i++)
    {
        visited[i] = 0;
    }

    vector<int> path;
    sort(matrix, node, visited, path);

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    delete[] visited;
}
