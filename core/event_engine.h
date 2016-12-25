#ifndef EVENTENGINE_H
#define EVENTENGINE_H
#include <string>
#include <queue>
#include <map>
#include <vector>
#include "action.h"
#include <boost/thread/thread.hpp>
#include "../../3rdparty/concurrentqueue/concurrentqueue.h"

using namespace std;

enum event_type {
    //GateWay相关
    EVENT_TICK = 0,
    EVENT_TRADE= 1,
    EVENT_ORDER= 2,
    EVENT_POSITION=3,
    EVENT_ACCOUNT=4,
    EVENT_CONTRACT=5,
    EVENT_ERROR=6,

    //系统相关
    EVENT_TIMER=7,
    EVENT_LOG=8,

    //CTA相关
    EVENT_CTA_LOG=9,
    EVENT_CTA_STRATEGY=10,

    //行情记录相关
    EVENT_DATARECODER_LOG=11,

    //Wind接口相关
    EVENT_WIND_CONNECTREQ=12,
};


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
        void put(event &ev);
private:
        int running;

/*
        moodycamel::ConcurrentQueue<event> queue;
        //q.enqueue(25);
        int item;
        bool found = q.try_dequeue(item);
        assert(found && item == 25);
*/
        moodycamel::ConcurrentQueue<event> ev_queue;
#if 0
        std::queue<event> ev_queue;
#endif
        boost::thread_group threads;
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
