#include "game.h"
#include "foods.h"
#include <iostream>
#include "SDL.h"
#include <algorithm>

Game::Game(std::size_t grid_width, std::size_t grid_height, std::string pname)
    : snake(grid_width, grid_height){
      playername = pname;
      foods.push_back(std::make_shared<BasicFood>(grid_width, grid_height));
      foods.push_back(std::make_shared<SuperFood>(grid_width, grid_height));
      foods.push_back(std::make_shared<PoisonFood>(grid_width, grid_height));

}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration ) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, foods);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, GetName());
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


void Game::Update() {
  if (!snake.alive) {
    std::ofstream myfile("hiscore.log", std::ios_base::app);
    myfile << "Player name: " << GetName() <<"\n";
    myfile << "Player score: " << GetScore() <<"\n";
    myfile << "Player size: " << GetSize() <<"\n";
    myfile.close();

    std::string msgText{"Score: " + std::to_string(GetScore()) + "\n Size: " + std::to_string(GetSize())};
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "You died!", msgText.c_str(), NULL);
    return;
  }

   if(snake.isPoisoned){
    std::future<void> f = std::async( &Game::PoisonedTH, this);
    f.get();

   }

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  for(auto  &food: foods){
    food->CheckForFood(new_x, new_y, score, snake);
  }

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
std::string Game::GetName() const{return playername;}


void Game::PoisonedTH(void)
{
  std::lock_guard<std::mutex> lock{mtx};

  std::cout << "Got Poisoned!!! at coord (" << snake.head_x <<", " << snake.head_y <<")" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Survived!" << std::endl;
  snake.isPoisoned = false;
}