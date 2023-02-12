#pragma once
class BaseDataControl
{
public:

	virtual ~BaseDataControl() = default;
 
	virtual void Edit() = 0;

	virtual void Add() = 0;

	virtual void Sub() = 0;
};

