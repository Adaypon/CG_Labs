#include "picture.hpp"

Picture::Picture(size_t cols, size_t rows) :
    cols(cols), rows(rows)
{
    picture.resize(rows);
    for (size_t row = 0; row < rows; ++row) {
        picture[row].resize(cols, ' ');
    }
}

void Picture::generatePicture() {
    std::cout << "[picture] Generating picture from added items" << std::endl;
    for (auto item : items) {
        for (auto coord : item->getPoints()) {
            if (coord.x < cols && coord.y < rows) {
                picture[coord.y][coord.x] = coord.symb;
            }
        }
    }
}

void Picture::addItem(Item* item) {
    items.push_back(item);
    std::cout << "[picture] Added item" << std::endl;
}

std::vector<std::string> Picture::getPicture() {
    return picture;
}