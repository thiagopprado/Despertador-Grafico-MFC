#pragma once


// CAlarmeDisp dialog

class CAlarmeDisp : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarmeDisp)

public:
	CAlarmeDisp(CWnd* pParent = NULL);   // standard constructor
	virtual ~CAlarmeDisp();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
