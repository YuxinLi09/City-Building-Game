/**
 * \file PointHistory.cpp
 *
 * \author Charles Owen
 */


#include "pch.h"
#include "PointHistory.h"


using namespace std;
using namespace Gdiplus;

/**
 * Constructor
 */
CPointHistory::CPointHistory()
{
}


/**
 * Destructor
 */
CPointHistory::~CPointHistory()
{
}



/**
 * Add a pointer to the collection of points.
 * \param p Point to add
 */
void CPointHistory::Add(Gdiplus::Point p)
{
    mPotatoLists[mCurrentList].push_back(p);
    mCurrentList = (mCurrentList + 1) % NumLists;
}
