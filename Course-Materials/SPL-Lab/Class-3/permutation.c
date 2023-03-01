#include <stdio.h>
#include <stdlib.h>

#define PERM_T int
#define PERM_T_PFLAG "%d"

void swap(PERM_T *array, int i, int j)
{
    PERM_T aux = array[i];
    array[i] = array[j];
    array[j] = aux;
}

void print_array_perm(PERM_T *array, int n)
{
    printf("[");
    n -= 1;
    for (int i = 0; i < n; i++)
    {
        printf(PERM_T_PFLAG ", ", array[i]);
    }
    if (n >= 0)
        printf(PERM_T_PFLAG, array[n]);
    printf("]\n");
}

void print_array_int(int *array, int n)
{
    printf("[");
    n -= 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
    if (n >= 0)
        printf("%d", array[n]);
    printf("]\n");
}

void copy_array_T(
    PERM_T *src, PERM_T *dst,
    int start, int end)
{
    for (int i = start; i < end; i++)
    {
        dst[i] = src[i];
    }
}

void copy_array_int(
    int *src, int *dst,
    int start, int end)
{
    for (int i = start; i < end; i++)
    {
        dst[i] = src[i];
    }
}

void rotate_array(
    PERM_T *array,
    int start, int end)
{
    PERM_T aux = array[start];
    copy_array_T(
        array + 1, array, start, end);
    array[end - 1] = aux;
}

typedef struct
{
    PERM_T *data;
    int length;
    int *ks;
    int kn;
} Perm;

Perm perm_(
    PERM_T *data, PERM_T *array, int n)
{
    copy_array_T(array, data, 0, n);
    int kn = n > 1 ? n - 1 : 0;

    int *ks = kn ? malloc(sizeof(PERM_T) * kn) : NULL;
    for (int i = 0; i < kn; i++)
        ks[i] = i;

    Perm p = {
        .data = data,
        .length = n,
        .ks = ks,
        .kn = kn};
    return p;
}

Perm perm(PERM_T *array, int n)
{
    PERM_T *data =
        malloc(sizeof(PERM_T) * n);
    return perm_(data, array, n);
}

Perm copy_perm(Perm p)
{
    Perm copy = perm(p.data, p.length);
    copy_array_int(p.ks, copy.ks, 0, p.kn);
    return copy;
}

void clear_perm(Perm *p)
{
    free(p->data);
    if (p->kn)
        free(p->ks);
}

int completed_perm(Perm *p)
{
    int n = p->length;
    for (int i = 0; i < p->kn; i++)
    {
        if (p->ks[i] + 1 != n)
            return 0;
    }
    return 1;
}

void next_perm_self(Perm *p)
{
    int n = p->length;

    if (n <= 1)
        return;

    int k = p->kn - 1;
    int *ks = p->ks;
    PERM_T *data = p->data;

    if (ks[k] + 1 != n)
    {
        rotate_array(data, k, n);
        ks[k] += 1;
    }
    else
    {
        while (k >= 0 && ks[k] + 1 == n)
        {
            ks[k] = k;
            rotate_array(data, k, n);
            k -= 1;
        }
        if (k >= 0)
        {
            rotate_array(data, k, n);
            ks[k] += 1;
        }
    }
}

Perm next_perm_(Perm *p)
{
    Perm next = copy_perm(*p);
    next_perm_self(&next);
    return next;
}

Perm next_perm(Perm *p)
{
    Perm next = next_perm_(p);
    clear_perm(p);
    return next;
}

void print_perm(Perm p)
{
    print_array_perm(p.data, p.length);
}

void print_perm_(Perm p)
{
    printf("%p\n", p.data);
    print_perm(p);
    print_array_int(p.ks, p.kn);
}

Perm next_print(Perm *p)
{
    Perm next = next_perm(p);
    print_perm(next);
    return next;
}

void next_print_self(Perm *p)
{
    next_perm_self(p);
    print_perm_(*p);
}

int main()
{
    int a1[] = {1, 2, 3, 4, 5};
    Perm p = perm(a1, 5);

    int i = 0;
    while (!completed_perm(&p))
    {
        printf("%2d ", i++);
        //p = next_print(p);
        next_print_self(&p);
    }

    clear_perm(&p);
    return 0;
}