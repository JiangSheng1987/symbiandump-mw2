// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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

/**
 @file
 @internalComponent
 @released
*/


#ifndef __ROAPKEYPARSER_H__
#define __ROAPKEYPARSER_H__

#include "parsehandlerbase.h"
#include "stringparser.h"

namespace ReferenceTestAgent
	{
	class CDrmRights;
	class CRightsObject;
	
	/** parser for the <Rights> tag
	*/
	class CRoapKeyParser : public CParseHandlerBase
		{
	public:
		static CRoapKeyParser* NewL();
		virtual ~CRoapKeyParser();
		
		virtual void ParseStartElementL(const RTagInfo& aElement, const RAttributeArray& aAttributes);
		virtual void ParseEndElementL(const RTagInfo& aElement);
		
		virtual void ParseContentL(const TDesC8& aBytes);
	private:
		CRoapKeyParser();

	private:
		TBool iDeviceIdParsed;
		TBool iRiIdParsed;
		TBool iKeyIdentifierParsed;
		TBool iHashParsed;
		};
	}

#endif