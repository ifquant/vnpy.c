#ifndef GATEWAY_H
#define GATEWAY_H
#include "event_engine.h"

class GateWayInfo {



};

class  Api_GateWay {
public:
       Api_GateWay( eventengine *eveg, GateWayInfo  *gwinfo);
      ~Api_GateWay();
private:
       eventengine *_eveg;
       GateWayInfo *_gwinfo;
};




#endif // GATEWAY_H
