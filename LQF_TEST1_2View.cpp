
// LQF_TEST1_2View.cpp : CLQF_TEST1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LQF_TEST1_2.h"
#endif

#include "LQF_TEST1_2Doc.h"
#include "LQF_TEST1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLQF_TEST1_2View

IMPLEMENT_DYNCREATE(CLQF_TEST1_2View, CView)

BEGIN_MESSAGE_MAP(CLQF_TEST1_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLQF_TEST1_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_32771, &CLQF_TEST1_2View::OnStart)
	ON_COMMAND(ID_32772, &CLQF_TEST1_2View::On32772)
	ON_COMMAND(ID_32773, &CLQF_TEST1_2View::OnDan)
END_MESSAGE_MAP()

// CLQF_TEST1_2View ����/����

CLQF_TEST1_2View::CLQF_TEST1_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CLQF_TEST1_2View::~CLQF_TEST1_2View()
{
}

BOOL CLQF_TEST1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLQF_TEST1_2View ����
void CLQF_TEST1_2View::OnDraw(CDC* /*pDC*/)
{
	CLQF_TEST1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	Hanoilmpl(4, 'A', 'B', 'C');
	pointR = route.begin();
	CDC *pDC = GetDC();
	init(pDC);
}


// CLQF_TEST1_2View ��ӡ


void CLQF_TEST1_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLQF_TEST1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CLQF_TEST1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLQF_TEST1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CLQF_TEST1_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLQF_TEST1_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLQF_TEST1_2View ���

#ifdef _DEBUG
void CLQF_TEST1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CLQF_TEST1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLQF_TEST1_2Doc* CLQF_TEST1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLQF_TEST1_2Doc)));
	return (CLQF_TEST1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CLQF_TEST1_2View ��Ϣ�������


void CLQF_TEST1_2View::OnTimer(UINT_PTR nIDEvent)
{
	onDrawFont();
	mynIDEvent = nIDEvent;
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (animTime == 0) {
		if (totalC==4) {
			KillTimer(nIDEvent);
			return;
		}
		this->pointR++;
		animTime = 3;
	}
	// ������һ��
	if (animTime == 3) {
		animTime--;
		this->st = pointR->first;
		this->ed = pointR->second;
		// ��A��ʼ��һ��
		if (st == 'A') {
			animFirst(A, townerTopA, townerA, totalA);
			if (ed == 'B') {
				int wid = A.top();
				A.pop();
				B.push(wid);
				totalA -= 1;
				totalB += 1;
			}
			else {
				int wid = A.top();
				A.pop();
				C.push(wid);
				totalA -= 1;
				totalC += 1;
			}
		}
		else if (st == 'B') {
			animFirst(B, townerTopB, townerB, totalB);
			if (ed == 'A') {
				int wid = B.top();
				B.pop();
				A.push(wid);
				totalB -= 1;
				totalA += 1;
			}
			else {
				int wid = B.top();
				B.pop();
				C.push(wid);
				totalB -= 1;
				totalC += 1;
			}
		}
		else if(st=='C')
		{
			animFirst(C, townerTopC, townerC, totalC);
			if (ed == 'A') {
				int wid = C.top();
				C.pop();
				A.push(wid);
				totalC -= 1;
				totalA += 1;
			}
			else {
				int wid = C.top();
				C.pop();
				B.push(wid);
				totalC -= 1;
				totalB += 1;
			}
		}
	}
	// �����ڶ���
	else if (animTime == 2) {
		animTime--;
		if (ed == 'A') {
			animSecond(townerTopA);
		}
		else if(ed == 'B')
		{
			animSecond(townerTopB);
		}
		else
		{
			animSecond(townerTopC);
		}
	}
	else {
		animTime--;
		if (ed == 'A') {
			animThird(townerA, totalA);
		}
		else if (ed == 'B') {
			animThird(townerB, totalB);
		}
		else {
			animThird(townerC, totalC);
		}
	}
	CView::OnTimer(nIDEvent);
}

void CLQF_TEST1_2View::Hanoilmpl(int n, char A, char B, char C) {
	if (n == 1) {
		move(A, C);
	}
	else {
		Hanoilmpl(n - 1, A, C, B);//����1 ��ACB����ִ��N-1�ĺ�ŵ���ƶ�
		move(A, C);             //����2   ִ����������ƶ�
		Hanoilmpl(n - 1, B, A, C);//����3 ��BAC����ִ��N-1�ĺ�ŵ���ƶ�
	}
}

void CLQF_TEST1_2View::move(char A, char C) {
	static int j = 0;
	j++;
	//printf("�ƶ�·�� &c ---> %c", A, C);
	route.push_back(std::pair<char, char>(A, C));
}
void CLQF_TEST1_2View::init(CDC *pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(217, 217, 217));
	// ���û���
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	// ����������
	CLine lineOne(300, 100, 300, 400);
	CLine lineTwo(500, 100, 500, 400);
	CLine lineThree(700, 100, 700, 400);
	CLine land(200, 400, 800, 400);
	lineOne.onDraw(pDC);
	lineTwo.onDraw(pDC);
	lineThree.onDraw(pDC);
	land.onDraw(pDC);
	pDC->SelectObject(oldPen);
	// ��ʼ���������ӵײ�����
	this->townerA = lineOne.getPoint2();
	this->townerB = lineTwo.getPoint2();
	this->townerC = lineThree.getPoint2();
	// ��ʼ��������������λ��
	this->townerTopA = lineOne.getPoint1();
	this->townerTopB = lineTwo.getPoint1();
	this->townerTopC = lineThree.getPoint1();
	// ������
	CBrush brush(RGB(255, 0, 0));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	CRectangle roundRect1(50);
	roundRect1.setNum(4);
	CRectangle roundRect2(100);
	roundRect2.setNum(3);
	CRectangle roundRect3(150);
	roundRect3.setNum(2);
	CRectangle roundRect4(200);
	roundRect4.setNum(1);
	A.push(200);
	A.push(150);
	A.push(100);
	A.push(50);
	roundRect1.prepare(townerA, pDC);
	roundRect2.prepare(townerA, pDC);
	roundRect3.prepare(townerA, pDC);
	roundRect4.prepare(townerA, pDC);
	pDC->SelectObject(oldBrush);
	ReleaseDC(pDC);
	//animFirst(A, townerTopA, townerA, totalA);
	//animSecond(townerTopB);
	//animThird(townerB, 1);
}

