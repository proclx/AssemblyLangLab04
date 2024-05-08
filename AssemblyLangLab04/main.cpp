#include <iostream>
using namespace std;
void task1() {
	int arr = 848843586; // (0011 0010 1001 1000
	// 0101 0011 0100 0010)
	int res = 0;
	__asm 
	{
		mov cx, 8 // ������� ������� �����
		mov eax, 1 // �����
	start_outer: // ������� ���������� ����� (�� ������)
		mov bx, 4 // ������� ������� ����������� ����� 
		xor di, di // ��������� ��������� �������
	start_inner : // ������� ���������� ����� (�� ����)
		mov edx, arr
		and edx, eax // ���������� �����
		jz go_next // ���� ��������� � 0
		inc di // ���� ��������� � 1, �������� ��������
	go_next :
		shl eax, 1 // �������� ���� ���� �� 1 ��
		dec bx // �������� �������� ������� �� 1
		test bx, bx // ���������� ����� ���������� �����
		jnz start_inner// ���������� ����, ���� ��������� �� 0
		and di, 1 // �������� �� �������
		jnz end_ // ���� �������
		inc res // ���� �����, �������� �������� 
	end_ :
		loop start_outer // ��������� ���������� �����
	}
	std::cout << res << std::endl;
}

int CountBytesWithoutAdjacentOnes(char* arr, int size_) 
{
	int count = 0;

	__asm 
	{
		mov ecx, 0
		mov esi, arr
		mov edx, size_

	loop_start :
		mov al, [esi]
		add esi, 1
		mov bl, al
		shr bl, 1
		and al, bl
		and al, 85
		cmp al, 0
		jz count_next
		inc ecx

	count_next :
		dec edx
		jnz loop_start
		mov count, ecx
	}

	return size_ - count;
}

int main()
{
	char arr[] = { 0b11000100, 0b01010101, 0b10001100, 0b00000111, 0, 0, 0, 0, 0, 0, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	std::cout << CountBytesWithoutAdjacentOnes(arr, size) << std::endl;
	//task1();
	system("pause");
	return 0;
}