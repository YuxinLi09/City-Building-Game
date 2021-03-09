/**
* \file TileBuilding.h
*
* \author Yuxin Li
*
*  Class that implements a Building tile
*/

#pragma once
#include "TileBuilding.h"

/**  A counter that is to count the buildings
*/
class CBuildingCounter : public CTileVisitor
{
public:
    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    /** Visit a CTileBuilding object
    * \param building Building we are visiting */
    void CBuildingCounter::VisitBuilding(CTileBuilding* building)
    {
        mNumBuildings++;
    }


private:
    /// Buildings counter
    int mNumBuildings = 0;
};

