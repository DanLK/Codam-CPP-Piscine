#include "Fixed.hpp"

// int main( void ) {
  
//   Fixed a = Fixed(5.6f);
//   Fixed b = Fixed(2.7f);
  
//   std::cout << "--------------LOGICAL---OPERATORS-------------" << std::endl;
  
//   std::cout << "a is " << a << std::endl;
//   std::cout << "b is " << b << std::endl;
//   std::cout << "a > b: " << (a > b) << std::endl;
//   std::cout << "a < b: " << (a < b) << std::endl;
//   std::cout << "b >= a: " << (b >= a) << std::endl;
//   std::cout << "b <= b: " << (b <= b) << std::endl;
//   std::cout << "a == a: " << (a == a) << std::endl;
//   std::cout << "a != b: " << (a != b) << std::endl;

//   std::cout << "------------ARITHMETIC---OPERATORS-------------" << std::endl;

//   std::cout << "a + b: " << a + b << std::endl;
//   std::cout << "a - b: " << a - b << std::endl;
//   std::cout << "a * b: " << a * b << std::endl;
//   std::cout << "a / b: " << a / b << std::endl;

//   std::cout << "------INCREMENT/DECREMENT---OPERATORS---------" << std::endl;

//   std::cout << "a: " << a << std::endl;
//   std::cout << "++a: " << ++a << std::endl;
//   std::cout << "a: " << a << std::endl;
//   std::cout << "a++: " << a++ << std::endl;
//   std::cout << "a: " << a << std::endl << std::endl;

//   Fixed c = Fixed(-3.5f);

//   std::cout << "c: " << c << std::endl;
//   std::cout << "--c: " << --c << std::endl;
//   std::cout << "c: " << c << std::endl;
//   std::cout << "c--: " << c-- << std::endl;
//   std::cout << "c: " << c << std::endl;

//   std::cout << "-------------MIN/MAX---FUNCTIONS------------" << std::endl;

//   Fixed const d( Fixed( 5.05f ) * Fixed( 2 ) );

//   std::cout << "a: " << a << std::endl;
//   std::cout << "d: " << d << std::endl;
//   std::cout << "min(a, a): " << Fixed::min( a, a ) << std::endl;
//   std::cout << "max(a, a): " << Fixed::max( a, a ) << std::endl;
//   std::cout << "min(a, d): " << Fixed::min( a, d ) << std::endl;
//   std::cout << "max(a, d): " << Fixed::max( a, d ) << std::endl;

//   std::cout << "------------------END--------------------------" << std::endl;
//   return 0;

// }

int main( void ) {

  Fixed a;
  Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
  
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max( a, b ) << std::endl;

  return 0;

}
