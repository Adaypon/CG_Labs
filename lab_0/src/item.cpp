#include "item.hpp"

Item::Item(const std::vector<Point> &coords) :
    itemCoords(coords)
{
    std::cout << "[item] Constructed" << std::endl;
}

std::vector<Point> Item::getPoints()
{
    std::cout << "[item] getPoints()" << std::endl; 
    return std::vector<Point>();
}
