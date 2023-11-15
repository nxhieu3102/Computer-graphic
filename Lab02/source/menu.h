#pragma once
#include <iostream>
#include <GL/glut.h>
#include <string>
#include <vector>
#include <map>
#include "helper.h"
using namespace std;
class Menu {
private:
	int id;
	string name;
	vector<Menu*> subMenu;
private:
	int static countMenu;
public:
	Menu(string name);
	Menu(string name, vector<string> child);
	void addSubMenu(Menu* subMenu);
	void static createMenu();
};
