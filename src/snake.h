#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <thread>
#include "SDL.h"

enum class Direction { kUp, kDown, kLeft, kRight };

class Snake {
 public:
  

  Snake(int grid_width, int grid_height);
  void Update();

  void GrowBody(int n=1);
  bool SnakeCell(int x, int y);
  Direction direction = Direction::kUp;

  bool isPoisoned{false};
  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  float grow_by{1};
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;

};

#endif