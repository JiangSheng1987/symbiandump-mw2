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
* Description: 
*   ?description_line
*
*/


#ifndef CPOSTP17_H
#define CPOSTP17_H

//  INCLUDES
#include "FT_CLandmarkTestProcedureBase.h"

// CLASS DECLARATION

/**
*  Test procedure 17
*/
class CPosTp17 : public CLandmarkTestProcedureBase
    {
    public:  // Constructors and destructor
        
        /**
        * C++ default constructor.
        */
        CPosTp17() : CLandmarkTestProcedureBase(17) {};
        
        /**
        * Destructor.
        */
        ~CPosTp17() {};

    public: // Functions from base classes

        /**
        * From CUtfwTestBase
        * Retrieves the test module name
        * @param aName The name of the test module.
        */
        void GetName(
            TDes&   aName
            ) const;

        /**
        * From CLandmarkTestProcedureBase
        * Runs the test in the module
        */
        void StartL();

        void CloseTest();

    private:

        void SetupTestDataL();
    
    private: // Data
   
        RArray<TInt>            iFootprints;
       
        RArray<TPtrC>           iDllNames;

    };

#endif      // CPOSTP17_H
            
// End of File