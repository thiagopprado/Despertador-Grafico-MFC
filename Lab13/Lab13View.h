
// Lab13View.h : interface of the CLab13View class
//

#pragma once
#include "atltime.h"


class CLab13View : public CView
{
protected: // create from serialization only
	CLab13View();
	DECLARE_DYNCREATE(CLab13View)

// Attributes
public:
	CLab13Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLab13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	CTime horaAtual;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnAlarmeAlarme1();
	afx_msg void OnAlarmeAlarme2();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnButton32775();
	afx_msg void OnUpdateButton32775(CCmdUI *pCmdUI);
protected:
	bool OnAlarme;
};

#ifndef _DEBUG  // debug version in Lab13View.cpp
inline CLab13Doc* CLab13View::GetDocument() const
   { return reinterpret_cast<CLab13Doc*>(m_pDocument); }
#endif

