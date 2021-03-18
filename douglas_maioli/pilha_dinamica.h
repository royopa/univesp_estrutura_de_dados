// Pilha Dinâmica = Dynamic Stack

typedef int TipoItem;

// é como se fosse uma classe
// cada nó guarda o valor e o endereço do próximo
struct Node
{
    TipoItem valor; //o valor do nó atual
    Node *next;     //ponteiro para o próximo elemento (outro nó)
};

class PilhaDinamica
{
private:
    // ponteiro para o nó topo
    Node *TopNode;

public:
    PilhaDinamica();          //construtor
    ~PilhaDinamica();         // destrutor
    bool isFull();            // verifica se tem memória no computador para inserir mais registros
    bool isEmpty();           // verifica se esta vazia
    void push(TipoItem item); // inserir
    TipoItem pop();           // remover
    void print();
    int length(); // retorna o tamanho
};