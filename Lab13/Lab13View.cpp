
// Lab13View.cpp : implementation of the CLab13View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab13.h"
#endif
#include <wmp.h>
#include "Lab13Doc.h"
#include "Lab13View.h"
#include "AlarmeDlg.h"
#include "AlarmeDisp.h"
#include <mmsystem.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLab13View

IMPLEMENT_DYNCREATE(CLab13View, CView)

BEGIN_MESSAGE_MAP(CLab13View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_COMMAND(ID_ALARME_ALARME1, &CLab13View::OnAlarmeAlarme1)
	ON_COMMAND(ID_ALARME_ALARME2, &CLab13View::OnAlarmeAlarme2)
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_BUTTON32775, &CLab13View::OnButton32775)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32775, &CLab13View::OnUpdateButton32775)
END_MESSAGE_MAP()

// CLab13View construction/destruction

CLab13View::CLab13View()
	: horaAtual(0)
	, OnAlarme(false)
{
	// TODO: add construction code here

}

CLab13View::~CLab13View()
{
}

BOOL CLab13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

// CLab13View drawing

void CLab13View::OnDraw(CDC* pDC)
{
	CLab13Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: add draw code for native data here
	
	CRect Tela;
	GetClientRect(&Tela);

	double raio = Tela.Height() / 2;
	CPoint centro(Tela.Width() / 2, Tela.Height() / 2);
	CPen contorno(PS_SOLID, 2*raio/200, RGB(0, 0, 0));
	CPen *old = pDC->SelectObject(&contorno);
	CBrush fundo(RGB(153, 204, 255));
	CBrush *oldB = pDC->SelectObject(&fundo);

	pDC->Ellipse(centro.x - raio, centro.y - raio, centro.x + raio, centro.y + raio);
	pDC->SelectObject(oldB);

	CBrush dentro(RGB(224, 255, 255));
	oldB = pDC->SelectObject(&dentro);
	pDC->Ellipse(centro.x - 0.95*raio, centro.y - 0.95*raio, centro.x + 0.95*raio, centro.y + 0.95*raio);
	
	pDC->Ellipse(centro.x - 0.01*raio, centro.y - 0.01*raio, centro.x + 0.01*raio, centro.y + 0.01*raio);
	
	pDC->SelectObject(old);

	for (int i = -90; i < 270; i += 6) {
		if (!(i % 30)) {
			pDC->MoveTo(centro.x + 0.82*raio*cos((double)i*3.1415/180), centro.y+ 0.82*raio*sin((double)i*3.1415 / 180));
		}
		else {
			pDC->MoveTo(centro.x + 0.90*raio*cos((double)i*3.1415 / 180), centro.y + 0.90*raio*sin((double)i*3.1415 / 180));
		}
		pDC->LineTo(centro.x + 0.95*raio*cos((double)i*3.1415 / 180), centro.y + 0.95*raio*sin((double)i*3.1415 / 180));
	}
	CFont oFont;
	oFont.CreateFont(0.15*raio, 0, 0, 0, 400, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, _T("Times New Roman"));
	CFont* oldfont = pDC->SelectObject(&oFont);
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOutW(centro.x + 0.69*raio*cos(60 * 3.1415 / 180), centro.y - 0.8*raio*sin(60 * 3.1415 / 180), _T("1"));
	pDC->TextOutW(centro.x + 0.72*raio*cos(30 * 3.1415 / 180), centro.y - 0.88*raio*sin(30 * 3.1415 / 180), _T("2"));
	pDC->TextOutW(centro.x + 0.74*raio*cos(360 * 3.1415 / 180), centro.y - 0.83*raio*sin(4 * 3.1415 / 180), _T("3"));
	pDC->TextOutW(centro.x + 0.72*raio*cos(330 * 3.1415 / 180), centro.y - 0.62*raio*sin(330 * 3.1415 / 180), _T("4"));
	pDC->TextOutW(centro.x + 0.75*raio*cos(300 * 3.1415 / 180), centro.y - 0.66*raio*sin(300 * 3.1415 / 180), _T("5"));
	pDC->TextOutW(centro.x + 0.75*raio*cos(268 * 3.1415 / 180), centro.y - 0.66*raio*sin(270 * 3.1415 / 180), _T("6"));
	pDC->TextOutW(centro.x + 0.72*raio*cos(236 * 3.1415 / 180), centro.y - 0.66*raio*sin(240 * 3.1415 / 180), _T("7"));
	pDC->TextOutW(centro.x + 0.78*raio*cos(210 * 3.1415 / 180), centro.y - 0.64*raio*sin(210 * 3.1415 / 180), _T("8"));
	pDC->TextOutW(centro.x + 0.78*raio*cos(180 * 3.1415 / 180), centro.y - 0.8*raio*sin(175 * 3.1415 / 180), _T("9"));
	pDC->TextOutW(centro.x + 0.8*raio*cos(150 * 3.1415 / 180), centro.y - 0.88*raio*sin(150 * 3.1415 / 180), _T("10"));
	pDC->TextOutW(centro.x + 0.85*raio*cos(120 * 3.1415 / 180), centro.y - 0.8*raio*sin(120 * 3.1415 / 180), _T("11"));
	pDC->TextOutW(centro.x + 0.75*raio*cos(95 * 3.1415 / 180), centro.y - 0.8*raio*sin(90 * 3.1415 / 180), _T("12"));

	CPen Vermelho(PS_SOLID, 0.02 * raio, RGB(255, 0, 0));
	CPen Verde(PS_SOLID, 0.015 * raio, RGB(0, 255, 0));
	CPen Azul(PS_SOLID, 0.015 * raio, RGB(0, 0, 255));

	//Horas
	pDC->SelectObject(&Vermelho);
	pDC->MoveTo(centro.x, centro.y);
	pDC->LineTo(centro.x + 0.40*raio*cos(3.1415 / 2 - (30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600)*3.1415 / 180)), centro.y - 0.40*raio*sin(3.1415 / 2 - (30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600)*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.35*raio*cos(3.1415 / 2 - ((30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600) - 3)*3.1415 / 180)), centro.y - 0.35*raio*sin(3.1415 / 2 - ((30 *(horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600) - 3)*3.1415 / 180)));
	pDC->MoveTo(centro.x + 0.40*raio*cos(3.1415 / 2 - (30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600)*3.1415 / 180)), centro.y - 0.40*raio*sin(3.1415 / 2 - (30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600)*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.35*raio*cos(3.1415 / 2 - ((30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600) + 3)*3.1415 / 180)), centro.y - 0.35*raio*sin(3.1415 / 2 - ((30 * (horaAtual.GetHour() + (double)horaAtual.GetMinute() / 60 + (double)horaAtual.GetSecond() / 3600) + 3)*3.1415 / 180)));

	//Minutos
	pDC->SelectObject(&Verde);
	pDC->MoveTo(centro.x, centro.y);
	pDC->LineTo(centro.x + 0.60*raio*cos(3.1415 / 2 - (6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60)*3.1415 / 180)), centro.y - 0.60*raio*sin(3.1415 / 2 - (6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60)*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.55*raio*cos(3.1415 / 2 - ((6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60)+2)*3.1415 / 180)), centro.y - 0.55*raio*sin(3.1415 / 2 - ((6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60) + 2)*3.1415 / 180)));
	pDC->MoveTo(centro.x + 0.60*raio*cos(3.1415 / 2 - (6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60)*3.1415 / 180)), centro.y - 0.60*raio*sin(3.1415 / 2 - (6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60)*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.55*raio*cos(3.1415 / 2 - ((6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60) - 2)*3.1415 / 180)), centro.y - 0.55*raio*sin(3.1415 / 2 - ((6 * (horaAtual.GetMinute() + (double)horaAtual.GetSecond() / 60) -2)*3.1415 / 180)));

	//Segundos
	pDC->SelectObject(&Azul);
	pDC->MoveTo(centro.x, centro.y);
	pDC->LineTo(centro.x + 0.80*raio*cos(3.1415 / 2 - (6 * horaAtual.GetSecond()*3.1415 / 180)), centro.y - 0.80*raio*sin(3.1415 / 2 - (6 * horaAtual.GetSecond()*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.75*raio*cos(3.1415 / 2 - ((6 * horaAtual.GetSecond() + 2)*3.1415 / 180)), centro.y - 0.75*raio*sin(3.1415 / 2 - ((6 * horaAtual.GetSecond() + 2)*3.1415 / 180)));
	pDC->MoveTo(centro.x + 0.80*raio*cos(3.1415 / 2 - (6 * horaAtual.GetSecond()*3.1415 / 180)), centro.y - 0.80*raio*sin(3.1415 / 2 - (6 * horaAtual.GetSecond()*3.1415 / 180)));
	pDC->LineTo(centro.x + 0.75*raio*cos(3.1415 / 2 - ((6 * horaAtual.GetSecond() - 2)*3.1415 / 180)), centro.y - 0.75*raio*sin(3.1415 / 2 - ((6 * horaAtual.GetSecond() - 2)*3.1415 / 180)));

	pDC->SelectObject(oldB);
	pDC->SelectObject(old);
	pDC->SelectObject(oldfont);
}


// CLab13View printing

BOOL CLab13View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLab13View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLab13View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLab13View diagnostics

#ifdef _DEBUG
void CLab13View::AssertValid() const
{
	CView::AssertValid();
}

void CLab13View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLab13Doc* CLab13View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLab13Doc)));
	return (CLab13Doc*)m_pDocument;
}
#endif //_DEBUG


