/**
* \file TileBuilding.h
*
* \author Yuxin Li
*
*  Class that implements a Garden tile
*/

#pragma once
#include "Tile.h"

/**
*  A Garden tile
*/
class CTileGarden : public CTile
{
public:
    CTileGarden(CCity* city);

    ///  Default constructor (disabled)
    CTileGarden() = delete;

    ///  Copy constructor (disabled)
    CTileGarden(const CTileCoalmine&) = delete;

    ~CTileGarden();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitGarden(this); }

    void PruneGarden();

private:
    /// The time since last pruning
    double mSincePruning = 0;

    /// The supported pruning states
    enum class PruningStates { Pruned, Overgrown1, Overgrown2, Overgrown3, Overgrown4 };

    /// The pruning states
    PruningStates mPruningState = PruningStates::Pruned;

    void CTileGarden::ImageUpdate();

};

