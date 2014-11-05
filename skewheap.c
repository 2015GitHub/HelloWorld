#include <stdio.h>
#include <stdlib.h>

#include "skewheap.h"

void preorder_skewheap(SkewHeap heap)
{
    if (heap != NULL)
    {
        printf("%d ",heap->key);
        preorder_skewheap(heap->left);
        preorder_skewheap(heap->right);
    }
}

void inorder_skewheap(SkewHeap heap)
{
    if (heap != NULL)
    {
        inorder_skewheap(heap->left);
        printf("%d ",heap->key);
        inorder_skewheap(heap->right);
    }
}

void postorder_skewheap(SkewHeap heap)
{
    if (heap != NULL)
    {
        postorder_skewheap(heap->left);
        postorder_skewheap(heap->right);
        printf("%d ",heap->key);
    }
}

int skewheap_minimum(SkewHeap heap,int *pval)
{
    if (heap == NULL)
        return -1;

    *pval = heap->key;

    return 0;
}

static void swap_skewheap_node(SkewNode *x,SkewNode *y)
{
    SkewNode tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

SkewNode* merge_skewheap(SkewHeap x,SkewHeap y)
{
    if (x == NULL)
        return y;
    if (y == NULL)
        return x;

    if (x->key > y->key)
        swap_skewheap_node(x,y);

    SkewNode *tmp = merge_skewheap(x->right,y);
    x->right = x->left;
    x->left = tmp;
}

SkewNode *insert_skewheap(SkewHeap heap,Type key)
{
    SkewNode *node;

    if ((node = (SkewNode *)malloc(sizeof(SkewNode))) == NULL)
        return heap;
    node->key = key;
    node->left = node->left = NULL;

    return merge_skewheap(heap,node);
}

SkewNode *delete_skewheap(SkewHeap heap)
{
    SkewNode *l = heap->left;
    SkewNode *r = heap->right;

    free(heap);

    return merge_skewheap(l,r);
}

void destroy_skewheap(SkewHeap heap)
{
    if (heap == NULL)
        return ;
    if (heap->left != NULL)
        destroy_skewheap(heap->left);
    if (heap->right != NULL)
        destroy_skewheap(heap->right);

    free(heap);
}

static void skewheap_print(SkewHeap heap,Type key,int direction)
{
    if (heap != NULL)
    {
        if (direction == 0)
        {
            printf("%2d is root\n",heap->key);
        }
        else
        {
            printf("%2d is %2d's %6s child\n",heap->key,key,direction==1?"right":"left");
        }

        skewheap_print(heap->left,heap->key,-1);
        skewheap_print(heap->right,heap->key,1);
    }
}
void print_skewheap(SkewHeap heap)
{
    if (heap != NULL)
        skewheap_print(heap,heap->key,0);
}
