// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//


#ifndef __CMTFTESTACTIONCREATEATTACHMENTNOFILECLOSE_H__
#define __CMTFTESTACTIONCREATEATTACHMENTNOFILECLOSE_H__

#include "CMtfSynchronousTestAction.h"

#include <f32file.h>

_LIT(KTestActionCreateAttachmentNoFileClose,"CreateAttachmentNoFileClose");

class CMtfTestActionCreateAttachmentNoFileClose : public CMtfSynchronousTestAction
	{
public:
	static CMtfTestAction* NewL(CMtfTestCase& aTestCase,CMtfTestActionParameters* ActionParameters);
	virtual ~CMtfTestActionCreateAttachmentNoFileClose(); 

public:
	virtual void ExecuteActionL();

private:
	CMtfTestActionCreateAttachmentNoFileClose(CMtfTestCase& aTestCase);
	
	void PopulateFileL(RFile& aFile, const TDesC& aDataFilePath);
	};


#endif // __CMTFTESTACTIONCREATEATTACHMENTNOFILECLOSE_H__