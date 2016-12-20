#ifndef CTPGATEWAY_H
#define CTPGATEWAY_H
#include "../../core/gateway.h"
class  ctpGW:public Api_GateWay
{
public:
    ctpGW(eventengine *eveg, string gwname);
    void on_tick(TickData *tickdata);
    void on_trade(TradeData *tradedata);
    void on_order(OrderData *orderdata);
    void on_position(PositionData *positiondata);
    void on_account(AccountData *accountdata);
    void on_error(ErrorData *errordata);
    void on_log(LogData *logdata);
    void on_contract(ContractData *contractdata);
    int  connect();
    int  subscribe(SubscribeReq *subreq);
    int  send_order(OrderReq    *ordreq);
    int  cancel_order(CancelOrderReq *cancelordreq);
    int  qry_account();
    int  close();


};
#endif // CTPGATEWAY_H
