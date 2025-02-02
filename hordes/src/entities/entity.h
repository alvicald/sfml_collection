#ifndef HORDES_ENTITY_H_
#define HORDES_ENTITY_H_

#include <memory>

namespace sf {

//! sf::RenderTarget forward declaration
class RenderTarget;

} // namespace sf

namespace hordes {

class Entity
{
public:
    using ptr = std::unique_ptr< Entity >;

public:
    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget&) = 0;

    virtual void move(float, float, float){}
};

} // namespace hordes

#endif
