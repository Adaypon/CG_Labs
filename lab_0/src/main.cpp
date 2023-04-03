#include <iostream>

#include "canvas.hpp"


int main() {
    Canvas canvas{100, 30};
    Picture pic1(canvas.colsCount(), canvas.rowsCount());
    
    Line line{{{1, 5}, {78, 19}}};
    pic1.addItem(&line);
    
    Circle c({{50, 10}}, 8);
    pic1.addItem(&c);

    Triangle t({{0, 0}, {25, 0}, {0, 16}});
    pic1.addItem(&t);
    
    canvas.addPicture(pic1);
    canvas.draw();
    canvas.clear();
    return 0;
}