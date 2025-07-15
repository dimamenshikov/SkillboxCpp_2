#include<Windows.h>
#include<iostream>
#include"Shop.h"
#include"Mop.h"
#include"CoffeeGrinder.h"
#include"Conditioner.h"
#include"Dryer.h"
#include"Fridge.h"
#include"Juicer.h"
#include"MeatGrinder.h"
#include"Mixer.h"
#include"WashingMachine.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Shop* shop = new Shop();

	Instrumentation* instrumentation = new CoffeeGrinder();
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Mop();
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Conditioner;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Dryer;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Fridge;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Juicer;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new MeatGrinder;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new Mixer;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	instrumentation = new WashingMachine;
	shop->AddInstrumentation(instrumentation);
	delete instrumentation;

	shop->Launch();

	delete shop;

	return 0;
}