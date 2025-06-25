#include <stdlib.h>
#include <stdio.h>

// Estrutura de dados do tipo FIFO
// ou seja, primeiro a entrar é o primeiro
// a sair

// Podemos implementar uma fila tanto com vetor
// quanto com lista encadeada.

// - Enqueue -> Adicionar elemento no final da fila
// - Dequeue -> remover o primeiro elemento do comeco da fila
// - isEmpty -> Saber se a fila está vazia

struct Node
{
    int value;
    struct Node *next;
};

struct Queue
{
    struct Node *head;
    struct Node *tail;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->value = value;
    node->next = NULL;

    return node;
}

// 1 2 3

int isEmpty(struct Queue *queue)
{
    if (queue->head == NULL)
    {
        return 1;
    }

    return 0;
}

void enqueue(struct Queue *queue, struct Node *node)
{
    if (isEmpty(queue))
    {
        queue->head = node;
        queue->tail = node;
        return;
    }

    struct Node *lastNode = queue->tail;
    lastNode->next = node;
    queue->tail = node;
    return;
}

void printQueue(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("\nValor: %d", node->value);

    printQueue(node->next);
    return;
}

struct Node *dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        return NULL;
    }

    struct Node *first = queue->head;
    queue->head = first->next;

    return first;
}

int main()
{
    struct Queue *queue = createQueue();

    for (int i = 1; i < 5; i++)
    {
        struct Node *node = createNode(i);
        enqueue(queue, node);
    }

    printf("\n-------");

    printQueue(queue->head);

    free(dequeue(queue));
    free(dequeue(queue));

    printf("\n-------");

    printQueue(queue->head);
}