/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>
#include "Click.h"


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);

    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * \param history The mouse history
         * \param pos The position where the mouse is
         * \param listNum The number of list */
        Iter(CPointHistory* history, int pos, int listNum) : mHistory(history), mPos(pos), mListNum(listNum) {}

        /** Test for end of the iterator
         * \param other Other position we are comparing to
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return (mPos != other.mPos)||(mListNum != other.mListNum);
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const { return mHistory->mPotatoLists[mListNum][mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mListNum = (mListNum + 1) % NumLists;

            if (mListNum == 0)
            {
                mPos++;
            }
            return *this;
        }

    private:
        CPointHistory* mHistory;   ///< Mouse history we are iterating over
        int mPos;       ///< Position in the collection
        int mListNum;    ///< Number of list in the collection
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, (mPotatoLists[NumLists-1].size()), mCurrentList); }

protected:
    /// Data is stored in alternating locations in 
    /// the multiple hot potato lists.
    std::vector<Gdiplus::Point> mPotatoLists[NumLists];

    /// The current list we are adding points to. Each time
    /// we add a point, we will add it to this list, then 
    /// change mCurrentList to change to the next list.
    int mCurrentList = 0;
};

