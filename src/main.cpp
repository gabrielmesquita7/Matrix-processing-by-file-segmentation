#include "matriz.hpp"

int main()
{
    EscreveMatrizG();
    int xi, yi, xj, yj;
    vector<int> coord = ler_coords();
    xi = coord[0];
    yi = coord[1];
    xj = coord[2];
    yj = coord[3];
    int M = (xj - xi) + 1; // MATRIZ DINAMICA
    int N = (yj - yi) + 1; //       M*N
    int **A = ler_matriz(xi, yi, xj, yj);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
    }
}