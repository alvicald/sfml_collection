#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <cstdint>

#include <SFML/Window/VideoMode.hpp>

namespace sf{

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

    void run();

private:
    void update_events();

    void render();

    void update_statistic(sf::Time const& time, sf::Time& game_working_time, uint32_t& frame_count);

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
    //! Main game window
    std::unique_ptr< sf::RenderWindow, window_deleter > m_game_window;

    //! Statistic information text
    std::unique_ptr< sf::Text, text_deleter> m_statistic_text;

    //! Statistic information text
    std::unique_ptr< sf::Font, font_deleter> m_font;

    //! Game name
    char const* game_name { "Hordes" };

    //! Game video mode
    sf::VideoMode m_video_mode { 860, 480 };

    //! Size mode
    std::uint32_t m_size_mode { 8 };
};

} // namespace hordes

#endif // GAME_H_
