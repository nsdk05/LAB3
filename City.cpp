#include "City.h"

#include <cstddef>
#include <iostream>
#include <string>

namespace lab3 {

City::City(const std::string& name)
		: name_(name) {}

void City::AddPath(const City* destination, int cost) {
	paths_.push_back({destination, cost});
}

// Связанные города выводятся парами "название:стоимость" через запятую
std::string City::ToString() const {
	std::string result = name_ + ": [";
	for (size_t i = 0; i < paths_.size(); ++i) {
		if (i > 0) {
			result += ", ";
		}
		result += paths_[i].destination->name() + ":" +
				std::to_string(paths_[i].cost);
	}
	return result + "]";
}

void City::Print() const {
	std::cout << ToString() << "\n";
}

}  // namespace lab3
