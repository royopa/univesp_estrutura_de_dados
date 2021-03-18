#include <iostream>
#include "fila_dinamica.h"
#include <cstddef> // para usar o NULL
#include <new>     //

using namespace std;

FilaDinamica::FilaDinamica()
{
    // cria um nó topo e seta o primeiro e o último como nulo
    // pois não tem nenhum elemento ainda
    FirstNode = NULL;
    LastNode = NULL;
}

FilaDinamica::~FilaDinamica()
{
    // cria um ponteiro para nó temporario
    Node *TempNode;
    while (FirstNode != NULL)
    {
        //  e aponta para o primeiro
        TempNode = FirstNode;
        // o segundo vira o primeiro
        FirstNode = FirstNode->next;
        // e aí apaga o temporário
        delete TempNode;
    }
    LastNode = NULL;
}

bool FilaDinamica::isFull()
{
    // se tem memória para adicionar mais elementos
    // faz o try e catch para saber se tem espaço em memória
    Node *TempNode;
    try
    {
        // tenta alocar um espaço em memória
        TempNode = new Node;
        delete TempNode; // tira da memória
        return false;    // retorna que não está cheio, ou seja,
                         // conseguiu alocar memoria
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool FilaDinamica::isEmpty()
{
    // se o primeiro é NULL, então está vazio
    return (FirstNode == NULL);
}

// inserir elemento
void FilaDinamica::push(TipoItem item)
{
    // se está cheio avisa que tem problema
    if (isFull())
    {
        cout << "A Fila está cheia!" << endl;
        cout << "Não foi possível inserir esse elemento." << endl;
        return;
    }

    Node *NewNode = new Node;
    // temos que usar a seta -> ao inves de ponto . para atribuir valor
    NewNode->valor = item; // o valor é o item que se deseja inserir
    NewNode->next = NULL;  // ele vai apontar para o NULL, pois não é o último

    // se é o primeiro que está inserindo, então primeiro e último são iguais
    if (FirstNode == NULL)
    {
        FirstNode = NewNode;
    }
    else
    {
        // o último antes da inclusão do item passa a ser o penúltimo
        // isso é feito pegando o último oanterior e setando o next como
        // esse item novo
        LastNode->next = NewNode;
    }

    // marca o novo item como o último nó, pois agora ele é o ultimo da fila
    LastNode = NewNode;
}

// remover
TipoItem FilaDinamica::pop()
{
    // se está vazio não remove ninguem
    if (isEmpty())
    {
        cout << "A Fila está vazia!" << endl;
        cout << "Não foi possível remover nenhum elemento." << endl;
        return 0;
    }

    // vai criar um nó temporario
    // para fazer o ponteiro apontar para o primeiro
    // e aí lilbera o ponteiro
    Node *TempNode;
    TempNode = FirstNode;
    // o item pega o valor do nó topo
    TipoItem item = TempNode->valor;
    // então o segundo elemento vira o primeiro da fila
    FirstNode = FirstNode->next;

    // verifica se o primeiro é nulo, então a lista ficou vazia
    if (FirstNode == NULL)
    {
        LastNode = NULL;
    }

    delete TempNode;
    return item;
}

void FilaDinamica::print()
{
    // cria uma variável temporária
    Node *TempNode = FirstNode;
    // vai andando do topo até chegar no primeiro
    // ele sabe que é o primeiro quando next é null
    cout << "Fila: [ ";
    while (TempNode != NULL)
    {
        cout << TempNode->valor << " ";
        TempNode = TempNode->next; // pega o proximo elemento da Fila
    }
    cout << "]" << endl;
}

int FilaDinamica::length()
{
    int tamanho = 0;
    Node *TempNode = FirstNode;
    while (TempNode != NULL)
    {
        TempNode = TempNode->next;
        tamanho += 1;
    }
    return tamanho;
}