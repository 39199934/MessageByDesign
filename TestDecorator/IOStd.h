#pragma once
#include "IOProtocol.h"
#include <iostream>
using namespace std;
class IOStd :
	public IOProtocol
	
{
public:
	virtual QByteArray input() override;
	virtual void output() override;
	virtual void outputOrigin();
};

