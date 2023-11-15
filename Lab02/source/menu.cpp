#include "menu.h"

int Menu::countMenu = 0;

Menu::Menu(string _name) {
	this->name = _name;
}

Menu::Menu(string _name, vector<string> child) {
	this->name = _name;
	for (int i = 0, size = child.size();  i < size; ++i) {
		this->subMenu.push_back(new Menu(child[i]));
	}
}

void Menu::addSubMenu(Menu* subMenu) {
	this->subMenu.push_back(subMenu);
}

void Menu::createMenu() {
	Menu* root = new Menu("Main Menu");
	root->addSubMenu(new Menu("Duong thang"));
	root->addSubMenu(new Menu("Tam Giac", vector<string>{"Vuong can", "Deu"}));
	root->addSubMenu(new Menu("Tu giac", vector<string>{"Hinh chu nhat", "Hinh vuong"}));
	root->addSubMenu(new Menu("Oval", vector<string>{"Hinh tron", "Elip"}));
	root->addSubMenu(new Menu("Da giac deu", vector<string>{"Ngu giac deu", "Luc giac deu"}));
	root->addSubMenu(new Menu("Hinh khac", vector<string>{"Mui ten", "Ngoi sao"}));
	root->addSubMenu(new Menu("Dau", vector<string>{"Cong", "Tru", "Nhan", "Chia"}));
	root->addSubMenu(new Menu("To mau", vector<string>{"Xanh", "Do", "Vang"}));

	vector <pair<int, int> > subMenuIds;

	for (int i = 0, size = root->subMenu.size(); i < size; ++i) {
		Menu* subMenu = root->subMenu[i];
		if (subMenu->subMenu.size() == 0) {
			continue;
		}
		int subMenuId = glutCreateMenu(Render::shapeView);
		subMenuIds.push_back(pair<int,int>(subMenuId, i));
		for (int j = 0, size = subMenu->subMenu.size(); j < size; ++j) {
			Menu* subSubMenu = subMenu->subMenu[j];
			glutAddMenuEntry(subSubMenu->name.c_str(), (i + 1) * 10 + j);
		}
	}

	glutCreateMenu(Render::shapeView);

	for (int i = 0, size = root->subMenu.size(); i < size; ++i) {
		Menu* subMenu = root->subMenu[i];
		if (subMenu->subMenu.size() != 0) {
			continue;
		}
		glutAddMenuEntry(subMenu->name.c_str(), i + 1);
	}

	for (int i = 0, size = subMenuIds.size(); i < size; ++i) {
		int id = subMenuIds[i].first;
		int pos = subMenuIds[i].second;
		glutAddSubMenu(root->subMenu[pos]->name.c_str(), id);
	}

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}