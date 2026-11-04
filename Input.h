/**
 * @file Input.h
 * @brief Объявления функций ввода с проверкой лабораторной работы №3.
 *
 * Содержит функции чтения строк, целых и вещественных чисел, цифр
 * и массивов с клавиатуры с повторным запросом при некорректном вводе.
 */

#ifndef LAB3_INPUT_H_
#define LAB3_INPUT_H_

#include <string>

/**
 * @brief Функции ввода с клавиатуры с проверкой корректности.
 */
namespace input {

/**
 * @name Ввод с проверкой
 * @{
 */

/**
 * @brief Выводит приглашение и считывает строку целиком.
 *
 * @param message Приглашение к вводу.
 * @return Введённая строка.
 * @note Если поток ввода закрыт, завершает программу.
 */
std::string ReadLine(const std::string& message);

/**
 * @brief Запрашивает целое число, пока ввод не будет корректным.
 *
 * @param message Приглашение к вводу.
 * @return Введённое число.
 */
int ReadInt(const std::string& message);

/**
 * @brief Запрашивает вещественное число, пока ввод не будет корректным.
 *
 * @param message Приглашение к вводу.
 * @return Введённое число.
 */
double ReadDouble(const std::string& message);

/**
 * @brief Запрашивает один символ-цифру от '0' до '9'.
 *
 * @param message Приглашение к вводу.
 * @return Введённый символ.
 */
char ReadCharToNum(const std::string& message);

/**
 * @brief Запрашивает целое число из отрезка [min_value, max_value].
 *
 * @param message Приглашение к вводу.
 * @param min_value Нижняя граница.
 * @param max_value Верхняя граница.
 * @return Введённое число.
 */
int ReadIntInRange(const std::string& message, int min_value, int max_value);

/**
 * @brief Заполняет массив значениями с клавиатуры.
 *
 * Каждый элемент запрашивается с проверкой через ReadInt.
 *
 * @param arr Заполняемый массив.
 * @param size Количество элементов.
 * @param name Название массива, показывается в приглашении.
 * @pre В массиве arr не меньше size элементов.
 */
void ReadArr(int* arr, int size, const std::string& name);
/** @} */

}  // namespace input

#endif  // LAB3_INPUT_H_
