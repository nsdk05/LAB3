/**
 * @file City.h
 * @brief Объявление класса City (задание 3.3).
 *
 * Город на карте с путями к другим городам.
 */

#ifndef LAB3_CITY_H_
#define LAB3_CITY_H_

#include <string>
#include <vector>

namespace lab3 {

/**
 * @brief Город: название и набор путей к другим городам.
 *
 * @warning Города назначения хранятся по указателю, поэтому они должны
 * существовать, пока существует город с путями к ним.
 */
class City {
public:
	/**
	 * @brief Путь из города в другой город.
	 */
	struct Path {
		/** @brief Город назначения. */
		const City* destination;
		/** @brief Стоимость поездки. */
		int cost;
	};

	/**
	 * @brief Создаёт город без путей.
	 *
	 * @param name Название города.
	 */
	explicit City(const std::string& name);

	/**
	 * @brief Копирование запрещено: пути других городов указывают на
	 * исходный объект.
	 */
	City(const City& other) = delete;

	/**
	 * @brief Присваивание запрещено по той же причине, что и копирование.
	 */
	City& operator=(const City& other) = delete;

	/**
	 * @brief Возвращает название города.
	 *
	 * @return Название города.
	 */
	const std::string& name() const { return name_; }

	/**
	 * @brief Возвращает пути из города.
	 *
	 * @return Набор путей.
	 */
	const std::vector<Path>& paths() const { return paths_; }

	/**
	 * @brief Добавляет путь из этого города в другой.
	 *
	 * @param destination Город назначения.
	 * @param cost Стоимость поездки.
	 * @pre destination не равен nullptr.
	 */
	void AddPath(const City* destination, int cost);

	/**
	 * @brief Возвращает текстовое представление.
	 *
	 * @return Строка вида "A: [B:5, C:3]".
	 */
	std::string ToString() const;

	/**
	 * @brief Выводит текстовое представление на экран.
	 */
	void Print() const;

private:
	std::string name_;
	std::vector<Path> paths_;
};

}  // namespace lab3

#endif  // LAB3_CITY_H_
