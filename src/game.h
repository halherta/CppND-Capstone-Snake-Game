#ifndef GAME_H
#define GAME_H

#include <random>
#include <string>
#include <vector>
#include <foods.h>
#include <memory>
#include <thread>
#include <future>
#include <mutex>
#include <fstream>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height,std::string pname="Player");
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  std::string GetName() const;
  void PoisonedTH(void);
  
 private:
  Snake snake;
  std::string playername;
  int score{0};
  std::vector<std::shared_ptr<AbstractFood>> foods; 
  std::mutex mtx; 
  void Update();
};

#endif