/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Operation for finalizing URL encoder.
*
*
*/


#ifndef CPOSLMURLENCODEROPERATION_H
#define CPOSLMURLENCODEROPERATION_H

//  INCLUDES
#include "EPos_CPosLmConverterOperation.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CPosLmOutput;

// CLASS DECLARATION

/**
* Operation for finalizing URL encoder. This operation can be either synchronous
* or asynchronous.
*
*  @lib eposconverter.lib
*/
class CPosLmUrlEncoderOperation : public CPosLmConverterOperation
    {

    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        * @param aEncoderOutput The output for the encoder. This class takes
        *   ownership of the output.
        * @returns A new instance of this class.
        */
        static CPosLmUrlEncoderOperation* NewL(
        /* IN */        CPosLmOutput* aEncoderOutput
        );

        /**
        * Destructor.
        */
        virtual ~CPosLmUrlEncoderOperation();

    public: // Functions from base classes

        /**
        * From CPosLmConverterOperation;
        *
        * @param aProgress Will be set to the progress of the operation when
        * the step has finished.
        * @return KErrNone if the operation has finished successfully.
        */
        TInt NextStepL(
        /* OUT */   TReal32& aProgress
        );

        /**
        * From CPosLmConverterOperation;
        *
        * @param aError An error code generated by NextStepL.
        */
        void HandleError(
        /* IN/OUT */    TInt& aError
        );

        /**
        * From CPosLmConverterOperation;
        *
        */
        void HandleOperationCompleted();

    private:

        /**
        * C++ default constructor.
        * @param aEncoderOutput The output for the encoder. This class takes
        *   ownership of the output.
        */
        CPosLmUrlEncoderOperation(
        /* IN */        CPosLmOutput* aEncoderOutput
        );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

        // Prohibit copy constructor 
        CPosLmUrlEncoderOperation(const CPosLmUrlEncoderOperation&);
        // Prohibit assigment operator 
        CPosLmUrlEncoderOperation& operator=(const CPosLmUrlEncoderOperation&);

    private:    // Data

        CPosLmOutput*       iEncoderOutput;

    };

#endif      // CPOSLMURLENCODEROPERATION_H

// End of File