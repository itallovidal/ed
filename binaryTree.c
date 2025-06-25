// Árvore binária é uma estrutura de dados
// onde os dados se conectam por nós, cada nó pode
// ter no máximo 2 ramos.

// O que definirá se o ramo será para esquerda ou direita
// é se o valor é maior ou menor do que o nó atual

// Temos diferentes formas de percorrer uma árvore binária
// PRÉ ORDEM -> raiz -> nó pai -> nó filho esquerdo -> nó filho direito
// https://www.w3schools.com/dsa/dsa_algo_binarytrees_preorder.php

// ORDEM -> nó esquerda -> nó pai (filho caso tenha) -> raíz -> nó direito
// https://www.w3schools.com/dsa/dsa_algo_binarytrees_inorder.php

// PÓS ORDEM -> nó esquerda -> (filho caso tenha) -> nó direita  -> nó pai
// https://www.w3schools.com/dsa/dsa_algo_binarytrees_postorder.php

// Métodos Comuns:
// Criar nó
// inserir
// remover

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

void printPreOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printf("%d\n", node->value);

    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printOrder(node->left);
    printf("%d\n", node->value);

    printOrder(node->right);
}

void printPostOrder(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d\n", node->value);
}

struct Node *insert(struct Node *tree, int value)
{
    if (tree == NULL)
    {
        return createNode(value);
    }

    if (value > tree->value)
    {
        return tree->right = insert(tree->right, value);
    }

    return tree->left = insert(tree->left, value);
}

int search(struct Node *tree, int value)
{
    if (tree == NULL)
    {
        printf("Não encontrado nesse ramificacão.");
        return -1;
    }

    if (value == tree->value)
    {
        return tree->value;
    }

    if (value > tree->value)
    {
        return search(tree->right, value);
    }

    return search(tree->left, value);
}

int main()
{
    struct Node *tree = NULL;

    tree = insert(tree, 5);
    insert(tree, 3);
    insert(tree, 8);
    insert(tree, 4);

    printf("Pré-ordem: ");
    printPreOrder(tree);
    printf("\n");

    printf("Em ordem: ");
    printOrder(tree);
    printf("\n");

    printf("Pós-ordem: ");
    printPostOrder(tree);
    printf("\n");

    search(tree, 10);

    return 0;
}