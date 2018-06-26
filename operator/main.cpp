#include "myList.h"

int main() {
	cList	list;
	cPerson one("WANG", 27, 'W');
	list += one;
	one = cPerson("DING", 38, 'M');
	list += one;
	one = cPerson("ZHANG", 33, 'M');
	list += one;
	PNODE find = list["ZHANG"];
	if (find)
		find->GetData().Show();
	else
		cout << "没有找到！" << endl;
	find = list["LI"];
	if (find)
		find->GetData().Show();
	else
		cout << "没有找到！" << endl;
	list.SetCurToHead();
	list.ShowCurData();
	while (list++)
		list.ShowCurData();
	return 0;
}
