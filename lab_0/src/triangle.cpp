#include "triangle.hpp"

Triangle::Triangle(const std::vector<Point> &coords) : 
    Item(coords)
{
    std::cout << "[triangle] Constructed" << std::endl;
    std::cout << "[triangle] Coords: ";
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "(" << coords[i].x << ", " << coords[i].y << ") ";        
    }
    std::cout << std::endl;

    Line sideA({coords[0], coords[1]});
    Line sideB({coords[1], coords[2]});
    Line sideC({coords[2], coords[0]});

    sideLines.push_back(sideA);
    sideLines.push_back(sideB);
    sideLines.push_back(sideC);
}

double Triangle::calcLength(Point p0, Point p1)
{
    return sqrt(pow(p1.x - p0.x, 2) + pow(p1.y - p0.y, 2));
}

bool Triangle::isValid()
{
    bool validFlag = false;
    double lengthA = calcLength(itemCoords[0], itemCoords[1]);
    double lengthB = calcLength(itemCoords[1], itemCoords[2]);
    double lengthC = calcLength(itemCoords[2], itemCoords[0]);

    validFlag = lengthA + lengthB > lengthC && 
                lengthA + lengthC > lengthB && 
                lengthB + lengthC > lengthA;
    
    return validFlag;
}

std::vector<Point> Triangle::getPoints()
{
    if (!isValid()) {
        std::cerr << "[triangle] triangle coords are not valid" << std::endl;
    }
    else {
        for (auto side : sideLines) {
            auto tmp = side.getPoints().size();
            int a = 10;
            for (auto sidePoint : side.getPoints()) {
                itemPoints.push_back(sidePoint);
            }
        }
    }
    return itemPoints;
}