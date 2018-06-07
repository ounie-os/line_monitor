#ifndef DATACONF_H
#define DATACONF_H

#include <QDateTime>

typedef qint8     int8_t;
typedef quint8    uint8_t;
typedef qint16    int16_t;
typedef quint16   uint16_t;
typedef qint32    int32_t;
typedef quint32   uint32_t;

enum messageType
{
    undefinedMessage = 0x00, //未定义报文类型
    sndDataMessage = 0x01, //服务端数据请求报文类型
    rcvDataMessage = 0x81, //监控设备数据回报报文类型
    sndConfigWriteMessage = 0x02, //服务端写参数报文类型
    rcvConfigWriteMessage = 0x82, //监控器端改变参数应答报文类型
    sndConfigReadMessage = 0x03, //服务端读参数报文类型
    rcvConfigReadMessage = 0x83, //监控器端参数发送报文类型
    rcvAlarmMessage = 0x84, //监控器端报警报文类型
    rcvHeartBeatMessage = 0x85
};

enum dataType
{
    DataTypeReserved = 0x00, //保留
    MainCable_RT = 0x01, //主缆电流实时值
    MainCable_AVG = 0x02, //主缆电流统计平均值
    MainCable_MAX = 0x03, //主缆电流统计最大值
    MainCable_MIN = 0x04, //主缆电流统计最小值
    MainCable_Alarm = 0x05, //主缆报警值

    GroundCablePhaseA_RT = 0x06, //护层环流A相实时值
    GroundCablePhaseA_AVG = 0x07, //护层环流A相统计平均值
    GroundCablePhaseA_MAX = 0x08, //护层环流A相统计最大值
    GroundCablePhaseA_MIN = 0x09, //护层环流A相统计最小值
    GroundCablePhaseA_Alarm = 0x0A, //护层环流A相报警值

    GroundCablePhaseB_RT = 0x0B, //护层环流B相实时值
    GroundCablePhaseB_AVG = 0x0C, //护层环流B相统计平均值
    GroundCablePhaseB_MAX = 0x0D, //护层环流B相统计最大值
    GroundCablePhaseB_MIN = 0x0E, //护层环流B相统计最小值
    GroundCablePhaseB_Alarm = 0x0F, //护层环流B相报警值

    GroundCablePhaseC_RT = 0x10, //护层环流C相实时值
    GroundCablePhaseC_AVG = 0x11, //护层环流C相统计平均值
    GroundCablePhaseC_MAX = 0x12, //护层环流C相统计最大值
    GroundCablePhaseC_MIN = 0x13, //护层环流C相统计最小值
    GroundCablePhaseC_Alarm = 0x14, //护层环流C相报警值

    GroundCablePhaseN_RT = 0x15, //护层环流N相实时值
    GroundCablePhaseN_AVG = 0x16, //护层环流N相统计平均值
    GroundCablePhaseN_MAX = 0x17, //护层环流N相统计最大值
    GroundCablePhaseN_MIN = 0x18, //护层环流N相统计最小值
    GroundCablePhaseN_Alarm = 0x19, //护层环流N相报警值

    InputVolt = 0x1A, //电池输入电压

    MainCableChangeRate_Alarm = 0x1B, //主缆电流变化率报警
    GroundCablePhaseAChangeRate_Alarm = 0x1C, //A相接地电缆电流变化率报警
    GroundCablePhaseBChangeRate_Alarm = 0x1D, //B相接地电缆电流变化率报警
    GroundCablePhaseCChangeRate_Alarm = 0x1E, //C相接地电缆电流变化率报警
    GroundCablePhaseNChangeRate_Alarm = 0x1F, //N相接地电缆电流变化率报警


    GroundCablePhaseA_Temp_RT = 0x20,
    GroundCablePhaseA_Temp_Alarm = 0x21, //A相接地电缆温度报警
    GroundCablePhaseB_Temp_RT = 0x22,
    GroundCablePhaseB_Temp_Alarm = 0x23, //B相接地电缆温度报警
    GroundCablePhaseC_Temp_RT = 0x24,
    GroundCablePhaseC_Temp_Alarm = 0x25, //C相接地电缆温度报警
    GroundCablePhaseN_Temp_RT = 0x26,
    GroundCablePhaseN_Temp_Alarm = 0x27, //N相接地电缆温度报警

