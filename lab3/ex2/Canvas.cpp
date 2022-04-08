#include "Canvas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Canvas::Canvas(int width, int height) {
	this->height = height;
	this->width = width;
	this->matrix = (char**)(malloc(height * sizeof(char*)));
	if (this->matrix != nullptr)
	{
		for (int i = 0; i < height; i++) {
			this->matrix[i] = (char*)(malloc(width * sizeof(char)));
			if (this->matrix[i] != nullptr)
			{
				memset(this->matrix[i], ' ', width * sizeof(char));
			}
		}
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int ii;
	int jj;
	int sum;
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++) {
			ii = i - x;
			ii = ii * ii;
			jj = j - y;
			jj = jj * jj;
			sum = ii * ii + jj * jj;
			if (sum >= ray * (ray - 1) && sum <= ray * (ray + 1))
				this->matrix[i][j] = ch;
		}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	int ii;
	int jj;
	int sum;
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++) {
			ii = i - x;
			ii = ii * ii;
			jj = j - y;
			jj = jj * jj;
			sum = ii * ii + jj * jj;
			if (sum <= ray * ray)
				this->matrix[i][j] = ch;
		}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	if (left < 0 || left >= this->width)
		return;
	if (right < 0 || right >= this->width)
		return;
	if (top < 0 || top >= this->height)
		return;
	if (bottom < 0 || bottom >= this->height)
		return;

	for (int i = left; i <= right; i++)
		this->matrix[i][top] = this->matrix[i][bottom] = ch;
	for (int i = top; i < bottom; i++)
		this->matrix[left][i] = this->matrix[right][i] = ch;

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	if (left < 0 || left >= this->width)
		return;
	if (right < 0 || right >= this->width)
		return;
	if (top < 0 || top >= this->height)
		return;
	if (bottom < 0 || bottom >= this->height)
		return;

	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			this->matrix[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch) {
	if (x < 0 || x >= this->height)
		return;
	if (y < 0 || y >= this->width)
		return;
	this->matrix[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int err = dx + dy;
	while (true) {
		this->matrix[x1][y1] = ch;
		if (x1 == x2 && y1 == y2)break;
		int e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y1 += sy;
		}
	}
}
void Canvas::Print() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++)
			printf("%c", this->matrix[i][j]);
		printf("\n");

	}
}
void Canvas::Clear() { // clears the canvas
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			this->matrix[i][j] = ' ';
}