// .h содержит определения классов и функций.

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Snack						// класс Снек
{
public:
	Snack(const string& name);
	Snack(const string&, int price);
	Snack(const string&, int price, int calories);
	~Snack() = default;

	string getNameSnack() const;
	void setNameSnack(string& name);		// Функция

	short getCostSnack() const;
	void setCostSnack(short value);			// Функция

	int getCaloriesSnack() const;
	void setCaloriesSnack(int value);		// Функция

private:
	string NameSnack;				// Название
	int PriceSnack;					// Стоимость
	int CaloriesSnack;				// Калории
};

//---//
class SnackSlot						// класс Лоток(Слот) для снеков
{
public:
	SnackSlot(short amt);
	~SnackSlot();

	short getAmt() const;
	short getSnackCount() const;

	void giveSnack();				// Функция
	void addSnack(Snack* snack);			// Функция
private:
	short Amt;					//
	short SnackCount;				//
	Snack** Snacks;
};

//---//
class  VendingMachine					// класс Автомат
{
public:
	VendingMachine(int slotCount);
	~VendingMachine();

	int getSize() const;
	int getEmptySlotsCount() const;
	int getSnacksCount() const;

	void addSlot(SnackSlot* slot);			// Функция Добавления батончика
	void giveSnack();				// Функция Выдачи продукта
private:
	int Size;					// Размер
	int SnackCount;					// Количество Снека
	int AllSlots;					// Все слота
	int FreeSlots;					// Свободный слот
	SnackSlot** slots;
};