    GroundCablePhaseAVibrationCount_Alarm = 0x28, //A相接地电缆振动次数报警
    GroundCablePhaseBVibrationCount_Alarm = 0x29, //B相接地电缆振动次数报警
    GroundCablePhaseCVibrationCount_Alarm = 0x2A, //C相接地电缆振动次数报警
    GroundCablePhaseNVibrationCount_Alarm = 0x2B, //N相接地电缆振动次数报警

    GroundCablePhaseA_Temp_AVG = 0x2C,
    GroundCablePhaseA_Temp_MAX = 0x2D,
    GroundCablePhaseA_Temp_MIN = 0x2E,

    GroundCablePhaseB_Temp_AVG = 0x2F,
    GroundCablePhaseB_Temp_MAX = 0x30,
    GroundCablePhaseB_Temp_MIN = 0x31,

    GroundCablePhaseC_Temp_AVG = 0x32,
    GroundCablePhaseC_Temp_MAX = 0x33,
    GroundCablePhaseC_Temp_MIN = 0x34,

    GroundCablePhaseN_Temp_AVG = 0x35,
    GroundCablePhaseN_Temp_MAX = 0x36,
    GroundCablePhaseN_Temp_MIN = 0x37,

    GroundCablePhaseA_Warning  = 0x38,
    GroundCablePhaseB_Warning  = 0x39,
    GroundCablePhaseC_Warning  = 0x3A,
    GroundCablePhaseN_Warning  = 0x3B,

    GroundCablePhaseA_Load_RT  = 0x3C,
    GroundCablePhaseA_Load_AVG = 0x3D,
    GroundCablePhaseA_Load_MAX = 0x3E,
    GroundCablePhaseA_Load_MIN = 0x3F,
    GroundCablePhaseA_Load_Alarm = 0x40,
    GroundCablePhaseA_Load_Warning = 0x41,

    GroundCablePhaseB_Load_RT  = 0x42,
    GroundCablePhaseB_Load_AVG = 0x43,
    GroundCablePhaseB_Load_MAX = 0x44,
    GroundCablePhaseB_Load_MIN = 0x45,
    GroundCablePhaseB_Load_Alarm = 0x46,
    GroundCablePhaseB_Load_Warning = 0x47,

    GroundCablePhaseC_Load_RT  = 0x48,
    GroundCablePhaseC_Load_AVG = 0x49,
    GroundCablePhaseC_Load_MAX = 0x4A,
    GroundCablePhaseC_Load_MIN = 0x4B,
    GroundCablePhaseC_Load_Alarm = 0x4C,
    GroundCablePhaseC_Load_Warning = 0x4D,

    GroundCablePhaseN_Load_RT  = 0x4E,
    GroundCablePhaseN_Load_AVG = 0x4F,
    GroundCablePhaseN_Load_MAX = 0x50,
    GroundCablePhaseN_Load_MIN = 0x51,
    GroundCablePhaseN_Load_Alarm = 0x52,
    GroundCablePhaseN_Load_Warning = 0x53,

    GroundCablePhaseA_Ratio_RT = 0x54,
    GroundCablePhaseA_Ratio_Alarm = 0x55,
    GroundCablePhaseA_Ratio_Warning = 0x56,

    GroundCablePhaseB_Ratio_RT = 0x57,
    GroundCablePhaseB_Ratio_Alarm = 0x58,
    GroundCablePhaseB_Ratio_Warning = 0x59,

    GroundCablePhaseC_Ratio_RT = 0x5A,
    GroundCablePhaseC_Ratio_Alarm = 0x5B,
    GroundCablePhaseC_Ratio_Warning = 0x5C,

    GroundCablePhaseN_Ratio_RT = 0x5D,
    GroundCablePhaseN_Ratio_Alarm = 0x5E,
    GroundCablePhaseN_Ratio_Warning = 0x5F,
};

enum configType
{
    ConfigReserved = 0x00, //保留
    StatisticArgument = 0x01, //统计周期
    MainCable_Alarm_Threhold = 0x02, //主缆报警阈值
    GroundCablePhaseA_Alarm_Threhold = 0x03, //护层环流A相报警阈值
    GroundCablePhaseB_Alarm_Threhold = 0x04, //护层环流B相报警阈值
    GroundCablePhaseC_Alarm_Threhold = 0x05, //护层环流C相报警阈值
    GroundCablePhaseN_Alarm_Threhold = 0x06, //
    RtcTime_Set = 0x07,
    SERVERIP_Address = 0x08,
    SERVERIP_Port = 0x09,
    MainCableCtValue_Set = 0x0A,
    GroundCablePhaseACtValue_Set = 0x0B,
    GroundCablePhaseBCtValue_Set = 0x0C,
    GroundCablePhaseCCtValue_Set = 0x0D,
    GroundCablePhaseNCtValue_Set = 0x0E,

//    MainCableChangeRate_Alarm_Threshold = 0x0F, //主缆电流变化率报警阀值
    SetChangeRateStatistical     = 0x0F,                //设置电流检测周期  电流变化率统计周期单位: 分钟[1 ~ 43210] 默认60
                                                        //变化率窗大小=变化率检测周期/电流采样周期，变化率窗范围：1-2048

