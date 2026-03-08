#include "core.h"
#include "Function.h"
#include "Operation.h"

void core(char c,int arr[][4],int *sp)
{
	switch (c)
	{
	case 'W':
	{
		Wyi(arr, 4, sp);
		appear(arr, 4);
	}break;

	case 'A':
	{
		Ayi(arr, 4, sp);
		appear(arr, 4);
	}break;
	
	case 'S':
	{
		Syi(arr, 4, sp);
		appear(arr, 4);
	}break;

	case 'D':
	{
		Dyi(arr, 4, sp);
		appear(arr, 4);
	}break;
	}
}