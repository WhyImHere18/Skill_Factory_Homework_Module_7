// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "IntegerArray.h"
#include "BadLength.h"
#include "BadRange.h"

const int SIZE = 10;

using namespace std;

int main()
{
	try
	{
		cout << "some random array: " << endl;
		int* array = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			array[i] = (int)rand();
			cout << array[i] << " ";
		}
		cout << endl << endl;

		IntegerArray obj (SIZE, array);

		delete[] array;

		cout << "New container 'obj' constructed based on the array above: " << endl;
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl << endl;

		IntegerArray objCopy(obj);
		cout << "Conteiner 'objCopy' created by copying the container 'obj' : " << endl;
		for (int i = 0; i < objCopy.getLength(); i++)
		{
			cout << objCopy[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << objCopy.getLength() << endl << endl;


		cout << "Insert number = -5 at the begin of the 'obj': " << endl;
		obj.insertAtBegin(-5);
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl << endl;

		
		cout << "Insert number = 27 at the end of the 'obj': " << endl;
		obj.insertAtEnd(27);
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl << endl;
		
		cout << "Insert number = 17 before position with index = 11: " << endl;
		obj.insertBefore(11, 17);
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl << endl;
		
		cout << "Remove element from position with index = -11: " << endl;
		obj.remove(-11);
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl << endl;
		
		cout << "Search a number with index = 0" << endl;
		cout << "index = 0, value = " << obj.searchByIndex(0) << endl << endl;
		
		cout << "Sort the 'obj' with ascending order: " << endl;
		obj.sortAscend();
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl << endl;

		cout << "Sort the 'obj' array with descending order: " << endl;
		obj.sortDescend();
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl << endl;
		
		cout << "Reallocate the array with new size of newLength = 5: " << endl;
		obj.reallocate(5);
		
		cout << "Erase the 'obj': " << endl;
		obj.erase();
		for (int i = 0; i < obj.getLength(); i++)
		{
			cout << obj[i] << " ";
		}
		cout << endl;
		cout << "Conteiner size = " << obj.getLength() << endl;
	}
	catch (BadLength& ex)
	{
		cout << "bad length = " << ex.getLength() << endl;
 	}
	catch (BadRange& ex)
	{
		cout << "bad index = " << ex.getIndex() << endl;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
	}
	catch (...)
	{

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
