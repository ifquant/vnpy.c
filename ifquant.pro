#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T21:31:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ifquant
TEMPLATE = app

CONFIG	 += release
DEFINES  *= QT_NO_DEBUG_OUTPUT
DEFINES  *= QT_USE_QSTRINGBUILDER


INCLUDEPATH += /home/dev/third_party/boost/boost_1_61_0
INCLUDEPATH += \
        include \
        3rdparty/sqlite3/include \
        3rdparty/ta-lib/include \
        3rdparty/libjson\
        3rdparty/asmlib

LIBS +=-L/home/dev/third_party/boost/boost_1_61_0/stage/lib  -lboost_system -lboost_log  -lboost_log_setup -lboost_filesystem -lboost_thread
LIBS +=-L/home/dev/Desktop/working\ code/vnpy-c/3rdparty/asmlib -laelf64
QMAKE_CFLAGS_RELEASE += \
        -DSQLITE_MAX_COLUMN=256 \
        -DSQLITE_MAX_SQL_LENGTH=134217728 \
        -DSQLITE_MAX_EXPR_DEPTH=256 \
        -DSQLITE_MAX_COMPOUND_SELECT=128 \
        -DSQLITE_THREADSAFE=1 \
        -DSQLITE_TEMP_STORE=2 \
        -DSQLITE_DEFAULT_PAGE_SIZE=4096 \
        -DJSON_ISO_STRICT \
        -D_CRT_SECURE_NO_WARNINGS\
        -DBOOST_LOG_DYN_LINK

QMAKE_CXXFLAGS_RELEASE += -DJSON_ISO_STRICT

linux-g++* {
    QMAKE_CXXFLAGS += -std=c++11\
            -DBOOST_LOG_DYN_LINK
}

unix {
    SNAPCHECK = $$(_)
    LIBS += -ldl
    QMAKE_POST_LINK = strip $(TARGET)
    QMAKE_CFLAGS_RELEASE -= -g -Wall -O2 -O1
    QMAKE_CXXFLAGS_RELEASE -= -g -Wall -O2 -O2
    QMAKE_CFLAGS_RELEASE += -fomit-frame-pointer -w -O2
    QMAKE_CXXFLAGS_RELEASE += -fomit-frame-pointer -Wall -O2 -Wno-reorder -Wno-unused-parameter
    equals(SNAPCHECK, "/usr/bin/snapcraft") {
     target.path = ../install/usr/bin
     INSTALLS += target
    } else {
     target.path = /usr/bin
     images.path = /usr/share/pixmaps
     desktop.path = /usr/share/applications/
     images.files = images/icons/$${PKG_NAME}.png
     desktop.files = $${PKG_NAME}.desktop
     INSTALLS = target desktop images
   }
}

