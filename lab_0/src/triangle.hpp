#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "item.hpp"
#include "line.hpp"

/// @brief Класс треугольника
class Triangle : public Item
{
public:
    Triangle(const std::vector<Point> &coords);
    ~Triangle() {};

    // TODO Перенести в класс Line
    /// @brief Вычислить длину отрезка между двумя точками
    /// @param p0 (x0, y0)
    /// @param p1 (x1, y1)
    /// @return Длина отрезка
    double calcLength(Point p0, Point p1);
    
    /// @brief Проверка, что треугольник валиден (сумма трех сторон больше третьей)
    /// @return true, если треугльник валидный
    bool isValid();

    std::vector<Point> getPoints() override;

private:
    /// @brief Вектор линий треугольника
    std::vector<Line> sideLines;
};

#endif // __TRIANGLE_H__