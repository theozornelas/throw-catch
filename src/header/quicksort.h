#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <functional>
#include <algorithm>
#include <iterator>

/**************
 * PROTOTYPES *
 **************/
//template <typename E>
//void QuickSort(QVector<E> &vecToSort, int first, int last);

//template <typename E, typename Comparator>
//void QuickSort(QVector<E> &vecToSort, int first, int last, Comparator compare);


/***************
 * DEFINITIONS *
 ***************/

// Performs a Quick Sort using the comparator passed in
template< typename Iterator, typename Compare >
void QuickSort( Iterator first, Iterator last, Compare compare ) {
    if(first != last) {
        Iterator left  = first;
        Iterator right = last;
        Iterator pivot = left++;

        while(left != right) {
            if( compare(*left, *pivot) ) {
                ++left;
            } else {
                while( (left != right) && compare( *pivot, *right ) )
                    --right;
                std::iter_swap( left, right );
            }
        }// End while(left != right)

        --left;
        std::iter_swap( pivot, left );

        QuickSort( first, left, compare );
        QuickSort( right, last, compare );
    }// End if(first != last)
}

// If a comparator isn't passed in, this sorts it from least to greatest
template< typename Iterator >
inline void QuickSort( Iterator first, Iterator last ) {
    QuickSort( first, last, std::less_equal< typename std::iterator_traits< Iterator >::value_type >() );
}



//Without comparator
//template <typename E>
//void QuickSort(QVector<E> &vecToSort, int first, int last)
//{
//    int left = first;
//    int right = last;
//    E temp;

//    //Chooses the pivot
//    E pivot = vecToSort[(first + last) / 2];

//    //Sorts the vector
//    while(left <= right)
//    {
//        while(vecToSort[left] < pivot)
//        {
//            ++left;
//        }
//        while(vecToSort[right] > pivot)
//        {
//            --right;
//        }
//        if(left <= right)
//        {
//            temp = vecToSort[left];
//            vecToSort[left] = vecToSort[right];
//            vecToSort[right] = temp;
//            ++left;
//            --right;
//        }
//    }

//    if(first < right)
//        QuickSort(vecToSort, first, right);
//    if(left < last)
//        QuickSort(vecToSort, left, last);
//}

//With comparator
//template <typename E, typename Comparator>
//void QuickSort(QVector<E> &vecToSort, int first, int last, Comparator compare)
//{
//    if(first != last)
//    {
//        int left = first;
//        int right = last;
//        E temp;

//        //Chooses the pivot
//        int pivot = (first + last) / 2;
//        ++left;

//        //Sorts the vector
//        while(left != right)
//        {
//            if(compare(vecToSort[left], vecToSort[pivot])) {
//                ++left;
//            }
//            else {
//                while( (left != right) && compare(vecToSort[pivot], vecToSort[right]) )
//                {
//                    --right;
//                }
//                //std::iter_swap(i, j);
//                temp = vecToSort[left];
//                vecToSort[left] = vecToSort[right];
//                vecToSort[right] = temp;

//            }// End else
//        }// End while(left != right)

//        --left;
//        temp = vecToSort[left];
//        vecToSort[left] = vecToSort[pivot];
//        vecToSort[pivot] = temp;

//        QuickSort(vecToSort, first, left, compare);
//        QuickSort(vecToSort, right, last, compare);
//    }
//}


#endif // QUICKSORT_H
