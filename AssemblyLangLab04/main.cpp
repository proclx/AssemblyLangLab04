#include <iostream>
using namespace std;
void task1() {
	int arr = 848843586; // (0011 0010 1001 1000
	// 0101 0011 0100 0010)
	int res = 0;
	__asm 
	{
		mov cx, 8 // к≥льк≥сть проход≥в циклу
		mov eax, 1 // маска
	start_outer: // початок зовн≥шнього циклу (по словах)
		mov bx, 4 // к≥льк≥сть проход≥в внутр≥шнього циклу 
		xor di, di // обнуленн€ л≥чильника одиниць
	start_inner : // початок внутр≥шного циклу (по б≥тах)
		mov edx, arr
		and edx, eax // накладанн€ маски
		jz go_next // €кщо результат Ч 0
		inc di // €кщо результат Ч 1, зб≥льшуЇмо л≥чильник
	go_next :
		shl eax, 1 // поб≥товий зсув вл≥во на 1 б≥т
		dec bx // зменшуЇмо л≥чильник проход≥в на 1
		test bx, bx // перев≥р€Їмо умову завершенн€ циклу
		jnz start_inner// повторюЇмо цикл, €кщо результат не 0
		and di, 1 // перев≥рка на парн≥сть
		jnz end_ // €кщо непарне
		inc res // €кщо парне, зб≥льшуЇмо л≥чильник 
	end_ :
		loop start_outer // зак≥нченн€ зовн≥шнього циклу
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