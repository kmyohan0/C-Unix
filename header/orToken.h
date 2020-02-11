
#ifndef __ORTOKEN_H__
#define __ORTOKEN_H__

#include "../header/base.h"

class orToken : public base {
	private:
		string command;
		base* left;
		base* right;

	public:
		orToken();
		void setLeft(base* left);
		void setRight(base* right);
		bool execute();
};
#endif //__ORTOKEN_H__
