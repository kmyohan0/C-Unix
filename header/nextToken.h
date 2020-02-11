
#ifndef __NEXT_TOKEN_H__
#define __NEXT_TOKEN_H__
#include "../header/base.h"
#include <string>

class nextToken : public base{

        private:
                base* left;
                base* right;
        public:
                nextToken();
                void setLeft(base* left);
                void setRight(base* right);
                bool execute();

};

#endif //__NEXT_TOKEN_H__
