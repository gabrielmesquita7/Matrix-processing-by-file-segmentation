#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define MAXTAM 10

using namespace std;

void EscreveMatrizG();
vector<string> tokenizer(string text);
vector<int> ler_coords();
int **ler_matriz(int xi, int yi, int xj, int yj);

#endif