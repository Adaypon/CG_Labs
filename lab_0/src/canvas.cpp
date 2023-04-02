#include "canvas.hpp"

Canvas::Canvas(size_t cols, size_t rows) :
    cols(cols), rows(rows)
{
    std::cout << "[canvas] Constructed" << std::endl;
    std::cout << "[canvas] Created canvas: rows = " << this->rows << " cols = " << this->cols << std::endl;
}

void Canvas::draw() {
    std::cout << "[canvas] Drawing next picture..." << std::endl;
    for (auto picture : pictures) {
        picture.generatePicture();
        for (auto strLine : picture.getPicture()) {
            std::cout << strLine << "\n";
        }
    }
}

void Canvas::clear() {
    std::cout << "[canvas] Clear canvas" << std::endl;
    // TODO cls
}

size_t Canvas::rowsCount() const {
    return this->rows;
}

size_t Canvas::colsCount() const {
    return this->cols;
}

void Canvas::addPicture(Picture pic) {
    pictures.push_back(pic);
}