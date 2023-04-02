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

// TODO вынести в отдельные классы

/*
struct Point {
    size_t x;
    size_t y;

    char symb;  // символ для отрисовки
};


class Line : public Item
{
public: 
    Line(const std::vector<Point> &coords) : Item(coords) {
        
    }

    std::vector<Point> getPoints() override; 

};

class Circle : public Item
{
public: 
    Circle(const std::vector<Point> &coords) : Item(coords) {
        
    }

    std::vector<Point> getPoints() override; 
};

class Triangle : public Item
{
public: 
    Triangle(const std::vector<Point> &coords) : Item(coords) {
        
    }

    std::vector<Point> getPoints() override; // проверить, что можно треугольник сделать

private:
    std::vector<Line> lines;
};
*/

#endif // __ITEM_H__