#include <stdlib.h>
#include <stdio.h>

// Stack (Pilha) é uma estrutura de dados do tipo FILO
// ou seja, o primeiro a entrar é o último a sair.

// As operacões básicas são:
// - peek   -> ver o último elemento
// - pop    -> retirar o último elemento
// - push   -> adicionar o elemento na stack
// - isEmpty -> saber se está vazio
// - isFull -> saber se está cheio

// Geralmente é feito com vetores

void printValue(int value)
{
    if (value == -1)
    {
        printf("\nPilha vazia, nada a printar.");
        return;
    }

    printf("\nValor: %d", value);
}

struct Stack
{
    int size;
    int *arr;
    int capacity;
};

struct Stack *createStack(int arrSize)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    stack->size = 0;
    stack->capacity = arrSize;
    stack->arr = (int *)malloc(arrSize * sizeof(int));

    return stack;
}

int isFull(struct Stack *stack)
{
    if (stack->size >= stack->capacity)
    {
        return 1;
    }

    return 0;
}

int push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        return 0;
    }
    stack->arr[stack->size] = value;
    stack->size++;

    return 1;
}

int isEmpty(struct Stack *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }

    return 0;
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }

    return stack->arr[stack->size - 1];
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }

    stack->size--;
    return stack->arr[stack->size];
}

void printStack(struct Stack *stack)
{
    for (int i = 0; i < stack->size; i++)
    {
        printValue(stack->arr[i]);
    }
}

int main()
{
    struct Stack *stack = createStack(5);

    int test = peek(stack);
    printValue(test);

    for (int i = 1; i < 7; i++)
    {
        int isSuccessful = push(stack, i);

        if (isSuccessful)
        {
            printf("\nValor %d adicionado na pilha!", i);
            continue;
        }

        printf("\nPilha cheia! Valor %d não adicionado.", i);
    }

    printf("\n-----");

    int lastValue = peek(stack);
    printValue(lastValue);

    printf("\n-----");

    printStack(stack);

    printf("\n-----");

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);

    int newLastValue = peek(stack);
    printValue(newLastValue);
}