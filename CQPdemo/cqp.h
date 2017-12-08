/*
* CoolQ SDK for VC++ 
* Api Version 9
* Written by Coxxs & Thanks for the help of orzFly
*/
#pragma once

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

#ifndef CQAPI
#define CQAPI(RETN_TYPE) extern "C" __declspec(dllimport) RETN_TYPE __stdcall
#endif

#define CQEVENT(RETN_TYPE, FUNC_NAME, HEAD_SIZE) __pragma(comment(linker, "/EXPORT:" #FUNC_NAME "=_" #FUNC_NAME "@" #HEAD_SIZE ))\
 extern "C" RETN_TYPE __stdcall FUNC_NAME

typedef BOOL CQBOOL;

#define EVENT_IGNORE 0          //�¼�_����
#define EVENT_BLOCK 1           //�¼�_����

#define REQUEST_ALLOW 1         //����_ͨ��
#define REQUEST_DENY 2          //����_�ܾ�

#define REQUEST_GROUPADD 1      //����_Ⱥ���
#define REQUEST_GROUPINVITE 2   //����_Ⱥ����

#define CQLOG_DEBUG 0           //���� ��ɫ
#define CQLOG_INFO 10           //��Ϣ ��ɫ
#define CQLOG_INFOSUCCESS 11    //��Ϣ(�ɹ�) ��ɫ
#define CQLOG_INFORECV 12       //��Ϣ(����) ��ɫ
#define CQLOG_INFOSEND 13       //��Ϣ(����) ��ɫ
#define CQLOG_WARNING 20        //���� ��ɫ
#define CQLOG_ERROR 30          //���� ��ɫ
#define CQLOG_FATAL 40          //�������� ���

/*
* ����˽����Ϣ, �ɹ�������ϢID
* QQID Ŀ��QQ��
* msg ��Ϣ����
*/
CQAPI(INT32) CQ_sendPrivateMsg(INT32 AuthCode, INT64 QQID, LPCSTR msg);

/*
* ����Ⱥ��Ϣ, �ɹ�������ϢID
* groupid Ⱥ��
* msg ��Ϣ����
*/
CQAPI(INT32) CQ_sendGroupMsg(INT32 AuthCode, INT64 groupid, LPCSTR msg);

/*
* ������������Ϣ, �ɹ�������ϢID
* discussid �������
* msg ��Ϣ����
*/
CQAPI(INT32) CQ_sendDiscussMsg(INT32 AuthCode, INT64 discussid, LPCSTR msg);

/*
* ������Ϣ
* msgid ��ϢID
*/
CQAPI(INT32) CQ_deleteMsg(INT32 AuthCode, INT64 msgid);

/*
* ������ �����ֻ���
* QQID QQ��
*/
CQAPI(INT32) CQ_sendLike(INT32 AuthCode, INT64 QQID);

/*
* ��ȺԱ�Ƴ�
* groupid Ŀ��Ⱥ
* QQID QQ��
* rejectaddrequest ���ٽ��մ��˼�Ⱥ���룬������
*/
CQAPI(INT32) CQ_setGroupKick(INT32 AuthCode, INT64 groupid, INT64 QQID, CQBOOL rejectaddrequest);

/*
* ��ȺԱ����
* groupid Ŀ��Ⱥ
* QQID QQ��
* duration ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0��
*/
CQAPI(INT32) CQ_setGroupBan(INT32 AuthCode, INT64 groupid, INT64 QQID, INT64 duration);

/*
* ��Ⱥ����Ա
* groupid Ŀ��Ⱥ
* QQID QQ��
* setadmin true:���ù���Ա false:ȡ������Ա
*/
CQAPI(INT32) CQ_setGroupAdmin(INT32 AuthCode, INT64 groupid, INT64 QQID, CQBOOL setadmin);

/*
* ��ȫȺ����
* groupid Ŀ��Ⱥ
* enableban true:���� false:�ر�
*/
CQAPI(INT32) CQ_setGroupWholeBan(INT32 AuthCode, INT64 groupid, CQBOOL enableban);

/*
* ������ȺԱ����
* groupid Ŀ��Ⱥ
* anomymous Ⱥ��Ϣ�¼��յ��� anomymous ����
* duration ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ����
*/
CQAPI(INT32) CQ_setGroupAnonymousBan(INT32 AuthCode, INT64 groupid, LPCSTR anomymous, INT64 duration);

/*
* ��Ⱥ��������
* groupid Ŀ��Ⱥ
* enableanomymous true:���� false:�ر�
*/
CQAPI(INT32) CQ_setGroupAnonymous(INT32 AuthCode, INT64 groupid, CQBOOL enableanomymous);

