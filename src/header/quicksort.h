#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <functional>
#include <algorithm>
#include <iterator>

/**
 * @brief Performs a quicksort on the data between the first and last iterators using the comparator specified
 * @param first [IN] The beginning iterator of the structure to sort
 * @param last [IN] The last iterator of the structure to sort
 * @param compare [IN] A comparator to perform the sort with
 */
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

/**
 * @brief Performs a quicksort on the data between the first and last iterators, sorting from least to greatest
 * @param first [IN] The beginning iterator of the structure to sort
 * @param last [IN] The last iterator of the structure to sort
 */
template< typename Iterator >
inline void QuickSort( Iterator first, Iterator last ) {
    QuickSort( first, last, std::less_equal< typename std::iterator_traits< Iterator >::value_type >() );
}



#endif // QUICKSORT_H
