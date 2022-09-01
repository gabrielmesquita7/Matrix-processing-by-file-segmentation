#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <chrono>

#define MAXTAM 10

using namespace std;

void EscreveMatrizG();
vector<string> tokenizer(string text);
vector<int> ler_coords();
int **ler_matriz(int xi, int yi, int xj, int yj);
int **transposta(int **matriz, int M, int N);
int **multiplicacao_matriz(int **matriz1, int **matriz2, int M, int N);
void hash_storage(int xi, int yi, int xj, int yj);
void readtxt();
bool verifyHash(int key, unordered_map<int, int **> hashm);
void printMatriz(int xi, int xj, int **m);

#endif