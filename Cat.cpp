#include "Cat.h"

#include <iostream>
#include <string>

namespace lab3 {

Cat::Cat(const std::string& name)
		: name_(name) {}

std::string Cat::ToString() const {
	return "кот: " + name_;
}

void Cat::Print() const {
	std::cout << ToString() << "\n";
}

// Одно мяуканье выводится так же, как мяуканье N раз при N = 1
void Cat::Meow() const {
	Meow(1);
}

// мяу повторяется times раз через дефис
void Cat::Meow(int times) const {
	if (times < 1) {
		std::cout << name_ << ": молчит\n";
		return;
	}
	std::string sound = "";
	for (int i = 0; i < times; ++i) {
		if (i > 0) {
			sound += "-";
		}
		sound += "мяу";
	}
	std::cout << name_ << ": " << sound << "!\n";
}

}  // namespace lab3
