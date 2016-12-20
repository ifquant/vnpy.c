#include "gateway.h"

Api_GateWay::Api_GateWay(eventengine *eveg, GateWayInfo *gw_info)
{
    _eveg = eveg;
    _gw_info = gw_info;
}

Api_GateWay::~Api_GateWay()
{
    return;
}
