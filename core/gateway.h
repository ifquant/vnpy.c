#ifndef GATEWAY_H
#define GATEWAY_H
#include "event_engine.h"
#include "struct.h"
class GateWayInfo {



};

class  Api_GateWay {
public:
       Api_GateWay( eventengine *eveg, GateWayInfo  *gw_info);
      ~Api_GateWay();

       virtual void on_tick(TickData *tickdata)=0;
       virtual void on_trade(TradeData *tradedata)=0;
       virtual void on_order(OrderData *orderdata)=0;
       virtual void on_position(PositionData *positiondata)=0;
       virtual void on_account(AccountData *accountdata)=0;
       virtual void on_error(ErrorData *errordata)=0;
       virtual void on_log(LogData *logdata)=0;
       virtual void on_contract(ContractData *contractdata)=0;
       virtual int  connect()=0;
       virtual int  subscribe(SubscribeReq *subreq)=0;
       virtual int  send_order(OrderReq    *ordreq)=0;
       virtual int  cancel_order(CancelOrderReq *cancelordreq)=0;
       virtual int  qry_account()=0;
       virtual int  close()=0;
private:
       eventengine *_eveg;
       GateWayInfo *_gw_info;
};




#endif // GATEWAY_H
