/*
* Copyright (c) 2002-2005 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description: Implementation plugin for supltiapi   
*
*/

#ifndef C_LBSSUPLTIAPIIMPL_H
#define C_LBSSUPLTIAPIIMPL_H


#include <e32base.h>
#include <lbs/supltiapi.h> //for MLbsSuplTiObserver

//Forward Declarations
class COMASuplTrace;
class CCLbsSuplTiRequestManager;
/**
 * Class:       CLbsSuplTiApiImplementation
 *
 * Description: Custom ECOM Implementation. This is used by SUPLTIAPI to
 *              interact with teminalinitiation library
 */


class CLbsSuplTiApiImplementation : public CLbsSuplTiApi
    {

public: 

    // Constructors and destructor
    /**
     * @Description:    For Two Phase Construction
     * @Param:          aObserver Reference to the observer to be notified when position request completes
     * @return:         instance of implementation		
     *
     */

    IMPORT_C   static CLbsSuplTiApiImplementation* NewL(MLbsSuplTiObserver& aObserver);

    /**
     * Function:   ~CLbsSuplTiApiImplementation  
     *
     * @Description: Destructor method for CLbsSuplTiApiImplementation
     */
    IMPORT_C  ~CLbsSuplTiApiImplementation();

private:   

    /**
     * Function:     CLbsSuplTiApiImplementation 
     *
     * @Description: Default constructor
     * @Param:       aObserver Reference to the observer to be notified when position request completes
     * @Returns:     None
     */
    CLbsSuplTiApiImplementation(MLbsSuplTiObserver& aObserver);

    /**
     * Function:     ConstructL
     *
     * @Description: For two phase construction 
     *
     * @Param:       none
     *
     * @Returns:     None
     */

    void ConstructL(); 


public://from CLbsSuplTiApi
    /** 
        Implementation method for CLbsSuplTiApi::RequestLocation()
        
        RequestLocation is an asynchronous call to determine the terminal's current
        position information or to determine additional positioning information such as
        assistance data.

        The client can cancel this request using CancelRequest().

        @param aSessionId is the Id of the location request. This is generated by the client and
                must be used by the initiation module when it performs actions releated to that
                request.
        @param aOptions should be of type TLbsNetPosRequestOptions.
               It provides information about the location request, including quality of the location
               required, and a flag to indicate this is the first request made by the client.
        @param aMethod This parameter contains a list of the positioning methods that should be used
               to obtain the device's position.

        @see TLbsNetSessionId
        @see TLbsNetPosRequestOptions
        @see TLbsNetPosRequestMethod
     */
    virtual void RequestLocation(const TLbsNetSessionId& aSessionId, const TLbsNetPosRequestOptionsBase& aOptions, const TLbsNetPosRequestMethod& aMethod);


    /**
        Implementation method for CLbsSuplTiApi::CancelRequest()
        
        Cancels an outstanding asynchronous location request started using RequestLocaion().
        Cancelling requests is typically attempted when an client is closing down.

        This method passes on the  the CancelRequest request to the CCLbsSuplTiRequestManager
        to cancel the location request.

        @param aSessionId The Id of the location request to be cancelled. This must be the same id used
               during the location request.
        @return an error code. A initiation module should return KErrNotFound for invalid session ids.

        @see TLbsNetSessionId
     */
    virtual TInt CancelRequest(const TLbsNetSessionId& aSessionId);


    /**
        This should be called when the request session is no longer required and prior to any call to ~CLbsSuplTiApi().
        All the outstanding requests must be cancelled before closing the session.

        The initiation module should use this opportunity to close any session and server connections it
        may have with any SUPL server framework.
     */
    virtual void CloseSession();


    /**
        Implementation method for CLbsSuplTiApi::GetPosition()
        This is an synchronous method for retrieving position information  
        determined during RSuplTiApi::RequestLocation().

        This method passes on the  the GetPosition request to the CCLbsSuplTiRequestManager
        to retrieve the position info.
        
        @param aSessionId the ID of session from which to obtain the location information.
        @param aPositionInfo the returned location information.
        @return an error code for the location information.

        @see TLbsNetSessionId
        @see TPositionInfoBase
     */
    virtual TInt GetPosition(const TLbsNetSessionId& aSessionId, TPositionInfoBase& aPositionInfo);

private:

    /**
     *	By default, prohibit copy constructor
     */

    CLbsSuplTiApiImplementation( const CLbsSuplTiApiImplementation& );

    /**
     *	By default, Prohibit assigment operator
     */

    CLbsSuplTiApiImplementation& operator= ( const CLbsSuplTiApiImplementation& );

private:

    /*For Logging*/
    COMASuplTrace* iTrace;

    //creates and manages CCLbsSuplTiApiRequestor objects for making location requests
    CCLbsSuplTiRequestManager* iRequestManager;
    };


#endif // C_LBSSUPLTIAPIIMPL_H

// End of File