#include <bits/stdc++.h>

using namespace std;

int n_test_cases, rows, number, maxim;
vector<vector<int>> triangle(rows);
vector<vector<int>> triangle_sum(rows);
vector<int> nova(rows);
vector<int> antiga(rows);

int path_topdown(int i, int j)
{
    if (j > i)
    {
        return 0;
    }

    // P[i,j] é o nº na posicao atual (ver tablet)
    // V[i,j] é a soma cumulada na posição atual (ver tablet)

    if (triangle_sum[i][j] > 0 || i == 0)
    {
        return triangle_sum[i][j];
    }

    if (j == 0)
        triangle_sum[i][j] = triangle[i][j] + path_topdown(i - 1, j);
    else
        triangle_sum[i][j] = triangle[i][j] + max(path_topdown(i - 1, j - 1), path_topdown(i - 1, j));

    return triangle_sum[i][j];
}

/*
int path_bottomup()
{

    // V[0..n][0..n] inicializada a 0

    // 2 abordagens diferentes: a nov´a e a que está comentada
    // no return, retorno V[n,1]... ou retorno antiga[n,1]...

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            // nova[j] = triangle[i][j] + max(antiga[j - 1], antiga[j]);
            triangle_sum[i][j] = triangle[i][j] + max(triangle_sum[i - 1][j], triangle_sum[i - 1][j - 1]);
        }
        // antiga = nova;
    }

    for (int i = 0; i < triangle_sum[rows - 1].size(); i++)
    {
        if (maxim < triangle_sum[rows - 1][i])
        {
            maxim = triangle_sum[rows - 1][i];
        }
    }
    return maxim;
}
*/

int main()
{
    cin >> n_test_cases; 

    for (int n = 0; n < n_test_cases; n++)
    {

        cin >> rows;
        triangle = vector<vector<int>>(rows, vector<int>(rows));
        triangle_sum = vector<vector<int>>(rows, vector<int>(rows));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> triangle[i][j];
            }
        }

        triangle_sum[0][0] = triangle[0][0];
        int maxim = 0;

        for (int i = 0; i < rows; i++)
        {
            if(maxim < path_topdown(rows - 1, i)) maxim = path_topdown(rows - 1, i);
        }
        cout << maxim << endl;
    }
}