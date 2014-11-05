#ifndef _SKEW_HEAP_H_
#define _SKEW_HEAP_H_

typedef int Type;

typedef struct _SkewNode
{
    Type key;
    struct _SkewNode *left;
    struct _SkewNode *right;
}SkewNode ,*SkewHeap;

void preorder_skewheap(SkewHeap heap);

void inorder_skewheap(SkewHeap heap);

void postorder_skewheap(SkewHeap heap);

int skewheap_minimum(SkewHeap heap,int *pval);

SkewNode* merge_skewheap(SkewHeap x,SkewHeap y);

SkewNode *insert_skewheap(SkewHeap heap,Type key);

SkewNode *delete_skewheap(SkewHeap heap);

void destroy_skewheap(SkewHeap heap);

void print_skewheap(SkewHeap heap);

#endif
