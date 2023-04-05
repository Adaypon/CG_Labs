#ifndef __ITEM_H__
#define __ITEM_H__

#include <iostream>
#include <vector>
#include <cmath>

#include "point.hpp"

/// @brief Абстрактный класс отображаемых примитивов
class Item 
{
public:
    /// @brief Конструктор
    /// @param coords координаты вершин
    /// @note Точки, не нужные для отображения примитива, будут проигнорированы
    Item(const std::vector<Point> &coords);
    virtual ~Item() {};
    
    /**
     * @brief Получить набор точек item'а.
     * @return Набор точек для отображения
     * 
     * @note  
     * Наследники либо реализуют алгоритм Брезенхема (линия, окружность) и возвращают результат работы, 
     * либо возвращают что-то свое (например, треугольник должен вернуть 3 линии, которые вернут набор точек)
     */
    virtual std::vector<Point> getPoints() = 0;

protected:
    /// @brief Координаты вершин
    std::vector<Point> itemCoords;
    
    /// @brief Координаты точек примитива (результат работы алгоритма Брезенхема)
    std::vector<Point> itemPoints;
};

#endif // __ITEM_H__