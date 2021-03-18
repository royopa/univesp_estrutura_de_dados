#include <iostream>
#include "fila_dinamica.h"

using namespace std;

int main()
{
    FilaDinamica fila1;
    int opcao;
    TipoItem item = 0;

    cout << "Programa gerador de filas dinâmicas" << endl;
    cout << "*************************" << endl;
    do
    {
        cout << endl;
        cout << "Digite 0 para parar o programa " << endl;
        cout << "Digite 1 para inserir um elemento " << endl;
        cout << "Digite 2 para remover um elemento " << endl;
        cout << "Digite 3 para printar a Fila " << endl;
        cout << "Digite 4 para ver a quantidade de elementos da Fila " << endl;
        cout << "Opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao)
        {
        case 1:
            cout << "Digite o elemento a ser inserido na fila: ";
            cin >> item;
            fila1.push(item);
            break;
        case 2:
            item = fila1.pop();
            cout << "Elemento " << item << " removido" << endl;
            break;
        case 3:
            fila1.print();
            break;
        case 4:
            cout << "A Fila tem " << fila1.length() << " elementos" << endl;
            break;
        default:
            break;
        }
    } while (opcao != 0);

    return 0;
}