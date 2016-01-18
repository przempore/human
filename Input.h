//
// Created by przemo on 01.09.15.
//

#ifndef SDLTEST_INPUT_H
#define SDLTEST_INPUT_H

#include <boost/variant.hpp>

namespace Game
{
    namespace Core
    {
        enum class KeyState
        {
            Down,
            Up
        };

        enum class TouchAction
        {
            Down,
            Move,
            Up,
        };

        struct TouchPoint
        {
            TouchAction m_action;
            int m_id;
            int m_x;
            int m_y;
        };

        struct KeyboardInput
        {
            KeyState m_state;
            int m_code;
        };

        struct TouchInput
        {
            TouchAction m_action;
            TouchPoint m_point;
        };

        typedef boost::variant<KeyboardInput, TouchInput> Input;
    }
}

#endif //SDLTEST_INPUT_H
