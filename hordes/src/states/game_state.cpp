#include <iostream>

#include <states/game_state.h>
#include <entities/hero.h>

#include <SFML/Graphics/RenderWindow.hpp>

namespace hordes {

GameState::GameState(sf::RenderWindow& rw):
    State(rw),
    m_hero(std::make_unique< Hero >())
{}

void GameState::update_keybinds(float dt)
{
    check_for_quit();
}

void GameState::update(float dt)
{
    update_keybinds(dt);
    m_hero->update(dt);
}

void GameState::render(sf::RenderTarget &rt)
{
    m_hero->render(m_main_window);
}

void GameState::end_state()
{
    std::cout << "Ending GameState!\n";
}

} // namespace hordes
