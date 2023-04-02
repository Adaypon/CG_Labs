#include "line.hpp"

Line::Line(const std::vector<Point> &coords) : Item(coords)
{
    std::cout << "[line] Constructed" << std::endl;
    std::cout << "[line] Coords: ";
    for (auto coord : itemCoords) {
        std::cout << "(" << coord.x << ", " << coord.y << ") ";
    }
    std::cout << std::endl;
}

std::vector<Point> Line::calcBresenhamLineAlgorithm(const Point p0, const Point p1) {
    std::vector<Point> res;
    Point p = p0;

    int dx = abs(p1.x - p0.x);
    int sx = p0.x < p1.x ? 1 : -1;
    int dy = -abs(p1.y - p0.y);
    int sy = p0.y < p1.y ? 1 : -1;
    int error = dx + dy;

    while (true) {
        res.push_back(p);
        if (p.x == p1.x && p.y == p1.y) {
            break;
        }

        int e2 = 2 * error;
        if (e2 >= dy) {
            if (p.x == p1.x) {
                break;
            }
            error += dy;
            p.x += sx;
        }
        if (e2 <= dx) {
            if (p.y == p1.y) {
                break;
            }
            error += dx;
            p.y += sy;
        }
    }
    return res;
}

std::vector<Point> Line::getPoints()
{
    std::cout << "[line] getPoints()" << std::endl;
    itemPoints = calcBresenhamLineAlgorithm(itemCoords[0], itemCoords[1]);
    return itemPoints;
}
