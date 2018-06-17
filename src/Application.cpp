#include "Application.h"
#include "Display.h"

#include "Playing.h"

Application::Application()
{
  pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{
  while (Display::isOpen())
  {
    Display::clear();
    Display::update();

    m_states.top()->input();
    m_states.top()->update();
    m_states.top()->draw();

    Display::checkForClose();
  }
}

void Application::pushState(std::unique_ptr<State::GameState> state)
{
  m_states.push(std::move(state)); //needed because its a unique ptr
}

void Application::popState()
{
  m_states.pop();
}
