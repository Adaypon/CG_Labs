#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "item.hpp"

/// @brief Класс окружности
class Circle : public Item
{
public: 
    Circle(const std::vector<Point> &coords, const int radius);
    ~Circle() {};

    /// @brief Реализация алгоритма Брезенхэма для отрисовки окружности по точке цетра и радиусу
    /// @param p0 (x0, y0)
    /// @param radius радиус окружности
    /// @return Вектор точек растеризации окружности
    /// @note https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    /// @note https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%91%D1%80%D0%B5%D0%B7%D0%B5%D0%BD%D1%85%D1%8D%D0%BC%D0%B0#%D0%A0%D0%B8%D1%81%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%BE%D0%BA%D1%80%D1%83%D0%B6%D0%BD%D0%BE%D1%81%D1%82%D0%B5%D0%B9
    std::vector<Point> calcBresenhamCircleAlgorithm(const Point p0, const int radius);
    
    std::vector<Point> getPoints() override; 

private:
    int radius;
};

#endif // __CIRCLE_H__