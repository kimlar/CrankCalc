#include "Calculator.h"

#include <cmath>

void Calculator::Add(float number)
{
	if(mathOp != MathOp::Equ)
		this->number = number;
	Execute();
	mathOp = MathOp::Add;
}

void Calculator::Sub(float number)
{
	if (mathOp != MathOp::Equ)
		this->number = number;
	Execute();
	mathOp = MathOp::Sub;
}

void Calculator::Mul(float number)
{
	if (mathOp != MathOp::Equ)
		this->number = number;
	Execute();
	mathOp = MathOp::Mul;
}

void Calculator::Div(float number)
{
	if (mathOp != MathOp::Equ)
		this->number = number;
	Execute();
	mathOp = MathOp::Div;
}

void Calculator::Equ(float number)
{
	this->number = number;
	Execute();
	mathOp = MathOp::Equ;
}

void Calculator::Sqr(float number)
{
	this->number = number;
	mathOp = MathOp::Sqr;
	Execute();
	mathOp = MathOp::Equ; // reset
}

void Calculator::Execute()
{
	switch (mathOp)
	{
	case MathOp::Add:
		sum += number;
		break;
	case MathOp::Sub:
		sum -= number;
		break;
	case MathOp::Mul:
		sum *= number;
		break;
	case MathOp::Div:
		sum /= number; // Returns "inf" if divided by zero
		break;
	case MathOp::Sqr:
		sum = sqrt(number);
		break;
	}
}

void Calculator::ClearAC()
{
	mathOp = MathOp::Add;
	sum = 0.0f;
	number = 0.0f;
}

float Calculator::GetSum()
{
	return sum;
}
