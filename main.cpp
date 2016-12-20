#include "ifquant.h"
#include <QApplication>
#include "ta_libc.h"

#include "core/event_engine.h"
#include "utils/boost_helper.h"

#include "common/appinfo.h"
#include "asmlib.h"
boost::mutex io_mutex;
void count(int id)
{
        for (int i = 0; i < 10; ++i)
        {
                boost::mutex::scoped_lock
                lock(io_mutex);
                std::cout << id << ": " <<
                i << std::endl;
        }
}


int main(int argc, char *argv[])
{
    char aa[20],bb[20];
    A_memcpy(aa,bb,10);
#if 1
    QApplication a(argc, argv);



    TA_RetCode retCode;
    retCode = TA_Initialize( );
    if( retCode != TA_SUCCESS )
    {
      printf( "Cannot initialize TA-Lib (%d)!\n", retCode );
      exit (1);
   }

    QApplication::setApplicationName (APPNAME);
    QApplication::setOrganizationName (APPNAME);






    ifquant w;
    w.show();
    return a.exec();




#else

    boost::thread thrd1(
    boost::bind(&count, 1));
    boost::thread thrd2(
    boost::bind(&count, 2));
    thrd1.join();
    thrd2.join();



    event ev;
#endif

}
