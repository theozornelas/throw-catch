#ifndef QUICKSORT_H
#define QUICKSORT_H

/**************
 * PROTOTYPES *
 **************/
template <typename E>
void QuickSort(QVector<E> &vecToSort, int first, int last);

template <typename E, typename Comparator>
void QuickSort(QVector<E> &vecToSort, int first, int last, Comparator compare);


/***************
 * DEFINITIONS *
 ***************/

//Without comparator
template <typename E>
void QuickSort(QVector<E> &vecToSort, int first, int last)
{
    int left = first;
    int right = last;
    E temp;

    //Chooses the pivot
    E pivot = vecToSort[(first + last) / 2];

    //Sorts the vector
    while(left <= right)
    {
        while(vecToSort[left] < pivot)
        {
            ++left;
        }
        while(vecToSort[right] > pivot)
        {
            --right;
        }
        if(left <= right)
        {
            temp = vecToSort[left];
            vecToSort[left] = vecToSort[right];
            vecToSort[right] = temp;
            ++left;
            --right;
        }
    }

    if(first < right)
        QuickSort(vecToSort, first, right);
    if(left < last)
        QuickSort(vecToSort, left, last);
}

//With comparator
template <typename E, typename Comparator>
void QuickSort(QVector<E> &vecToSort, int first, int last, Comparator compare)
{
    if(first != last)
    {
        int left = first;
        int right = last;
        E temp;

        //Chooses the pivot
        int pivot = (first + last) / 2;
        ++left;

        //Sorts the vector
        while(left != right)
        {
            if(compare(vecToSort[left], vecToSort[pivot])) {
                ++left;
            }
            else {
                while( (left != right) && compare(vecToSort[pivot], vecToSort[right]) )
                {
                    --right;
                }
                //std::iter_swap(i, j);
                temp = vecToSort[left];
                vecToSort[left] = vecToSort[right];
                vecToSort[right] = temp;

            }// End else
        }// End while(left != right)

        --left;
        temp = vecToSort[left];
        vecToSort[left] = vecToSort[pivot];
        vecToSort[pivot] = temp;

        QuickSort(vecToSort, first, left, compare);
        QuickSort(vecToSort, right, last, compare);
    }
}


// Some code I found online...

//template< typename BidirectionalIterator, typename Compare >
//void quick_sort( BidirectionalIterator first, BidirectionalIterator last, Compare cmp ) {
//    if( first != last ) {
//        BidirectionalIterator left  = first;
//        BidirectionalIterator right = last;
//        BidirectionalIterator pivot = left++;

//        while( left != right ) {
//            if( cmp( *left, *pivot ) ) {
//                ++left;
//            } else {
//                while( (left != right) && cmp( *pivot, *right ) )
//                    --right;
//                std::iter_swap( left, right );
//            }
//        }

//        --left;
//        std::iter_swap( pivot, left );

//        quick_sort( first, left, cmp );
//        quick_sort( right, last, cmp );
//    }
//}

//template< typename BidirectionalIterator >
//    inline void quick_sort( BidirectionalIterator first, BidirectionalIterator last ) {
//        quick_sort( first, last,
//                std::less_equal< typename std::iterator_traits< BidirectionalIterator >::value_type >()
//                );
//    }



#endif // QUICKSORT_H
