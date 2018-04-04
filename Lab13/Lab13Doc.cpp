
// Lab13Doc.cpp : implementation of the CLab13Doc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Lab13.h"
#endif

#include "Lab13Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLab13Doc

IMPLEMENT_DYNCREATE(CLab13Doc, CDocument)

BEGIN_MESSAGE_MAP(CLab13Doc, CDocument)
END_MESSAGE_MAP()


// CLab13Doc construction/destruction

CLab13Doc::CLab13Doc()
{
	// TODO: add one-time construction code here

}

CLab13Doc::~CLab13Doc()
{
}

BOOL CLab13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CLab13Doc serialization

void CLab13Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << Alarme1.h << Alarme1.m << Alarme1.s << Alarme1.on << Alarme2.h << Alarme2.m << Alarme2.s << Alarme2.on << Alarme1.pachal << Alarme2.pachal;
	}
	else
	{
		// TODO: add loading code here
		ar >> Alarme1.h >> Alarme1.m >> Alarme1.s >> Alarme1.on >> Alarme2.h >> Alarme2.m >> Alarme2.s >> Alarme2.on >> Alarme1.pachal >> Alarme2.pachal;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLab13Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLab13Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLab13Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLab13Doc diagnostics

#ifdef _DEBUG
void CLab13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLab13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLab13Doc commands
