#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	const int ROW = 3;       
	const int COL = 4;       
	int arr[ROW][COL];       
	int count_ = ROW * COL;     
	int temp = 0;

	srand(time(0));     

	//ЗАПОЛНЕНИЕ ДВУМЕРНОГО МАССИВА
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			arr[i][j] = rand() % 10 - 5;     
		}
	}
	
	//ВЫВОД ДВУМЕРНОГО МАССИВА НА ЭКРАН
	cout << "Original array:\n";
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout.width(5);
			cout << arr[i][j];
		}
		cout << '\n';
	}

	//СОРТИРОВКА ДВУМЕРНОГО МАССИВА
	cout << "\n\nsorted:\n";
	for (int m = 0; m < (ROW * COL); m++) 
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (i == ROW - 1 && j == COL - 1) {  
					continue;
				}

				if (arr[i][j] > arr[i][j + 1]) { 
					temp = arr[i][j];        
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
				}
			}
		}

	//ВЫВОД ДВУМЕРНОГО МАССИВА НА ЭКРАН
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout.width(5);
			cout << arr[i][j];
		}
		cout << '\n';
	}

	system("pause>null");
}
