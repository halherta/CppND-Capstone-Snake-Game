#include "snake.h"
#include <cmath>
#include <iostream>


Snake::Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}


void Snake::Update()
{
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    UpdateBody(current_cell, prev_cell);
  }

}

void Snake::UpdateHead()
{
  switch (direction)
  {
  case Direction::kUp:
    head_y -= speed;
    break;

  case Direction::kDown:
    head_y += speed;
    break;

  case Direction::kLeft:
    head_x -= speed;
    break;

  case Direction::kRight:
    head_x += speed;
    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing)
  {
    // Remove the tail from the vector.
    body.erase(body.begin());
  }
  else
  {
    growing = false;
    size += grow_by;
    if (grow_by > 1)
    {
      //std::cout << "prev x " << prev_head_cell.x << " prev y " << prev_head_cell.y << " curr x " << current_head_cell.x << " curr y " << current_head_cell.y << std::endl;
      prev_head_cell.x = current_head_cell.x;
      prev_head_cell.y = current_head_cell.y;
      //std::cout << "head_x :" << head_x << " head_y: " << head_y << std::endl;
      switch (direction)
      {
      case Direction::kUp:
        current_head_cell.y--;
        break;

      case Direction::kDown:
        current_head_cell.y++;
        break;

      case Direction::kLeft:
        current_head_cell.x--;
        break;

      case Direction::kRight:
        current_head_cell.x++;
        break;
      }
      //std::cout << "head_x :" << head_x << " head_y: " << head_y << std::endl;
      head_x = current_head_cell.x;
      head_y = current_head_cell.y;
      //std::cout << "prev x " << prev_head_cell.x << " prev y " << prev_head_cell.y << " curr x " << current_head_cell.x << " curr y " << current_head_cell.y << std::endl;
      body.push_back(prev_head_cell);
      //for (auto &body_cell : body)
      //{
      //  std::cout << "body x: " << body_cell.x << " body y: " << body_cell.y << std::endl;
      //}
    }
  }

  // Check if the snake has died.
  for (auto const &item : body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      alive = false;
    }
  }
}

void Snake::GrowBody(int num)
{
  growing = true;
  grow_by = num;
}

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}

