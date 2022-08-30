#include "matriz.hpp"

void EscreveMatrizG()
{
    int nrand = 0;
    ofstream file;

    file.open("matriz.txt");

    if (!file)
    {
        cout << "Erro na abertura do arquivo!" << endl;
        abort();
    }

    srand(time(NULL));

    for (int i = 0; i < MAXTAM; i++)
    {
        for (int j = 0; j < MAXTAM; j++)
        {
            nrand = rand() % (99 + 1 - 10) + 10;
            file << nrand << " ";
        }
        file << endl;
    }

    file.close();
}

vector<string> tokenizer(string text)
{
    char del = ',';
    vector<string> coords;

    stringstream sstream(text);
    string token;
    while (getline(sstream, token, del))
        coords.push_back(token);
    return coords;
}

vector<int> ler_coords()
{
    ifstream ifs("coordenadas.txt");
    string content((istreambuf_iterator<char>(ifs)), // leitura de todo o documento armazenado
                   (istreambuf_iterator<char>()));   // em uma string

    vector<int> coords;
    vector<string> tokens = tokenizer(content);
    for (auto &i : tokens)
    {
        if (stoi(i) > (MAXTAM - 1))
        {
            cout << "Coordenadas invalidas!" << endl;
            abort();
        }
        else
        {
            coords.push_back(stoi(i));
        }
    }

    return coords;
}

int **ler_matriz(int xi, int yi, int xj, int yj)
{
    int count = 0, col_atual = 0, k = 0;
    vector<int> tokens;
    string buffer;
    int num_elementsM = ((xj + 1) - xi) * ((yj + 1) - yi);
    int M = (xj - xi) + 1; // MATRIZ DINAMICA
    int N = (yj - yi) + 1; //       M*N
    ifstream file;
    file.open("matriz.txt");

    if (!file)
    {
        cout << "Erro na abertura do arquivo!" << endl;
        abort();
    }

    for (int i = 0; i < xi; i++)
    {
        getline(file, buffer);
    }

    while (!file.eof())
    {
        while (getline(file, buffer, ' '))
        {
            if (count < num_elementsM)
            {
                if ((col_atual >= yi) && (col_atual <= yj))
                {
                    tokens.push_back(stoi(buffer));
                    count++;
                }
            }
            col_atual++;
            if (col_atual == MAXTAM)
            {
                col_atual = 0;
            }
        }
    }

    file.close();

    // *MATRIZ DINAMICA* //
    int **A = new int *[M];

    for (int i = 0; i < M; i++)
    {
        A[i] = new int[N];
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = tokens[k];
            k++;
        }
    }

    return A;
}