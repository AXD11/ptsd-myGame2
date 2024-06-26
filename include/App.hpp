#ifndef APP_HPP
#define APP_HPP

#include "Card/Card.hpp"
#include "pch.hpp" // IWYU pragma: export
#include "Util/Root.hpp"

#include "Background.hpp"
#include "Giraffe.hpp"
#include "GiraffeText.hpp"
#include "Camera.hpp"
#include "Mouse.hpp"
#include "card/Card.hpp"
#include <list>
#include <map>
#include <memory>
#include <utility>
#include "Board.hpp"
class App {
public:
    enum class Modle {
        Origin,
        Menu,
        Playing
    };
    enum class State {
        START,
        UPDATE,
        END,
    };
    State GetCurrentState() const { return m_CurrentState; }

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)
    static void AddCard(std::shared_ptr<card::Card> NewCard); 
    static void AddObjectToRoot(std::shared_ptr<Util::GameObject> object);
    static void MoveCardToNewX(const std::shared_ptr<card::Card>& specifiedObj, int oldX = 0); 
    static void RemoveCard(const std::shared_ptr<card::Card>& specifiedObj, int X = 0);
    static void ChangeCard(const std::shared_ptr<card::Card>& specifiedObj,  const std::shared_ptr<card::Card> toChange, int X = 0);


private:
    void Play();
    void Pause();
    void CameraUpdate();
    void StackUpdate();
    void Origin();
    void Menu();
    void Playing();
    void mouseUp();

    
private:
    enum class PauseOrPlay {
        Pause,
        Play
    };
    State m_CurrentState = State::START;
    PauseOrPlay m_IsPlayButton= PauseOrPlay::Play;
    Modle m_Modle = Modle::Origin;

    std::vector<std::shared_ptr<GiraffeText>> m_MenuElement = { std::make_shared<GiraffeText>() ,std::make_shared<GiraffeText>() ,std::make_shared<GiraffeText>() };
    std::shared_ptr<Background> m_Background = std::make_shared<Background>();
    std::shared_ptr<Background> m_Menu = std::make_shared<Background>();
    std::shared_ptr<GiraffeText> m_GiraffeText = std::make_shared<GiraffeText>();
    std::shared_ptr<Camera> m_Camera = std::make_shared<Camera>();
    static std::list<std::weak_ptr<card::Card>> m_PushProcessingArea;
    std::shared_ptr<Mouse> m_Mouse = std::make_shared<Mouse>();
    static Util::Root m_Root;
    std::shared_ptr<Board> m_Board = std::make_shared<Board>();
    std::vector<std::string> files = { "AnimalPen", "Apple", "AppleTree", "Baby", "Bear", "Berry", "BerryBush",//
        "Bone", "Brick", "Brickyard", "Campfire", "Carrot", "Catacombs", "Chicken", "Coin", "CoinChest", "CookedMeat",//
        "Corpse", "Cow", "Demon", "Dog", "Egg", "Explorer", "Farm", "Flint", "Forest", "Frittata", "FruitSalad", "Garden", //
        "GiantRat", "Goblin", "GoldenGoblet", "Graveyard", "House", "IronBar", "IronDeposit", "IronMine", "IronOre",//
        "Key", "LumberCamp", "MagicDust", "Map", "Market", "Militia", "Milk", "Milkshake", "Mountain", "Mushroom", "OldTome", //
        "OldVillage", "Omelette", "Onion", "Plains", "Plank", "Poop", "Potato", "Quarry", "Rabbit", "RarePortal", "Rat", //
        "RawMeat", "Rock", "Sawmill", "Shed", "Skeleton", "Slime", "SmallSlime",//
        "Smelter", "Smithy", "Soil", "Spear", "Stew", "Stick", "Stone",  "StrangePortal", "Sword", "Swordsman", "Temple", //
        "TravellingCart", "TreasureChest", "Tree", "Villager", "Warehouse", "WickedWitch", "Wolf", "Wood" };


    static std::multimap<int, std::shared_ptr<card::Card>> m_WorldCards;
};
#endif
