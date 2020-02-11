#include "..header/nextToken.h"
#include <string>

nextToken::nextToken()
{
        left = NULL;
        right = NULL;
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
	if(left == NULL && right == NULL)
	{	
		return false;
	}
	if (left != NULL)
	{
		left->execute();
		if (right != NULL)
		{
			right->execute();
		}
		return true; 
	}
	return false;
}
		






		
}