/*
* ��Ⱥ��Ա��Ƭ
* groupid Ŀ��Ⱥ
* QQID Ŀ��QQ
* newcard ����Ƭ(�ǳ�)
*/
CQAPI(INT32) CQ_setGroupCard(INT32 AuthCode, INT64 groupid, INT64 QQID, LPCSTR newcard);

/*
* ��Ⱥ�˳� ����, �˽ӿ���Ҫ�ϸ���Ȩ
* groupid Ŀ��Ⱥ
* isdismiss �Ƿ��ɢ true:��ɢ��Ⱥ(Ⱥ��) false:�˳���Ⱥ(����Ⱥ��Ա)
*/
CQAPI(INT32) CQ_setGroupLeave(INT32 AuthCode, INT64 groupid, CQBOOL isdismiss);

/*
* ��Ⱥ��Աר��ͷ�� ��Ⱥ��Ȩ��
* groupid Ŀ��Ⱥ
* QQID Ŀ��QQ
* newspecialtitle ͷ�Σ����Ҫɾ����������գ�
* duration ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1��
*/
CQAPI(INT32) CQ_setGroupSpecialTitle(INT32 AuthCode, INT64 groupid, INT64 QQID, LPCSTR newspecialtitle, INT64 duration);

/*
* ���������˳�
* discussid Ŀ���������
*/
CQAPI(INT32) CQ_setDiscussLeave(INT32 AuthCode, INT64 discussid);

/*
* �ú����������
* responseflag �����¼��յ��� responseflag ����
* responseoperation REQUEST_ALLOW �� REQUEST_DENY
* remark ��Ӻ�ĺ��ѱ�ע
*/
CQAPI(INT32) CQ_setFriendAddRequest(INT32 AuthCode, LPCSTR responseflag, INT32 responseoperation, LPCSTR remark);

/*
* ��Ⱥ�������
* responseflag �����¼��յ��� responseflag ����
* requesttype���������¼������������� REQUEST_GROUPADD �� REQUEST_GROUPINVITE
* responseoperation  REQUEST_ALLOW �� REQUEST_DENY
* reason �������ɣ��� REQUEST_GROUPADD �� REQUEST_DENY ʱ����
*/
CQAPI(INT32) CQ_setGroupAddRequestV2(INT32 AuthCode, LPCSTR responseflag, INT32 requesttype, INT32 responseoperation, LPCSTR reason);

/*
* ȡȺ��Ա��Ϣ
* groupid Ŀ��QQ����Ⱥ
* QQID Ŀ��QQ��
* nocache ��ʹ�û���
*/
CQAPI(LPCSTR) CQ_getGroupMemberInfoV2(INT32 AuthCode, INT64 groupid, INT64 QQID, CQBOOL nocache);

/*
* ȡİ������Ϣ
* QQID Ŀ��QQ
* nocache ��ʹ�û���
*/
CQAPI(LPCSTR) CQ_getStrangerInfo(INT32 AuthCode, INT64 QQID, CQBOOL nocache);

/*
* ��־
* priority ���ȼ���CQLOG ��ͷ�ĳ���
* category ����
* content ����
*/
CQAPI(INT32) CQ_addLog(INT32 AuthCode, INT32 priority, LPCSTR category, LPCSTR content);

/*
* ȡCookies ����, �˽ӿ���Ҫ�ϸ���Ȩ
*/
CQAPI(LPCSTR) CQ_getCookies(INT32 AuthCode);

/*
* ȡCsrfToken ����, �˽ӿ���Ҫ�ϸ���Ȩ
*/
CQAPI(INT32) CQ_getCsrfToken(INT32 AuthCode);

/*
* ȡ��¼QQ
*/
CQAPI(INT64) CQ_getLoginQQ(INT32 AuthCode);

/*
* ȡ��¼QQ�ǳ�
*/
CQAPI(LPCSTR) CQ_getLoginNick(INT32 AuthCode);

/*
* ȡӦ��Ŀ¼�����ص�·��ĩβ��"\"
*/
CQAPI(LPCSTR) CQ_getAppDirectory(INT32 AuthCode);

/*
* ������������ʾ
* errorinfo ������Ϣ
*/
CQAPI(INT32) CQ_setFatal(INT32 AuthCode, LPCSTR errorinfo);

/*
* ����������������Ϣ�е�����(record),���ر����� \data\record\ Ŀ¼�µ��ļ���
* file �յ���Ϣ�е������ļ���(file)
* outformat Ӧ������������ļ���ʽ��Ŀǰ֧�� mp3 amr wma m4a spx ogg wav flac
*/
CQAPI(LPCSTR) CQ_getRecord(INT32 AuthCode, LPCSTR file, LPCSTR outformat);