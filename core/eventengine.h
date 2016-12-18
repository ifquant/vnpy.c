#ifndef EVENTENGINE_H
#define EVENTENGINE_H

#include <queue>
#include <map>
#include <vector>
#include "action.h"
struct event {
   int  ev_type;
   int  ev_pad;
   void *ev_data;
};

class eventengine {

public:
        eventengine();
        ~eventengine();
        void init();
        void start();
        void stop();
private:
        int running;
        std::queue<event> ev_queue;
        std::map< int, std::vector<action*> > ev_map;
        void __run();
        void __process();
        void __run_timer();
};














#endif // EVENTENGINE_H