// CLab13View message handlers


void CLab13View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1, 1000, NULL);
}


void CLab13View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillTimer(1);
}


void CLab13View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	horaAtual = CTime::GetCurrentTime();
	Invalidate();
	CLab13Doc* pDoc = GetDocument();
	if (GetDocument()->Alarme1.on) {
		if ((horaAtual.GetHour() == pDoc->Alarme1.h) && (horaAtual.GetMinute() == pDoc->Alarme1.m) && (horaAtual.GetSecond() == pDoc->Alarme1.s)) {
			//AfxMessageBox(_T("Alarme 1!"));
			if (GetDocument()->Alarme1.pachal) {
				PlaySound(MAKEINTRESOURCEW(IDR_WAVE3), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC | SND_LOOP);
				if (!OnAlarme)
					OnAlarme = true;
			}
			else {
				system("shutdown \/h");
			}
			
			
		}
	}
	if (GetDocument()->Alarme2.on) {
		if ((horaAtual.GetHour() == pDoc->Alarme2.h) && (horaAtual.GetMinute() == pDoc->Alarme2.m) && (horaAtual.GetSecond() == pDoc->Alarme2.s)) {
			//AfxMessageBox(_T("Alarme 2!"));
			if (GetDocument()->Alarme2.pachal) {
				PlaySound(MAKEINTRESOURCEW(IDR_WAVE3), AfxGetInstanceHandle(), SND_RESOURCE |SND_ASYNC | SND_LOOP);
				if (!OnAlarme)
					OnAlarme = true;
			}
			else {
				system("shutdown \/h");
			}
			
		}
		
	}
	CView::OnTimer(nIDEvent);
}


