#include "Person.h"

#include <iostream>
#include <string>

namespace lab3 {

namespace {

// Сравнение побайтовое, поэтому подходит и для строк в UTF-8
bool EndsWith(const std::string& text, const std::string& suffix) {
	if (text.size() < suffix.size()) {
		return false;
	}
	return text.compare(text.size() - suffix.size(), suffix.size(),
			suffix) == 0;
}

// Заменяет все вхождения from на to
void ReplaceAll(std::string& text, const std::string& from,
		const std::string& to) {
	std::string::size_type pos = 0;
	while ((pos = text.find(from, pos)) != std::string::npos) {
		text.replace(pos, from.size(), to);
		pos += to.size();
	}
}

// Строит отчество из имени отца
// Иван - Иванович, Сергей - Сергеевич, Пётр - Петрович, Лев - Львович
std::string MakePatronymic(const std::string& father_name) {
	if (father_name == "Лев") {
		return "Львович";
	}
	std::string base = father_name;
	ReplaceAll(base, "ё", "е");
	if (EndsWith(base, "й")) {
		base.erase(base.size() - 2);
		return base + "евич";
	}
	return base + "ович";
}

}  // namespace

// Остальные конструкторы только передают данные основному конструктору
Person::Person(const std::string& first_name, int height)
		: Person(Name(first_name), height, nullptr) {}

Person::Person(const Name& name, int height)
		: Person(name, height, nullptr) {}

Person::Person(const std::string& first_name, int height,
		const Person* father)
		: Person(Name(first_name), height, father) {}

// Единственный конструктор, в котором выполняется присваивание
Person::Person(const Name& name, int height, const Person* father) {
	name_ = name;
	height_ = height;
	father_ = father;
}

void Person::set_father(const Person* father) {
	father_ = father;
}

// Полное имя вычисляется при каждом обращении, поэтому отец, заданный после
// создания объекта, тоже учитывается
Name Person::FullName() const {
	Name result = name_;
	if (father_ == nullptr) {
		return result;
	}
	const Name father_name = father_->FullName();
	if (result.last_name().empty()) {
		result.set_last_name(father_name.last_name());
	}
	if (result.patronymic().empty() && !father_name.first_name().empty()) {
		result.set_patronymic(MakePatronymic(father_name.first_name()));
	}
	return result;
}

std::string Person::ToString() const {
	return FullName().ToString() + ", " + std::to_string(height_);
}

void Person::Print() const {
	std::cout << ToString() << "\n";
}

}  // namespace lab3
