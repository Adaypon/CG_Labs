#ifndef __PICTURE_H__
#define __PICTURE_H__

#include <iostream>
#include <vector>
#include <string>

#include "point.hpp"
#include "item.hpp"
#include "line.hpp"
#include "circle.hpp"

class Canvas;

/// @brief Класс изображения
class Picture {
public:
    /// @brief Конструктор
    /// @param cols число столбцов
    /// @param rows число строк 
    Picture(size_t cols, size_t rows);
    ~Picture() {};

    /// @brief Добавить item для отображения
    /// @param item отображаемый примитив
    void addItem(Item* item);

    /// @brief Сгенерировать изображение из добавленных item'ов
    void generatePicture();

    /// @brief Получить готовое изображение
    /// @return Изображение для отображения холст
    std::vector<std::string> getPicture();

private:
	/// @brief Вектор item'ов
	std::vector<Item*> items;
    /// @brief Матрица "пикселей" (вектор строк)
    std::vector<std::string> picture;

    /// @brief Число строк изображения
    size_t rows;
    
    /// @brief Число столбцов изображения
    size_t cols;
};

#endif // __PICTURE_H__