void CLab13View::OnAlarmeAlarme1()
{
	// TODO: Add your command handler code here
	CAlarmeDlg dlg;
	dlg.hora = GetDocument()->Alarme1.h;
	dlg.minuto = GetDocument()->Alarme1.m;
	dlg.segundo = GetDocument()->Alarme1.s;
	dlg.alarmeOn = GetDocument()->Alarme1.on;
	dlg.pachal = GetDocument()->Alarme1.pachal;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->Alarme1.h = dlg.hora;
		GetDocument()->Alarme1.m = dlg.minuto;
		GetDocument()->Alarme1.s = dlg.segundo;
		GetDocument()->Alarme1.on = dlg.alarmeOn;
		GetDocument()->Alarme1.pachal = dlg.pachal;
		//GetDocument()->SetModifiedFlag();
	}
}


void CLab13View::OnAlarmeAlarme2()
{
	// TODO: Add your command handler code here
	CAlarmeDlg dlg;
	dlg.hora = GetDocument()->Alarme2.h;
	dlg.minuto = GetDocument()->Alarme2.m;
	dlg.segundo = GetDocument()->Alarme2.s;
	dlg.alarmeOn = GetDocument()->Alarme2.on;
	dlg.pachal = GetDocument()->Alarme2.pachal;
	if (dlg.DoModal() == IDOK) {
		GetDocument()->Alarme2.h = dlg.hora;
		GetDocument()->Alarme2.m = dlg.minuto;
		GetDocument()->Alarme2.s = dlg.segundo;
		GetDocument()->Alarme2.on = dlg.alarmeOn;
		GetDocument()->Alarme2.pachal = dlg.pachal;
		//GetDocument()->SetModifiedFlag();
	}
}



void CLab13View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (OnAlarme) {
		PlaySound(NULL, NULL, 0);
		OnAlarme = false;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CLab13View::OnButton32775()
{
	// TODO: Add your command handler code here
	if (OnAlarme) {
		PlaySound(NULL, NULL, 0);
		OnAlarme = false;
	}
}


void CLab13View::OnUpdateButton32775(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(OnAlarme);
}
