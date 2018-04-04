
// Lab13Doc.h : interface of the CLab13Doc class
//


#pragma once
#include "atltime.h"


class CLab13Doc : public CDocument
{
protected: // create from serialization only
	CLab13Doc();
	DECLARE_DYNCREATE(CLab13Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CLab13Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	struct tempo {
		int h, m, s, on, pachal;
	};
	tempo Alarme1{-1,-1,-1, 0, 0}, Alarme2{ -1,-1,-1, 0, 0};

};
