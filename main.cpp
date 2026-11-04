#include <iostream>
#include <string>

#include "Cat.h"
#include "City.h"
#include "Input.h"
#include "Name.h"
#include "Person.h"

namespace {

// Максимальное число "мяу", которое можно запросить с клавиатуры
constexpr int kMaxMeows = 20;

void PrintTitle(const std::string& title) {
	std::cout << "\n" << title << "\n";
}

// Задание 1.3: имена с незаданными частями
void Task1() {
	PrintTitle("Задание 1.3: Имена");
	const lab3::Name cleopatra("Клеопатра");
	const lab3::Name pushkin("Александр", "Сергеевич", "Пушкин");
	const lab3::Name mayakovsky("Владимир", "Маяковский");
	cleopatra.Print();
	pushkin.Print();
	mayakovsky.Print();
}

// Задание 2.2: имя человека задаётся объектом Name, а не строкой
void Task2() {
	PrintTitle("Задание 2.2: Человек с именем");
	const lab3::Person cleopatra(lab3::Name("Клеопатра"), 152);
	const lab3::Person pushkin(
			lab3::Name("Александр", "Сергеевич", "Пушкин"), 167);
	const lab3::Person mayakovsky(lab3::Name("Владимир", "Маяковский"), 189);
	cleopatra.Print();
	pushkin.Print();
	mayakovsky.Print();
}

// Задание 2.3: отец задаётся после создания людей.
// Рост в условии не указан, значения выбраны произвольно
void Task3() {
	PrintTitle("Задание 2.3: Человек с родителем");
	lab3::Person ivan(lab3::Name("Иван", "Чудов"), 180);
	lab3::Person petr(lab3::Name("Пётр", "Чудов"), 175);
	lab3::Person boris(lab3::Name("Борис"), 170);
	petr.set_father(&ivan);
	boris.set_father(&petr);
	ivan.Print();
	petr.Print();
	boris.Print();
}

// Задание 3.3: граф городов с рисунка 2
void Task4() {
	PrintTitle("Задание 3.3: Города");
	lab3::City a("A");
	lab3::City b("B");
	lab3::City c("C");
	lab3::City d("D");
	lab3::City e("E");
	lab3::City f("F");
	a.AddPath(&f, 1);
	b.AddPath(&a, 5);
	b.AddPath(&c, 3);
	d.AddPath(&c, 4);
	d.AddPath(&a, 6);
	d.AddPath(&e, 2);
	e.AddPath(&f, 2);
	f.AddPath(&b, 1);
	f.AddPath(&e, 2);
	a.Print();
	b.Print();
	c.Print();
	d.Print();
	e.Print();
	f.Print();
}

// Задание 4.5: три способа создать имя
void Task5() {
	PrintTitle("Задание 4.5: Создаём Имена");
	const lab3::Name cleopatra("Клеопатра");
	const lab3::Name pushkin("Александр", "Сергеевич", "Пушкин");
	const lab3::Name mayakovsky("Владимир", "Маяковский");
	const lab3::Name khristofor("Христофор", "Бонифатьевич");
	cleopatra.Print();
	pushkin.Print();
	mayakovsky.Print();
	khristofor.Print();
}

// Задание 4.6: четыре способа создать человека
void Task6() {
	PrintTitle("Задание 4.6: Создаём Человека");
	const lab3::Person lev("Лев", 170);
	const lab3::Person sergei(lab3::Name("Сергей", "Пушкин"), 168, &lev);
	const lab3::Person alexander("Александр", 167, &sergei);
	lev.Print();
	sergei.Print();
	alexander.Print();
}

// Задание 5.2: кот мяукает один и три раза, затем столько, сколько
// введёт пользователь
void Task7() {
	PrintTitle("Задание 5.2: Кот мяукает");
	const lab3::Cat barsik("Барсик");
	barsik.Print();
	barsik.Meow();
	barsik.Meow(3);
	const std::string message = "Сколько раз ещё помяукать (от 1 до " +
			std::to_string(kMaxMeows) + "): ";
	const int times = input::ReadIntInRange(message, 1, kMaxMeows);
	barsik.Meow(times);
}

void PrintMenu() {
	std::cout << "\nВыберите задание\n";
	std::cout << "1: Задание 1.3 Имена\n";
	std::cout << "2: Задание 2.2 Человек с именем\n";
	std::cout << "3: Задание 2.3 Человек с родителем\n";
	std::cout << "4: Задание 3.3 Города\n";
	std::cout << "5: Задание 4.5 Создаём Имена\n";
	std::cout << "6: Задание 4.6 Создаём Человека\n";
	std::cout << "7: Задание 5.2 Кот мяукает\n";
	std::cout << "0: Выход\n";
}

}  // namespace

int main() {
	while (true) {
		PrintMenu();
		const int choice = input::ReadIntInRange("Ваш выбор: ", 0, 7);
		switch (choice) {
			case 1: {
				Task1();
				break;
			}
			case 2: {
				Task2();
				break;
			}
			case 3: {
				Task3();
				break;
			}
			case 4: {
				Task4();
				break;
			}
			case 5: {
				Task5();
				break;
			}
			case 6: {
				Task6();
				break;
			}
			case 7: {
				Task7();
				break;
			}
			default: {
				return 0;
			}
		}
	}
}
