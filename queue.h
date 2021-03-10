#include "item_type.h"

const int MAX_ITEMS = 100;

class Queue
{
public:
    Queue();  // Construtor
    ~Queue(); // Destrutor
    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void push(ItemType);
    ItemType pop();

private:
    int length;
    ItemType *structure;
};
