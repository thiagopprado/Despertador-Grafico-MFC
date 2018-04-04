#pragma once


// CAlarmeDlg dialog

class CAlarmeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarmeDlg)

public:
	CAlarmeDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAlarmeDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int hora;
	int minuto;
	int segundo;
	int alarmeOn;
	int pachal;
};
