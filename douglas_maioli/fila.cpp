#include <iostream>
#include "fila.h"

using namespace std;

Fila::Fila()
{
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[MAX_ITENS];
}

Fila::~Fila()
{
    delete[] estrutura;
}

bool Fila::isFull()
{
    // se a diferença entre o último e o primeiro é igual
    // ao máximo de itens
    return (ultimo - primeiro == MAX_ITENS);
}

// se o ultimo é o valor do primeiro, então está vazio
bool Fila::isEmpty()
{
    return (primeiro == ultimo);
}

// inserir
void Fila::push(TipoItem item)
{
    if (isFull())
    {
        cout << "A Fila já está cheia" << endl;
        cout << "Não é possível inserir este elemento" << endl;
        return;
    }

    // insere no final da fila, ou seja,
    // no resto da posição do último item
    estrutura[ultimo % MAX_ITENS] = item;
    ultimo++;
}

// remover
TipoItem Fila::pop()
{
    if (isEmpty())
    {
        cout << "A Fila está vazia" << endl;
        cout << "Nenhum elemento foi removido" << endl;
        return 0;
    }

    //
    primeiro++;
    return estrutura[(primeiro - 1) % MAX_ITENS];
}

void Fila::print()
{
    cout << "Fila: [ ";
    // percorre do primeiro até o ultimo
    for (int i = primeiro; i < ultimo; i++)
    {
        cout << estrutura[i % MAX_ITENS] << " ";
    }
    cout << "]" << endl;
}

int Fila::length()
{
    return ultimo - primeiro;
}