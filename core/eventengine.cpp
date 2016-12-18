#include "eventengine.h"
#include "../utils/boost_helper.h"


using namespace boost;
eventengine::eventengine()
{
    running = 0;
    return;
}

void eventengine::init()
{
     boost::thread_group threads;
     boost::thread *t = new boost::thread(&eventengine::__run, this);
     threads.add_thread(t);
}

void eventengine::start()
{
    running = 1;

}

void eventengine::stop()
{
    running = 0;
}

void eventengine::__run()
{
    while (running) {
    event ev = ev_queue.front();
    ev_queue.pop();
    for (std::vector<action *>::iterator it = ev_map[ev.ev_type].begin();it!=ev_map[ev.ev_type].end();it++){
        (*it)->handler(ev);
    }
    }
}
void eventengine::__run_timer()
{

}


