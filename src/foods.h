#pragma once

#include <random>
#include <cstddef>
#include <iostream>

#include "SDL.h"
#include "snake.h"
#include "random_gen.h"

class AbstractFood{
    public:
    //AbstractFood()=delete;
    AbstractFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o);
    AbstractFood(std::size_t grid_width, std::size_t grid_height);
    ~AbstractFood();
    void setX(int x);
    void setY(int y);
    void setFoodCoord(int x, int y);
    void setColor(int r, int g, int b, int o);
    int getX() const ;
    int getY() const ;
    int getR() const ;
    int getG() const ;
    int getB() const ;
    int getO() const ;

    void PlaceFoodItem(Snake &snake);

    virtual void CheckForFood(int x, int y,int &score, Snake &snake);

   
    protected:
        int *_r, *_g, *_b, *_o;
        SDL_Point food;
        std::size_t grid_w, grid_h;
};

class BasicFood: public AbstractFood{
    public:
    //BasicFood()=delete;
    BasicFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o);

    BasicFood(std::size_t grid_width, std::size_t grid_height);

    void CheckForFood(int new_x, int new_y, int &score, Snake &snake);
};


class SuperFood: public AbstractFood{
    public:
    //SuperFood()=delete;
    SuperFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o);

    SuperFood(std::size_t grid_width, std::size_t grid_height);

    void CheckForFood(int new_x, int new_y, int &score, Snake &snake);
};

class PoisonFood: public AbstractFood{
    public:
    //PoisonFood()=delete;
    PoisonFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o);

    PoisonFood(std::size_t grid_width, std::size_t grid_height);

    void CheckForFood(int new_x, int new_y, int &score, Snake &snake);
};