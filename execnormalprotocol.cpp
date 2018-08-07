#include "execnormalprotocol.h"


#include <QDebug>
#include <QStringList>

#include "info.h"

ExecNormalProtocol::ExecNormalProtocol(QObject *parent)
          :QObject(parent)
{

}

ExecNormalProtocol::~ExecNormalProtocol()//析构函数
{

}

///执协议中的操作命令
void ExecNormalProtocol::execOperateCmd(const NormalProtocol &protocol)
{
    m_protocol = protocol;
    //qDebug() << "void ExecNormalProtocol::execUserOperate(void)";
    switch (m_protocol.m_operType) {
    case OperType_None: break;                             //操作-空操作
    case OperType_Login: execOperateCmdLogin(); break;     //操作-登陆
    case OperType_User: execOperateCmdUser();   break;     //操作-用户管理
    case OperType_Student: execOperateCmdStudent(); break; //操作-学籍管理
    case OperType_Take: execOperateCmdTake(); break;       //操作-网上选课
    case OperType_Arrange: execOperateCmdArrange(); break; //操作-教学安排
    case OperType_Exam: execOperateCmdExam(); break;       //操作-考试安排
    case OperType_Grade: execOperateCmdGrade(); break;     //操作-成绩管理
    case OperType_Teacher: execOperateCmdTeacher(); break; //操作-教师管理
    case OperType_Admin: execOperateCmdAdmin(); break;     //操作-管理员信息
    case OperType_Department: execOperateCmdDelDepart(); break; //操作-系别管理
    case OperType_Class: execOperateCmdClass(); break;     //操作-班级管理
    case OperType_Room: execOperateCmdRoom(); break;       //操作-教室分配
    case OperType_Time: execOperateCmdTime(); break;       //操作-时间安排
    case OperType_Other: execOperateCmdOther(); break;     //操作-其他
    default:
        break;
    }
}


////////////执行操作命令-登陆
void ExecNormalProtocol::execOperateCmdLogin(void)
{
   //qDebug() << "void ExecNormalProtocol::execOperateCmdLogin(void)";
    switch (m_protocol.m_operCmd) {
    case CmdLogin_LoginAsk: execOperateCmdLoginAsk(); break;
    //case CmdLogin_QuitAsk: execOperateCmdExitAsk(); break;
    default: break;
    }
}

///执行操作命令-登陆请求
void ExecNormalProtocol::execOperateCmdLoginAsk(void)
{
    QStringList list = QString::fromUtf8(m_protocol.m_dataCont).split("|");
    //qDebug() << list;

    User info;

    info.updataUserinfo(list[0], list[1], list[2], list[3]);
    emit signalUserLoginSuccess(info);
}


//////////////执行操作命令-用户管理
void ExecNormalProtocol::execOperateCmdUser(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdUser_AskUserInfo: execOperateCmdAskUserInfo();  break;
    case CmdUser_SelectUser:  execOperateSelectUser();      break;
    default:
        break;
    }
}

///执行操作命令-用户信息获取
void ExecNormalProtocol::execOperateCmdAskUserInfo(void)
{

}

///执行操作命令-查询用户
void ExecNormalProtocol::execOperateSelectUser(void)
{
    QStringList list = QString::fromUtf8(m_protocol.m_dataCont).split("*");

//    qDebug() << "execOperateSelectUser";
//    qDebug() << list;
//    qDebug() << "Server---------execOperateSelectUser "<<list.size();

    QStringList info;
    User user;
    UserList userList;

    for(int i = 0; i < list.size() - 1; i++)
    {
        info = list[i].split("|");
        user.updataUserinfo(info[0],info[1],info[2],info[3]);
        //user.display();
        userList.append(user);
    }

    emit signalSelectUserInfos(userList);
}


////////////执行操作命令-学籍管理
void ExecNormalProtocol::execOperateCmdStudent(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdStudent_AskStuInfo: execOperateCmdAskStuInfo(); break;
    case CmdStudent_AddStuInfo: execOperateCmdAddStuInfo(); break;
    case CmdStudent_ModifyStuInfo: execOperateCmdModifyStuInfo(); break;
    case CmdStudent_DelStuInfo: execOperateCmdDelStuInfo(); break;
    default:
        break;
    }
}

