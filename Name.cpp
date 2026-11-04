#include "Name.h"

#include <iostream>
#include <string>

namespace lab3 {

Name::Name(const std::string& first_name)
		: first_name_(first_name) {}

Name::Name(const std::string& first_name, const std::string& last_name)
		: first_name_(first_name), last_name_(last_name) {}

// Порядок параметров совпадает с привычной записью Имя Отчество Фамилия
Name::Name(const std::string& first_name, const std::string& patronymic,
		const std::string& last_name)
		: first_name_(first_name),
		  last_name_(last_name),
		  patronymic_(patronymic) {}

void Name::set_last_name(const std::string& last_name) {
	last_name_ = last_name;
}

void Name::set_patronymic(const std::string& patronymic) {
	patronymic_ = patronymic;
}

// Собирает строку Фамилия Имя Отчество, пустые части пропускаются
std::string Name::ToString() const {
	const std::string parts[] = {last_name_, first_name_, patronymic_};
	std::string result = "";
	for (const std::string& part : parts) {
		if (part.empty()) {
			continue;
		}
		if (!result.empty()) {
			result += ' ';
		}
		result += part;
	}
	return result;
}

void Name::Print() const {
	std::cout << ToString() << "\n";
}

}  // namespace lab3
