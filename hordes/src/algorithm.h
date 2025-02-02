#ifndef HORDES_ALGORITHM_H_
#define HORDES_ALGORITHM_H_

namespace hordes {

//! hordes::Entity forward declaration
class Entity;

class CollisionAlgorithm
{
public:
    virtual bool check_collision(Entity const&, Entity const&) = 0;
};

} // namespace hordes

#endif // HORDES_ALGORITHM_H_
