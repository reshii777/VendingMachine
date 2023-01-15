// .h �������� ����������� ������� � �������.

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Snack									// ����� ����
{
public:
	Snack(const string& name);
	Snack(const string&, int price);
	Snack(const string&, int price, int calories);
	~Snack() = default;

	string getNameSnack() const;
	void setNameSnack(string& name);	// �������

	short getCostSnack() const;
	void setCostSnack(short value);			

	int getCaloriesSnack() const;
	void setCaloriesSnack(int value);		

private:
	string NameSnack;						// ��������
	int PriceSnack;							// ���������
	int CaloriesSnack;						// �������
};

//---//
class SnackSlot								// ����� �����(����) ��� ������
{
public:
	SnackSlot(short amt);
	~SnackSlot();

	short getAmt() const;
	short getSnackCount() const;			

	void giveSnack();						
	void addSnack(Snack* snack);			
private:
	short Amt;								
	short SnackCount;						
	Snack** Snacks;							
};

//---//
class  VendingMachine						// ����� �������
{
public:
	VendingMachine(int slotCount);
	~VendingMachine();

	int getSize() const;
	int getEmptySlotsCount() const;
	int getSnacksCount() const;

	void addSlot(SnackSlot* slot);			// ������� ���������� ���������
	void giveSnack();						// ������� ������ ��������
private:
	int Size;								// ������
	int SnackCount;							// ���������� �����
	int AllSlots;							// ��� �����
	int FreeSlots;							// ��������� ����
	SnackSlot** slots;
};
