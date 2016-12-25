#include "ctpgateway.h"





ctpGW::ctpGW(eventengine *eveg, string gwname):Api_GateWay( eveg, NULL)
{

}

void ctpGW::on_tick(TickData *tickdata)
{

}

void ctpGW::on_trade(TradeData *tradedata)
{

}

void ctpGW::on_order(OrderData *orderdata)
{

}

void ctpGW::on_position(PositionData *positiondata)
{

}

void ctpGW::on_account(AccountData *accountdata)
{

}

void ctpGW::on_error(ErrorData *errordata)
{

}

void ctpGW::on_log(LogData *logdata)
{

}

void ctpGW::on_contract(ContractData *contractdata)
{

}

int ctpGW::connect()
{
    return 0;
}

int ctpGW::subscribe(SubscribeReq *subreq)
{
    return 0;
}

int ctpGW::send_order(OrderReq *ordreq)
{
    return 0;
}

int ctpGW::cancel_order(CancelOrderReq *cancelordreq)
{
    return 0;
}

int ctpGW::qry_account()
{
    return 0;
}

int ctpGW::close()
{
    return 0;
}


CtpTdApi::CtpTdApi()
{
};

CtpTdApi::~CtpTdApi()
{
};

void CtpTdApi::Login(){

};
void CtpTdApi::Subscribe() {

};


///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
///@param nReason 错误原因
///        0x1001 网络读失败
///        0x1002 网络写失败
///        0x2001 接收心跳超时
///        0x2002 发送心跳失败
///        0x2003 收到错误报文
void CtpTdApi::OnFrontDisconnected(int nReason){
    ErrorData err;
    err.err_type =   GW_ONDISCONNECT;
    err.data.errID = GW_ONDISCONNECT;
    gw->on_error(&err);
};

void CtpTdApi::OnFrontConnected() {
    this->Login();
};

///登录请求响应
void CtpTdApi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {
        this->Subscribe();
    } else {
        ErrorData err;
        err.err_type = GW_ONUSERLOGIN;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};
///登出请求响应
void CtpTdApi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    } else {
        ErrorData err;
        err.err_type = GW_ONRSPUSERLOGOUT;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};

///心跳超时警告。当长时间未收到报文时，该方法被调用。
///@param nTimeLapse 距离上次接收报文的时间
void CtpTdApi::OnHeartBeatWarning(int nTimeLapse){};

///客户端认证响应
void CtpTdApi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    }else {
        ErrorData err;
        err.err_type = GW_ONRSPAUTH;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};


///报单录入请求响应
void CtpTdApi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {
        //??????
    } else {
        ErrorData err;
        err.err_type = GW_ONRSPORDERINSERT;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};

///请求查询投资者持仓响应
void CtpTdApi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {
        PositionData pos_data;
        gw->on_position(&pos_data);
    } else {
        ErrorData err;
        err.err_type = GW_ONRSPQRYPOSITION;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};

///请求查询资金账户响应
void CtpTdApi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {
        AccountData accountdata;
        gw->on_account(&accountdata);
    } else {
        ErrorData err;
        err.err_type = GW_ONRSPQRYACCOUNT;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};




///错误应答
void CtpTdApi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    } else {
        ErrorData err;
        err.err_type = GW_ONRSPERROR;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }

};

///报单通知
void CtpTdApi::OnRtnOrder(CThostFtdcOrderField *pOrder) {
    if (pOrder) {

    } else {

    }
};

///成交通知
void CtpTdApi::OnRtnTrade(CThostFtdcTradeField *pTrade) {
    if (pTrade) {

    } else {

    }
};

///报单录入错误回报
void CtpTdApi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {
    if (pRspInfo == NULL) {

    } else {

    }
};

///报单操作错误回报
void CtpTdApi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {
    if (pRspInfo == NULL) {

    } else {

    }
};

///合约交易状态通知
void CtpTdApi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {
    if (pInstrumentStatus) {

    } else {

    }
};

///交易所公告通知
void CtpTdApi::OnRtnBulletin(CThostFtdcBulletinField *pBulletin) {
    if (pBulletin) {

    }
};

///交易通知
void CtpTdApi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {
    if (pTradingNoticeInfo) {

    }
};

///报单操作请求响应
void CtpTdApi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    } else if (pRspInfo){


    }
};

///查询最大报单数量响应
void CtpTdApi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    assert(0);
};
///投资者结算结果确认响应
void CtpTdApi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    assert(0);
};

///用户口令更新请求响应
void CtpTdApi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    } else {
        ErrorData err;
        err.err_type = GW_ONRSPPASSWORD;
        err.data.errID = pRspInfo->ErrorID;
        gw->on_error(&err);
    }
};

///资金账户口令更新请求响应
void CtpTdApi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
    if (pRspInfo == NULL) {

    } else {
        ErrorData err;
        err.err_type = GW_ONRSPTAPASSWORD;
        err.data.errID = pRspInfo->ErrorID;
    }
};

///请求查询投资者响应
void CtpTdApi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {

};

///请求查询合约保证金率响应
void CtpTdApi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {

};

///请求查询合约手续费率响应
void CtpTdApi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {

};


