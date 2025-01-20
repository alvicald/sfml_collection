#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <cstdint>

#include <SFML/Window/VideoMode.hpp>

namespace sf{

// sf::RenderWindow forward declaration
class RenderWindow;

} // namespace sf

namespace hordes {

class Game
{
public:
    explicit Game();

    void run();

private:
    void update_events();

private:
    //! sf::RenderWindow deleter
    struct window_deleter
    {
        void operator()(sf::RenderWindow*);
    };

private:
    //! Main game window
    std::unique_ptr< sf::RenderWindow, window_deleter > m_game_window;

    //! Game name
    char const* game_name { "Hordes" };

    //! Game video mode
    sf::VideoMode m_video_mode { 860, 480};

    //! Size mode
    std::uint32_t m_size_mode { 8 };
};

} // namespace hordes

#endif // GAME_H_
