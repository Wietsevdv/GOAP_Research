#pragma once
#include "Consequences.h"
#include <vector>

//Action will be a baseClass. Inherited classes will define behaviour
class Action
{
public:
	~Action() = default;

	Action(Action&& other) = delete;
	Action(const Action& other) = delete;
	Action operator=(Action&& other) = delete;
	Action operator=(const Action&& other) = delete;

	static bool Perform() {}; //static functions can be called with no need for an instance of the class (no this pointer)

private:
	Action() {};	//private constructor -> disallow constructor to be called -> no instance of Action can be created

	std::vector<Consequence> m_PreConditions;	//possibly this/these should be a map with key == consequence and value == data		(or will Purpose handle that?)
	std::vector<Consequence> m_Consequences;
};