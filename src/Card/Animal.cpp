#include "Card/Animal.hpp"
namespace card {
    Animal::Animal(Type type, std::string name, unsigned int id, const std::vector<std::shared_ptr<Util::SFX>> sfxs, const std::shared_ptr<Util::Image> image)
        : Mob(type, name, id, sfxs, image) {
    }
}