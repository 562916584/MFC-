
// LQF_TEST1_2.h : LQF_TEST1_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLQF_TEST1_2App:
// �йش����ʵ�֣������ LQF_TEST1_2.cpp
//

class CLQF_TEST1_2App : public CWinAppEx
{
public:
	CLQF_TEST1_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLQF_TEST1_2App theApp;
