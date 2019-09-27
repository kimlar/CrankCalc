#pragma once

#include "GuiManager.h"
#include "GuiProperty.h"

#include "Calculator.h"

class Form1 : public GuiManager
{
public:
	Form1(SharedContext &sharedContext) : GuiManager(sharedContext) {}

	void Load();
	void UpdateControls(GuiEvent guiEvent);

	const static int width = 195;
	const static int height = 170;
	
private:
	void AddDigit(std::string digit);
	void DoMathOperation(Calculator::MathOp mathOp);

	bool opCalled = false;
	Calculator calculator;
};
