#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>

int Math::Add(int x1, int x2)
{
	return int(x1 + x2);
}
int Math::Add(int x1, int x2, int x3)
{
	return int(x1 + x2 + x3);
}
int Math::Add(double x1, double x2)
{
	return int(x1 + x2);
}
int Math::Add(double x1, double x2, double x3)
{
	return int(x1 + x2 + x3);
}
int Math::Mul(int x1, int x2)
{
	return int(x1 * x2);
}
int Math::Mul(int x1, int x2, int x3)
{
	return int(x1 * x2 * x3);
}
int Math::Mul(double x1, double x2)
{
	return int(x1 * x2);
}
int Math::Mul(double x1, double x2, double x3)
{
	return int(x1 * x2 * x3);
}
int Math::Add(int count, ...)
{
	int s = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
		s = s + va_arg(vl, int);
	va_end(vl);
	return s;
}
char* Math::Add(const char* sir1, const char* sir2)
{
	if (sir1 == nullptr || sir2 == nullptr)
		return nullptr;
	int sir1_len = strlen(sir1);
	int sir2_len = strlen(sir2);
	int SpaceToAlloc = sir1_len + sir2_len + 1;
	char* sir = (char*)malloc(SpaceToAlloc * sizeof(char));
	memset(sir, 0, SpaceToAlloc);
	strcpy_s(sir, SpaceToAlloc, sir1);
	strcpy_s(sir + sir1_len, SpaceToAlloc, sir2);
	return sir;
}