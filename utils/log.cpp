#include "log.h"

src::logger g_lg;
src::severity_logger< severity_level > g_slg;

// The formatting logic for the severity level
template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
    std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}

int sync_log_init(string logprefix)
{
    // This is a simple tutorial/example of Boost.Log usage


    // The first thing we have to do to get using the library is
    // to set up the logging sinks - i.e. where the logs will be written to.
    logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");


    // One can also use lambda expressions to setup filters and formatters
    logging::add_file_log
    (
        logprefix+".log",
        keywords::filter = expr::attr< severity_level >("Severity") == normal,
        keywords::format = expr::stream
            << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
            << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
            << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
            << "] <" << expr::attr< severity_level >("Severity")
            << "> " << expr::message
/*
        keywords::format = expr::format("%1% [%2%] [%3%] <%4%> %5%")
            % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
            % expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
            % expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
            % expr::attr< severity_level >("Severity")
            % expr::message
*/
    );

    logging::add_file_log
    (
        logprefix+".warn.log",
        keywords::filter = expr::attr< severity_level >("Severity") >= warning,
        keywords::format = expr::stream
            << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
            << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
            << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
            << "] <" << expr::attr< severity_level >("Severity")
            << "> " << expr::message
    );
    logging::add_file_log
    (
        logprefix+".error.log",
        keywords::filter = expr::attr< severity_level >("Severity") >= error,
        keywords::format = expr::stream
            << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
            << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
            << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
            << "] <" << expr::attr< severity_level >("Severity")
            << "> " << expr::message
    );

    // Also let's add some commonly used attributes, like timestamp and record counter.
    logging::add_common_attributes();
    logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());


    BOOST_LOG_FUNCTION();


    // Now our logs will be written both to the console and to the file.
    // Let's do a quick test and output something. We have to create a logger for this.
    //src::logger lg;

    // And output...
    BOOST_LOG(g_lg) << "Hello, World!";


    // Now, let's try logging with severity
    //src::severity_logger< severity_level > slg;

    // Let's pretend we also want to profile our code, so add a special timer attribute.
    g_slg.add_attribute("Uptime", attrs::timer());


    BOOST_LOG_SEV(g_slg, normal) << "A normal severity message, will not pass to the file";
    BOOST_LOG_SEV(g_slg, warning) << "A warning severity message, will pass to the file";
    BOOST_LOG_SEV(g_slg, error) << "An error severity message, will pass to the file";

    FAKE 123abc
    return 0;
}

