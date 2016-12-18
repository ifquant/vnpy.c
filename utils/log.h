#ifndef LOG_H
#define LOG_H


#include <iostream>
#include <string>
#define BOOST_LOG_DYN_LINK 1
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>


#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>


#include <boost/log/sources/logger.hpp>


#include <boost/log/support/date_time.hpp>

using namespace std;

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;


using boost::shared_ptr;


// Here we define our application severity levels.
enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};



extern src::logger g_lg;
extern src::severity_logger< severity_level > g_slg;

#define DBUG   BOOST_LOG_SEV(g_slg, normal)
#define DWARN  BOOST_LOG_SEV(g_slg, warning)
#define DERROR BOOST_LOG_SEV(g_slg, error)
#define FAKE   \/\/
int synlog_init(string logprefix);

#endif // LOG_H
