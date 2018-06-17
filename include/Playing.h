#ifndef PLAYING_H
#define PLAYING_H

#include "GameState.h"

class Application;

namespace State
{
  class Playing : public GameState
  {
  public:
    Playing(Application& application);

    void input  () override;
    void update () override;
    void draw   () override;
  };
}

#endif