void CLQF_TEST1_2View::animFirst(std::stack<int>& target, CPoint toPoint,CPoint prePoint,int num) {
	// ������һ������
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	int rwid = target.top();
	CRectangle roundRect(rwid);
	roundRect.setNum(num);
	roundRect.prepare(prePoint, pDC);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	// ��ȫ����
	recover(roundRect);
	// ���붥��1���߶�
	roundRect.setNum(1);
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	roundRect.prepare(toPoint, pDC);
	ReleaseDC(pDC);
	// ��Ŀ�����
	this->targetR = new CRectangle(roundRect);
}

void CLQF_TEST1_2View::recover(CRectangle & rectangle)
{
	CPoint top, bottom;
	top.x = rectangle.getPoint1().x + rectangle.getWidth();
	top.y = rectangle.getPoint1().y;
	bottom.x = rectangle.getPoint2().x - rectangle.getWidth();
	bottom.y = rectangle.getPoint2().y;
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	pDC->MoveTo(top.x, top.y);
	pDC->LineTo(bottom.x, bottom.y);
	ReleaseDC(pDC);
}

void CLQF_TEST1_2View::animSecond(CPoint toPoint)
{
	// ������һ������
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	this->targetR->onDraw(pDC);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	// ������һ��λ�þ���
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	this->targetR->prepare(toPoint, pDC);
	ReleaseDC(pDC);
}

void CLQF_TEST1_2View::animThird(CPoint toPoint,int num)
{
	// ������һ������
	CDC *pDC = GetDC();
	CPen cTowerPen;
	cTowerPen.CreatePen(PS_SOLID, 0, RGB(217, 217, 217));
	CPen* oldPen = pDC->SelectObject(&cTowerPen);
	CBrush brush(RGB(217, 217, 217));
	CBrush *oldBrush = pDC->SelectObject(&brush);
	this->targetR->onDraw(pDC);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	// ������һ������
	this->targetR->setNum(num);
	CBrush brush1(RGB(255, 0, 0));
	CBrush *oldBrush1 = pDC->SelectObject(&brush1);
	this->targetR->prepare(toPoint, pDC);
	ReleaseDC(pDC);
}

