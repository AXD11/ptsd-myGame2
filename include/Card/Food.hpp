#ifndef FOOD_HPP
#define FOOD_HPP
#include "pch.hpp"
#include "Card/Card.hpp"
namespace card {
	class Food :public Card {
	private:
	public:  
		Food(Type type, std::string name, unsigned int id, const std::vector<std::shared_ptr<Util::SFX>> sfxs, const std::shared_ptr<Util::Image> image, const bool iconcolor);
		virtual bool CanHaveCard(std::shared_ptr<Card> otherCard) override;
		virtual ~Food() override = default;
	};
}
#endif