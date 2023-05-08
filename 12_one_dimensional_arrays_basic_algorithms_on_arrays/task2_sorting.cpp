#include <iostream>

void merge (double *a, int l, int m, int r)
{
    int remainSize1 = m - l + 1;
    int remainSize2 = r - m;
    double tempL[remainSize1];
    double tempR[remainSize2];
    
    for (int i = 0; i < remainSize1; ++i)
        tempL[i] = a[l + i];
    for (int i = 0; i < remainSize2; ++i)
        tempR[i] = a[m + 1 + i];
        
    int i, j, k;
    i = j = 0;
    k = l;
    while (i < remainSize1 && j < remainSize2) {
        if (tempL[i] >= tempR[j])
            a[k++] = tempL[i++];
        else
            a[k++] = tempR[j++];
    }
    
    while (i < remainSize1)
        a[k++] = tempL[i++];
        
    while (j < remainSize2)
        a[k++] = tempR[j++];

}

void mergeSort (double *a, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort (a, l, m);
        mergeSort (a, m + 1, r);
        merge (a, l, m, r);
    }
}

int main ()
{
    double array[15];
    std::cout << "Input 15 elements of double type:" << std::endl;
    for (int i = 0; i < 15; ++i)
        std::cin >> array[i];
    mergeSort (array, 0, 14);
    for (int i = 0; i < 15; ++i)
        std::cout << array[i] << ' ';
    return 0;
}
