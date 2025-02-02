#ifndef HORDES_GAME_H_
#define HORDES_GAME_H_

#include <cstdint>
#include <stack>

#include <states/state.h>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Clock.hpp>

namespace sf {

//! sf::RenderWindow forward declaration
class RenderWindow;

//! sf::Text forward declaration
class Text;

//! sf::Time forward declaration
class Time;

//! sf::Time forward declaration
class Font;

} // namespace sf

namespace hordes {

class Game
{
public:
    explicit Game();
    ~Game();

    void run();

private:
    void init_states();

    void update_events();

    void render();

    void update();

    void updateDt();

private:
    //! sf::RenderWindow deleter
    struct window_deleter
    {
        void operator()(sf::RenderWindow*);
    };

    //! sf::Text deleter
    struct text_deleter
    {
        void operator()(sf::Text*);
    };

    //! sf::Text deleter
    struct font_deleter
    {
        void operator()(sf::Font*);
    };

private:
    //! State stack
    std::stack< State::Ptr > m_state_stack;

    //! Main game window
    std::unique_ptr< sf::RenderWindow, window_deleter > m_game_window;

    //! Statistic information text
    std::unique_ptr< sf::Text, text_deleter > m_statistic_text;

    //! Statistic information text
    std::unique_ptr< sf::Font, font_deleter > m_font;

    //! Game name
    char const* game_name { "Hordes" };

    //! Game video mode
    sf::VideoMode m_video_mode { 860, 480 };

    //! Size mode
    std::uint32_t m_size_mode { 8 };

    //! Delta time
    float m_dt;

    //! Time clock
    sf::Clock m_clock;
};

} // namespace hordes

#endif // HORDES_GAME_H_
