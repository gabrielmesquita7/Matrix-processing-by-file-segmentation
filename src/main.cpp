#include "matriz.hpp"

int main()
{
    EscreveMatrizG();
    vector<int> teste = ler_coords();

    for (auto &i : teste)
    {
        cout << i << "\t";
    }
    return 0;
}