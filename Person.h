/**
 * @file Person.h
 * @brief Объявление класса Person (задания 2.2, 2.3 и 4.6).
 *
 * Человек с именем, ростом и, при необходимости, отцом.
 */

#ifndef LAB3_PERSON_H_
#define LAB3_PERSON_H_

#include <string>

#include "Name.h"

namespace lab3 {

/**
 * @brief Человек: имя, рост и отец.
 *
 * Если у человека не задана фамилия или отчество, а отец указан, то
 * в полном имени фамилия берётся у отца, а отчество строится из имени отца.
 *
 * @warning Отец хранится по указателю, поэтому объект отца должен
 * существовать, пока существует объект человека.
 */
class Person {
public:
	/**
	 * @brief Создаёт человека по личному имени и росту.
	 *
	 * @param first_name Личное имя, фамилия и отчество не задаются.
	 * @param height Рост.
	 */
	Person(const std::string& first_name, int height);

	/**
	 * @brief Создаёт человека по имени и росту.
	 *
	 * @param name Имя.
	 * @param height Рост.
	 */
	Person(const Name& name, int height);

	/**
	 * @brief Создаёт человека по личному имени, росту и отцу.
	 *
	 * Фамилия и отчество берутся у отца.
	 *
	 * @param first_name Личное имя.
	 * @param height Рост.
	 * @param father Отец или nullptr.
	 */
	Person(const std::string& first_name, int height, const Person* father);

	/**
	 * @brief Создаёт человека по имени, росту и отцу.
	 *
	 * Незаданные в имени фамилия и отчество берутся у отца.
	 *
	 * @param name Имя.
	 * @param height Рост.
	 * @param father Отец или nullptr.
	 */
	Person(const Name& name, int height, const Person* father);

	/**
	 * @brief Конструктор копирования.
	 */
	Person(const Person& other) = default;

	/**
	 * @brief Оператор присваивания копированием.
	 */
	Person& operator=(const Person& other) = default;

	/**
	 * @brief Возвращает рост.
	 *
	 * @return Рост.
	 */
	int height() const { return height_; }

	/**
	 * @brief Возвращает отца.
	 *
	 * @return Отец или nullptr, если он не задан.
	 */
	const Person* father() const { return father_; }

	/**
	 * @brief Задаёт отца.
	 *
	 * @param father Отец или nullptr.
	 */
	void set_father(const Person* father);

	/**
	 * @brief Возвращает полное имя с учётом отца.
	 *
	 * Незаданная фамилия берётся у отца, незаданное отчество строится
	 * из имени отца.
	 *
	 * @return Полное имя.
	 */
	Name FullName() const;

	/**
	 * @brief Возвращает текстовое представление.
	 *
	 * @return Строка вида "Имя, рост".
	 */
	std::string ToString() const;

	/**
	 * @brief Выводит текстовое представление на экран.
	 */
	void Print() const;

private:
	Name name_;
	int height_ = 0;
	const Person* father_ = nullptr;
};

}  // namespace lab3

#endif  // LAB3_PERSON_H_
