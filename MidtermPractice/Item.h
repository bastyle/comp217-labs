#pragma once
#include <string>

#include "ItemType.h"

class Item
{
	const ItemType m_category;
	std::string m_description{};
	std::string m_id{};
	double m_price{};
	double m_discount{};// a number in the interval [0, 1]
};

