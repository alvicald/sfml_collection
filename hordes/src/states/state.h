#ifndef HORDES_STATE_H_
#define HORDES_STATE_H_

#include <memory>

namespace sf {

//! sf::RenderTarget forward declaration
class RenderTarget;

//! sf::RenderWindow forward declaration
class RenderWindow;

} // namespace sf

namespace hordes {

class State
{
public:
    using Ptr = std::unique_ptr< State >;

public:
    explicit State(sf::RenderWindow&);
    virtual ~State() = default;

    virtual void update_keybinds(float dt) = 0;
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderTarget& rt) = 0;
    virtual void end_state() = 0;

    virtual void check_for_quit();

    bool getQuit() const;

protected:
    sf::RenderWindow& m_main_window;

private:
    bool m_quit { false };
};

} // namespace hordes

#endif
