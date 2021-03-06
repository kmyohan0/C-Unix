
#include "../header/orToken.h"
#include <string>

orToken::orToken()
{
	left = NULL;
	right = NULL;
}

void orToken::setLeft(base* left)
{
	this->left = left;
}

void orToken::setRight(base* right)
{
	this->right = right;
}

bool orToken::execute()
{
	if (left != NULL) {
	    if (left->execute()) {
	        return true;
	    }
	    else {
            if (right != NULL) {
                if (right->execute()) {
                    return true;
                }
                else {
                    return false;
                }
            }
	        return false;
	    }
	    return false;
	}
	else {
        if (right != NULL) {
            if (right->execute()) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

