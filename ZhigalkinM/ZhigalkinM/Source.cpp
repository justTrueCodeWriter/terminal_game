//#include <stdlib.h>
//#include <stdio.h>
////18,9
//
//int const ROWS = 100;
//int const COLS = 100;
//
//void task18() {
//	int mas[ROWS][COLS];
//	int rows, cols;
//	int element, sum = 0, product = 1;
//	printf("Найти сумму всех элементов некоторого двумерного массива и сравнить их с произведением элементов некоторой строки\n");
//	do {
//		printf("Введите количество строк "); scanf_s("%d", &rows);
//		printf("Введите количество столбцов "); scanf_s("%d", &cols);
//		if (rows < 1 or cols < 1) printf("Количество строк или столбцов не может быть меньше 1\n");
//	} while (rows < 1 or cols < 1);
//	printf("Введите элементы массива\n");
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			scanf_s("%d", &mas[i][j]);
//		}
//	}
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			sum = sum + mas[i][j];
//		}
//	}
//	int Rows=0;
//	printf("Выберите строку в которой будет выполнено произведение элементов строки для сравнения ее с суммой массива\n"); 
//	do {
//		scanf_s("%d", &Rows);
//		if (Rows < 1 or Rows > rows) printf("Введено неверное значение\n");
//	} while (Rows < 1 or Rows > rows);
//	for (int i = 0; i < rows; i++) {
//		product = product * mas[Rows-1][i];
//	}
//
//	printf("сумма = %d\n", sum);
//	printf("произведение = %d\n", product);
//	if (sum > product) printf("Сумма массива больше произведения выбранной строки\n");
//	if (product > sum) printf("Произведение выбранной строки больше суммы массива\n");
//}
//
//void task9() {
//	int mas[ROWS][COLS];
//	int rows, cols;
//	int arraymin[ROWS];
//	int max = -99999, min =999999 ;
//	printf("Дано: целочисленная матрица из n строк и m столбцов. Найти: максимум из наименьших элементов столбцов\n");
//	do {
//		printf("Введите количество строк "); scanf_s("%d", &rows);
//		printf("Введите количество столбцов "); scanf_s("%d", &cols);
//		if (rows < 1 or cols < 1) printf("Количество строк или столбцов не может быть меньше 1\n");
//	} while (rows < 1 or cols < 1);
//	printf("Введите элементы массива\n");
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			scanf_s("%d", &mas[i][j]);
//		}
//	}
//	for (int n = 1; n < rows * cols; n++) {
//		for (int i = 0; i < rows; i++) {
//			for (int j = 0; j < cols - 1; j++) {
//				if (mas[i][j] > mas[i][j + 1]) {
//					int tmp = mas[i][j];
//					mas[i][j] = mas[i][j + 1];
//					mas[i][j + 1] = tmp;
//				}
//			}
//		}
//	}
//
//	/*for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			printf("%d ", mas[i][j]);
//		}
//		printf("\n");
//	}*/
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			arraymin[i] = mas[i][0];
//		}
//	}
//
//	/*printf("Вывод минимальных элементов\n");
//	for (int i = 0; i < rows; i++) {
//		printf("%d\n", arraymin[i]);
//	}*/
//
//	for (int i = 0; i < rows; i++) {
//		if (arraymin[i] > max)
//			max = arraymin[i];
//	}
//	printf("Вывод максимального элемента из минимальных\n"); printf("%d\n", max);
//
//}
//
//int main() {
//	system("chcp 1251");
//	task9();
//}