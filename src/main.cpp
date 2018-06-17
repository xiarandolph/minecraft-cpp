#include "Display.h"

int main(int argc, char* argv[])
{
  Display::init();

  while (Display::isOpen())
  {
    Display::clear();
    Display::update();

    Display::checkForClose();
  }

  return 0;
}
