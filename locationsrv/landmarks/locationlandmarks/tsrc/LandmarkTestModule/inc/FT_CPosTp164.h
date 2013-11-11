/*
* Copyright (c) 2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: 
*   ?description_line
*
*/


#ifndef CPOSTp164_H
#define CPOSTp164_H

//  INCLUDES
#include "FT_CLandmarkTestProcedureBase.h"

// CLASS DECLARATION

/**
*  Test procedure 164
*/
class CPosTp164 :public CLandmarkTestProcedureBase
    {
    public:  // Constructors and destructor
        
        /**
        * C++ default constructor.
        */
       
        CPosTp164(TInt tpno, CStifLogger* aLog) : CLandmarkTestProcedureBase(tpno, aLog) {};
        /**
        * Destructor.
        */
        ~CPosTp164() {};

    public: // Functions from base classes

        
        /**
        * From CLandmarkTestProcedureBase
        * Runs the test in the module
        */
        void StartL();
        
        void CloseTest();

    private:
    
        void TestImportEmptyDbL(const TDesC& aFile, const TDesC8& aMime);
        
        void TestImport1L(const TDesC& aFile, const TDesC8& aMime);
        
        void CheckLandmarkL(TPosLmItemId aLandmarkId, RArray<TPosLmItemId> aCategoriesList);
        
    private:
    
        CPosLandmarkParser* iLandmarkParser;
        TInt iErrorsFound;
    };
    

#endif      // CPOSTp164_H
            
// End of File