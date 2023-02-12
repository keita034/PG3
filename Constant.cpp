#include "Constant.h"
#include<random>
#include<iostream>

USERDATA::USERDATA(const std::string& name, const std::string& affiliation)
{
	this->name = name;
	this->affiliation = affiliation;
}

USERDATA::USERDATA(long id, const std::string& name, const std::string& affiliation)
{
	this->id = id;
	this->name = name;
	this->affiliation = affiliation;
}

long GetRand(long min, long max)
{
	// —”¶¬Ší
	static std::random_device rd;
	static std::default_random_engine eng(rd());

	// •ª•z¶¬Ší
	std::uniform_int_distribution<long> get_rand_uni_real(min, max);

	// —”‚ğ¶¬
	return get_rand_uni_real(eng);
}

void GetEnter()
{
	std::string insertNum;
	while (std::getchar() != '\n');
	std::getline(std::cin, insertNum);
}
