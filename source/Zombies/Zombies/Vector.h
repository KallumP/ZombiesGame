#pragma once
class Vector {

public:
	
	Vector();

	float GetX();
	float GetY();

	void SetX(float);
	void SetY(float);

	void Add(Vector*);

	void Multiply(Vector*);
	void Multiply(float);

	void Constrain(Vector*, Vector*);
	void Constrain(float, float);


private:

	float x;
	float y;

};

