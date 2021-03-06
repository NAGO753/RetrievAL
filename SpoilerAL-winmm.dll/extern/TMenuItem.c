#include "TMenuItem.h"

#pragma warning(disable:4733)

extern const DWORD __InitExceptBlockLDTC;
extern const DWORD F005E0D50;
extern const DWORD F0054B87C;
extern const DWORD F005E0EA8;

__declspec(naked) HMENU __fastcall TMenuItem_GetHandle(LPCVOID MenuItem)
{
	__asm
	{
		mov     edx, 0054A0DCH
		mov     eax, ecx
		jmp     edx
	}
}

__declspec(naked) void __stdcall TMenuItem_SetCaption(LPVOID MenuItem, LPCSTR lpText)
{
	static const DWORD data1[] = {
		0x00401834,
		0x00000004, -4,
		0x00000000,
	};
	static const DWORD data2[] = {
		0x00000000, -40,
		0x00050000, 00000000,
		(DWORD)data1
	};

	__asm
	{
		push    ebp
		mov     eax, offset data2
		mov     ebp, esp
		sub     esp, 40
		call    dword ptr [__InitExceptBlockLDTC]
		mov     edx, dword ptr [ebp + 0CH]
		lea     eax, [ebp - 4H]
		call    dword ptr [F005E0D50]
		mov     edx, dword ptr [eax]
		mov     eax, dword ptr [ebp + 8H]
		call    dword ptr [F0054B87C]
		mov     edx, 2
		lea     eax, [ebp - 4H]
		call    dword ptr [F005E0EA8]
		mov     ecx, dword ptr [ebp - 40]
		mov     dword ptr fs:[0], ecx
		mov     esp, ebp
		pop     ebp
		ret     8
	}
}
