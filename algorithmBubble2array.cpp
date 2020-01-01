#include <iostream>
#include <ctime>
using namespace std;

static const char alphanum[] = "12346789";
int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
	return alphanum[rand() % stringLength];
}


int main()
{
	setlocale(LC_ALL, "rus");

	const int ROW = 3;       //Строки массива
	const int COL = 4;       //Колонки массива
	int arr[ROW][COL];       //Двумерный массив
	int count_ = ROW * COL;     //для заполнения массива числами по порядку
	int temp = 0;

	srand(time(0u));     //Для генератора случайных чисел


	/*ЗАПОЛНЕНИЕ ДВУМЕРНОГО МАССИВА*/
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			//arr[i][j] = rand() % 100 + 1; //Так можно задавать random
			arr[i][j] = count_--;          //заполнение в порядке убывания
		}
	}
	/*КОНЕЦ ЗАПОЛНЕНИЯ ДВУМЕРНОГО МАССИВА*/

	/*ВЫВОД ЗНАЧЕНИЙ ДВУМЕРНОГО МАССИВА НА ЭКРАН*/
	cout << "original:\n";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout.width(5);
			cout << arr[i][j];
		}
		cout << '\n';
	}
	/*КОНЕЦ ВЫВОДА ЗНАЧЕНИЙ ДВУМЕРНОГО МАССИВА НА ЭКРАН*/


	/*СОРТИРОВКА ДВУМЕРНОГО МАССИВА*/
	cout << "\n\nsorted:\n";
	for (int m = 0; m < (ROW * COL); m++)   //сдвиги очередных элементов в правильную позицию
		/*сдвиг элемента массива в правильную позицию*/
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				/*АНАЛИЗ НА ПОСЛЕДНИЙ ЭЛЕМЕНТ МАССИВА*/
				if (i == ROW - 1 && j == COL - 1) {  //Если строка последняя и справа тупик, то ничего не делаем
					continue;
				}
				/*КОНЕЦ АНАЛИЗА НА ПОСЛЕДНЮЮ СТРОКУ*/

				if (arr[i][j] > arr[i][j + 1]) { //Если элемент не на своей позиции
					temp = arr[i][j];        //Обмен местами
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
				}
			}
		}
	/*КОНЕЦ СОРТИРОВКИ ДВУМЕРНОГО МАССИВА*/

	/*ВЫВОД ЗНАЧЕНИЙ ДВУМЕРНОГО МАССИВА НА ЭКРАН*/
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout.width(5);
			cout << arr[i][j];
		}
		cout << '\n';
	}
	/*КОНЕЦ ВЫВОДА ЗНАЧЕНИЙ ДВУМЕРНОГО МАССИВА НА ЭКРАН*/

	system("pause");
}