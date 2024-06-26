#ifndef ANIMALPEN_HPP
#define ANIMALPEN_HPP
#include "pch.hpp"
#include "Card/Card.hpp"
namespace card {
	class AnimalPen :public Card {
	private:
		int m_MaxAnimalCount = 5;
	public:
		AnimalPen(Type type, std::string name, unsigned int id, const std::vector<std::shared_ptr<Util::SFX>> sfxs, const std::shared_ptr<Util::Image> image, const bool iconcolor);
		virtual ~AnimalPen() override = default;
		virtual bool CanHaveCard(std::shared_ptr<Card> otherCard) override;
	};
}
#endif