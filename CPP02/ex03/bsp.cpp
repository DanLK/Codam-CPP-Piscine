#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {

  //Cross product AB x AP
  Fixed crossAB_AP;
  Fixed crossBC_BP;
  Fixed crossCA_CP;

  crossAB_AP = (b.getX() - a.getX()) * (point.getY()- a.getY()) -
            (b.getY() - a.getY()) * (point.getX()- a.getX());
  crossBC_BP = (c.getX() - b.getX()) * (point.getY()- b.getY()) -
            (c.getY() - b.getY()) * (point.getX()- b.getX());
  crossCA_CP = (a.getX() - c.getX()) * (point.getY()- c.getY()) -
            (a.getY() - c.getY()) * (point.getX()- c.getX());

  Fixed zero = Fixed(0);

  if (crossAB_AP > zero) {
    if (crossBC_BP < zero || crossCA_CP < zero)
      return false;
  }
  if (crossAB_AP < zero) {
    if (crossBC_BP > zero || crossCA_CP > zero)
      return false;
  }
  if (crossAB_AP == zero || crossBC_BP == zero || crossCA_CP == 0)
    return true;

  return true;
  
}