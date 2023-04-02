#include <iostream>

#include "canvas.hpp"


int main() {
    Canvas canvas{100, 20};
    Picture pic1(canvas.colsCount(), canvas.rowsCount());
    
    Line line{{{1, 5}, {78, 19}}};
    pic1.addItem(&line);
    
    Circle c({{50, 10}}, 8);
    pic1.addItem(&c);
    
    canvas.addPicture(pic1);
    canvas.draw();
    canvas.clear();
    return 0;
}