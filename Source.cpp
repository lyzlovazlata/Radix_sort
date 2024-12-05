#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%4d ", arr[i]);
	}
}

void gen(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}
}

void radix_sort(int* arr, int n)
{
	int s, t;
	int* cnt_arr = (int*)malloc(sizeof(int) * 256);   //������-�������, � ������� ����� ����������� � �������� ������� ���������
	int* res = (int*)malloc(sizeof(int) * n);       // �������������� ������, �� �������� ����� �������������� ��������
	for (int i = 0; i < 4; i++)                // ��� �� ������ ������� �������� ������� (�� 4, �.�. ��� int)
	{
		s = 0;

		for (int j = 0; j < 256; j++)    // �������� ������-�������. �������� 256 ������������ ��������� �����.
		{
			cnt_arr[j] = 0;
		}

		for (int k = 0; k < n; k++)    // �������� ���� ���� ������� ����� � � ��������������� ������� ��������� 1
		{
			unsigned char* byte = (unsigned char*) & arr[k];
			cnt_arr[byte[i]]++;
		}

		for (int m = 0; m < 256; m++) // ��������� ������� � �������� �����, ���� ���� �������� ������ ����� (���������� ��������� �� 1)
		{
			t = cnt_arr[m];
			cnt_arr[m] = s;
			s += t;
		}

		for (int l = 0; l < n; l++) // ������� �� ���� ����� � �������������� ��� ������ ����� �� ������ �������
		{
			unsigned char* byte = (unsigned char*) & arr[l];
			res[cnt_arr[byte[i]]] = arr[l];
			cnt_arr[byte[i]]++;
		}

		for (int p = 0; p < n; p++) // � �������� ������ ��������� ��������������
		{
			arr[p] = res[p];
		}
	}
	free(cnt_arr);
	free(res);
}
