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
//	printf("����� ����� ���� ��������� ���������� ���������� ������� � �������� �� � ������������� ��������� ��������� ������\n");
//	do {
//		printf("������� ���������� ����� "); scanf_s("%d", &rows);
//		printf("������� ���������� �������� "); scanf_s("%d", &cols);
//		if (rows < 1 or cols < 1) printf("���������� ����� ��� �������� �� ����� ���� ������ 1\n");
//	} while (rows < 1 or cols < 1);
//	printf("������� �������� �������\n");
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
//	printf("�������� ������ � ������� ����� ��������� ������������ ��������� ������ ��� ��������� �� � ������ �������\n"); 
//	do {
//		scanf_s("%d", &Rows);
//		if (Rows < 1 or Rows > rows) printf("������� �������� ��������\n");
//	} while (Rows < 1 or Rows > rows);
//	for (int i = 0; i < rows; i++) {
//		product = product * mas[Rows-1][i];
//	}
//
//	printf("����� = %d\n", sum);
//	printf("������������ = %d\n", product);
//	if (sum > product) printf("����� ������� ������ ������������ ��������� ������\n");
//	if (product > sum) printf("������������ ��������� ������ ������ ����� �������\n");
//}
//
//void task9() {
//	int mas[ROWS][COLS];
//	int rows, cols;
//	int arraymin[ROWS];
//	int max = -99999, min =999999 ;
//	printf("����: ������������� ������� �� n ����� � m ��������. �����: �������� �� ���������� ��������� ��������\n");
//	do {
//		printf("������� ���������� ����� "); scanf_s("%d", &rows);
//		printf("������� ���������� �������� "); scanf_s("%d", &cols);
//		if (rows < 1 or cols < 1) printf("���������� ����� ��� �������� �� ����� ���� ������ 1\n");
//	} while (rows < 1 or cols < 1);
//	printf("������� �������� �������\n");
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
//	/*printf("����� ����������� ���������\n");
//	for (int i = 0; i < rows; i++) {
//		printf("%d\n", arraymin[i]);
//	}*/
//
//	for (int i = 0; i < rows; i++) {
//		if (arraymin[i] > max)
//			max = arraymin[i];
//	}
//	printf("����� ������������� �������� �� �����������\n"); printf("%d\n", max);
//
//}
//
//int main() {
//	system("chcp 1251");
//	task9();
//}