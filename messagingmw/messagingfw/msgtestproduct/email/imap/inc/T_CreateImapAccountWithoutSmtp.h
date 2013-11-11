// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the header file for CT_MsgCreateImapAccountWithoutSmtp class
// 
//

#ifndef T_CREATE_IMAP_ACCOUNT_WITHOUT_SMTP_H
#define T_CREATE_IMAP_ACCOUNT_WITHOUT_SMTP_H

/* User include */
#include "T_MsgSyncStepIMAP.h"

/* Literal used */
_LIT(KCreateImapAccountWithoutSmtp,"CreateImapAccountWithoutSmtp");

/* Implements a test step to create an IMAP account reading the settings from a config file */
class CT_MsgCreateImapAccountWithoutSmtp : public CT_MsgSyncStepIMAP
	{
public:
	CT_MsgCreateImapAccountWithoutSmtp(CT_MsgSharedDataImap& aSharedDataIMAP);

	/* CTestStep implementation */
	virtual TVerdict doTestStepL();
	
private:
	TBool ReadIni();

private:
	TPtrC iImapAccountName;
	TPtrC iConfigFileName;
	
	};
#endif /* T_CREATE_IMAP_ACCOUNT_WITHOUT_SMTP_H */