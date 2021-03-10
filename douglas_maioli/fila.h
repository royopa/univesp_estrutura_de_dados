typedef int TipoItem;

const int MAX_ITENS = 100;

class Fila
{
private:
    int primeiro, ultimo;
    TipoItem *estrutura; // a estrutura é um vetor com elementos daquele tipo definido

public:
    Fila();                   //construtora
    ~Fila();                  // destrutora
    bool isFull();            // verifica se a pilha está cheia
    bool isEmpty();           // verifica se esta vazia
    void push(TipoItem item); // inserir
    TipoItem pop();           // remover
    void print();
    int length(); // retorna o tamPem anho
};