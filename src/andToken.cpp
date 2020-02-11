
#include "../header/andToken.h"
#include <string>

andToken::andToken()
{
	left = NULL;
	right = NULL;
}

void andToken::setLeft(base* left)
{
	this->left = left;
}

void andToken::setRight(base* right)
{
	this->right = right;
}

bool andToken::execute()
{	
	if (left != NULL)
	{
		if (!(left->execute()))
		{
			return false;
		}
	}
	if (right != NULL)
	{
		if(!(right->execute()))
		{
			return false;
		}
		return true;
	}
	return false;
}


