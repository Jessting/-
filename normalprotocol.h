#ifndef NORMALPROTOCOL_H
#define NORMALPROTOCOL_H

#include "abstructprotocol.h"

#include <QQueue>//QQueue类是提供队列的通用容器。
#include <QVariant>//QVariant类的作用类似于最常见的Qt数据类型的联合。

/*用户操作类型*/
enum USER_OPER{
    OperType_None = 0x30,   //空操作
    OperType_Login,         //登陆
    OperType_Student,       //学籍管理
    OperType_Take,          //网上选课
    OperType_Arrange,       //教学安排
    OperType_Exam,          //考试安排
    OperType_Grade,         //成绩管理
    OperType_Teacher,       //教师管理
    OperType_User,          //用户管理
    OperType_Admin,         //管理员信息
    OperType_Department,    //系别管理
    OperType_Class,         //班级管理
    OperType_Room,          //教室分配
    OperType_Time,          //时间安排
    OperType_Other          //其他

};

/*登陆-操作命令定义*/
enum CMD_LOGIN{
    CmdLogin_LoginAsk = 0x30,//登录请求
    CmdLogin_RemeberAsk,     //记住密码
    CmdLogin_ForgetAsk,     //忘记密码
    CmdLogin_QuitAsk        //退出
};

/*学籍管理-操作命令定义*/
enum CMD_STUDENT{
    CmdStudent_AskStuInfo = 0x30,//学生信息获取
    CmdStudent_AddStuInfo,     //添加学生信息
    CmdStudent_ModifyStuInfo,  //修改学生信息
    CmdStudent_DelStuInfo      //删除学生信息
};

/*网上选课-操作命令定义*/
enum CMD_TAKE{
    CmdTake_AskManageInfo = 0x30,//查看选课管理规定
    CmdTake_Take,          //选课
    CmdTake_AskResult,     //查看选课结果
    CmdTake_AgainTake,     //补选
    CmdTake_QuitTake       //退选
};

/*教学安排（排课）-操作命令定义*/
enum CMD_ARRANGE{
    CmdArrange_AskArrange = 0x30,//查看排课表
    CmdArrange_AddArrange,        //添加排课信息
    CmdArrange_ModifyArrange,     //修改排课信息
    CmdArrange_DelArrange         //删除排课信息

};

/*考试安排-操作命令定义*/
enum CMD_EXAM{
    CmdExam_AskExamInfo = 0x30,//查看考试安排表
    CmdExam_ModifyExam,        //修改考试安排表
    CmdExam_AddExam,           //添加考试信息
    CmdExam_DelExam          //删除考试信息

};

/*成绩管理-操作命令定义*/
enum CMD_GRADE{
    CmdGrade_AddGrade = 0x30,//录入成绩
    CmdGrade_AskGradeInfo,   //查询成绩
    CmdGrade_ModifyGrade,    //修改成绩
    CmdGrade_DelGrade,       //删除成绩
    CmdGrade_AnalyzeGrade    //统计成绩

};

/*教师信息管理-操作命令定义*/
enum CMD_TEACHER{
    CmdTeacher_AskTeachInfo = 0x30,//教师信息获取
    CmdTeacher_AddTeacher,     //添加教师信息
    CmdTeacher_ModifyTeacher,  //修改教师信息
    CmdTeacher_DelTeacher      //删除教师信息
};

/*教师信息管理-操作命令定义*/
enum CMD_USER{
    CmdUser_AskUserInfo = 0x30,//用户信息获取
    CmdUser_SelectUser        //查询用户

};

/*教务管理员信息-操作命令定义*/
enum CMD_ADMIN{
    CmdAdmin_AddAdmin = 0x30,//添加管理员
    CmdAdmin_DelAdmin,       //删除管理员
    CmdAdmin_AskAdmin,       //管理员信息获取
    CmdAdmin_ModifyAdmin     //管理员信息修改
};

/*系别管理-操作命令定义*/
enum CMD_DEPARTMENT{
    CmdDepart_AskDepartInfo = 0x30,//查看系别信息
    CmdDepart_ModifyDepart,       //修改系别信息
    CmdDepart_AddDepart,          //添加系别信息
    CmdDepart_DelDepart          //删除系别信息
};

/*班级管理-操作命令定义*/
enum CMD_CLASS{
    CmdClass_AskClassInfo = 0x30,//查看班级信息
    CmdClass_ModifyClass,       //修改班级信息
    CmdClass_AddClass,          //添加班级信息
    CmdClass_DelClass           //删除班级信息
};

/*教室分配-操作命令定义*/
enum CMD_ROOM{
    CmdRoom_AskRoomInfo = 0x30,//查看教室信息
    CmdRoom_ModifyRoom,       //修改教室信息
    CmdRoom_AddRoom,          //添加教室信息
    CmdRoom_DelRoom           //删除教室信息
};

/*时间安排-操作命令定义*/
enum CMD_TIME{
    CmdTime_AskTimeInfo = 0x30,//查看时间安排表
    CmdTime_ModifyTime,       //修改时间安排
    CmdTime_AddTime,          //添加时间安排
    CmdTime_DelTime           //删除时间安排
};

/*其他-操作命令定义*/
enum CMD_OTHER{
    CmdOther_DownFile = 0x30,//下载文件
    CmdOther_UpFile,              //上传文件
    CmdOther_ModifyPswd,          //修改密码
    CmdOther_AskHelp,             //帮助说明
    CmdOther_AskVersion           //介绍版本
};

class NormalProtocol : public AbstructProtocol
{
public:
    //正常协议带参数的构造函数
    NormalProtocol(quint32 client = CLIENT_NONE,
                   quint8 operType = OperType_None,
                   quint8 operCmd = MSG_NONE_CMD,
                   quint8 dataType = DataType_None,
                   QByteArray dataCont = QByteArray());
    ~NormalProtocol();//正常协议的析构函数

    //更新正常协议
    void updateNormalProtocol(quint32 client = CLIENT_NONE,
                   quint8 operType = OperType_None,
                   quint8 operCmd = MSG_NONE_CMD,
                   quint8 dataType = DataType_None,
                   QByteArray dataCont = QByteArray());

    void clearProtocolData(); //清除协议数据
    void displayProtocol() const; //打印协议
    const QByteArray packetProtocol() const; //打包协议，传出字节数组
    void unPacketProcotol(QDataStream &in) ; //解包协议，传入字节流引用

    /*normal protocol detail*/
    quint8 m_operType;  //数据，操作类型
    quint8 m_operCmd;   //数据，操作命令
    quint8 m_dataType;  //数据，数据类型
    QByteArray m_dataCont;//数据，数据协议内容
};

typedef QQueue<NormalProtocol> QueueNormalProtocol;//自定义正常协议队列

#endif // NORMALPROTOCOL_H
