typedef int TipoItem;

const int MAX_ITENS = 100;

class Pilha
{
private:
    int tamanho;
    TipoItem *estrutura; // a estrutura é um vetor com elementos daquele tipo definido

public:
    Pilha();                  //construtora
    ~Pilha();                 // destrutora
    bool isFull();            // verifica se a pilha está cheia
    bool isEmpty();           // verifica se esta vazia
    void push(TipoItem item); // inserir
    TipoItem pop();           // remover
    void print();
    int length(); // retorna o tamanho
};