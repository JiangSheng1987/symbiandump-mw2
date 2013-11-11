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
* Description: Operation for importing landmarks to a database.
*
*
*/


#ifndef CPOSLMLOCALIMPORTOP_H
#define CPOSLMLOCALIMPORTOP_H

//  INCLUDES
#include <EPos_CPosLandmarkDatabase.h>
#include "EPos_CPosLmLocalModifyOp.h"
#include "EPos_MPosLmLocalInternalProxyOpClient.h"
#include "EPos_MPosLmLocalInternalOpExecutor.h"

// CONSTANTS

// FORWARD DECLARATIONS
class CPosLmLocalDatabase;
class CPosLmGlobalCategoryReader;
class CPosLandmarkParser;
class CPosLandmarkCategory;
class CPosLmDiskUtilities;
class CPosLmLocalInternalOpActive;

// CLASS DECLARATION

/**
* Operation for importing landmarks to a database.
*
* @lib eposlmlocalaccess.lib
*/
NONSHARABLE_CLASS(CPosLmLocalImportOp) : public CPosLmLocalModifyOp,
    public MPosLmLocalInternalOpExecutor,
    public MPosLmLocalInternalProxyOpClient
    {

    public:  // Constructors and destructor

        /**
        * Two-phased constructor.
        *
        * @param aDb A landmark database.
        * @param aLandmarkParser A landmark parser object.
        * @param aTransferOptions A bitmap representing the options for the
        *   import operation. The bitmap values are defined by
        *   @ref _TTransferOptions.
        * @param aDiskUtils Disk utilities.
        * @return A new instance of this class.
        */
        static CPosLmLocalImportOp* NewL(
        /* IN  */       CPosLmLocalDatabase& aDb,
        /* IN  */       CPosLandmarkParser& aLandmarkParser,
        /* IN  */       CPosLandmarkDatabase::TTransferOptions aTransferOptions,
        /* IN  */       CPosLmDiskUtilities& aDiskUtils
        );

        /**
        * Two-phased constructor.
        *
        * @param aDb A landmark database.
        * @param aLandmarkParser A landmark parser object.
        * @param aLandmarksSelection The indexes for the landmarks that should
        * be imported.
        * @param aTransferOptions A bitmap representing the options for the
        *   import operation. The bitmap values are defined by
        *   @ref _TTransferOptions.
        * @param aDiskUtils Disk utilities.
        * @return A new instance of this class.
        */
        static CPosLmLocalImportOp* NewL(
        /* IN  */       CPosLmLocalDatabase& aDb,
        /* IN  */       CPosLandmarkParser& aLandmarkParser,
        /* IN  */       const RArray<TUint>& aLandmarksSelection,
        /* IN  */       CPosLandmarkDatabase::TTransferOptions aTransferOptions,
        /* IN  */       CPosLmDiskUtilities& aDiskUtils
        );

        /**
        * Destructor.
        */
        virtual ~CPosLmLocalImportOp();

    public: // New functions

        /**
        * Copies all imported landmark item ids into array aLmItemIds.
        *
        * @param aLmItemIds Array of imported landmark item ids.
        */
        void ImportedLandmarkItemIdsL(
        /*  IN/OUT */   RArray<TPosLmItemId>& aLmItemIds
        );

    public: // Functions from base classes

         /**
        * From CPosLmLocalModifyOp.
        *
        * @param aProgress The current progress.
        */
        void DoNextStepPreL(
        /* OUT */       TReal32& aProgress
        );

        /**
        * From CPosLmLocalModifyOp.
        *
        * @param aProgress The current progress.
        * @return ETrue if a begin transaction should be made. EFalse otherwise.
        */
        TBool DoNextStepPostL(
        /* OUT */       TReal32& aProgress
        );

        /**
        * From CPosLmLocalModifyOp.
        *
        * @return Current step size.
        */
        TReal32 Step();

        /**
        * From CPosLmLocalModifyOp.
        *
        * @param aResourceId A resource id.
        * @param aNoOfSubOperations A number of sub operations.
        */
        void CheckResourceValue(
        /* IN */    TInt aResourceId,
        /* IN */    TInt aNoOfSubOperations
        );

        /**
        * From CPosLmLocalOperation;
        *
        * @param aError An error code generated by NextStepL.
        */
        void HandleError(
        /* IN/OUT */    TInt& aError
        );

        /**
        * From MPosLmLocalInternalOpExecutor.
        *
        * @param aStatus Internal operation complete status.
        * @param aProgress Internal operation progress.
        * @param aStatus Client request status.
        * @param aProgress Client progress.
        */
        void InternalOpCompleted(
        /* IN */        TInt aStatus,
        /* IN */        TReal32 aProgress,
        /* IN/OUT */    TRequestStatus& aClientStatus,
        /* IN/OUT */    TReal32& aClientProgress
        );

        /**
        * From MPosLmLocalInternalProxyOpClient.
        *
        * @param aStatus A request status.
        * @param aProgress The operation progress
        */
        void DoNextStep(
        /* OUT */       TRequestStatus& aStatus,
        /* OUT */       TReal32& aProgress
        );

        /**
        * From MPosLmLocalInternalProxyOpClient.
        */
        void DoExecuteL();

    private:

        /**
        * C++ default constructor.
        * @param aDb A landmark db.
        * @param aLandmarkParser A landmark parser.
        * @param aTransferOptions A transfer options.
        * @param aDiskUtils Disk utils.
        */
        CPosLmLocalImportOp(
        /* IN  */       CPosLmLocalDatabase& aDb,
        /* IN  */       CPosLandmarkParser& aLandmarkParser,
        /* IN  */       CPosLandmarkDatabase::TTransferOptions aTransferOptions,
        /* IN  */       CPosLmDiskUtilities& aDiskUtils
        );

        /**
        * By default Symbian 2nd phase constructor is private.
        */
        void ConstructL();

        /**
        * By default Symbian 2nd phase constructor is private.
        *
        * @param aLandmarkIdArray Array of selected landmark index to import.
        */
        void ConstructL(
        /* IN  */       const RArray<TUint>& aLandmarkIdArray
        );

        /**
        * Parse landmark using landmark parser.
        */
        void ParseLandmarkL();

        /**
        * Get parsed landmark from landmark parser.
        */
        void GetParsedLandmarkL();

        /**
        * Import landmark to database.
        */
        void ImportLandmarkL();

        /**
        * Import landmark categories to database.
        */
        void ImportLmCategoriesL();

        /**
        * Add local category to landmark database.
        *
        * @return @p ETrue if category is added to database or
        * item id is set for category. If category doesn't exist in
        * database and import operation should supress creation of
        * categories @p EFalse is returned.
        */
        TBool AddLocalCategoryL(
        /* IN */    CPosLandmarkCategory& aLmCat,
        /* IN */    TPosLmItemId& aLmItemId
        );

        /**
        * Update the progress of the import operation.
        *
        * @param aProgress Progress of the import operation.
        */
        void UpdateProgress(
        /* IN/OUT */    TReal32& aProgress
        );

        /**
        * Check whether import operation should import selected
        * landmarks or not.
        *
        * @return TBool ETrue if import operation should import
        * selected landmarks.
        */
        TBool LandmarkSelection();

        /**
        * Check whether current landmark is a selected one or not.
        *
        * @return ETrue if it is a selected landmark, otherwise EFalse.
        */
        TBool IsSelectedLandmark();

        /**
        * Checks whether all selected landmarks are imported or not.
        *
        * @return ETrue if all selected landmarks is imported,
        * otherwise EFalse.
        */
        TBool IsSelectedLandmarksImported();

        /**
        * Function is returning global category name from resource file.
        *
        * @param aCategory Category to check in resource file.
        * @return NULL if aCategory is not found in resource file, otherwise
        * category name from resource file is returned.
        */
        HBufC* GlobalCategoryNameInResourceL(
        /*  IN/OUT */   CPosLandmarkCategory* aCategory
        );

        /**
        * Rollback if in transaction and generate an event.
        * @param aProgress Current progress.
        */
        void RollbackAndGenerateEventIfNeeded(
        /* IN */        TReal32 aProgress
        );

        /**
        * Generates an event.
        * @param aProgress Current progress.
        * @return KErrNone if successful. Otherwise any system-wide error code.
        */
        TInt GenerateEventIfNeeded(
        /* IN */        TReal32 aProgress
        );

        /**
        * Adds a category if enough disk space is available.
        * @param aCategory A category.
        *
        * @return @p ETrue if category is added to database or
        * item id is set for category. If category doesn't exist in
        * database and import operation should supress creation of
        * categories @p EFalse is returned.
        */
        TBool AddCategoryL(
        /* IN */        CPosLandmarkCategory& aCategory
        );

        void PrepareNextParsingStep();

        TBool IsInParsingState();

        // Prohibit copy constructor if not deriving from CBase.
        CPosLmLocalImportOp(const CPosLmLocalImportOp&);
        // Prohibit assigment operator if not deriving from CBase.
        CPosLmLocalImportOp& operator=(const CPosLmLocalImportOp&);

    private:    // Data

        // States of the import operation.
        enum TImportState
            {
            EImportParseLm,
            EImportAddLmCatToDb,
            EImportAddLmToDb,
            EReadyImportingLm
            };

        // Landmark parser (no ownership).
        CPosLandmarkParser* iLandmarkParser;

        // Transfer options
        CPosLandmarkDatabase::TTransferOptions iTransferOptions;

        // Landmark global category reader.
        CPosLmGlobalCategoryReader* iReader;

        // State of the import operation.
        TImportState iImportState;

        // Latest status of the parser operation
        TInt iParserOpStatus;

        // Old progress of the parser operation
        TReal32 iOldParserProgress;

        // Current progress of the parser operation
        TReal32 iParserProgress;

        // Current landmark parsed from parser
        CPosLandmark* iCurrentLm;

        // The current category handled in the id array.
        TInt iCurrentCategory;

        // Current landmark category ids for parsed landmark
        RArray<TPosLmItemId> iCurrentCategoryIds;

        // Current parser landmark index
        TUint iCurrentLmIndex;

        // Item list with landmarks to import.
        RArray<TPosLmItemId> iSelectedLmIds;

        // Position of next selected landmark id in iSelectedLmIds.
        TInt iSelectedLmIdPos;

        // Item list with imported landmarks.
        RArray<TPosLmItemId> iImportedLmIds;

        // Number of categories added
        TInt iNrOfCategoriesAdded;

        // Number of categories updated
        TInt iNrOfCategoriesUpdated;

        // Item id of last changed category id
        TPosLmItemId iLastChangedCategoryId;

        // Last reported progress for this operation
        TReal32 iLastReportedProgress;

        // Current progress
        TReal32 iCurrentProgress;

        // Disk utilities (no ownership)
        CPosLmDiskUtilities* iDiskUtils;

        // Active object running the internal operation asynchronously
        CPosLmLocalInternalOpActive* iInternalOpActive;

    };

#endif      // CPOSLMLOCALIMPORTOP_H

// End of File