#include <stdio.h>
#include "skewheap.h"

#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

void main()
{
    int i ;
    int a[] = {10,40,24,30,36,20,12,16};
    int b[] = {17,13,11,15,19,21,23};
    int alen = LENGTH(a);
    int blen = LENGTH(b);
    SkewHeap ha,hb;

    ha = hb = NULL;

    printf("==:");
    for (i = 0;i < alen;i++)
    {
        printf("%d ",a[i]);
        ha = insert_skewheap(ha,a[i]);
    }
    printf("\n==:\n");
    print_skewheap(ha);

    printf("\n==:");
    for (i = 0;i < blen ;i++)
    {
        printf("%d ",b[i]);
        hb = insert_skewheap(hb,b[i]);
    }

    printf("\n==:\n");
    print_skewheap(hb);

    ha = merge_skewheap(ha,hb);
    printf("\n==:\n");
    print_skewheap(ha);

    destroy_skewheap(ha);
}
