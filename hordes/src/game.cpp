#include <iostream>

#include <game.h>
#include <conf.h>
#include <entities/hero.h>
#include <states/game_state.h>

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

} // namespace

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

        init_states();
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

Game::~Game()
{
    while (!m_state_stack.empty())
        m_state_stack.pop();
}

void Game::run()
{
    while (m_game_window->isOpen())
    {
        updateDt();
        update();
        render();
    }
}

void Game::init_states()
{
    m_state_stack.push(std::make_unique< GameState >(*m_game_window));
}

void Game::update_events()
{
    sf::Event event;
    while (m_game_window->pollEvent(event))
    {

    }
}


void Game::render()
{
    m_game_window->clear();

    if (!m_state_stack.empty())
        m_state_stack.top()->render(*m_game_window);

    m_game_window->draw(*m_statistic_text);
    m_game_window->display();
}

void Game::update()
{
    update_events();

    if (!m_state_stack.empty())
    {
        m_state_stack.top()->update(m_dt);

        if (m_state_stack.top()->getQuit())
        {
            m_state_stack.top()->end_state();
            m_state_stack.pop();
        }
    }
    else
        m_game_window->close();
}

void Game::updateDt()
{
    m_dt = m_clock.restart().asSeconds();
    m_statistic_text->setString(std::to_string(m_dt));
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
