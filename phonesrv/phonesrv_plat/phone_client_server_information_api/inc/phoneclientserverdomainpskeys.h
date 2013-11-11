/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Phone Client-Server Domain Publish and Subscribe keys.
*
*/


#ifndef PHONECLIENTSERVERDOMAINPSKEYS_H
#define PHONECLIENTSERVERDOMAINPSKEYS_H

#include <e32std.h>

// CONSTANTS

/******************************************************************************
* Phone Client Server Information API
******************************************************************************/
const TUid KPSUidPhoneClientServerInformation = {0x102029AA}; 

/**
* Indication about operator logo change. 
* @see TTelOTALogoUpdate in phoneclientserverdomainpstypes.h
* @type RProperty::EByteArray
*/

const TUint32 KTelOperatorLogoUpdated = 0x00000001; 

#endif   // PHONECLIENTSERVERDOMAINPSKEYS_H

// End of file