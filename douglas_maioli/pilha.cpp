#include <iostream>
#include "pilha.h"

using namespace std;

Pilha::Pilha()
{
    tamanho = 0;
    estrutura = new TipoItem[MAX_ITENS];
}

Pilha::~Pilha()
{
    delete[] estrutura;
}

bool Pilha::isFull()
{
    // se o tamanho é igual ao máximo de itens, então está cheia
    return (tamanho == MAX_ITENS);
}

bool Pilha::isEmpty()
{
    return (tamanho == 0);
}

void Pilha::push(TipoItem item)
{
    if (isFull())
    {
        cout << "A pilha já está cheia" << endl;
        cout << "Não é possível inserir este elemento" << endl;
        return;
    }

    // insere no topo e aumenta 1 no tamanho
    estrutura[tamanho] = item;
    tamanho++;
}

TipoItem Pilha::pop()
{
    if (isEmpty())
    {
        cout << "A pilha está vazia" << endl;
        cout << "Não tem elemento para ser removido." << endl;
        return 0;
    }

    tamanho--;
    return estrutura[tamanho];
}

void Pilha::print()
{
    cout << "Pilha: [ ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << estrutura[i] << " ";
    }
    cout << "] " << endl;
}

int Pilha::length()
{
    return tamanho;
}