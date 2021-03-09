#include "pch.h"
#include "TileGarden.h"

using namespace std;
using namespace Gdiplus;

/// Image when the garden is at initial stage
const wstring PrunedImage = L"garden.png";

/// Image when the garden is at stage one
const wstring OvergrownOneImage = L"garden1.png";

/// Time to reach low production level in seconds
const double GrowToStageOneTime = 2;

/// Image when the garden is at stage two
const wstring OvergrownTwoImage = L"garden2.png";

/// Time to reach Medium production level in seconds
const double GrowToStageTwoTime = 4;

/// Image when the garden is at stage three
const wstring OvergrownThreeImage = L"garden3.png";

/// Time to reach Medium production level in seconds
const double GrowToStageThreeTime = 7;

/// Image when the garden is at stage four
const wstring OvergrownFourImage = L"garden4.png";

/// Time to reach Medium production level in seconds
const double GrowToStageFourTime = 10;

/** Constructor
* \param city The city this is a member of
*/
CTileGarden::CTileGarden(CCity* city) : CTile(city)
{
    if (mPruningState == PruningStates::Pruned)
    {
        CTile::SetImage(PrunedImage);
    }

}

/**
*  Destructor
*/
CTileGarden::~CTileGarden()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileGarden::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"garden");
    itemNode->SetAttribute(L"file", GetFile());

    return itemNode;
}

/**
 * Called when user checked prune garden menu
 */
void CTileGarden::PruneGarden()
{
    mSincePruning = 0;
    mPruningState = PruningStates::Pruned;
}

/**
 * Called after the prune state is set
 */
void CTileGarden::ImageUpdate() 
{

    if (mPruningState == PruningStates::Pruned)
    {
        CTile::SetImage(PrunedImage);
    }
    else if (mPruningState == PruningStates::Overgrown1)
    {
    CTile::SetImage(OvergrownOneImage);
    }

    else if (mPruningState == PruningStates::Overgrown2)
    {
    CTile::SetImage(OvergrownTwoImage);
    }

    else if (mPruningState == PruningStates::Overgrown3)
    {
    CTile::SetImage(OvergrownThreeImage);
    }

    else if (mPruningState == PruningStates::Overgrown4)
    {
    CTile::SetImage(OvergrownFourImage);
    }
}

/**
 * Called before the image is drawn
 * \param elapsed Time since last draw
 */
void CTileGarden::Update(double elapsed)
{

    CTile::Update(elapsed);

    mSincePruning += elapsed;

    if (mSincePruning >= 2)
    {
        mPruningState = PruningStates::Overgrown1;
    } 

    if (mSincePruning >= 4)
    {
        mPruningState = PruningStates::Overgrown2;
    }

    if (mSincePruning >= 7)
    {
        mPruningState = PruningStates::Overgrown3;
    }

    if (mSincePruning >= 10)
    {
        mPruningState = PruningStates::Overgrown4;
    }

    ImageUpdate();
}