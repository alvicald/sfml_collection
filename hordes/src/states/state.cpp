#include <states/state.h>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace hordes {

State::State(sf::RenderWindow& rw):
    m_main_window(rw)
{}

void State::check_for_quit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_quit = true;
}

bool State::getQuit() const
{
    return m_quit;
}

} // namespace hordes
