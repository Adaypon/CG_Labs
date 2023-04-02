#ifndef __LINE_H__
#define __LINE_H__

#include "item.hpp"

/// @brief Класс линии
class Line : public Item
{
public: 
    Line(const std::vector<Point> &coords);
    ~Line() {};

    /// @brief Реализация алгоритма Брезенхэма для отрисовки линии по двум заданным точкам
    /// @param p0 (x0, y0)
    /// @param p1 (x1, y1)
    /// @return Вектор точек растеризации линии
    /// @note https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    std::vector<Point> calcBresenhamLineAlgorithm(const Point p0, const Point p1);
    
    std::vector<Point> getPoints() override; 
};

#endif // __LINE_H__