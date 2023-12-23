#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include <memory>
#include "SDL.h"
#include "snake.h"
#include "foods.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, std::vector<std::shared_ptr<AbstractFood>> foods);
  void UpdateWindowTitle(int score, int fps, std::string playername);
  SDL_Window* GetWindow() {return  sdl_window;}
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif