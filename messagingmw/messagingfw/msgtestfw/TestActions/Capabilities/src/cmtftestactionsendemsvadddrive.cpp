// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include "cmtftestactionsendemsvadddrive.h"

#include <e32std.h>
#include <e32base.h>

#include <msvipc.h>
#include "MCLIENT.H"
#include "MSERVER.H"


#include "CMtfTestCase.h"
#include "CMtfTestActionParameters.h"

#include "IPCCommandForCapsPermissions.h"
#include "SendProxyClient.h"
#include "SendProxyserver.h"


/**
  Function : NewL
  Description :
  @internalTechnology
  @param : aTestCase - CMtfTestCase for the CMtfTestAction base class
  @param : aActionParams - CMtfTestActionParameters
  @return : CMtfTestAction* - a base class pointer to the newly created CMtfTestActionSendEMsvAddDrive object
  @pre none
  @post none
*/
CMtfTestAction* CMtfTestActionSendEMsvAddDrive::NewL(CMtfTestCase& aTestCase,CMtfTestActionParameters* aActionParameters)
	{
	CMtfTestActionSendEMsvAddDrive* self = new (ELeave) CMtfTestActionSendEMsvAddDrive(aTestCase);
	CleanupStack::PushL(self);
	self->ConstructL(aActionParameters);
	CleanupStack::Pop(self);
	return self;
	}

/**
  Function : CMtfTestActionSendEMsvAddDrive
  Description : Constructor
  @internalTechnology
  @param : aTestCase - CMtfTestCase for the CMtfTestAction base class
  @return : N/A
  @pre none
  @post none
*/
CMtfTestActionSendEMsvAddDrive::CMtfTestActionSendEMsvAddDrive(CMtfTestCase& aTestCase) : CMtfSynchronousTestAction(aTestCase)
	{
	}

/**
  Function : ~CMtfTestActionSendEMsvAddDrive
  Description : Destructor
  @internalTechnology
  @param :
  @return :
  @pre
  @post
*/
CMtfTestActionSendEMsvAddDrive::~CMtfTestActionSendEMsvAddDrive()
	{
	}

/**
  Function : ExecuteActionL
  Description : Entry point for the this test action in the test framework
  @internalTechnology
  @param : none
  @return : void
  @pre none
  @post none
*/
void CMtfTestActionSendEMsvAddDrive::ExecuteActionL()
	{
	TestCase().INFO_PRINTF2(_L("Test Action %S start..."), &KTestActionSendEMsvAddDrive);
	// input params
	TInt drive = ObtainValueParameterL<TInt>(TestCase(),ActionParameters().Parameter(0) );
	TInt priority = ObtainValueParameterL<TInt>(TestCase(),ActionParameters().Parameter(1) );
	TInt pass = ObtainValueParameterL<TInt>(TestCase(),ActionParameters().Parameter(2) );

	RProxyServerSession RPSS;
	TInt error = RPSS.Connect();
	CleanupClosePushL(RPSS);

	// Will auto start the server if not started.
	if (error!=KErrNone)
		{
		TestCase().ERR_PRINTF1(_L("CMtfTestActionSendEMsvAddDrive :: Unable to start proxy server. !"));
		TestCase().SetTestStepResult(EFail);
		}
	else
		{
		TInt32 serverCaps;
		RPSS.GetServerCapabilities(serverCaps);
		TestCase().INFO_PRINTF2(_L("Proxy Server has capabilities: %x"), serverCaps);

		TUint newPriority = priority;
		TPckg<TInt> priorityPkg(newPriority);

		TInt error = RPSS.SendReceive(EMsvAddDriveToDriveList, TIpcArgs(TDriveNumber(drive),priority,&priorityPkg));
		IPCCommandReportPassOrFailForCapsPermissions( TestCase(), KMsvServerName, error , pass );
		}

	CleanupStack::Check(&RPSS);
	CleanupStack::PopAndDestroy(); // RPSS

	TestCase().INFO_PRINTF2(_L("Test Action %S completed."), &KTestActionSendEMsvAddDrive);
	TestCase().ActionCompletedL(*this);
	}
