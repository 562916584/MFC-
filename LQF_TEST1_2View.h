
// LQF_TEST1_2View.h : CLQF_TEST1_2View ��Ľӿ�
//

#pragma once

#include"CLine.h"
#include"CRectangle.h"
#include<stack>
#include<vector>
class CLQF_TEST1_2View : public CView
{
protected: // �������л�����
	CLQF_TEST1_2View();
	DECLARE_DYNCREATE(CLQF_TEST1_2View)

// ����
public:
	CLQF_TEST1_2Doc* GetDocument() const;

// ����
public:
	void Hanoilmpl(int n, char A, char B, char C);
	void move(char A, char C);
	void init(CDC *pDC);
	// ������һ��
	void animFirst(std::stack<int>& target, CPoint toPoint, CPoint prePoint, int num);
	// ��ȫ����
	void recover( CRectangle& rectangle);
	// �����ڶ���
	void animSecond(CPoint toPoint);
	// ����������
	void animThird(CPoint toPoint,int num);
	// ��������ִ��
	void oneStep();
	// д��
	void onDrawFont();
private:
	// �������ӵĵײ�����
	CPoint townerA, townerB, townerC;
	// �������Ӷ��� Ҳ���Ƕ�����һ�����������λ��
	CPoint townerTopA, townerTopB, townerTopC;

	int totalA=4, totalB=0, totalC=0; // ͳ����������θ���
	std::stack<int> A,B,C; // ��������ľ��ο��
	CRectangle* targetR; // Ŀ�����
	int animTime =3; // ��ʾ���ڽ��ж����ĵڼ���
	// �ƶ���·��
	std::vector<std::pair<char, char>> route;
	std::vector<std::pair<char, char>>::iterator pointR;
	char st, ed;
	UINT_PTR mynIDEvent;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLQF_TEST1_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStart();
	afx_msg void On32772();
	afx_msg void OnDan();
};

#ifndef _DEBUG  // LQF_TEST1_2View.cpp �еĵ��԰汾
inline CLQF_TEST1_2Doc* CLQF_TEST1_2View::GetDocument() const
   { return reinterpret_cast<CLQF_TEST1_2Doc*>(m_pDocument); }
#endif

