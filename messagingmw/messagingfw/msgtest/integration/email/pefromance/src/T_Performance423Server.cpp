// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include "T_Performance423Step.h"

_LIT(KServerName,"T_Performance423");

CPerformance423Server* CPerformance423Server::NewL()
	{
	CPerformance423Server * server = new (ELeave) CPerformance423Server();
	CleanupStack::PushL(server);
	server-> ConstructL(KServerName);

	CleanupStack::Pop(server);
	return server;
	}
	
LOCAL_C void MainL()
	{
	CActiveScheduler* sched=new(ELeave) CActiveScheduler;
	CActiveScheduler::Install(sched);
	CPerformance423Server* server = NULL;
	// Create the CTestServer derived server
	TRAPD(err,server = CPerformance423Server::NewL());
	if(err==KErrNone)
		{
		// Sync with the client and enter the active scheduler
		RProcess::Rendezvous(KErrNone);
		sched->Start();
		}
	delete server;
	delete sched;
	}


GLDEF_C TInt E32Main()
	{
	__UHEAP_MARK;
	
	CTrapCleanup* cleanup = CTrapCleanup::New();
	if(cleanup == NULL)
		{
		return KErrNoMemory;
		}
	TRAPD(err,MainL());
	delete cleanup;
	
	__UHEAP_MARKEND;
	return err;
    }


RFs& CPerformance423Server::Fs()
	{
	return iFs;
	};	

CTestStep* CPerformance423Server::CreateTestStep(const TDesC& aStepName)
	{
		
	CTestStep* testStep = NULL;
	
	if(aStepName == KPerformance423)
		{
		testStep = new CPerformance423Step();		
		}

	return testStep;
	}