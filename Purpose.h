#pragma once

//Purpose will be a baseClass. Inherited classes will define behaviour
class Purpose
{
public:
	~Purpose() = default;
	Purpose(Purpose&& other) = delete;
	Purpose(const Purpose& other) = delete;
	Purpose operator=(Purpose&& other) = delete;
	Purpose operator=(const Purpose&& other) = delete;
};

class MakeMoney final : public Purpose
{
public:
	~MakeMoney() = default;
	MakeMoney(MakeMoney&& other) = delete;
	MakeMoney(const MakeMoney& other) = delete;
	MakeMoney operator=(MakeMoney&& other) = delete;
	MakeMoney operator=(const MakeMoney&& other) = delete;

private:
};