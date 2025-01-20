#include <game.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace hordes {

Game::Game()
{
    try
    {
        m_game_window = std::unique_ptr< sf::RenderWindow, window_deleter >(new sf::RenderWindow(m_video_mode, game_name, m_size_mode));
    }
    catch(...)
    {

    }
}

void Game::run()
{
    while(m_game_window->isOpen())
    {
        update_events();
    }
}

void Game::update_events()
{
    sf::Event event;
    while(m_game_window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_game_window->close();
            break;
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                m_game_window->close();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::window_deleter::operator()(sf::RenderWindow* ptr)
{
    if (ptr != nullptr)
        delete ptr;
}



} // namespace hordes
