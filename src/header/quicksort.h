#ifndef QUICKSORT_H
#define QUICKSORT_H

// Prototype
template <typename E>
void QuickSort(QVector<E> &vecToSort, int left, int right);

// Definition
template <typename E>
void QuickSort(QVector<E> &vecToSort, int left, int right)
{
    int i = left;
    int j = right;
    E temp;

    //Chooses the pivot
    E pivot = vecToSort[(left + right) / 2];

    //Sorts the vector
    while(i <= j)
    {
        while(vecToSort[i] < pivot)
        {
            ++i;
        }
        while(vecToSort[j] > pivot)
        {
            --j;
        }
        if(i <= j)
        {
            temp = vecToSort[i];
            vecToSort[i] = vecToSort[j];
            vecToSort[j] = temp;
            ++i;
            --j;
        }
    }

    if(left < j)
        QuickSort(vecToSort, left, j);
    if(i < right)
        QuickSort(vecToSort, i, right);
}


#endif // QUICKSORT_H
