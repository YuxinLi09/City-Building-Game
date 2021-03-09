/**
* \file PruneGarden.h
*
* \author Yuxin Li
*
*  Class that implements a Building tile
*/

#pragma once
#include "TileGarden.h"

/**  A counter that is to count the buildings
*/
class CPruneGarden : public CTileVisitor
{
public:

    /** Visit a CTileGarden object
    * \param garden Garden we are visiting */
    void CPruneGarden::VisitGarden(CTileGarden* garden)
    {
        garden->PruneGarden();
    }
};
