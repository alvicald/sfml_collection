#ifndef HORDES_GAME_STATE_H_
#define HORDES_GAME_STATE_H_

#include <states/state.h>
#include <entities/entity.h>

namespace hordes {

class GameState : public State
{
public:
    explicit GameState(sf::RenderWindow&);
    ~GameState() override = default;

    void update_keybinds(float dt) override;
    void update(float dt) override;
    void render(sf::RenderTarget& rt) override;
    void end_state() override;

private:
    Entity::ptr m_hero;
};

} // namespace hordes

#endif
