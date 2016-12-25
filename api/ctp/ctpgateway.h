#ifndef CTPGATEWAY_H
#define CTPGATEWAY_H
#include "../../core/gateway.h"
#include "../../core/struct.h"
#include "./linux64/ThostFtdcTraderApi.h"
#include "./linux64/ThostFtdcMdApi.h"
#include "./linux64/ThostFtdcUserApiStruct.h"





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



class CtpTdApi : public CThostFtdcTraderSpi
{
private:
    CThostFtdcTraderApi* api;
    ctpGW              * gw;
public:
    CtpTdApi();
    ~CtpTdApi();
    void Login();
    void Subscribe();
    void OnFrontDisconnected(int nReason);
    void OnFrontConnected();
    void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///心跳超时警告。当长时间未收到报文时，该方法被调用。
    ///@param nTimeLapse 距离上次接收报文的时间
    void OnHeartBeatWarning(int nTimeLapse);
    ///客户端认证响应
    void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///报单录入请求响应
    void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询投资者持仓响应
    void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询资金账户响应
    virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///错误应答
    virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///报单通知
    virtual void OnRtnOrder(CThostFtdcOrderField *pOrder);
    ///成交通知
    virtual void OnRtnTrade(CThostFtdcTradeField *pTrade);
    ///报单录入错误回报
    virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
    ///报单操作错误回报
    virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);

    ///合约交易状态通知
    virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);

    ///交易所公告通知
    virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin);

    ///交易通知
    virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);

    ///报单操作请求响应
    virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///查询最大报单数量响应
    virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
    ///投资者结算结果确认响应
    virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///用户口令更新请求响应
    virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///资金账户口令更新请求响应
    virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询投资者响应
    virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询合约保证金率响应
    virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

    ///请求查询合约手续费率响应
    virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
 };

#endif // CTPGATEWAY_H
