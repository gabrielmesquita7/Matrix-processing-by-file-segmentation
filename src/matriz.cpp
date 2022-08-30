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
            nrand = rand() % (99 + 1 - 10) + 10; // somente numeros de 2 algarismos
            file << nrand << "\t";
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
    string content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));

    vector<int> coords;
    vector<string> tokens = tokenizer(content);
    for (auto &i : tokens)
    {
        coords.push_back(stoi(i));
    }

    return coords;
}
