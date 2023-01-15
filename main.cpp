#include <iostream>

#include "Header_Vending.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	Snack* bounty = new Snack("Bounty");																//
	Snack* snickers = new Snack("Snickers");															//
	SnackSlot* slot = new SnackSlot(10/*���������� ����������, ������� ���������� � ����*/);
	slot->addSnack(bounty);																				//��������� �������� � ����
	slot->addSnack(snickers);																			//��������� �������� � ����																			//��������� �������� � ����
	VendingMachine* machine = new VendingMachine(22/*slotCount*/ /*���������� ������ ��� ������*/);
	machine->addSlot(slot);																				// �������� ���� ������� � �������

	//cout << machine->getEmptySlotsCount();																// ������ �������� ���������� ������ ������ ��� ������
	
	cout << "���������� ������ ������ ��� ������: " << machine->getEmptySlotsCount() << endl; // ������ �������� ���������� ������ ������ ��� ������
	cout << "���������� ������ � ��������: " << machine->getSnacksCount() << endl;

	machine->giveSnack();

	cout << "���������� ������ ������ ��� ������: " << machine->getEmptySlotsCount() << endl;
	cout << "���������� ������ � ��������: " << machine->getSnacksCount() << endl;

	machine->giveSnack();

	cout << "���������� ������ ������ ��� ������: " << machine->getEmptySlotsCount() << endl;
	cout << "���������� ������ � ��������: " << machine->getSnacksCount() << endl;

	delete machine;																						// ����������� ������, ���������� ��� machine
	delete slot;																						// ����������� ������, ���������� ��� slot
	delete snickers;																					// ����������� ������, ���������� ��� snickers
	delete bounty;																						// ����������� ������, ���������� ��� bounty
}

