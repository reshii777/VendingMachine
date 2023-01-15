// .cpp реализация класса

#include <iostream>
#include <string>
#include "Header_Vending.h"
using namespace std;

//---//Snack
Snack::Snack(const string& name)
{
	NameSnack = name;
	PriceSnack = 0;
	CaloriesSnack = 0;
}

Snack::Snack(const string& name, int price)
{
	NameSnack = name;
	PriceSnack = price;
	CaloriesSnack = 0;
}

Snack::Snack(const string& name, int price, int calories)
{
	NameSnack = name;
	PriceSnack = price;
	CaloriesSnack = calories;
}

string Snack::getNameSnack() const
{
	return NameSnack;
}
void Snack::setNameSnack(string& name)
{
	NameSnack = name;
}

short Snack::getCostSnack() const
{
	return PriceSnack;
}
void Snack::setCostSnack(short value)
{
	PriceSnack = value;
}

int Snack::getCaloriesSnack() const
{
	return CaloriesSnack;
}
void Snack::setCaloriesSnack(int value)
{
	CaloriesSnack = value;
}


//---//SnackSlot
SnackSlot::SnackSlot(short amt)
{
	Amt = amt;
	SnackCount = 0;
	Snacks = new Snack * [Amt];
}

SnackSlot::~SnackSlot()
{
	delete[] Snacks;
}

short SnackSlot::getAmt() const
{
	return Amt;
}

short SnackSlot::getSnackCount() const
{
	return SnackCount;
}

void SnackSlot::addSnack(Snack* snack)
{
	if (SnackCount < Amt)
	{
		Snacks[SnackCount] = snack;
		++SnackCount;
		cout << snack->getNameSnack() << " добавлен в слот" << endl;
	}
}

void SnackSlot::giveSnack()
{
	if (SnackCount > 0)
	{
		--SnackCount;
		cout << Snacks[SnackCount]->getNameSnack() << " выдан" << endl;
	}
}



//---//VendingMachine
VendingMachine::VendingMachine(int size)
{
	Size = size;
	AllSlots = 0;
	FreeSlots = Size;
	SnackCount = 0;
	slots = new SnackSlot * [size];
}

VendingMachine::~VendingMachine()
{
	delete[] slots;
}

int VendingMachine::getSize() const
{
	return Size;
}

int VendingMachine::getEmptySlotsCount() const
{
	return FreeSlots;
}

int VendingMachine::getSnacksCount() const
{
	return SnackCount;
}

void VendingMachine::addSlot(SnackSlot* slot)
{
	slots[AllSlots] = slot;
	for (Size; Size != 0; Size--)
		--FreeSlots;
	++AllSlots;
	SnackCount += slot->getSnackCount();
}

void VendingMachine::giveSnack()
{
	--SnackCount;
	slots[AllSlots - 1]->giveSnack();
	++FreeSlots;
}
