/*-------------------------------------------------------------------------
FileName     : cloudapp.h
Description  : app对象
remark       : 作为CppCloudServ的客户端而存在
Modification :
--------------------------------------------------------------------------
   1、Date  2018-10-12       create     hejl 
-------------------------------------------------------------------------*/
#ifndef _CLOUDAPP_H_
#define _CLOUDAPP_H_
#include "comm/public.h"
#include "iohand.h"


using namespace std;



class CloudApp: public IOHand
{
public:
	HEPCLASS_DECL(CloudApp, CloudApp);
	SINGLETON_CLASS2(CloudApp)
	CloudApp();

	// message handle
	static int OnCMD_WHOAMI_RSP( void* ptr, unsigned cmdid, void* param );
	int onCMD_WHOAMI_RSP( void* ptr, unsigned cmdid, void* param );

public:
	int init( int epfd, const string& svrhost_port );
	void uninit( void );

	bool isInitOk( void ) const;
	string whoamiMsg( void ) const;

	void setSvrid( int svrid );

	virtual int qrun( int flag, long p2 );
	virtual int onClose( int p1, long p2 );

private:
	void reset( void );
	int taskRun( int flag, long p2 );
	int appendTimerq( void );

private:
	int m_appid;
	int m_epfd;

	int m_stage;
	int m_seqid;
	int m_port;
	int m_cliType;
	bool m_inqueue;
	bool m_existLink; // 是否已连接中
	string m_rhost;
	string m_svrname;
	string m_mconf;
	static CloudApp* This;
};

#endif