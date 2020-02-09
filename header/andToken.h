
#ifndef __ANDTOKEN_H__
#define __ANDTOKEN_H__
#include "../header/base.h"
#include <string>

class andToken : public base{

	private:
		string command;
		base* left;
		base* right;
	public:
		AndToken();
		void setLeft(base* left);
		void setRight(base* right);
		bool execute();

};







#endif __ANDTOKEN_H__
