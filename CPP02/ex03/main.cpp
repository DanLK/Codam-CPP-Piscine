#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

  std::cout << "-------------------Inside----------------------------" << std::endl;
  const Point a = Point(0.5f, 1.0f);
  const Point b = Point(2.5f, 3.0f);
  const Point c = Point(-1.0f, 2.0f);

  const Point point = Point(0.5f, 2.0f);
  
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;
  std::cout << "point: " << point << std::endl;

  std::cout << "Point in triangle ABC: " << bsp(a, b, c, point) << std::endl;

  std::cout << "------------------Outside (on edge)-----------------------------" << std::endl;

  const Point d = Point(-6.0f, -2.50f);
  const Point e = Point(-6.0f, 3.5f);
  const Point f = Point(-4.5f, 1.5f);

  const Point point2 = Point(-6.0f, 0.0f);
  
  std::cout << "d: " << d << std::endl;
  std::cout << "e: " << e << std::endl;
  std::cout << "f: " << f << std::endl;
  std::cout << "point: " << point2 << std::endl;

  std::cout << "Point in triangle DEF: " << bsp(d, e, f, point2) << std::endl;

  std::cout << "----------------Degenerate-------------------------------" << std::endl;

  const Point g = Point(0.0f, 0.0f);
  const Point h = Point(0.0f, 0.0f);
  const Point i = Point(0.0f, 0.0f);

  const Point point3 = Point(0.0f, 0.0f);
  
  std::cout << "g: " << g << std::endl;
  std::cout << "h: " << h << std::endl;
  std::cout << "i: " << i << std::endl;
  std::cout << "point: " << point3 << std::endl;

  std::cout << "Point in triangle GHI: " << bsp(g, h, i, point3) << std::endl;

  std::cout << "----------------Vertex-------------------------------" << std::endl;

  const Point j = Point(0.0f, 0.0f);
  const Point k = Point(2.0f, 1.0f);
  const Point l = Point(2.0f, -1.0f);

  const Point point4 = Point(2.0f, 1.0f);
  
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;
  std::cout << "l: " << l << std::endl;
  std::cout << "point: " << point4 << std::endl;

  std::cout << "Point in triangle JKL: " << bsp(j, k, l, point4) << std::endl;

  return 0;

}