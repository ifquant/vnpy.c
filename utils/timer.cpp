#include "boost_helper.h"
typedef void(*time_callback)(const boost::system::error_code&, boost::asio::deadline_timer*, void *);
boost::asio::io_service g_io;
void timer_io()
{
    while (1) {
        //cout << "ggg" << std::endl;

        g_io.run();
        boost::thread::sleep(boost::get_system_time() + boost::posix_time::microseconds(100));
        //Sleep(10);
    }
}

int timer_init() {
    new boost::thread(timer_io);
    return 0;
};
int timer_add(time_callback pfun, int seconds, void *userdata) {

    boost::asio::deadline_timer *pt = new boost::asio::deadline_timer(g_io, boost::posix_time::microseconds(100));
    //pt->expires_at(pt->expires_at() + boost::posix_time::microseconds(seconds * 900));
    pt->expires_at(pt->expires_at() + boost::posix_time::milliseconds(seconds * 950));
    pt->async_wait(boost::bind(pfun, boost::asio::placeholders::error, pt, userdata));
    return 0;
}
int timer_del() {
    return 0;
}


void print(const boost::system::error_code&,
    boost::asio::deadline_timer* t, int* count)
{
    if (*count<10)
    {
        std::cout << *count << "\n";
        ++(*count);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(boost::bind(print,
            boost::asio::placeholders::error, t, count));
    }
    else {
        free(t);
    }
}

int timer_test()
{
    boost::asio::io_service io;
    new boost::thread(timer_io);
    //Sleep(1000);
    int count1 = 0;
    int count2 = 0;
    //boost::posix_time::microseconds(100);
    boost::posix_time::milliseconds(100);
    //std::cout << "posixtime"<<boost::posix_time::milliseconds(100) << std::endl;;

    boost::asio::deadline_timer *t1 = new boost::asio::deadline_timer(g_io, boost::posix_time::microseconds(100));
    //boost::asio::deadline_timer *t2 = new boost::asio::deadline_timer(g_io, boost::posix_time::seconds(2));

    t1->async_wait(boost::bind(print, boost::asio::placeholders::error,
        t1, &count1));

    //t2->async_wait(boost::bind(print, boost::asio::placeholders::error,t2, &count2));

    //Sleep(2000);
    std::cout << "Final count1 is" << count1 << "\n";
    std::cout << "Final count2 is" << count2 << "\n";
    while (1) {
        //Sleep(1);
    }
    return 0;
}
