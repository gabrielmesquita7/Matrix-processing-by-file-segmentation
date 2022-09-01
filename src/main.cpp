#include "matriz.hpp"

int main()
{
    int xi, yi, xj, yj, op = 0, op2;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    EscreveMatrizG();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "------------------------" << endl;
    cout << "Matriz foi criada em " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "[ms]" << endl;
    while (op != 2)
    {
        cout << "------------------------" << endl;
        cout << "MENU:" << endl;
        cout << "1->Realizar novo calculo" << endl;
        cout << "2->Sair..." << endl;
        cout << "-> ";
        cin >> op;
        cout << "------------------------" << endl;
        switch (op)
        {
        case 1:
            cout << "------------------------" << endl;
            cout << "0)Ler coordenadas.txt\n1)Digitar coordenadas\n-> ";
            cin >> op2;
            cout << "------------------------" << endl;
            if (op2 == 0)
            {
                readtxt();
            }
            else if (op2 == 1)
            {
                cout << "Digite as coordenadas para verificacao: " << endl;
                cout << "xi = ";
                cin >> xi;
                cout << "yi = ";
                cin >> yi;
                cout << "xj = ";
                cin >> xj;
                cout << "yj = ";
                cin >> yj;
                cout << "------------------------" << endl;
                int M = (xj - xi) + 1;
                int N = (yj - yi) + 1;
                if (M <= 0 || N <= 0)
                {
                    cout << "Error! Dimensao negativa da matriz" << endl;
                    break;
                }
                hash_storage(xi, yi, xj, yj);
            }
            else
            {
                cout << "Opcao invalida" << endl;
                break;
            }

            break;
        case 2:
            cout << "Finalizando..." << endl;
            abort();
            break;
        default:
            break;
        }
    }

    return 0;
}