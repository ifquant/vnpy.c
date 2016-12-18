#ifndef EVENTENGINE_H
#define EVENTENGINE_H
#include <string>
#include <queue>
#include <map>
#include <vector>
#include "action.h"

using namespace std;

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

        /**
         * @brief ev_map
         * @todo show we use a map  && vector?
         * or better function?
         */
        std::map< int, std::vector<action*> > ev_map;
        void __run();
        void __process();
        void __run_timer();
};














#endif // EVENTENGINE_H
