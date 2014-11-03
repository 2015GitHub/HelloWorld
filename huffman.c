#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

extern void create_minheap(Type a[],int size);

extern HuffmanNode *dump_from_minheap();

extern int dump_to_minheap(HuffmanNode *node);

extern void destroy_minheap();

void preorder_huffman(HuffmanTree tree)
{
    if (tree != NULL)
    {
        printf("%d ",tree->key);
        preorder_huffman(tree->left);
        preorder_huffman(tree->right);
    }
}

void inorder_huffman(HuffmanTree tree)
{
    if (tree != NULL)
    {
        inorder_huffman(tree->left);
        printf("%d ",tree->key);
        inorder_huffman(tree->right);
    }
}

void postorder_huffman(HuffmanTree tree)
{
    if (tree != NULL)
    {
        postorder_huffman(tree->left);
        postorder_huffman(tree->right);
        printf("%d ",tree->key);
    }
}

HuffmanNode *huffman_create_node(Type key,HuffmanNode *left,HuffmanNode *right,HuffmanNode *parent)
{
    HuffmanNode *p;

    if ((p = (HuffmanNode *)malloc(sizeof(HuffmanNode))) == NULL)
        return NULL;

    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;

    return p;
}

HuffmanNode *create_huffman(Type a[],int size)
{
    int i;
    HuffmanNode *left,*right,*parent;

    create_minheap(a,size);

    for (i = 0 ;i < size-1;i++)
    {
        left = dump_from_minheap();
        right = dump_from_minheap();

        parent = huffman_create_node(left->key + right->key,left,right,NULL);
        left->parent = parent;
        right->parent = parent;

        if (dump_to_minheap(parent) != 0)
        {
            printf("failed\n");
            destroy_huffman(parent);
            parent = NULL;
            break;
        }
    }
    
    destroy_minheap();

    return parent;
}

void destroy_huffman(HuffmanTree tree)
{
    if (tree == NULL)
        return;

    if (tree->left != NULL)
        destroy_huffman(tree->left);
    if (tree->right != NULL)
        destroy_huffman(tree->right);


    free(tree);
}

void huffman_print(HuffmanTree tree,Type key,int direction)
{
    if (tree != NULL)
    {
        if (direction == 0)
            printf("%2d is root\n",tree->key);
        else
            printf("%2d is %2d's %6s child\n",tree->key,key,direction==1 ? "right" : "left");

        huffman_print(tree->left,tree->key,-1);
        huffman_print(tree->right,tree->key,1);
    }
}

void print_huffman(HuffmanTree tree)
{
    if (tree != NULL)
    {
        huffman_print(tree,tree->key,0);
    }
}
