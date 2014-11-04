#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ((sizeof(a)) / (sizeof(a[0])))

static int m_heap[30];
static int m_capacity = 30;
static int m_size = 0;

int get_index(int data)
{
    int i = 0;

    for (i = 0;i < m_size;i++)
    {
        if (data == m_heap[i])
            return i;
    }

    return -1;
}

static void minheap_filterdown(int start,int end)
{
    int c = start;
    int l = 2*c + 1;
    int tmp = m_heap[c];

    while ( l <= end )
    {
        if (l < end && m_heap[l] > m_heap[l+1])
            l++;
        if (tmp <= m_heap[l])
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

int minheap_remove(int data)
{
    int index;

    if (m_size == 0)
        return -1;

    index = get_index(data);
    
    if (index == -1)
        return -1;

    m_heap[index] = m_heap[--m_size];
    minheap_filterdown(index,m_size-1);

    return 0;
}

static void filter_up(int start)
{
    int c = start;
    int p = (c-1)/2;
    int tmp = m_heap[c];

    while ( c > 0 )
    {
        if (m_heap[c] <= tmp)
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

int minheap_insert(int data)
{
    if (m_size == m_capacity)
        return -1;

    m_heap[m_size] = data;
    filter_up(m_size);
    m_size++;

    return 0;
}

void minheap_print()
{
    int i ;

    for (i = 0;i < m_size;i++)
    {
        printf("%d ",m_heap[i]);
    }
}

int main()
{
    int a[] = {80,40,30,60,90,70,10,50,20};
    int i,len=LENGTH(a);

    for (i = 0;i < len;i++)
    {
        printf("%d ",a[i]);
        minheap_insert(a[i]);
    }
    
    printf("\n");

    minheap_print();
    
    printf("\n");

    i = 15;
    minheap_insert(i);
    minheap_print();
    
    printf("\n");

    i = 10;
    minheap_remove(i);
    minheap_print();

    return 0;
}