void CLQF_TEST1_2View::oneStep()
{
	if (animTime == 0) {
		if (totalC == 4) {
			
			return;
		}
		this->pointR++;
		animTime = 3;
	}
	// ������һ��
	if (animTime == 3) {
		animTime--;
		this->st = pointR->first;
		this->ed = pointR->second;
		// ��A��ʼ��һ��
		if (st == 'A') {
			animFirst(A, townerTopA, townerA, totalA);
			if (ed == 'B') {
				int wid = A.top();
				A.pop();
				B.push(wid);
				totalA -= 1;
				totalB += 1;
			}
			else {
				int wid = A.top();
				A.pop();
				C.push(wid);
				totalA -= 1;
				totalC += 1;
			}
		}
		else if (st == 'B') {
			animFirst(B, townerTopB, townerB, totalB);
			if (ed == 'A') {
				int wid = B.top();
				B.pop();
				A.push(wid);
				totalB -= 1;
				totalA += 1;
			}
			else {
				int wid = B.top();
				B.pop();
				C.push(wid);
				totalB -= 1;
				totalC += 1;
			}
		}
		else if (st == 'C')
		{
			animFirst(C, townerTopC, townerC, totalC);
			if (ed == 'A') {
				int wid = C.top();
				C.pop();
				A.push(wid);
				totalC -= 1;
				totalA += 1;
			}
			else {
				int wid = C.top();
				C.pop();
				B.push(wid);
				totalC -= 1;
				totalB += 1;
			}
		}
	}
	// �����ڶ���
	else if (animTime == 2) {
		animTime--;
		if (ed == 'A') {
			animSecond(townerTopA);
		}
		else if (ed == 'B')
		{
			animSecond(townerTopB);
		}
		else
		{
			animSecond(townerTopC);
		}
	}
	else {
		animTime--;
		if (ed == 'A') {
			animThird(townerA, totalA);
		}
		else if (ed == 'B') {
			animThird(townerB, totalB);
		}
		else {
			animThird(townerC, totalC);
		}
	}
}

void CLQF_TEST1_2View::onDrawFont()
{
	CDC* pDC = GetDC();
	HDC dc = pDC->GetSafeHdc();
	CRect clientRect;
	GetClientRect(clientRect);

	int width = clientRect.Width();
	int height = clientRect.Height();
	int textRectWidth = width / 50 + width * 2 / 5;
	int textRectHeight = width / 50;
	CString times;
	int moveTimes = 0;

	SetTextColor(*pDC, RGB(0, 0, 0));
	SetBkMode(*pDC, TRANSPARENT);

	//moveTimes = needleMoveTimes[0] == 0 ? 14 : 14 + int(log10(needleMoveTimes[0]));
	CRect textRect = CRect(width / 3 - width / 4, height / 5 + height / 2, width / 3 + width / 50 + width / 5, height / 5 + height / 2 + textRectHeight);
	times.Format(_T("A�����Ϸ��������ƶ�������%d"), totalA);
	DrawText(dc, times, moveTimes, textRect, DT_LEFT | DT_VCENTER | DT_SINGLELINE);

	//moveTimes = needleMoveTimes[1] == 0 ? 14 : 14 + int(log10(needleMoveTimes[1]));
	textRect = CRect(width / 2 - width / 5, height / 5 + height / 2, width / 2 + width / 50 + width / 5, height / 5 + height / 2 + textRectHeight);
	times.Format(_T("B�����Ϸ��������ƶ�������%d"), totalB);
	DrawText(dc, times, moveTimes, textRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//moveTimes = needleMoveTimes[2] == 0 ? 14 : 14 + int(log10(needleMoveTimes[2]));
	textRect = CRect(width * 2 / 3, height / 5 + height / 2, width * 2 / 3 + width / 50 + width / 4, height / 5 + height / 2 + textRectHeight);
	times.Format(_T("C�����Ϸ��������ƶ�������%d"), totalC);
	DrawText(dc, times, moveTimes, textRect, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);


}


void CLQF_TEST1_2View::OnStart()
{
	// TODO: �ڴ���������������

	SetTimer(1, 500, NULL);
}


void CLQF_TEST1_2View::On32772()
{
	// TODO: �ڴ���������������
	KillTimer(mynIDEvent);
}


void CLQF_TEST1_2View::OnDan()
{
	// TODO: �ڴ���������������
	oneStep();
}
