#include <iostream>

#include "Header_Vending.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Snack* bounty = new Snack("Bounty");									//
	Snack* snickers = new Snack("Snickers");								//
	SnackSlot* slot = new SnackSlot(10/*количество батончиков, которые помещаются в слот*/);		//
	slot->addSnack(bounty);											//Добавляем батончик в слот
	slot->addSnack(snickers);										//Добавляем батончик в слот
	VendingMachine* machine = new VendingMachine(22/*slotCount*/ /*Количество слотов для снеков*/);		//
	machine->addSlot(slot);											// Помещаем слот обратно в аппарат

	//cout << machine->getEmptySlotsCount();								// Должно выводить количество пустых слотов для снеков
	
	cout << "Количество пустых слотов для снеков: " << machine->getEmptySlotsCount() << endl; 		// Должно выводить количество пустых слотов для снеков
	cout << "Количество снеков в автомате: " << machine->getSnacksCount() << endl;				

	machine->giveSnack();											

	cout << "Количество пустых слотов для снеков: " << machine->getEmptySlotsCount() << endl;		
	cout << "Количество снеков в автомате: " << machine->getSnacksCount() << endl;				

	machine->giveSnack();

	cout << "Количество пустых слотов для снеков: " << machine->getEmptySlotsCount() << endl;		
	cout << "Количество снеков в автомате: " << machine->getSnacksCount() << endl;				

	delete machine;												// Освобождаем память, выделенную для machine
	delete slot;												// Освобождаем память, выделенную для slot
	delete snickers;											// Освобождаем память, выделенную для snickers
	delete bounty;												// Освобождаем память, выделенную для bounty
}