///学生信息获取
void ExecNormalProtocol::execOperateCmdAskStuInfo(void)
{

    QStringList list = QString::fromUtf8(m_protocol.m_dataCont).split("*");

    QStringList info;
    Student student;

    StudentList stuList;

    for(int i = 0; i < list.size() - 1; i++)
    {
        info = list[i].split("|");
        student.updataUserinfo(info[0], info[1], info[2], info[3]);
        student.updataStudentinfo(info[4], info[5], info[6], info[7],info[8], info[9]);
        student.display();
        stuList.append(student);
    }

    emit signalSelectStuAll(stuList);
}

///添加学生信息
void ExecNormalProtocol::execOperateCmdAddStuInfo(void)
{

}

///修改学生信息
void ExecNormalProtocol::execOperateCmdModifyStuInfo(void)
{

}
///删除学生信息
void ExecNormalProtocol::execOperateCmdDelStuInfo(void)
{

}


////////////执行操作命令-网上选课
void ExecNormalProtocol::execOperateCmdTake(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdTake_AskManageInfo: execOperateCmdAskManageInfo(); break;
    case CmdTake_Take: execOperateCmdTake(); break;
    case CmdTake_AskResult: execOperateCmdAskResult(); break;
    case CmdTake_QuitTake: execOperateCmdQuitTake(); break;
    case  CmdTake_AgainTake: execOperateCmdAgainTake(); break;
    default:
        break;
    }
}


///执行操作命令-查看选课管理规定
void ExecNormalProtocol::execOperateCmdAskManageInfo(void)
{

}

 ///执行操作命令-选课
void ExecNormalProtocol::execOperateCmdTake_Take(void)
{

}

///执行操作命令-查看选课结果
void ExecNormalProtocol::execOperateCmdAskResult(void)
{

}

///执行操作命令-补选
void ExecNormalProtocol::execOperateCmdAgainTake(void)
{

}

///执行操作命令-退选
void ExecNormalProtocol::execOperateCmdQuitTake(void)
{

}


////////////////教学安排表/排课表--执行操作命令-教学安排
void ExecNormalProtocol::execOperateCmdArrange(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdArrange_AskArrange: execOperateCmdAskArrange(); break;
    case CmdArrange_AddArrange: execOperateCmdAddArrange(); break;
    case CmdArrange_ModifyArrange: execOperateCmdModifyArrange(); break;
    case CmdArrange_DelArrange: execOperateCmdDelArrange(); break;
    default:
        break;
    }
}

///查看排课表
void ExecNormalProtocol::execOperateCmdAskArrange(void)
{

}

///添加排课信息
void ExecNormalProtocol::execOperateCmdAddArrange(void)
{

}

///修改排课信息
void ExecNormalProtocol::execOperateCmdModifyArrange(void)
{

}

///删除排课信息
void ExecNormalProtocol::execOperateCmdDelArrange(void)
{

}


////////////////考试安排---//执行操作命令-执行操作命令-考试安排
void ExecNormalProtocol::execOperateCmdExam(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdExam_AskExamInfo: execOperateCmdAskExamInfo(); break;
    case CmdExam_AddExam: execOperateCmdAddExam(); break;
    case CmdExam_ModifyExam: execOperateCmdModifyExam(); break;
    case CmdExam_DelExam: execOperateCmdDelExam(); break;
    default:
        break;
    }
}

///执行操作命令-查看考试安排表
void ExecNormalProtocol::execOperateCmdAskExamInfo(void)
{

}

///执行操作命令-修改考试安排表
void ExecNormalProtocol::execOperateCmdModifyExam(void)
{

}

///执行操作命令-添加考试信息
void ExecNormalProtocol::execOperateCmdAddExam(void)
{

}

///执行操作命令-删除考试信息
void ExecNormalProtocol::execOperateCmdDelExam(void)
{

}


