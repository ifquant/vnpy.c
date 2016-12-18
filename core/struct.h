#ifndef STRUCT_H
#define STRUCT_H
#include <string>
using namespace std;



class  vdata {
public:
      string gw;
      void   *data;
};

class tickdata :public vdata {
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

class tradedata :public vdata {
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

class orderdata :public vdata{


};












#endif // STRUCT_H
