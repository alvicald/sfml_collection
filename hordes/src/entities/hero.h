#ifndef HORDES_HERO_H_
#define HORDES_HERO_H_

#include <entities/entity.h>

namespace sf {

//! sf::CircleShape forward declaration
class CircleShape;

} // namespace sf

namespace hordes {

class Hero : public Entity
{
private:
    struct circleshape_deleter
    {
        void operator()(sf::CircleShape*);
    };

public:
    explicit Hero();
    ~Hero() override = default;

    void update(float dt) override;
    void render(sf::RenderTarget&) override;

    void move(float dt, float x, float y) override;

private:
    std::unique_ptr< sf::CircleShape, circleshape_deleter > m_hero;
    float m_hero_speed { 200 };
};

} // namespace hordes

#endif // HORDES_HERO_H_