SOURCES += main.cpp\
        ifquant.cpp \
    gui/gui.cpp \
    utils/boost_helper.cpp \
    core/action.cpp \
                3rdparty/sqlite3/sqlite3.c \
                3rdparty/ta-lib/ta_abstract/tables/table_s.c \
                3rdparty/ta-lib/ta_abstract/tables/table_r.c \
                3rdparty/ta-lib/ta_abstract/tables/table_y.c \
                3rdparty/ta-lib/ta_abstract/tables/table_j.c \
                3rdparty/ta-lib/ta_abstract/tables/table_e.c \
                3rdparty/ta-lib/ta_abstract/tables/table_n.c \
                3rdparty/ta-lib/ta_abstract/tables/table_q.c \
                3rdparty/ta-lib/ta_abstract/tables/table_z.c \
                3rdparty/ta-lib/ta_abstract/tables/table_u.c \
                3rdparty/ta-lib/ta_abstract/tables/table_x.c \
                3rdparty/ta-lib/ta_abstract/tables/table_f.c \
                3rdparty/ta-lib/ta_abstract/tables/table_i.c \
                3rdparty/ta-lib/ta_abstract/tables/table_g.c \
                3rdparty/ta-lib/ta_abstract/tables/table_l.c \
                3rdparty/ta-lib/ta_abstract/tables/table_w.c \
                3rdparty/ta-lib/ta_abstract/tables/table_h.c \
                3rdparty/ta-lib/ta_abstract/tables/table_c.c \
                3rdparty/ta-lib/ta_abstract/tables/table_t.c \
                3rdparty/ta-lib/ta_abstract/tables/table_k.c \
                3rdparty/ta-lib/ta_abstract/tables/table_d.c \
                3rdparty/ta-lib/ta_abstract/tables/table_m.c \
                3rdparty/ta-lib/ta_abstract/tables/table_v.c \
                3rdparty/ta-lib/ta_abstract/tables/table_b.c \
                3rdparty/ta-lib/ta_abstract/tables/table_o.c \
                3rdparty/ta-lib/ta_abstract/tables/table_p.c \
                3rdparty/ta-lib/ta_abstract/tables/table_a.c \
                3rdparty/ta-lib/ta_abstract/ta_func_api.c \
                3rdparty/ta-lib/ta_abstract/ta_def_ui.c \
                3rdparty/ta-lib/ta_abstract/ta_abstract.c \
                3rdparty/ta-lib/ta_abstract/frames/ta_frame.c \
                3rdparty/ta-lib/ta_abstract/ta_group_idx.c \
                3rdparty/ta-lib/ta_common/ta_global.c \
                3rdparty/ta-lib/ta_common/ta_version.c \
                3rdparty/ta-lib/ta_common/ta_retcode.c \
                3rdparty/ta-lib/ta_func/ta_CDLMATCHINGLOW.c \
                3rdparty/ta-lib/ta_func/ta_CDLINVERTEDHAMMER.c \
                3rdparty/ta-lib/ta_func/ta_FLOOR.c \
                3rdparty/ta-lib/ta_func/ta_CDLHAMMER.c \
                3rdparty/ta-lib/ta_func/ta_CDLHARAMICROSS.c \
                3rdparty/ta-lib/ta_func/ta_CDLSHOOTINGSTAR.c \
                3rdparty/ta-lib/ta_func/ta_HT_DCPERIOD.c \
                3rdparty/ta-lib/ta_func/ta_CDLHANGINGMAN.c \
                3rdparty/ta-lib/ta_func/ta_BETA.c \
                3rdparty/ta-lib/ta_func/ta_STOCHF.c \
                3rdparty/ta-lib/ta_func/ta_ACOS.c \
                3rdparty/ta-lib/ta_func/ta_STDDEV.c \
                3rdparty/ta-lib/ta_func/ta_MEDPRICE.c \
                3rdparty/ta-lib/ta_func/ta_CDLENGULFING.c \
                3rdparty/ta-lib/ta_func/ta_STOCH.c \
                3rdparty/ta-lib/ta_func/ta_CDLGRAVESTONEDOJI.c \
                3rdparty/ta-lib/ta_func/ta_LOG10.c \
                3rdparty/ta-lib/ta_func/ta_LINEARREG_SLOPE.c \
                3rdparty/ta-lib/ta_func/ta_RSI.c \
                3rdparty/ta-lib/ta_func/ta_CDLRISEFALL3METHODS.c \
                3rdparty/ta-lib/ta_func/ta_ADX.c \
                3rdparty/ta-lib/ta_func/ta_BOP.c \
                3rdparty/ta-lib/ta_func/ta_CEIL.c \
                3rdparty/ta-lib/ta_func/ta_CDLINNECK.c \
                3rdparty/ta-lib/ta_func/ta_TSF.c \
                3rdparty/ta-lib/ta_func/ta_CDLUPSIDEGAP2CROWS.c \
                3rdparty/ta-lib/ta_func/ta_CDLMARUBOZU.c \
                3rdparty/ta-lib/ta_func/ta_CDLHIGHWAVE.c \
                3rdparty/ta-lib/ta_func/ta_NVI.c \
                3rdparty/ta-lib/ta_func/ta_ROC.c \
                3rdparty/ta-lib/ta_func/ta_LINEARREG.c \
                3rdparty/ta-lib/ta_func/ta_CDLCLOSINGMARUBOZU.c \
                3rdparty/ta-lib/ta_func/ta_EXP.c \
                3rdparty/ta-lib/ta_func/ta_CDLSTALLEDPATTERN.c \
                3rdparty/ta-lib/ta_func/ta_HT_DCPHASE.c \
                3rdparty/ta-lib/ta_func/ta_CDLTASUKIGAP.c \
                3rdparty/ta-lib/ta_func/ta_CDLMORNINGSTAR.c \
                3rdparty/ta-lib/ta_func/ta_VAR.c \
                3rdparty/ta-lib/ta_func/ta_TRANGE.c \
                3rdparty/ta-lib/ta_func/ta_HT_PHASOR.c \
                3rdparty/ta-lib/ta_func/ta_CDLDARKCLOUDCOVER.c \
                3rdparty/ta-lib/ta_func/ta_CDL3OUTSIDE.c \
                3rdparty/ta-lib/ta_func/ta_DX.c \
                3rdparty/ta-lib/ta_func/ta_MINUS_DM.c \
                3rdparty/ta-lib/ta_func/ta_CDLTHRUSTING.c \
                3rdparty/ta-lib/ta_func/ta_MACDEXT.c \
                3rdparty/ta-lib/ta_func/ta_COS.c \
                3rdparty/ta-lib/ta_func/ta_MINMAXINDEX.c \
                3rdparty/ta-lib/ta_func/ta_CDLUNIQUE3RIVER.c \
                3rdparty/ta-lib/ta_func/ta_MAXINDEX.c \
                3rdparty/ta-lib/ta_func/ta_SAR.c \
                3rdparty/ta-lib/ta_func/ta_CDLHOMINGPIGEON.c \
                3rdparty/ta-lib/ta_func/ta_CDLONNECK.c \
                3rdparty/ta-lib/ta_func/ta_WCLPRICE.c \
                3rdparty/ta-lib/ta_func/ta_ATAN.c \
                3rdparty/ta-lib/ta_func/ta_CDL3INSIDE.c \
                3rdparty/ta-lib/ta_func/ta_ADD.c \
                3rdparty/ta-lib/ta_func/ta_AD.c \
                3rdparty/ta-lib/ta_func/ta_MACD.c \
                3rdparty/ta-lib/ta_func/ta_CDLIDENTICAL3CROWS.c \
                3rdparty/ta-lib/ta_func/ta_MACDFIX.c \
                3rdparty/ta-lib/ta_func/ta_WILLR.c \
                3rdparty/ta-lib/ta_func/ta_CCI.c \
                3rdparty/ta-lib/ta_func/ta_MAMA.c \
                3rdparty/ta-lib/ta_func/ta_ATR.c \
                3rdparty/ta-lib/ta_func/ta_STOCHRSI.c \
                3rdparty/ta-lib/ta_func/ta_CDLABANDONEDBABY.c \
                3rdparty/ta-lib/ta_func/ta_TANH.c \
                3rdparty/ta-lib/ta_func/ta_SAREXT.c \
                3rdparty/ta-lib/ta_func/ta_CDLADVANCEBLOCK.c \
                3rdparty/ta-lib/ta_func/ta_utility.c \
                3rdparty/ta-lib/ta_func/ta_ROCR.c \
                3rdparty/ta-lib/ta_func/ta_ROCR100.c \
                3rdparty/ta-lib/ta_func/ta_OBV.c \
                3rdparty/ta-lib/ta_func/ta_NATR.c \
                3rdparty/ta-lib/ta_func/ta_CDLEVENINGSTAR.c \
                3rdparty/ta-lib/ta_func/ta_MINUS_DI.c \
                3rdparty/ta-lib/ta_func/ta_SUM.c \
                3rdparty/ta-lib/ta_func/ta_CDLCONCEALBABYSWALL.c \
                3rdparty/ta-lib/ta_func/ta_HT_SINE.c \
                3rdparty/ta-lib/ta_func/ta_MININDEX.c \
                3rdparty/ta-lib/ta_func/ta_CDL2CROWS.c \
                3rdparty/ta-lib/ta_func/ta_CDLSEPARATINGLINES.c \
                3rdparty/ta-lib/ta_func/ta_CDLSTICKSANDWICH.c \
                3rdparty/ta-lib/ta_func/ta_CDLTRISTAR.c \
                3rdparty/ta-lib/ta_func/ta_CDLSHORTLINE.c \
                3rdparty/ta-lib/ta_func/ta_SQRT.c \
                3rdparty/ta-lib/ta_func/ta_TYPPRICE.c \
                3rdparty/ta-lib/ta_func/ta_CDLSPINNINGTOP.c \
                3rdparty/ta-lib/ta_func/ta_CDLHARAMI.c \
                3rdparty/ta-lib/ta_func/ta_HT_TRENDLINE.c \
                3rdparty/ta-lib/ta_func/ta_LINEARREG_ANGLE.c \
                3rdparty/ta-lib/ta_func/ta_MOM.c \
                3rdparty/ta-lib/ta_func/ta_CDLBREAKAWAY.c \
                3rdparty/ta-lib/ta_func/ta_T3.c \
                3rdparty/ta-lib/ta_func/ta_CDLRICKSHAWMAN.c \
                3rdparty/ta-lib/ta_func/ta_WMA.c \
                3rdparty/ta-lib/ta_func/ta_CDL3BLACKCROWS.c \
                3rdparty/ta-lib/ta_func/ta_CDLEVENINGDOJISTAR.c \
                3rdparty/ta-lib/ta_func/ta_CDLDRAGONFLYDOJI.c \
                3rdparty/ta-lib/ta_func/ta_MAX.c \
                3rdparty/ta-lib/ta_func/ta_MIN.c \
                3rdparty/ta-lib/ta_func/ta_CDLHIKKAKE.c \
                3rdparty/ta-lib/ta_func/ta_CDLBELTHOLD.c \
                3rdparty/ta-lib/ta_func/ta_CDLDOJISTAR.c \
                3rdparty/ta-lib/ta_func/ta_CDLGAPSIDESIDEWHITE.c \
                3rdparty/ta-lib/ta_func/ta_PPO.c \
                3rdparty/ta-lib/ta_func/ta_AROONOSC.c \
                3rdparty/ta-lib/ta_func/ta_SUB.c \
                3rdparty/ta-lib/ta_func/ta_TEMA.c \
                3rdparty/ta-lib/ta_func/ta_MINMAX.c \
                3rdparty/ta-lib/ta_func/ta_EMA.c \
                3rdparty/ta-lib/ta_func/ta_CDLKICKING.c \
                3rdparty/ta-lib/ta_func/ta_MFI.c \
                3rdparty/ta-lib/ta_func/ta_CDLXSIDEGAP3METHODS.c \
                3rdparty/ta-lib/ta_func/ta_LN.c \
                3rdparty/ta-lib/ta_func/ta_COSH.c \
                3rdparty/ta-lib/ta_func/ta_CDLHIKKAKEMOD.c \
                3rdparty/ta-lib/ta_func/ta_ADOSC.c \
                3rdparty/ta-lib/ta_func/ta_MULT.c \
                3rdparty/ta-lib/ta_func/ta_SINH.c \
                3rdparty/ta-lib/ta_func/ta_MA.c \
                3rdparty/ta-lib/ta_func/ta_CDLCOUNTERATTACK.c \
                3rdparty/ta-lib/ta_func/ta_AROON.c \
                3rdparty/ta-lib/ta_func/ta_ASIN.c \
                3rdparty/ta-lib/ta_func/ta_CDL3WHITESOLDIERS.c \
                3rdparty/ta-lib/ta_func/ta_ROCP.c \
                3rdparty/ta-lib/ta_func/ta_LINEARREG_INTERCEPT.c \
                3rdparty/ta-lib/ta_func/ta_CDLMATHOLD.c \
                3rdparty/ta-lib/ta_func/ta_PLUS_DI.c \
                3rdparty/ta-lib/ta_func/ta_CDLTAKURI.c \
                3rdparty/ta-lib/ta_func/ta_AVGPRICE.c \
                3rdparty/ta-lib/ta_func/ta_CDLMORNINGDOJISTAR.c \
                3rdparty/ta-lib/ta_func/ta_CDLPIERCING.c \
                3rdparty/ta-lib/ta_func/ta_TRIX.c \
                3rdparty/ta-lib/ta_func/ta_DEMA.c \
                3rdparty/ta-lib/ta_func/ta_HT_TRENDMODE.c \
                3rdparty/ta-lib/ta_func/ta_APO.c \
                3rdparty/ta-lib/ta_func/ta_CDLKICKINGBYLENGTH.c \
                3rdparty/ta-lib/ta_func/ta_CDL3LINESTRIKE.c \
                3rdparty/ta-lib/ta_func/ta_SMA.c \
                3rdparty/ta-lib/ta_func/ta_MIDPRICE.c \
                3rdparty/ta-lib/ta_func/ta_CDLDOJI.c \
                3rdparty/ta-lib/ta_func/ta_CMO.c \
                3rdparty/ta-lib/ta_func/ta_CORREL.c \
                3rdparty/ta-lib/ta_func/ta_MAVP.c \
                3rdparty/ta-lib/ta_func/ta_MIDPOINT.c \
                3rdparty/ta-lib/ta_func/ta_PVI.c \
                3rdparty/ta-lib/ta_func/ta_DIV.c \
                3rdparty/ta-lib/ta_func/ta_TRIMA.c \
                3rdparty/ta-lib/ta_func/ta_PLUS_DM.c \
                3rdparty/ta-lib/ta_func/ta_BBANDS.c \
                3rdparty/ta-lib/ta_func/ta_TAN.c \
                3rdparty/ta-lib/ta_func/ta_SIN.c \
                3rdparty/ta-lib/ta_func/ta_CDLLONGLEGGEDDOJI.c \
                3rdparty/ta-lib/ta_func/ta_ULTOSC.c \
                3rdparty/ta-lib/ta_func/ta_KAMA.c \
                3rdparty/ta-lib/ta_func/ta_CDLLADDERBOTTOM.c \
                3rdparty/ta-lib/ta_func/ta_ADXR.c \
                3rdparty/ta-lib/ta_func/ta_CDL3STARSINSOUTH.c \
                3rdparty/ta-lib/ta_func/ta_CDLLONGLINE.c \
                3rdparty/libjson/_internal/Source/JSONAllocator.cpp \
                3rdparty/libjson/_internal/Source/JSONChildren.cpp \
                3rdparty/libjson/_internal/Source/JSONDebug.cpp \
                3rdparty/libjson/_internal/Source/JSONIterators.cpp \
                3rdparty/libjson/_internal/Source/JSONMemory.cpp \
                3rdparty/libjson/_internal/Source/JSONNode.cpp \
                3rdparty/libjson/_internal/Source/JSONNode_Mutex.cpp \
                3rdparty/libjson/_internal/Source/JSONPreparse.cpp \
                3rdparty/libjson/_internal/Source/JSONStream.cpp \
                3rdparty/libjson/_internal/Source/JSONValidator.cpp \
                3rdparty/libjson/_internal/Source/JSONWorker.cpp \
                3rdparty/libjson/_internal/Source/JSONWriter.cpp \
                3rdparty/libjson/_internal/Source/internalJSONNode.cpp \
                3rdparty/libjson/_internal/Source/libjson.cpp \
    utils/log.cpp \
    utils/timer.cpp \
    core/compute_engine.cpp \
    core/excute_engine.cpp \
    core/io_engine.cpp \
    core/strategy_engine.cpp \
    core/trade_engine.cpp \
    core/event_engine.cpp \
    core/gateway.cpp \
    api/ctp/ctpgateway.cpp


