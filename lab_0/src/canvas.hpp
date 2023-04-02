#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "picture.hpp"

// TODO Сделать в виде абстрактного класса и реализовать CanvasTerminal, CanvasFile, CanvasOpenGL(?)

/// @brief Базовый класс холста
class Canvas {
public:
    /// @brief Конструктор
    /// @param cols число столбцов
    /// @param rows число строк
    Canvas(size_t cols, size_t rows);
    ~Canvas() {};

    /// @brief Отобразить изображение на холст
    void draw();
    // virtual void draw() = 0;    // отображаем картинки, возможно по таймеру, если pictures.size() > 1

    /// @brief Очистить холст 
    void clear();
    // virtual void clear() = 0;

    /**
     * @brief Получить количество строк пикселей
     * @return Количество строк пикселей
     */
    size_t rowsCount() const;
    
    /**
     * @brief Получить количество столбцов пикселей
     * @return Количество столбцов пикселей
     */
    size_t colsCount() const;

    /// @brief Добавить изображение
    /// @param pic изображение
    void addPicture(Picture pic);

private:
    /// @brief Число строк канваса
    size_t rows;
    
    /// @brief Число столбцов канваса
    size_t cols;
    
    /// @brief Вектор изображений
    std::vector<Picture> pictures;
};

#endif // __CANVAS_H__