#ifndef GATEWAY_H
#define GATEWAY_H
#include "event_engine.h"
#include "struct.h"
class GateWayInfo {



};

enum  GW_DETAIL_ERROR {
    GW_ONCONNECT=1,
    GW_ONDISCONNECT=2,
    GW_ONUSERLOGIN=3,
    GW_ONRSPUSERLOGOUT=4,
    GW_ONRSPAUTH=5,
    GW_ONRSPORDERINSERT=6,
    GW_ONRSPQRYPOSITION=7,
    GW_ONRSPQRYACCOUNT=8,
    GW_ONRSPERROR=9,
    GW_ONERRRTNORDERINSERT=10,
    GW_ONRSPPASSWORD,
    GW_ONRSPTAPASSWORD,
};

enum  GW_ERROR {
    GW_ERR_TICK,
    GW_ERR_TRADE,
    GW_ERR_ORDER,
    GW_ERR_POSITION,
    GW_ERR_ACCOUNT,
    GW_ERR_CONNECT,
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