    GroundCablePhaseAChangeRate_Alarm_Threshold = 0x10, //A相接地电缆电流变化率报警阀值
    GroundCablePhaseBChangeRate_Alarm_Threshold = 0x11, //B相接地电缆电流变化率报警阀值
    GroundCablePhaseCChangeRate_Alarm_Threshold = 0x12, //C相接地电缆电流变化率报警阀值
    GroundCablePhaseNChangeRate_Alarm_Threshold = 0x13, //N相接地电缆电流变化率报警阀值
    //(无符号32为变化率阀值为 mA/分钟)

    GroundCablePhaseATemperature_Alarm_Threshold = 0x14, //A相接地电缆温度报警阀值
    GroundCablePhaseBTemperature_Alarm_Threshold = 0x15, //B相接地电缆温度报警阀值
    GroundCablePhaseCTemperature_Alarm_Threshold = 0x16, //C相接地电缆温度报警阀值
    GroundCablePhaseNTemperature_Alarm_Threshold = 0x17, //N相接地电缆温度报警阀值
    //(有符号32位温度单位为摄氏度)


    GroundCablePhaseAVibrationCount_Alarm_Threshold = 0x18, //A相接地电缆振动次数报警阀值
    GroundCablePhaseBVibrationCount_Alarm_Threshold = 0x19, //B相接地电缆振动次数报警阀值
    GroundCablePhaseCVibrationCount_Alarm_Threshold = 0x1A, //C相接地电缆振动次数报警阀值
    GroundCablePhaseNVibrationCount_Alarm_Threshold = 0x1B, //N相接地电缆振动次数报警阀值
    //(无符号32 位震动次数为次数/秒 )

    ChangeRateStatisticalCycle = 0x1C,  //读取电流变化周期
    TemperatureMeasureCycle = 0x1D, //温度测量周期，单位:秒[10-1800],默认60
    VibrationStatisticalCycle = 0x1E, //震动统计周期，单位:秒[1-600],默认10

    CurrentChannelControl = 0x1F, //电流测量通道使能控制
    TemperatureChannelControl = 0x20, //温度测量通道使能控制
    VibrationChannelControl = 0x21, //振动测量通道使能控制

    MainCableTemperature_Alarm_Threshold = 0x5F, //主缆缆温度报警阀值

    IAPUpdate = 0xED,
    ResetSystem = 0xEE
};

enum current_type
{
    GroundCablePhaseA = 0x00,  // A相接地电流
    GroundCablePhaseB,         // B相接地电流
    GroundCablePhaseC,         // C相接地电流
    GroundCablePhaseN,       // N相接地电流
    GroundCablePhaseMain,        // 主缆电流
    ConnectorATemp,            // A接头温度
    ConnectorBTemp,            // B接头温度
    ConnectorCTemp,            // C接头温度
    GroundCable_A_Alarm, // A相接地电流报警
    GroundCable_B_Alarm, // B相接地电流报警
    GroundCable_C_Alarm, // C相接地电流报警
    GroundCable_N_Alarm, // N相接地电流报警
    GroundCable_Main_Alarm, // 主缆接地电流报警
    GroundCablePhaseA_Rate_Alarm, // A相接地电流变化率报警
    GroundCablePhaseB_Rate_Alarm, // B相接地电流变化率报警
    GroundCablePhaseC_Rate_Alarm, // C相接地电流变化率报警
    GroundCablePhaseN_Rate_Alarm, // N相接地电流变化率报警
    GroundCablePhaseMain_Rate_Alarm, // 主缆接地电流变化率报警
    ConnectorATemp_Alarm,            // A接头温度报警
    ConnectorBTemp_Alarm,            // B接头温度报警
    ConnectorCTemp_Alarm,            // C接头温度报警
};


#endif
