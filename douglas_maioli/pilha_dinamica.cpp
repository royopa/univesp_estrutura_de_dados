#include <iostream>
#include "pilha_dinamica.h"
#include <cstddef> // para usar o NULL

using namespace std;

PilhaDinamica::PilhaDinamica()
{
    // cria um nó topo e seta como nulo, pois não tem nenhum elemento ainda
    TopNode = NULL;
}

PilhaDinamica::~PilhaDinamica()
{
    // cria um nó temporario
    Node *TempNode;
    while (TopNode != NULL)
    {
        TempNode = TopNode;
        TopNode = TopNode->next;
        delete TempNode;
    }
}

bool PilhaDinamica::isFull()
{
    // se tem memória para adicionar mais elementos
    // faz o try e catch para saber se tem espaço em memória
    Node *NewNode;
    try
    {
        // tena alocar um espaço em memória
        NewNode = new Node;
        delete NewNode; // tira da memória
        return false;   // retorna que não está cheio, ou seja, conseguiu alocar memoria
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool PilhaDinamica::isEmpty()
{
    // se o nó topo é nulo, então não tem ninguem na pilha
    return (TopNode == NULL);
}

// inserir elemento
void PilhaDinamica::push(TipoItem item)
{
    // se está cheio avisa que tem problema
    if (isFull())
    {
        cout << "A pilha está cheia!" << endl;
        cout << "Não foi possível inserir esse elemento." << endl;
        return;
    }

    Node *NewNode = new Node;
    // como um dos elementos do struct é um ponteiro,
    // temos que usar a seta -> ao inves de ponto . para atribuir valor
    NewNode->valor = item;   // o valor é o item que se deseja inserir
    NewNode->next = TopNode; // ele vai apontar para o topo antigo
    TopNode = NewNode;       // e o nó topo agora vai ser ele mesmo
}

// remover
TipoItem PilhaDinamica::pop()
{
    // se está vazio não remove ninguem
    if (isEmpty())
    {
        cout << "A pilha está vazia!" << endl;
        cout << "Não foi possível remover nenhum elemento." << endl;
        return 0;
    }

    // vai criar um nó temporario
    // para fazer o ponteiro apontar para o próximo
    // e aí lilbera o ponteiro
    Node *TempNode;
    TempNode = TopNode;
    // o item pega o valor do nó topo
    TipoItem item = TopNode->valor;
    //
    TopNode = TopNode->next;
    delete TempNode;
    return item;
}

void PilhaDinamica::print()
{
    // cria uma variável temporária
    Node *TempNode = TopNode;
    // vai andando do topo até chegar no primeiro
    // ele sabe que é o primeiro quando next é null
    cout << "Pilha: [ ";
    while (TempNode != NULL)
    {
        cout << TempNode->valor << " ";
        TempNode = TempNode->next; // pega o proximo elemento da pilha
    }
    cout << "]" << endl;
}

int PilhaDinamica::length()
{
    int tamanho = 0;
    Node *TempNode = TopNode;
    while (TempNode != NULL)
    {
        TempNode = TempNode->next;
        tamanho += 1;
    }
    return tamanho;
}