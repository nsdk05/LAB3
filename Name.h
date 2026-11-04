/**
 * @file Name.h
 * @brief Объявление класса Name (задания 1.3 и 4.5).
 *
 * Имя человека из трёх частей: фамилии, личного имени и отчества.
 */

#ifndef LAB3_NAME_H_
#define LAB3_NAME_H_

#include <string>

/**
 * @brief Классы лабораторной работы №3.
 */
namespace lab3 {

/**
 * @brief Имя человека: фамилия, личное имя и отчество.
 *
 * Любая часть может быть не задана (пустая строка), тогда она не участвует
 * в текстовом представлении.
 */
class Name {
public:
	/**
	 * @brief Создаёт пустое имя.
	 */
	Name() = default;

	/**
	 * @brief Создаёт имя только из личного имени.
	 *
	 * @param first_name Личное имя.
	 */
	explicit Name(const std::string& first_name);

	/**
	 * @brief Создаёт имя из личного имени и фамилии.
	 *
	 * @param first_name Личное имя.
	 * @param last_name Фамилия.
	 */
	Name(const std::string& first_name, const std::string& last_name);

	/**
	 * @brief Создаёт имя из личного имени, отчества и фамилии.
	 *
	 * @param first_name Личное имя.
	 * @param patronymic Отчество.
	 * @param last_name Фамилия.
	 */
	Name(const std::string& first_name, const std::string& patronymic,
			const std::string& last_name);

	/**
	 * @brief Конструктор копирования.
	 */
	Name(const Name& other) = default;

	/**
	 * @brief Оператор присваивания копированием.
	 */
	Name& operator=(const Name& other) = default;

	/**
	 * @brief Возвращает личное имя.
	 *
	 * @return Личное имя или пустая строка, если оно не задано.
	 */
	const std::string& first_name() const { return first_name_; }

	/**
	 * @brief Возвращает фамилию.
	 *
	 * @return Фамилия или пустая строка, если она не задана.
	 */
	const std::string& last_name() const { return last_name_; }

	/**
	 * @brief Возвращает отчество.
	 *
	 * @return Отчество или пустая строка, если оно не задано.
	 */
	const std::string& patronymic() const { return patronymic_; }

	/**
	 * @brief Задаёт фамилию.
	 *
	 * @param last_name Фамилия.
	 */
	void set_last_name(const std::string& last_name);

	/**
	 * @brief Задаёт отчество.
	 *
	 * @param patronymic Отчество.
	 */
	void set_patronymic(const std::string& patronymic);

	/**
	 * @brief Возвращает текстовое представление.
	 *
	 * Части идут в порядке "Фамилия Имя Отчество", незаданные пропускаются.
	 *
	 * @return Текстовое представление имени.
	 */
	std::string ToString() const;

	/**
	 * @brief Выводит текстовое представление на экран.
	 */
	void Print() const;

private:
	std::string first_name_;
	std::string last_name_;
	std::string patronymic_;
};

}  // namespace lab3

#endif  // LAB3_NAME_H_