////////////成绩管理//执行操作命令-成绩管理
void ExecNormalProtocol::execOperateCmdGrade(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdGrade_AddGrade: execOperateCmdAddGrade(); break;
    case CmdGrade_AskGradeInfo: execOperateCmdAskExamInfo(); break;
    case CmdGrade_ModifyGrade: execOperateCmdModifyGrade(); break;
    case CmdGrade_DelGrade: execOperateCmdDelGrade(); break;
    case CmdGrade_AnalyzeGrade: execOperateCmdAnalyzeGrade(); break;
    default:
        break;
    }
}

///执行操作命令-录入成绩
void ExecNormalProtocol::execOperateCmdAddGrade(void)
{

}

///执行操作命令-查询成绩
void ExecNormalProtocol::execOperateCmdAskGradeInfo(void)
{

}

///执行操作命令-修改成绩
void ExecNormalProtocol::execOperateCmdModifyGrade(void)
{

}

///执行操作命令-删除成绩
void ExecNormalProtocol::execOperateCmdDelGrade(void)
{

}

///执行操作命令-统计成绩
void ExecNormalProtocol::execOperateCmdAnalyzeGrade (void)
{

}


/////////////教师信息 //执行操作命令-教师管理
void ExecNormalProtocol::execOperateCmdTeacher(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdTeacher_AskTeachInfo: execOperateCmdAskTeachInfo(); break;
    case CmdTeacher_AddTeacher: execOperateCmdAddTeacher(); break;
    case CmdTeacher_ModifyTeacher: execOperateCmdModifyTeacher(); break;
    case CmdTeacher_DelTeacher: execOperateCmdDelTeacher(); break;
    default:
        break;
    }
}

///执行操作命令-教师信息获取
void ExecNormalProtocol::execOperateCmdAskTeachInfo(void)
{

}

///执行操作命令-添加教师信息
void ExecNormalProtocol::execOperateCmdAddTeacher(void)
{

}

///执行操作命令-修改教师信息
void ExecNormalProtocol::execOperateCmdModifyTeacher(void)
{

}

///执行操作命令-删除教师信息
void ExecNormalProtocol::execOperateCmdDelTeacher (void)
{

}


///////////////管理员//执行操作命令-管理员信息
void ExecNormalProtocol::execOperateCmdAdmin(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdAdmin_AskAdmin: execOperateCmdAskAdmin(); break;
    case CmdAdmin_AddAdmin: execOperateCmdAddAdmin(); break;
    case CmdAdmin_ModifyAdmin: execOperateCmdModifyAdmin(); break;
    case CmdAdmin_DelAdmin: execOperateCmdDelAdmin(); break;
    default:
        break;
    }
}

///执行操作命令-添加管理员
void ExecNormalProtocol::execOperateCmdAddAdmin(void)
{

}

///执行操作命令-删除管理员
void ExecNormalProtocol::execOperateCmdDelAdmin(void)
{

}

///执行操作命令-管理员信息获取
void ExecNormalProtocol::execOperateCmdAskAdmin(void)
{

}

///执行操作命令-管理员信息修改
void ExecNormalProtocol::execOperateCmdModifyAdmin (void)
{

}


////////////系别管理//执行操作命令-系别管理
void ExecNormalProtocol::execOperateCmdDepartment(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdDepart_AskDepartInfo: execOperateCmdAskDepartInfo();  break;
    case CmdDepart_AddDepart: execOperateCmdAddDepart(); break;
    case CmdDepart_ModifyDepart: execOperateCmdModifyDepart(); break;
    case CmdDepart_DelDepart: execOperateCmdDelDepart(); break;
    default:
        break;
    }
}

///执行操作命令-查看系别信息
void ExecNormalProtocol::execOperateCmdAskDepartInfo (void)
{

}

///执行操作命令-修改系别信息
void ExecNormalProtocol::execOperateCmdModifyDepart(void)
{

}

///执行操作命令-添加系别信息
void ExecNormalProtocol::execOperateCmdAddDepart(void)
{

}

