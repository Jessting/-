#ifndef EXECNORMALPROTOCOL_H
#define EXECNORMALPROTOCOL_H

#include <QThread>

#include "info.h"
#include "datapacket.h"
#include "normalprotocol.h"

class ExecNormalProtocol : public QObject
{
    Q_OBJECT
public:
    ExecNormalProtocol(QObject *parent = 0);//构造函数
    ~ExecNormalProtocol();//析构函数

    void execOperateCmd(const NormalProtocol &protocol);//执协议中的操作命令

    ////登陆
    void execOperateCmdLogin(void);     //执行操作命令-登陆
    void execOperateCmdLoginAsk(void);  //执行操作命令-登陆请求

    ////学生学籍管理
    void execOperateCmdStudent(void);    //执行操作命令-学籍管理
    void execOperateCmdAskStuInfo(void); //学生信息获取
    void execOperateCmdAddStuInfo(void);  //添加学生信息
    void execOperateCmdModifyStuInfo(void); //修改学生信息
    void execOperateCmdDelStuInfo(void);    //删除学生信息

    ////网上选课操作
    void execOperateCmdTake(void);          //执行操作命令-网上选课
    void execOperateCmdAskManageInfo(void); //执行操作命令-查看选课管理规定
    void execOperateCmdTake_Take(void);     //执行操作命令-选课
    void execOperateCmdAskResult(void);     //执行操作命令-查看选课结果
    void execOperateCmdAgainTake(void);     //执行操作命令-补选
    void execOperateCmdQuitTake(void);      //执行操作命令-退选

    ////教学安排表/排课表
    void execOperateCmdArrange(void);      //执行操作命令-执行操作命令-教学安排
    void execOperateCmdAskArrange(void);   //执行操作命令-查看排课表
    void execOperateCmdAddArrange(void);   //执行操作命令-添加排课信息
    void execOperateCmdModifyArrange(void);//执行操作命令-修改排课信息
    void execOperateCmdDelArrange(void);   //执行操作命令-删除排课信息

    ////考试安排
    void execOperateCmdExam(void);       //执行操作命令-执行操作命令-考试安排
    void execOperateCmdAskExamInfo(void);//执行操作命令-查看考试安排表
    void execOperateCmdModifyExam(void); //执行操作命令-修改考试安排表
    void execOperateCmdAddExam(void);    //执行操作命令-添加考试信息
    void execOperateCmdDelExam(void);    //执行操作命令-删除考试信息


    ////成绩管理
    void execOperateCmdGrade(void);        //执行操作命令-成绩管理
    void execOperateCmdAddGrade(void);     //执行操作命令-录入成绩
    void execOperateCmdAskGradeInfo(void); //执行操作命令-查询成绩
    void execOperateCmdModifyGrade(void);  //执行操作命令-修改成绩
    void execOperateCmdDelGrade(void);     //执行操作命令-删除成绩
    void execOperateCmdAnalyzeGrade (void);//执行操作命令-统计成绩

    ////教师信息
    void execOperateCmdTeacher(void);       //执行操作命令-教师管理
    void execOperateCmdAskTeachInfo(void);  //执行操作命令-教师信息获取
    void execOperateCmdAddTeacher(void);    //执行操作命令-添加教师信息
    void execOperateCmdModifyTeacher(void); //执行操作命令-修改教师信息
    void execOperateCmdDelTeacher (void);   //执行操作命令-删除教师信息


    ////用户管理
    void execOperateCmdUser(void);       //执行操作命令-用户管理
    void execOperateCmdAskUserInfo(void);//执行操作命令-用户信息获取
    void execOperateSelectUser(void);    //执行操作命令-查询用户

    ////管理员
    void execOperateCmdAdmin(void);        //执行操作命令-管理员信息
    void execOperateCmdAddAdmin(void);     //执行操作命令-添加管理员
    void execOperateCmdDelAdmin(void);     //执行操作命令-删除管理员
    void execOperateCmdAskAdmin(void);     //执行操作命令-管理员信息获取
    void execOperateCmdModifyAdmin (void); //执行操作命令-管理员信息修改

    ////系别管理
    void execOperateCmdDepartment(void);     //执行操作命令-系别管理
    void execOperateCmdAskDepartInfo (void); //执行操作命令-查看系别信息
    void execOperateCmdModifyDepart(void);   //执行操作命令-修改系别信息
    void execOperateCmdAddDepart(void);      //执行操作命令-添加系别信息
    void execOperateCmdDelDepart (void);     //执行操作命令-删除系别信息

    ////班级管理
    void execOperateCmdClass(void);         //执行操作命令-班级管理
    void execOperateCmdAskClassInfo(void);  //执行操作命令-查看班级信息
    void execOperateCmdModifyClass(void);   //执行操作命令-修改班级信息
    void execOperateCmdAddClass(void);      //执行操作命令-添加班级信息
    void execOperateCmdDelClass(void);      //执行操作命令-删除班级信息

    ////教室分配
    void execOperateCmdRoom(void);       //执行操作命令-教室分配
    void execOperateCmdAskRoomInfo(void);//执行操作命令-查看教室信息
    void execOperateCmdModifyRoom(void); //执行操作命令-修改教室信息
    void execOperateCmdAddRoom(void);    //执行操作命令-添加教室信息
    void execOperateCmdDelRoom(void);    //执行操作命令-删除教室信息

    ////时间安排
    void execOperateCmdTime(void);        //执行操作命令-时间安排
    void execOperateCmdAskTimeInfo(void); //执行操作命令-查看时间安排表
    void execOperateCmdModifyTime(void);  //执行操作命令-修改时间安排
    void execOperateCmdAddTime(void);     //执行操作命令-添加时间安排
    void execOperateCmdDelTime(void);     //执行操作命令-删除时间安排

    ////其他操作
    void execOperateCmdOther(void);      //执行操作命令-其他
    void execOperateCmdDownFile(void);   //执行操作命令-下载文件
    void execOperateCmdUpFile(void);     //执行操作命令-上传文件
    void execOperateCmdModifyPswd(void); //执行操作命令-修改密码
    void execOperateCmdAskHelp(void);    //执行操作命令-帮助说明
    void execOperateCmdAskVersion (void);//执行操作命令-介绍版本

signals:
    void signalSendDataToClient(QByteArray buffer);//信号-发送数据到客户端
    void signalUserLoginSuccess(User info);     //信号-用户登录成功

private:
    NormalProtocol m_protocol; //对象-正常协议
    DataPacket m_dataPacket;   //对象-数据包

};

#endif // EXECNORMALPROTOCOL_H
