#include "Display.h"

#include <memory>
#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace Display
{
  constexpr static int WIDTH = 1280;
  constexpr static int HEIGHT = 800;

  std::unique_ptr<sf::RenderWindow> window;

  void init()
  {
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.majorVersion = 4;
    settings.minorVersion = 5; //OpenGL 4.5
    settings.attributeFlags = sf::ContextSettings::Attribute::Core;

    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT), "Window", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, WIDTH, HEIGHT);


  }

  void close()
  {
    window->close();
  }

  void clear()
  {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  }

  void update()
  {
    window->display();
  }

  void checkForClose()
  {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        close();
      }
    }
  }

  bool isOpen()
  {
    return window->isOpen();
  }
}
