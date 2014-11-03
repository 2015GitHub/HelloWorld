#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef int Type;

typedef struct _HuffmanNode
{
    Type key;
    struct _HuffmanNode *left;
    struct _HuffmanNode *right;
    struct _HuffmanNode *parent;
}HuffmanNode,*HuffmanTree;

void preorder_huffman(HuffmanTree tree);

void inorder_huffman(HuffmanTree tree);

void postorder_huffman(HuffmanTree tree);

HuffmanNode *create_huffman(Type arr[],int size);

void destroy_huffman(HuffmanTree tree);

void print_huffman(HuffmanTree tree);

#endif
