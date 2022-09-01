#include "matriz.hpp"

unordered_map<int, int **> hashmap;

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

int **transposta(int **matriz, int M, int N)
{
    int **B = new int *[N];

    for (int i = 0; i < N; i++)
    {
        B[i] = new int[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            B[i][j] = matriz[j][i];
        }
    }

    return B;
}

int **multiplicacao_matriz(int **matriz1, int **matriz2, int M, int N)
{
    int **C = new int *[M];

    for (int i = 0; i < M; i++)
    {
        C[i] = new int[M];
    }

    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < M; k++)
        {
            C[i][k] = 0;
            for (int j = 0; j < N; j++)
            {
                C[i][k] += matriz1[i][j] * matriz2[j][k];
            }
        }
    }
    return C;
}

void hash_storage(int xi, int yi, int xj, int yj) // 0 lendo txt //1 lendo menu
{
    int key = stoi((to_string(xi)) + to_string(yi) + to_string(xj) + to_string(yj));

    int M = (xj - xi) + 1; // MATRIZ DINAMICA
    int N = (yj - yi) + 1; //       M*N
    if (verifyHash(key, hashmap) == true)
    {
        cout << "Ja foi cadastrado" << endl;
        int **matrixaux = hashmap[key];
        cout << "------------------------" << endl;
        cout << "Chave: " << key << endl;
        cout << "Matriz: " << endl;
        printMatriz(xi, xj, matrixaux);
        cout << "------------------------" << endl;
    }
    else
    {
        cout << "------------------------" << endl;
        cout << "Nao foi cadastrado" << endl;
        cout << "Cadastrando nova chave: " << key << endl;
        int **matriz = ler_matriz(xi, yi, xj, yj);
        int **matriz_transposta = transposta(matriz, M, N);
        int **mult_matrizes = multiplicacao_matriz(matriz, matriz_transposta, M, N);
        hashmap.emplace(key, mult_matrizes);
        cout << "------------------------" << endl;
    }
}

bool verifyHash(int key, unordered_map<int, int **> hashm)
{
    if (hashm.find(key) != hashm.end())
    {
        return true;
    }
    return false;
}

void printMatriz(int xi, int xj, int **m)
{
    int M = (xj - xi) + 1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void readtxt()
{
    int xi, yi, xj, yj;
    vector<int> coord = ler_coords();
    xi = coord[0];
    yi = coord[1];
    xj = coord[2];
    yj = coord[3];
    hash_storage(xi, yi, xj, yj);
}