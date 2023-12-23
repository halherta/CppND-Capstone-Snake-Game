#include "foods.h"

// AbstractFood()=delete;
AbstractFood::AbstractFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o) : grid_w(grid_width), grid_h(grid_height){
    _r = new int;
    _g = new int;
    _b = new int;
    _o = new int;
    *_r = r;
    *_g = g;
    *_b = b;
    *_o = o;
    
    RandomGen ra(grid_w, grid_h);
    food.x = ra.RandomWidth();
    food.y = ra.RandomHeight();
}

AbstractFood::~AbstractFood(){
    delete _r;
    delete _g;
    delete _b;
    delete _o;
}

AbstractFood::AbstractFood(std::size_t grid_width, std::size_t grid_height):grid_w(grid_width), grid_h(grid_height){
    *_r = 0xFF;
    *_g = 0xFF;
    *_b = 0xFF;
    *_o = 0xFF;
    RandomGen r(grid_w, grid_h);
    food.x = r.RandomWidth();
    food.y = r.RandomHeight();
}

void AbstractFood::setX(int x) { food.x = x; }
void AbstractFood::setY(int y) { food.y = y; }
void AbstractFood::setFoodCoord(int x, int y)
{
    food.x = x;
    food.y = y;
}
void AbstractFood::setColor(int r, int g, int b, int o)
{
    *_r = r;
    *_g = g;
    *_b = b;
    *_o = o;
}
int AbstractFood::getX() const { return food.x; }
int AbstractFood::getY() const { return food.y; }
int AbstractFood::getR() const { return *_r; }
int AbstractFood::getG() const { return *_g; }
int AbstractFood::getB() const { return *_b; }
int AbstractFood::getO() const { return *_o; }

void AbstractFood::CheckForFood(int x, int y,int &score, Snake &snake){std::cout << "testing\n";}

void AbstractFood::PlaceFoodItem(Snake &snake)
{
    int x, y;
    while (true)
    {
        RandomGen r(grid_w, grid_h);
        x = r.RandomWidth();
        y = r.RandomHeight();
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake.SnakeCell(x, y))
        {
            food.x = x;
            food.y = y;
            return;
        }
    }
}

BasicFood::BasicFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o) : AbstractFood(grid_width, grid_height, r, g, b, o) {}

BasicFood::BasicFood(std::size_t grid_width, std::size_t grid_height) : AbstractFood(grid_width, grid_height, 0xFF, 0xFF, 0x00, 0xFF) {} // yellow

void BasicFood::CheckForFood(int new_x, int new_y, int &score, Snake &snake)
{
    // Check if there's food over here
    if (food.x == new_x && food.y == new_y)
    {
        score++;
        PlaceFoodItem(snake);
        // Grow snake and increase speed.
        snake.GrowBody();
        snake.speed += 0.02;
    }
}

SuperFood::SuperFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o) : AbstractFood(grid_width, grid_height, r, g, b, o) {}

SuperFood::SuperFood(std::size_t grid_width, std::size_t grid_height) : AbstractFood(grid_width, grid_height, 0x00, 0xFF, 0x00, 0xFF) {} // green

void SuperFood::CheckForFood(int new_x, int new_y, int &score, Snake &snake)
{
    // Check if there's superfood over here
    if (food.x == new_x && food.y == new_y)
    {
        score += 2;
        PlaceFoodItem(snake);
        // Grow snake and increase speed.
        snake.GrowBody(2);
        snake.speed += 0.04;
    }
}

PoisonFood::PoisonFood(std::size_t grid_width, std::size_t grid_height, int r, int g, int b, int o) : AbstractFood(grid_width, grid_height, r, g, b, o) {}

PoisonFood::PoisonFood(std::size_t grid_width, std::size_t grid_height) : AbstractFood(grid_width, grid_height, 0xFF, 0x00, 0x00, 0xFF) {} // red

void PoisonFood::CheckForFood(int new_x, int new_y, int &score, Snake &snake)
{
    // Check if there's food over here
    if (food.x == new_x && food.y == new_y)
    {
        score--;
        PlaceFoodItem(snake);
        snake.isPoisoned = true;
        //std::thread poisonAction(&Snake::PoisonedTH, snake);
        //poisonAction.detach();
    }
}