/*--------------------------------------------------------------------------*\
 |                                                                          |
 |  Copyright (C) 2017                                                      |
 |                                                                          |
 |         , __                 , __                                        |
 |        /|/  \               /|/  \                                       |
 |         | __/ _   ,_         | __/ _   ,_                                | 
 |         |   \|/  /  |  |   | |   \|/  /  |  |   |                        |
 |         |(__/|__/   |_/ \_/|/|(__/|__/   |_/ \_/|/                       |
 |                           /|                   /|                        |
 |                           \|                   \|                        |
 |                                                                          |
 |      Enrico Bertolazzi                                                   |
 |      Dipartimento di Ingegneria Industriale                              |
 |      Universita` degli Studi di Trento                                   |
 |      email: enrico.bertolazzi@unitn.it                                   |
 |                                                                          |
\*--------------------------------------------------------------------------*/

///
/// file: G2lib.hh
///

#ifndef G2LIB_HH
#define G2LIB_HH

#include <iostream>
#include <cmath>
#include <sstream>
#include <stdexcept>

#ifndef G2LIB_ASSERT
  #define G2LIB_ASSERT(COND,MSG)         \
    if ( !(COND) ) {                        \
      std::ostringstream ost ;              \
      ost << "On line: " << __LINE__        \
          << " file: " << __FILE__          \
          << '\n' << MSG << '\n' ;          \
      throw std::runtime_error(ost.str()) ; \
    }
#endif

//! Clothoid computations routine
namespace G2lib {

  typedef double valueType ;
  typedef int    indexType ;

  /*
  // sin(x)/x
  */
  valueType Sinc( valueType x );
  valueType Sinc_D( valueType x );
  valueType Sinc_DD( valueType x );
  valueType Sinc_DDD( valueType x );

  /*
  // (1-cos(x))/x
  */
  valueType Cosc( valueType x );
  valueType Cosc_D( valueType x );
  valueType Cosc_DD( valueType x );
  valueType Cosc_DDD( valueType x );

  //! Add or remove multiple of \f$ 2\pi \f$ to an angle  in order to put it in the range \f$ [-\pi,\pi]\f$.
  void rangeSymm( valueType & ang ) ;

  /*\
   |   ____        _           ____       ____
   |  / ___|  ___ | |_   _____|___ \__  _|___ \
   |  \___ \ / _ \| \ \ / / _ \ __) \ \/ / __) |
   |   ___) | (_) | |\ V /  __// __/ >  < / __/
   |  |____/ \___/|_| \_/ \___|_____/_/\_\_____|
  \*/

  class Solve2x2 {
    indexType i[2], j[2] ;
    valueType LU[2][2] ;
    valueType epsi ;
    bool      singular ;

  public:
  
    Solve2x2() : epsi(1e-10) {}
    bool factorize( valueType A[2][2] ) ;
    bool solve( valueType const b[2], valueType x[2] ) const ;
  } ;

}

#endif

///
/// eof: G2lib.hh
///
