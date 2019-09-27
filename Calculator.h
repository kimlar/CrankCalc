#pragma once

class Calculator
{
public:
	enum class MathOp { Add = 0, Sub, Mul, Div, Equ, Sqr };

	// Math operators
	void Add(float number);
	void Sub(float number);
	void Mul(float number);
	void Div(float number);
	void Equ(float number);
	void Sqr(float number);
	void Execute();

	// Externals
	void ClearAC();
	float GetSum();

private:
	MathOp mathOp = MathOp::Add;
	float sum = 0.0f;
	float number = 0.0f;
};
