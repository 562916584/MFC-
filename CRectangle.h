#pragma once
#include "CShape.h"
class CRectangle :
	public CShape
{
public:
	CRectangle();
	CRectangle(int width) :width(width/2) {
		//Ĭ��Բ��Ϊ10
		roundP.x = 10;
		roundP.y = 10;
	}
	CRectangle(int x1, int y1, int x2, int y2, int width) : CShape(x1, y1, x2, y2),width(width) {
		//Ĭ��Բ��Ϊ10
		roundP.x = 10;
		roundP.y = 10;
	};
	~CRectangle();
	void onDraw(CDC *pDC);
	void prepare(const CPoint location,int height,CDC *pDC);
	void setNum(int num);
	void prepare(const CPoint location, CDC * pDC);
	int getWidth();
private:
	CPoint roundP;
	CPoint top, bottom;
	int width;// ���εĿ��
	int height = 25; // ���θ߶�
	int num;// ����ײ����ٸ��߶�
};

