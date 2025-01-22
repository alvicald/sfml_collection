#include <iostream>

#include <game.h>
#include <conf.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Sleep.hpp>

namespace {

template < typename T >
void free_sf_object(T* ptr)
{
    if (ptr != nullptr)
        delete ptr;
}

}

namespace hordes {

sf::Time const TimePerFrame { sf::seconds(1.f / 60.f) };

Game::Game()
{
    try
    {
        m_game_window = std::unique_ptr< sf::RenderWindow, window_deleter >(new sf::RenderWindow(m_video_mode, game_name, m_size_mode));
        m_statistic_text = std::unique_ptr< sf::Text, text_deleter >(new sf::Text);

        if (m_statistic_text)
        {
            m_font = std::unique_ptr< sf::Font, font_deleter >(new sf::Font);
            if (m_font)
            {
                if (!m_font->loadFromFile(RESOURCE_DIR"/fonts/letseat.TTF"))
                    throw std::runtime_error("Cant load font.");
            }
            else
                throw std::runtime_error("Font pointer is null.");

            m_statistic_text->setFont(*m_font);
            m_statistic_text->setCharacterSize(20);
            m_statistic_text->setFillColor({255, 255, 255});
            m_statistic_text->setPosition(5, 5);
        }
        else
            throw std::runtime_error("Text pointer is null");

    }
    catch (std::bad_alloc& e)
    {
        std::cout << e.what() << '\n';
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void Game::run()
{
    sf::Clock clock;
    sf::Time game_working_time { sf::Time::Zero };
    std::uint32_t frame_count { 0 };

    while (m_game_window->isOpen())
    {
        sf::Time iter_work_time = clock.restart();

        update_events();

        update_statistic(iter_work_time, game_working_time, frame_count);
        render();

        sf::Time sleepTime = TimePerFrame - clock.getElapsedTime();
        if (sleepTime > sf::Time::Zero)
            sf::sleep(sleepTime);
    }
}

void Game::update_events()
{
    sf::Event event;
    while (m_game_window->pollEvent(event))
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


void Game::render()
{
    m_game_window->clear();
    m_game_window->draw(*m_statistic_text);
    m_game_window->display();
}

void Game::update_statistic(sf::Time const& time,
                            sf::Time& game_working_time,
                            std::uint32_t& frame_count)
{
    game_working_time += time;
    frame_count += 1;

    if (game_working_time >= sf::seconds(1.f))
    {
        m_statistic_text->setString("FPS: " + std::to_string(frame_count));
        game_working_time -= sf::seconds(1.0f);
        frame_count = 0;
    }
}

void Game::window_deleter::operator()(sf::RenderWindow* ptr)
{
    free_sf_object(ptr);
}

void Game::text_deleter::operator()(sf::Text* ptr)
{
    free_sf_object(ptr);
}

void Game::font_deleter::operator()(sf::Font* ptr)
{
    free_sf_object(ptr);
}



} // namespace hordes
