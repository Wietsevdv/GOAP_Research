#pragma once
#include "Action.h"
#include <unordered_map>
#include <functional>

class GOAP final
{
public:
	GOAP();
	~GOAP();

	GOAP(GOAP&& other) = delete;
	GOAP(const GOAP& other) = delete;
	GOAP operator=(GOAP&& other) = delete;
	GOAP operator=(const GOAP&& other) = delete;

private:
	std::unordered_map<Consequence, std::vector<Action*>> m_Actions; //this means a pointer is saved for each actions consequence (performance ? )
																	 //I could use a map and since its ordered, access the action through [consequence] (performance boost?)


																	//this is wrong for now. It stores Action pointers but no instance of any action will be made.
																	//every action will have a public static 'perform' function. Pointers to these functions must be stored instead

																	//std::unordered_map<Consequence, std::vector<std::function<void()>>> m_Actions;

																	// this is almost how it should be. Return type and parameters still need to be chosen
																	// 
																	//pb1: return consequence. bool& parameter to tell if a new path of action should be created or current one should be kept
};

