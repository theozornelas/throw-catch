#ifndef QUICKSORT_H
#define QUICKSORT_H

/**************
 * PROTOTYPES *
 **************/
template <typename E>
void QuickSort(QVector<E> &vecToSort, int left, int right);

template <typename E, typename Comparator>
void QuickSort(QVector<E> &vecToSort, int left, int right, Comparator compare);

/***************
 * DEFINITIONS *
 ***************/

//Without comparator
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

//With comparator
template <typename E, typename Comparator>
void QuickSort(QVector<E> &vecToSort, int left, int right, Comparator compare)
{
    int i = left;
    int j = right;
    E temp;

    //Chooses the pivot
    E pivot = vecToSort[(left + right) / 2];

    //Sorts the vector
    while(i <= j)
    {
        while(compare(vecToSort[i], pivot))
        {
            ++i;
        }
        while(!compare(vecToSort[j], pivot))
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
        QuickSort(vecToSort, left, j, compare);
    if(i < right)
        QuickSort(vecToSort, i, right, compare);
}


#endif // QUICKSORT_H
