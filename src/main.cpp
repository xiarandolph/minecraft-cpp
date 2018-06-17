#include "Display.h"
#include "Application.h"


int main(int argc, char* argv[])
{
  Display::init();

  Application app;

  app.runMainGameLoop();
  
  return 0;
}
