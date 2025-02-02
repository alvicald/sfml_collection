#include <entities/hero.h>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace hordes {

Hero::Hero():
    m_hero(std::unique_ptr< sf::CircleShape, circleshape_deleter >(new sf::CircleShape))
{
    m_hero->setRadius(10);
    m_hero->setFillColor(sf::Color::Green);
    m_hero->setOutlineColor(sf::Color{255, 150, 0});
    m_hero->setOutlineThickness(2);
}

void Hero::update(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(dt, -1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(dt, 1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move(dt, 0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move(dt, 0, 1);
}

void Hero::render(sf::RenderTarget& rt)
{
    rt.draw(*m_hero);
}

void Hero::move(float dt, float x, float y)
{
    if (m_hero)
        m_hero->move(x * m_hero_speed * dt,
                     y * m_hero_speed * dt);
}

void Hero::circleshape_deleter::operator()(sf::CircleShape* ptr)
{
    if (ptr != nullptr)
        delete ptr;
}

} // namespace hordes
