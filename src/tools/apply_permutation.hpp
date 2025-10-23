#ifndef NJOY_TOOLS_APPLYPERMUTATION
#define NJOY_TOOLS_APPLYPERMUTATION

// system includes

// other includes

namespace njoy {
namespace tools {

  /**
   *  @brief Apply a permutation on a given range
   *
   *  This code was adopted from the boost algorithm library.
   *
   *  Note: the range of indices is modified as well so this range cannot
   *        be reused.
   *
   *  @param[in] begin    the iterator to the start of the range
   *  @param[in] end      the iterator to the end of the range
   *  @param[in] pbegin   the iterator to the permutation range
   */
  template< typename Iterator, typename PIterator >
  void apply_permutation( Iterator begin, const Iterator end, PIterator pbegin ) {

    using difference_type = typename std::iterator_traits< PIterator >::value_type;

    difference_type size = std::distance( begin, end );

    for ( difference_type i = 0; i < size; ++i ) {

      difference_type current = i;
      while ( i != pbegin[ current ] ) {

        difference_type next = pbegin[ current ];
        std::swap( begin[ current ], begin[ next ] );
        pbegin[ current ] = current;
        current = next;
      }
      pbegin[ current ] = current;
    }
  }

  /**
   *  @brief Apply a permutation on a given range
   *
   *  This code was adopted from the boost algorithm library.
   *
   *  Note: the range of indices is modified as well so this range cannot
   *        be reused.
   *
   *  @param[in] values    the range of values
   *  @param[in] indices   the permutation range
   */
  template< typename Range, typename PRange >
  void apply_permutation( Range& values, PRange& indices ) {

    apply_permutation( std::begin( values ), std::end( values ), std::begin( indices ) );
  }

} // tools namespace
} // njoy namespace

#endif
