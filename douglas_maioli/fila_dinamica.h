// Fila Dinâmica = Dynamic Queue

typedef int TipoItem;

// é como se fosse uma classe
// cada nó guarda o valor e o endereço do próximo
class Node
{
public:
    TipoItem valor; //o valor do nó atual
    Node *next;     //ponteiro para o próximo elemento (outro nó)
};

class FilaDinamica
{
private:
    Node *FirstNode; // ponteiro para o primeiro nó
    Node *LastNode;  // ponteiro para o último nó

public:
    FilaDinamica();           //construtor
    ~FilaDinamica();          // destrutor
    bool isFull();            // verifica se tem memória no computador para inserir mais registros
    bool isEmpty();           // verifica se esta vazia
    void push(TipoItem item); // inserir
    TipoItem pop();           // remover
    void print();
    int length(); // retorna o tamanho
};