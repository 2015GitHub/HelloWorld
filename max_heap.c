#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

static int m_heap[30];
static int m_capacity = 30;
static int m_size = 0;

int get_index(int data)
{
    int i = 0;

    for (i = 0 ;i < m_size; i++)
    {
        if (data == m_heap[i])
            return i;
    }

    return -1;
}

static void maxheap_filterdown(int start,int end)
{
    int c = start;
    int l = 2*c + 1;
    int tmp = m_heap[c];

    while ( l <= end )
    {
        if (l < end && m_heap[l] < m_heap[l+1])
            l++;
        if (tmp >= m_heap[l])
            break;
        else
        {
            m_heap[c] = m_heap[l];
            c = l;
            l = 2*l + 1;
        }
    }

    m_heap[c] = tmp;
}


int maxheap_remove(int data)
{
    int index;

    if (m_size == 0)
        return -1;

    index = get_index(data);
    if (index == -1)
        return -1;

    m_heap[index] = m_heap[--m_size];
    maxheap_filterdown(index,m_size-1);

    return 0;
}

static void maxheap_filterup(int start)
{
    int c = start;
    int p = (c-1)/2;
    int tmp = m_heap[c];

    while (c > 0)
    {
        if (m_heap[p] >= tmp)
            break;
        else
        {
            m_heap[c] = m_heap[p];
            c = p;
            p = (p-1)/2;
        }
    }
    m_heap[c] = tmp;
}

int maxheap_insert(int data)
{
    if (m_size == m_capacity)
        return -1;

    m_heap[m_size] = data;
    maxheap_filterup(m_size);
    m_size++;

    return 0;
}

void maxheap_print()
{
    int i = 0;
    
    for (i = 0;i < m_size;i++)
        printf("%d ",m_heap[i]);
}

int main()
{
    int a[] = {10,40,30,60,90,70,20,50,80};
    int i,len = LENGTH(a);

    printf("==:");
    for (i = 0;i < len;i++)
    {
        printf("%d ",a[i]);
        maxheap_insert(a[i]);
    }

    printf("\n== max:");
    maxheap_print();

    i = 85;
    maxheap_insert(i);
    printf("\n==:%d",i);
    printf("\n==max:");
    maxheap_print();

    i = 90;
    maxheap_remove(i);
    printf("\n==:%d",i);
    printf("\n==:");
    maxheap_print();
    printf("\n");
}
