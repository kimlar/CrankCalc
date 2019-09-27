#include "Form1.h"

void Form1::Load()
{
	float posX = 10.0f;
	float posY = 10.0f;
	float buttonSize = 25.0f;
	float buttonSpacing = 5.0f;
	float buttonGrid = buttonSize + buttonSpacing;

	// Setup the form window
	SetFormTitle("Calculator");

	// TODO: Reform this into the library instead
	// Setup the icon	
	sf::Image iconImg;
	iconImg.loadFromFile("Resources/CrankCalc.png");
	sharedContext.GetRenderWindow().setIcon(iconImg.getSize().x, iconImg.getSize().y, iconImg.getPixelsPtr());

	// Add controls to the application form
	AddControl(GuiControlType::EditBox, "Answer", sf::Vector2f(posX + 0 * buttonGrid, posY + 0 * buttonGrid + 5.0f));
	AddControl(GuiControlType::Button, "Digit7", sf::Vector2f(posX + 0 * buttonGrid, posY + 1 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit8", sf::Vector2f(posX + 1 * buttonGrid, posY + 1 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit9", sf::Vector2f(posX + 2 * buttonGrid, posY + 1 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit4", sf::Vector2f(posX + 0 * buttonGrid, posY + 2 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit5", sf::Vector2f(posX + 1 * buttonGrid, posY + 2 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit6", sf::Vector2f(posX + 2 * buttonGrid, posY + 2 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit1", sf::Vector2f(posX + 0 * buttonGrid, posY + 3 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit2", sf::Vector2f(posX + 1 * buttonGrid, posY + 3 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit3", sf::Vector2f(posX + 2 * buttonGrid, posY + 3 * buttonGrid));
	AddControl(GuiControlType::Button, "Digit0", sf::Vector2f(posX + 0 * buttonGrid, posY + 4 * buttonGrid));
	AddControl(GuiControlType::Button, "Dot", sf::Vector2f(posX + 2 * buttonGrid, posY + 4 * buttonGrid));
	AddControl(GuiControlType::Button, "Div", sf::Vector2f(posX + 3 * buttonGrid, posY + 1 * buttonGrid));
	AddControl(GuiControlType::Button, "Mul", sf::Vector2f(posX + 3 * buttonGrid, posY + 2 * buttonGrid));
	AddControl(GuiControlType::Button, "Sub", sf::Vector2f(posX + 3 * buttonGrid, posY + 3 * buttonGrid));
	AddControl(GuiControlType::Button, "Add", sf::Vector2f(posX + 3 * buttonGrid, posY + 4 * buttonGrid));
	AddControl(GuiControlType::Button, "Sqr", sf::Vector2f(posX + 4 * buttonGrid, posY + 1 * buttonGrid));
	AddControl(GuiControlType::Button, "Prc", sf::Vector2f(posX + 4 * buttonGrid, posY + 2 * buttonGrid));
	AddControl(GuiControlType::Button, "Equ", sf::Vector2f(posX + 4 * buttonGrid, posY + 3 * buttonGrid));
	AddControl(GuiControlType::Button, "Clr", sf::Vector2f(posX + 5 * buttonGrid, posY + 1 * buttonGrid));

	// TEMP STUFF!!!!! -- TODO: Move into library
	NextFocus();
	SetFocus(curFocus);

	// Set properties
	SetProperty("Answer", GuiProperty::Text, "0");
	SetProperty("Answer", GuiProperty::Size, sf::Vector2f((buttonSize + buttonSpacing) * 6 - buttonSpacing, buttonSize - 5.0f));
	SetProperty("Digit7", GuiProperty::Text, "7");
	SetProperty("Digit7", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit8", GuiProperty::Text, "8");
	SetProperty("Digit8", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit9", GuiProperty::Text, "9");
	SetProperty("Digit9", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit4", GuiProperty::Text, "4");
	SetProperty("Digit4", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit5", GuiProperty::Text, "5");
	SetProperty("Digit5", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit6", GuiProperty::Text, "6");
	SetProperty("Digit6", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit1", GuiProperty::Text, "1");
	SetProperty("Digit1", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit2", GuiProperty::Text, "2");
	SetProperty("Digit2", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit3", GuiProperty::Text, "3");
	SetProperty("Digit3", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Digit0", GuiProperty::Text, "0");
	SetProperty("Digit0", GuiProperty::Size, sf::Vector2f(buttonSize + buttonGrid, buttonSize));
	SetProperty("Dot", GuiProperty::Text, ".");
	SetProperty("Dot", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Div", GuiProperty::Text, "/");
	SetProperty("Div", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Mul", GuiProperty::Text, "*");
	SetProperty("Mul", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Sub", GuiProperty::Text, "-");
	SetProperty("Sub", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Add", GuiProperty::Text, "+");
	SetProperty("Add", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Sqr", GuiProperty::Text, "Sqr");
	SetProperty("Sqr", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Prc", GuiProperty::Text, "%");
	SetProperty("Prc", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));
	SetProperty("Equ", GuiProperty::Text, "=");
	SetProperty("Equ", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize + buttonGrid));
	SetProperty("Clr", GuiProperty::Text, "AC");
	SetProperty("Clr", GuiProperty::Size, sf::Vector2f(buttonSize, buttonSize));	
}

void Form1::UpdateControls(GuiEvent guiEvent)
{
	for (int i = 0; i < 10; i++)
	{
		if (CheckForControlEvent(guiEvent, "Digit"+ std::to_string(i), GuiEvent::GuiEventType::OnMouseLeftClick))
		{
			AddDigit(std::to_string(i));
			break;
		}
	}

	if (CheckForControlEvent(guiEvent, "Clr", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		opCalled = false;
		calculator.ClearAC();
		SetProperty("Answer", GuiProperty::Text, "0");
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Dot", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		EditBox* editBox = CastControlToEditBox("Answer");
		if (editBox != nullptr)
		{
			std::string temp = editBox->GetText();
			if (temp.size() == 0)
				return;
			if(temp.find('.') != std::string::npos)
				return;
			editBox->SetText(editBox->GetText() + ".");
		}
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Add", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Add);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Sub", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Sub);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Mul", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Mul);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Div", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Div);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Equ", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Equ);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Sqr", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		DoMathOperation(Calculator::MathOp::Sqr);
		return;
	}
	else if (CheckForControlEvent(guiEvent, "Prc", GuiEvent::GuiEventType::OnMouseLeftClick))
	{
		EditBox* editBox = CastControlToEditBox("Answer");
		if (editBox != nullptr)
		{
			float input = (float)std::atof(editBox->GetText().c_str());
			float sum = calculator.GetSum();			// TODO: Reform this into the calculator class
			float tempval = sum * (input/100.0f);		//
			editBox->SetText(std::to_string(tempval));
		}
		return;
	}
}

void Form1::AddDigit(std::string digit)
{
	EditBox* editBox = CastControlToEditBox("Answer");

	if (opCalled)
	{
		opCalled = false;
		editBox->SetText("0");
	}

	if (editBox->GetText() == "0" || editBox->GetText() == "")
		editBox->SetText(digit);
	else
		editBox->SetText(editBox->GetText() + digit);
}

void Form1::DoMathOperation(Calculator::MathOp mathOp)
{
	EditBox* editBox = CastControlToEditBox("Answer");
	if (editBox == nullptr)
		return;

	opCalled = true;
	float input = (float)std::atof(editBox->GetText().c_str());

	switch (mathOp)
	{
	case Calculator::MathOp::Add:
		calculator.Add(input);
		break;
	case Calculator::MathOp::Sub:
		calculator.Sub(input);
		break;
	case Calculator::MathOp::Mul:
		calculator.Mul(input);
		break;
	case Calculator::MathOp::Div:
		calculator.Div(input);
		break;
	case Calculator::MathOp::Equ:
		calculator.Equ(input);
		break;
	case Calculator::MathOp::Sqr:
		calculator.Sqr(input);
		break;
	}
	editBox->SetText(std::to_string(calculator.GetSum()));
}
