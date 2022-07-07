// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "IntegerArray.h"
#include "ExceptionCode.h"

using namespace std;

int main()
{
	try
	{
		IntegerArray arr(10);
		cout << "initial array with 10 numbers: " << endl;
		for (int i = 0; i < arr.getLength(); i++)
		{
			arr[i] = (int)rand();
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl << endl;

		IntegerArray arr1(arr);
		cout << "array 1 creared by copying the initial array: " << endl;
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << arr1[i] << " ";
		}
		cout << endl;
		cout << "array 1 length = " << arr1.getLength() << endl << endl;

		cout << "insert number = 14 at the begin of the array: " << endl;
		arr.insertAtBegin(14);
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl << endl;

		cout << "insert number = 27 at the end of the array: " << endl;
		arr.insertAtEnd(27);
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl << endl;

		cout << "insert number = 17 before position with index = 5: " << endl;
		arr.insertBefore(5, 17);
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl << endl;

		cout << "remove element from position with index = 3: " << endl;
		arr.remove(3);
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl << endl;

		cout << "search a number with index = 6" << endl;
		cout << "index = 6, value = " << arr.searchByIndex(6) << endl << endl;

		cout << "sort the array with ascending order: " << endl;
		arr.sortAscend();
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;

		cout << "sort the array with descending order: " << endl;
		arr.sortDescend();
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;

		cout << "reallocate the array with new size of newLength = -5: " << endl;
		arr.reallocate(-5);

		cout << "erase the array: " << endl;
		arr.erase();
		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << "array length = " << arr.getLength() << endl;

	}
	catch (ExceptionCode& e)
	{
		cout << e.getCode() << endl;
 	}

	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
