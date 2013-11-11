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

#include "CMtfTestActionSendEMsvDeInstallMtmGroup.h"

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
  @return : CMtfTestAction* - a base class pointer to the newly created CMtfTestActionSendEMsvDeInstallMtmGroup object
  @pre none
  @post none
*/
CMtfTestAction* CMtfTestActionSendEMsvDeInstallMtmGroup::NewL(CMtfTestCase& aTestCase,CMtfTestActionParameters* aActionParameters)
	{
	CMtfTestActionSendEMsvDeInstallMtmGroup* self = new (ELeave) CMtfTestActionSendEMsvDeInstallMtmGroup(aTestCase);
	CleanupStack::PushL(self);
	self->ConstructL(aActionParameters);
	CleanupStack::Pop(self);
	return self;
	}

/**
  Function : CMtfTestActionSendEMsvDeInstallMtmGroup
  Description : Constructor
  @internalTechnology
  @param : aTestCase - CMtfTestCase for the CMtfTestAction base class
  @return : N/A
  @pre none
  @post none
*/
CMtfTestActionSendEMsvDeInstallMtmGroup::CMtfTestActionSendEMsvDeInstallMtmGroup(CMtfTestCase& aTestCase) : CMtfSynchronousTestAction(aTestCase)
	{
	}
	
/**
  Function : ~CMtfTestActionSendEMsvDeInstallMtmGroup
  Description : Destructor
  @internalTechnology
  @param :
  @return : 
  @pre 
  @post 
*/
CMtfTestActionSendEMsvDeInstallMtmGroup::~CMtfTestActionSendEMsvDeInstallMtmGroup()
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




void CMtfTestActionSendEMsvDeInstallMtmGroup::ExecuteActionL()
	{
	TestCase().INFO_PRINTF2(_L("Test Action %S start..."), &KTestActionSendEMsvDeInstallMtmGroup);
	// input params
	HBufC* fullName = ObtainParameterReferenceL<HBufC>(TestCase(),ActionParameters().Parameter(0) );
	TInt pass = ObtainValueParameterL<TInt>(TestCase(),ActionParameters().Parameter(1) );

	RProxyServerSession RPSS;
	
	// Will auto start the server if not started.
	TInt error = RPSS.Connect();
	CleanupClosePushL(RPSS);
	
	if (error!=KErrNone)
		{
		TestCase().ERR_PRINTF1(_L("CMtfTestActionSendEMsvDeInstallMtmGroup :: Unable to start proxy server. !"));
		TestCase().SetTestStepResult(EFail);
		}
	else
		{
		TInt32 serverCaps;
		RPSS.GetServerCapabilities(serverCaps);
		TestCase().INFO_PRINTF2(_L("Proxy Server has capabilities: %x"), serverCaps);
				
		error = 0;
		
		TPtr pFullName = fullName->Des();
		
		error=RPSS.SendReceive(EMsvDeInstallMtmGroup , TIpcArgs(&pFullName));

		IPCCommandReportPassOrFailForCapsPermissions( TestCase(), KMsvServerName, error , pass );
		}
	
	CleanupStack::Check(&RPSS);
	CleanupStack::PopAndDestroy(); // RPSS
		
	TestCase().INFO_PRINTF2(_L("Test Action %S completed."), &KTestActionSendEMsvDeInstallMtmGroup);
	TestCase().ActionCompletedL(*this);
	}