HEADERS  += ifquant.h \
    utils/boost_helper.h \
    core/action.h \
                3rdparty/ta-lib/include/ta_frame_priv.h \
                3rdparty/ta-lib/include/ta_java_defs.h \
                3rdparty/ta-lib/include/ta_frame.h \
                3rdparty/ta-lib/include/ta_def_ui.h \
                3rdparty/ta-lib/include/ta_memory.h \
                3rdparty/ta-lib/include/ta_pragma.h \
                3rdparty/ta-lib/include/ta_global.h \
                3rdparty/ta-lib/include/ta_magic_nb.h \
                3rdparty/ta-lib/include/ta_utility.h \
                3rdparty/ta-lib/include/ta_abstract.h \
                3rdparty/ta-lib/include/ta_common.h \
                3rdparty/ta-lib/include/ta_defs.h \
                3rdparty/ta-lib/include/ta_func.h \
                3rdparty/ta-lib/include/ta_libc.h \
                3rdparty/sqlite3/include/sqlite3ext.h \
                3rdparty/sqlite3/include/sqlite3.h \
                3rdparty/libjson/JSONOptions.h \
                3rdparty/libjson/libjson.h \
    3rdparty/libjson/_internal/Dependencies/libbase64++/libbase64++.h \
    3rdparty/libjson/_internal/Dependencies/mempool++/mempool.h \
    3rdparty/libjson/_internal/Source/JSONDefs/GNU_C.h \
    3rdparty/libjson/_internal/Source/JSONDefs/Strings_Defs.h \
    3rdparty/libjson/_internal/Source/JSONDefs/Unknown_C.h \
    3rdparty/libjson/_internal/Source/JSONDefs/Visual_C.h \
    3rdparty/libjson/_internal/Source/internalJSONNode.h \
    3rdparty/libjson/_internal/Source/JSON_Base64.h \
    3rdparty/libjson/_internal/Source/JSONAllocator.h \
    3rdparty/libjson/_internal/Source/JSONChildren.h \
    3rdparty/libjson/_internal/Source/JSONDebug.h \
    3rdparty/libjson/_internal/Source/JSONDefs.h \
    3rdparty/libjson/_internal/Source/JSONGlobals.h \
    3rdparty/libjson/_internal/Source/JSONMemory.h \
    3rdparty/libjson/_internal/Source/JSONMemoryPool.h \
    3rdparty/libjson/_internal/Source/JSONNode.h \
    3rdparty/libjson/_internal/Source/JSONPreparse.h \
    3rdparty/libjson/_internal/Source/JSONSharedString.h \
    3rdparty/libjson/_internal/Source/JSONSingleton.h \
    3rdparty/libjson/_internal/Source/JSONStats.h \
    3rdparty/libjson/_internal/Source/JSONStream.h \
    3rdparty/libjson/_internal/Source/JSONValidator.h \
    3rdparty/libjson/_internal/Source/JSONWorker.h \
    3rdparty/libjson/_internal/Source/NumberToString.h \
    3rdparty/ta-lib/ta_abstract/templates/ta_frame.c.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_frame.h.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_func.h.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_func_api.c.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_retcode.c.template \
    common/appinfo.h \
    utils/log.h \
    core/event_engine.h \
    core/gateway.h \
    core/struct.h \
    3rdparty/asmlib/asmlib.h \
    3rdparty/asmlib/asmlibran.h \
    api/ctp/linux64/ThostFtdcMdApi.h \
    api/ctp/linux64/ThostFtdcTraderApi.h \
    api/ctp/linux64/ThostFtdcUserApiDataType.h \
    api/ctp/linux64/ThostFtdcUserApiStruct.h \
    api/ctp/ctpgateway.h

