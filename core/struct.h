#ifndef STRUCT_H
#define STRUCT_H
#include <string>
using namespace std;



class  vdata {
public:
      string gw;
      void   *data;
};

class TickData :public vdata {
public:
    //代码相关
    string symbol;                      //合约代码
    string exchange;                    //交易所代码
    string vtSymbol;        //# 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

    //成交数据
    double lastPrice;            //# 最新成交价
    int lastVolume;             //# 最新成交量
    int volume;                //# 今天总成交量
    int openInterest;           //# 持仓量
    int time;                   //# 时间 11:20:56
    int date;                   //# 日期 20151009

    //# 常规行情
    double openPrice;            // # 今日开盘价
    double highPrice;            //# 今日最高价
    double lowPrice;                //# 今日最低价
    double preClosePrice;
    double upperLimit;              //# 涨停价
    double lowerLimit;              //# 跌停价
};

class TradeData :public vdata {
public:
//# 代码编号相关
    string symbol ;             //# 合约代码
    string exchange ;          // # 交易所代码
    string vtSymbol ;           // # 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

    string tradeID ;            //# 成交编号
    string vtTradeID ;           //# 成交在vt系统中的唯一编号，通常是 Gateway名.成交编号

    string orderID ;            //# 订单编号
    string vtOrderID ;          // # 订单在vt系统中的唯一编号，通常是 Gateway名.订单编号

    //# 成交相关
    char direction;//        # 成交方向
    char offset;    //        # 成交开平仓
    double price;//              # 成交价格
    int    volume;//               # 成交数量
    int    tradeTime;//           # 成交时间
};

class OrderData :public vdata{
public:
    //# 代码编号相关
    string symbol;              //# 合约代码
    string exchange;            //# 交易所代码
    string vtSymbol;            //# 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

    string orderID;             //# 订单编号
    string vtOrderID;           //# 订单在vt系统中的唯一编号，通常是 Gateway名.订单编号

    //# 报单相关
    char direction;         //# 报单方向
    char offset;            //# 报单开平仓
    double price;           //    # 报单价格
    int  totalVolume;       //    # 报单总数量
    int  tradedVolume;      //   # 报单成交数量
    int  status;            //# 报单状态

    int  orderTime;         //# 发单时间
    int  cancelTime;        //# 撤单时间

    //# CTP/LTS相关
    int frontID;            //# 前置机编号
    int sessionID;          //# 连接编号
};

class PositionData:public vdata {
public:
//# 代码编号相关
string symbol;              //# 合约代码
string exchange;            //# 交易所代码
string vtSymbol;            //# 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码

string orderID;             //# 订单编号
string vtOrderID;           //# 订单在vt系统中的唯一编号，通常是 Gateway名.订单编号

//# 持仓相关
char direction;              //# 报单方向
int   position;               //# 持仓量
int   frozen;                //# 冻结数量
float price;                //# 持仓均价
string vtPositionName;      //# 持仓在vt系统中的唯一代码，通常是vtSymbol.方向

//# 20151020添加
int ydPosition;             //# 昨持仓
};

class AccountData: public vdata {
public:
    //# 账号代码相关
    string accountID;          //# 账户代码
    string vtAccountID;         //# 账户在vt中的唯一代码，通常是 Gateway名.账户代码

    //# 数值相关
    double preBalance;          //# 昨日账户结算净值
    double balance;             //# 账户净值
    double available;           //# 可用资金
    double commission;          //# 今日手续费
    double margin;              //# 保证金占用
    double closeProfit;          //# 平仓盈亏
    double positionProfit;       //# 持仓盈亏

};

class ErrorData : public vdata {
public:
    int err_type;  //# 错误代码
    int err_time;  //# 错误生成时间
    string errMsg; //# 错误信息
    union  {
    void   *edata; //# 补充信息
    int     errID;
    } data;
};

class LogData : public vdata {
public:
    int time;       //日志生成时间
    string content; //日志内容

};

class ContractData :public vdata {
public:

    string symbol; //合约代码
    string exchange;                  //# 交易所代码
    string vtSymbol;                    //# 合约在vt系统中的唯一代码，通常是 合约代码.交易所代码
    string name;                 //# 合约中文名
    string productClass;         //合约类型
    int    size;                 //合约大小
    double priceTick;            //合约最小波动价格


    //# 期权相关
    double strikePrice;          //# 期权行权价
    string underlyingSymbol;     //# 标的物合约代码
    int    optionType;           //# 期权类型

};

class SubscribeReq: public vdata {
public:
    //"""Constructor"""
    string symbol;//# 代码
    string exchange;//# 交易所

    //# 以下为IB相关
    string productClass;//# 合约类型
    string currency;//# 合约货币
    string expiry;//# 到期日
    string strikePrice;//# 行权价
    string optionType;//# 期权类型
};


class OrderReq : public vdata {
public:
    //"""Constructor"""
    string symbol;//# 代码
    string exchange;//# 交易所
    double price;//# 价格
    int volume; //# 数量

    char  priceType; //# 价格类型
    char direction;//# 买卖
    char offset;//# 开平

    //# 以下为IB相关
    string productClass;//# 合约类型
    string currency;//# 合约货币
    string expiry;//# 到期日
    string strikePrice;//# 行权价
    string optionType;//# 期权类型
};

class CancelOrderReq: public vdata {
    //"""撤单时传入的对象类"""
    string symbol;             //# 代码
    string exchange;           //# 交易所

    //# 以下字段主要和CTP、LTS类接口相关
    string orderID;             //# 报单号
    string frontID;          //# 前置机号
    string sessionI;      //# 会话号

};




#endif // STRUCT_H
