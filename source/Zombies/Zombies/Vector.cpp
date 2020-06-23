#include "Vector.h"

Vector::Vector() {

	x = 0;
	y = 0;
}


/// <summary>
/// Adds on the input vector values
/// </summary>
/// <param name="v">The vector who's values to add</param>
void Vector::Add(Vector* v) {

	x += v->GetX();
	y += v->GetY();
}

void Vector::Multiply(Vector* v) {

	x = GetX() * v->GetX();
	y = GetY() * v->GetY();



}
void Vector::Multiply(float i) {

	x = GetX() * i;
	y = GetY() * i;
}

/// <summary>
/// Constrains the vector between two vectors
/// </summary>
/// <param name="min">minimum constraint vector<param>
/// <param name="max">maximum constraint vector</param>
void Vector::Constrain(Vector* min, Vector* max) {

	if (x > max->GetX())
		x = max->GetX();

	if (x < min->GetX())
		x = min->GetX();

	if (y > max->GetY())
		y = max->GetY();

	if (y < min->GetY())
		y = min->GetY();
}

/// <summary>
/// Constrains the vector betwen two floats
/// </summary>
/// <param name="min">the minimum value for both x and y</param>
/// <param name="max">the maximum value for both x and y</param>
void Vector::Constrain(float min, float max) {

	if (x > max)
		x = max;

	if (x < min)
		x = min;

	if (y > max)
		y = max;

	if (y < min)
		y = min;

}



//properties

float Vector::GetX() {
	return x;
}

void Vector::SetX(float _x) {
	x = _x;
}


void Vector::SetY(float _y) {
	y = _y;
}

float Vector::GetY() {
	return y;
}