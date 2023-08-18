#pragma once

//This is 1 huge list of all the consequences of all the actions
//To improve readability and correct usage we can use rules:

enum class Consequence
{
	//Change something			Rule: changing something starts with "Changed"		extra information will likely be shared through a void*
	ChangedLocation,			//move somewhere
	ChangedBridgeState,			//bridge is open or closed
	 
	//Obtaining something		 Rule: obtaining anything from items to points starts with 'Obtain'
	ObtainLog,
	ObtainAxe,
	ObtainMoney,
};