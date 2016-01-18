//
// Created by przemo on 18.01.16.
//

#ifndef HUMAN_EVENT_H
#define HUMAN_EVENT_H

#include <boost/variant.hpp>

namespace Game
{
    namespace Core
    {
        struct FocusEvent
        {
            bool m_gain;
        };

        struct ResizeEvent
        {
            int m_displayWidth;
            int m_displayHeight;
        };

        typedef boost::variant<FocusEvent, ResizeEvent> Event;
    }
}

#endif //HUMAN_EVENT_H
