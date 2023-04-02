#include "circle.hpp"

Circle::Circle(const std::vector<Point> &coords, const int radius) : 
    Item(coords), radius(radius)
{
    std::cout << "[circle] Constructed" << std::endl;
    std::cout << "[circle] Coords: (" 
                << coords[0].x << ", " 
                << coords[0].y << ") "
                << "r = " << radius << std::endl;
}

std::vector<Point> Circle::calcBresenhamCircleAlgorithm(const Point p0, const int radius) {
    std::vector<Point> res;
    int x = 0;
    int y = radius;
    int delta = 1 - 2 * radius;
    int error = 0;

    while (y >= x) {
        res.push_back({p0.x + x, p0.y + y});
        res.push_back({p0.x + x, p0.y - y});
        res.push_back({p0.x - x, p0.y + y});
        res.push_back({p0.x - x, p0.y - y});
        
        res.push_back({p0.x + y, p0.y + x});
        res.push_back({p0.x + y, p0.y - x});
        res.push_back({p0.x - y, p0.y + x});
        res.push_back({p0.x - y, p0.y - x});

        error = 2 * (delta + y) - 1;
        if (delta < 0 && error <= 0) {
            delta += 2 * ++x + 1;
            continue;
        }
        if (delta < 0 && error > 0) {
            delta -= 2 * --y + 1;
            continue;
        }
        delta += 2 * (++x - --y);
    }

    return res;
}

std::vector<Point> Circle::getPoints()
{
    std::cout << "[circle] getPoints()" << std::endl;
    itemPoints = calcBresenhamCircleAlgorithm(itemCoords[0], radius);
    return itemPoints;
}
