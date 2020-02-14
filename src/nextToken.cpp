#include "../header/nextToken.h"
#include <string>

nextToken::nextToken()
{
        left = nullptr;
        right = nullptr;
}

void nextToken::setLeft(base* left)
{
        this->left = left;
}

void nextToken::setRight(base* right)
{
        this->right = right;
}

bool nextToken::execute()
{
	if(left == nullptr && right == nullptr)
	{	
		return false;
	}
	if (left != nullptr)
	{
		left->execute();
		if (right != nullptr)
		{
			right->execute();
			return true;
		}
		return true;
	}
	return false;
}