///执行操作命令-删除系别信息
void ExecNormalProtocol::execOperateCmdDelDepart (void)
{

}


////////////班级管理//执行操作命令-班级管理
void ExecNormalProtocol::execOperateCmdClass(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdClass_AskClassInfo: execOperateCmdAskClassInfo(); break;
    case CmdClass_AddClass: execOperateCmdAddClass(); break;
    case CmdClass_ModifyClass: execOperateCmdModifyClass(); break;
    case CmdClass_DelClass: execOperateCmdDelClass(); break;
    default:
        break;
    }
}

///查看班级信息
void ExecNormalProtocol::execOperateCmdAskClassInfo(void)
{

}

///修改班级信息
void ExecNormalProtocol::execOperateCmdModifyClass(void)
{

}

///添加班级信息
void ExecNormalProtocol::execOperateCmdAddClass(void)
{

}

///删除班级信息
void ExecNormalProtocol::execOperateCmdDelClass(void)
{

}


////////////////教室分配//执行操作命令-教室分配
void ExecNormalProtocol::execOperateCmdRoom(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdRoom_AskRoomInfo: execOperateCmdAskClassInfo(); break;
    case CmdRoom_AddRoom: execOperateCmdAddRoom(); break;
    case CmdRoom_ModifyRoom: execOperateCmdModifyRoom(); break;
    case CmdRoom_DelRoom: execOperateCmdDelRoom(); break;
    default:
        break;
    }
}

///执行操作命令-查看教室信息
void ExecNormalProtocol::execOperateCmdAskRoomInfo(void)
{

}

///执行操作命令-修改教室信息
void ExecNormalProtocol::execOperateCmdModifyRoom(void)
{

}

///执行操作命令-添加教室信息
void ExecNormalProtocol::execOperateCmdAddRoom(void)
{

}

///执行操作命令-删除教室信息
void ExecNormalProtocol::execOperateCmdDelRoom(void)
{

}


/////////////时间安排//执行操作命令-时间安排
void ExecNormalProtocol::execOperateCmdTime(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdTime_AskTimeInfo: execOperateCmdAskTimeInfo(); break;
    case CmdTime_AddTime: execOperateCmdAddTime(); break;
    case CmdTime_ModifyTime: execOperateCmdModifyTime(); break;
    case CmdTime_DelTime: execOperateCmdDelTime(); break;
    default:
        break;
    }
}

///执行操作命令-查看时间安排表
void ExecNormalProtocol::execOperateCmdAskTimeInfo(void)
{

}

///执行操作命令-修改时间安排
void ExecNormalProtocol::execOperateCmdModifyTime(void)
{

}

///执行操作命令-添加时间安排
void ExecNormalProtocol::execOperateCmdAddTime(void)
{

}

///执行操作命令-删除时间安排
void ExecNormalProtocol::execOperateCmdDelTime(void)
{

}


/////////////////////其他操作//执行操作命令-其他
void ExecNormalProtocol::execOperateCmdOther(void)
{
    switch (m_protocol.m_operCmd) {
    case CmdOther_AskHelp: execOperateCmdAskHelp(); break;
    case CmdOther_AskVersion: execOperateCmdAskVersion(); break;
    case CmdOther_UpFile: execOperateCmdUpFile(); break;
    case CmdOther_DownFile: execOperateCmdDownFile(); break;
    case CmdOther_ModifyPswd: execOperateCmdModifyPswd(); break;
    default:
        break;
    }
}

///执行操作命令-下载文件
void ExecNormalProtocol::execOperateCmdDownFile(void)
{

}

///执行操作命令-上传文件
void ExecNormalProtocol::execOperateCmdUpFile(void)
{

}

///执行操作命令-修改密码
void ExecNormalProtocol::execOperateCmdModifyPswd(void)
{

}

///执行操作命令-帮助说明
void ExecNormalProtocol::execOperateCmdAskHelp(void)
{

}

///执行操作命令-介绍版本
void ExecNormalProtocol::execOperateCmdAskVersion (void)
{

}
