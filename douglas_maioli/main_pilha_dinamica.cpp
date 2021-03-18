#include <iostream>
#include "pilha_dinamica.h"

using namespace std;

int main()
{
    PilhaDinamica pilha1;
    TipoItem item = 0;

    int opcao;

    cout << "Programa gerador de pilhas dinâmicas" << endl;
    do
    {
        cout << "Digite 0 para parar o programa " << endl;
        cout << "Digite 1 para inserir um elemento " << endl;
        cout << "Digite 2 para remover um elemento " << endl;
        cout << "Digite 3 para printar a pilha " << endl;
        cout << "Digite 4 para ver a quantidade de elementos da pilha " << endl;
        cin >> opcao;

        if (opcao == 1)
        {
            cout << "Digite o elemento a ser inserido " << endl;
            cin >> item;
            pilha1.push(item);
        }
        else if (opcao == 2)
        {
            item = pilha1.pop();
            cout << "Elemento " << item << " removido" << endl;
        }
        else if (opcao == 3)
        {
            pilha1.print();
        }
        else if (opcao == 4)
        {
            cout << "A pilha tem " << pilha1.length() << " elementos" << endl;
        }

    } while (opcao != 0);

    return 0;
}