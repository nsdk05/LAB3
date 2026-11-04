/**
 * @file Cat.h
 * @brief Объявление класса Cat (задание 5.2).
 *
 * Кот с именем, который умеет мяукать.
 */

#ifndef LAB3_CAT_H_
#define LAB3_CAT_H_

#include <string>

namespace lab3 {

/**
 * @brief Кот с именем.
 */
class Cat {
public:
	/**
	 * @brief Создаёт кота с именем.
	 *
	 * @param name Имя кота.
	 */
	explicit Cat(const std::string& name);

	/**
	 * @brief Конструктор копирования.
	 */
	Cat(const Cat& other) = default;

	/**
	 * @brief Оператор присваивания копированием.
	 */
	Cat& operator=(const Cat& other) = default;

	/**
	 * @brief Возвращает имя кота.
	 *
	 * @return Имя кота.
	 */
	const std::string& name() const { return name_; }

	/**
	 * @brief Возвращает текстовое представление.
	 *
	 * @return Строка вида "кот: Имя".
	 */
	std::string ToString() const;

	/**
	 * @brief Выводит текстовое представление на экран.
	 */
	void Print() const;

	/**
	 * @brief Мяукает один раз.
	 *
	 * Выводит строку вида "Имя: мяу!".
	 */
	void Meow() const;

	/**
	 * @brief Мяукает несколько раз.
	 *
	 * Выводит строку вида "Имя: мяу-мяу-...-мяу!".
	 *
	 * @param times Количество "мяу".
	 * @note Если times меньше 1, выводит "Имя: молчит".
	 */
	void Meow(int times) const;

private:
	std::string name_;
};

}  // namespace lab3

#endif  // LAB3_CAT_H_
