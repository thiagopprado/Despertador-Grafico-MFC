// AlarmeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Lab13.h"
#include "AlarmeDlg.h"
#include "afxdialogex.h"


// CAlarmeDlg dialog

IMPLEMENT_DYNAMIC(CAlarmeDlg, CDialogEx)

CAlarmeDlg::CAlarmeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, hora(0)
	, minuto(0)
	, segundo(0)
	, alarmeOn(false)
	, pachal(0)
{

}

CAlarmeDlg::~CAlarmeDlg()
{
}

void CAlarmeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, hora);
	DDV_MinMaxInt(pDX, hora, 0, 23);
	DDX_Text(pDX, IDC_EDIT2, minuto);
	DDV_MinMaxInt(pDX, minuto, 0, 59);
	DDX_Text(pDX, IDC_EDIT3, segundo);
	DDV_MinMaxInt(pDX, segundo, 0, 59);
	DDX_Radio(pDX, IDC_RADIO1, alarmeOn);
	DDX_Radio(pDX, IDC_RADIO3, pachal);
}


BEGIN_MESSAGE_MAP(CAlarmeDlg, CDialogEx)
END_MESSAGE_MAP()


// CAlarmeDlg message handlers
