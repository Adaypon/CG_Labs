#ifndef __POINT_H__
#define __POINT_H__

/// @brief Точка
struct Point {
    Point(int x, int y, char symb = '.');
    int x;
    int y;
    char symb;
};

#endif // __POINT_H__