FORMS    += ifquant.ui

#DISTFILES += \
#    build-ifquant-Desktop_Qt_5_7_0_GCC_64bit-Debug/ifquant \
#    README.md \
#    3rdparty/ta-lib/ta_common/ta_retcode.csv \
#    3rdparty/ta-lib/ta_abstract/templates/CoreAnnotated.java.template \
#    3rdparty/ta-lib/ta_abstract/templates/excel_glue.c.template \
#    3rdparty/ta-lib/ta_abstract/templates/ta_func.swg.template \
#    3rdparty/ta-lib/ta_abstract/templates/ta_group_idx.c.template \
#    3rdparty/ta-lib/ta_abstract/templates/ta_java_defs.h.template \
#    3rdparty/ta-lib/ta_abstract/templates/ta_x.c.template

DISTFILES += \
    3rdparty/ta-lib/ta_common/ta_retcode.csv \
    3rdparty/ta-lib/ta_abstract/templates/CoreAnnotated.java.template \
    3rdparty/ta-lib/ta_abstract/templates/excel_glue.c.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_func.swg.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_group_idx.c.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_java_defs.h.template \
    3rdparty/ta-lib/ta_abstract/templates/ta_x.c.template \
    README.md \
    3rdparty/asmlib/libaomf32.lib \
    3rdparty/asmlib/libaomf32o.lib \
    3rdparty/asmlib/asmlib-instructions.pdf \
    3rdparty/asmlib/libacof32.lib \
    3rdparty/asmlib/libacof32o.lib \
    3rdparty/asmlib/libacof64.lib \
    3rdparty/asmlib/libacof64o.lib \
    3rdparty/asmlib/libad32.lib \
    3rdparty/asmlib/libad64.lib \
    3rdparty/asmlib/libaelf32.a \
    3rdparty/asmlib/libaelf32o.a \
    3rdparty/asmlib/libaelf64.a \
    3rdparty/asmlib/libaelf64o.a \
    3rdparty/asmlib/libamac32.a \
    3rdparty/asmlib/libamac32o.a \
    3rdparty/asmlib/libamac64.a \
    3rdparty/asmlib/libamac64o.a \
    3rdparty/asmlib/libad32.dll \
    3rdparty/asmlib/libad64.dll \
    3rdparty/asmlib/src/asmlibSrc.zip \
    3rdparty/asmlib/asmlibSrc.zip \
    3rdparty/asmlib/inteldispatchpatch.zip \
    3rdparty/asmlib/src/asmlib.make \
    3rdparty/asmlib/src/libad32.def \
    3rdparty/asmlib/src/libad64.def \
    3rdparty/asmlib/src/MakeAsmlib.bat \
    3rdparty/asmlib/src/randomah.asi \
    3rdparty/asmlib/license.txt \
    3rdparty/asmlib/src/cachesize32.asm \
    3rdparty/asmlib/src/cachesize64.asm \
    3rdparty/asmlib/src/cpuid32.asm \
    3rdparty/asmlib/src/cpuid64.asm \
    3rdparty/asmlib/src/cputype32.asm \
    3rdparty/asmlib/src/cputype64.asm \
    3rdparty/asmlib/src/debugbreak32.asm \
    3rdparty/asmlib/src/debugbreak64.asm \
    3rdparty/asmlib/src/dispatchpatch32.asm \
    3rdparty/asmlib/src/dispatchpatch64.asm \
    3rdparty/asmlib/src/divfixedi32.asm \
    3rdparty/asmlib/src/divfixedi64.asm \
    3rdparty/asmlib/src/divfixedv32.asm \
    3rdparty/asmlib/src/divfixedv64.asm \
    3rdparty/asmlib/src/instrset32.asm \
    3rdparty/asmlib/src/instrset64.asm \
    3rdparty/asmlib/src/libad32.asm \
    3rdparty/asmlib/src/libad64.asm \
    3rdparty/asmlib/src/memcmp32.asm \
    3rdparty/asmlib/src/memcmp64.asm \
    3rdparty/asmlib/src/memcpy32.asm \
    3rdparty/asmlib/src/memcpy64.asm \
    3rdparty/asmlib/src/memmove32.asm \
    3rdparty/asmlib/src/memmove64.asm \
    3rdparty/asmlib/src/memset32.asm \
    3rdparty/asmlib/src/memset64.asm \
    3rdparty/asmlib/src/mersenne32.asm \
    3rdparty/asmlib/src/mersenne64.asm \
    3rdparty/asmlib/src/mother32.asm \
    3rdparty/asmlib/src/mother64.asm \
    3rdparty/asmlib/src/physseed32.asm \
    3rdparty/asmlib/src/physseed64.asm \
    3rdparty/asmlib/src/popcount32.asm \
    3rdparty/asmlib/src/popcount64.asm \
    3rdparty/asmlib/src/procname32.asm \
    3rdparty/asmlib/src/procname64.asm \
    3rdparty/asmlib/src/rdtsc32.asm \
    3rdparty/asmlib/src/rdtsc64.asm \
    3rdparty/asmlib/src/round32.asm \
    3rdparty/asmlib/src/round64.asm \
    3rdparty/asmlib/src/sfmt32.asm \
    3rdparty/asmlib/src/sfmt64.asm \
    3rdparty/asmlib/src/strcat32.asm \
    3rdparty/asmlib/src/strcat64.asm \
    3rdparty/asmlib/src/strcmp32.asm \
    3rdparty/asmlib/src/strcmp64.asm \
    3rdparty/asmlib/src/strcountset32.asm \
    3rdparty/asmlib/src/strcountset64.asm \
    3rdparty/asmlib/src/strcountutf832.asm \
    3rdparty/asmlib/src/strcountutf864.asm \
    3rdparty/asmlib/src/strcpy32.asm \
    3rdparty/asmlib/src/strcpy64.asm \
    3rdparty/asmlib/src/stricmp32.asm \
    3rdparty/asmlib/src/stricmp64.asm \
    3rdparty/asmlib/src/strlen32.asm \
    3rdparty/asmlib/src/strlen64.asm \
    3rdparty/asmlib/src/strspn32.asm \
    3rdparty/asmlib/src/strspn64.asm \
    3rdparty/asmlib/src/strstr32.asm \
    3rdparty/asmlib/src/strstr64.asm \
    3rdparty/asmlib/src/strtouplow32.asm \
    3rdparty/asmlib/src/strtouplow64.asm \
    3rdparty/asmlib/src/substring32.asm \
    3rdparty/asmlib/src/substring64.asm \
    3rdparty/asmlib/src/unalignedisfaster32.asm \
    3rdparty/asmlib/src/unalignedisfaster64.asm \
    api/API/v6.3.6_20160606_api_tradeapi_linux64/thostmduserapi.so \
    api/API/v6.3.6_20160606_api_tradeapi_linux64/thosttraderapi.so \
    api/API/v6.3.6_20160606_api_tradeapi_linux64/error.xml \
    api/API/v6.3.6_20160606_api_tradeapi_linux64/error.dtd \
    doc/CTPcdg_ch.pdf \
    api/ctp/linux64/thostmduserapi.so \
    api/ctp/linux64/thosttraderapi.so \
    api/ctp/linux64/error.xml \
    api/ctp/linux64/error.dtd \
    api/ctp/63620160606API.zip
