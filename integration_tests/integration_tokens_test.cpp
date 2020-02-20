//
// Created by Yohan on 2/10/2020.
//

#include "gtest/gtest.h"
#include "../header/andToken.h"
#include "../header/orToken.h"
#include "../header/quitToken.h"
#include "../header/nextToken.h"
#include "../header/testingToken.h"
#include "../header/base.h"


int main(int argc, char **argv) {
    base* anything = new testToken("this");
    base* justthing = new testToken("that");
    nextToken* orTokens = new nextToken;
    orTokens->setLeft(anything);
    orTokens->setRight(justthing);
    orTokens->execute();
    quitToken* quit = new quitToken;
//    quit->execute();
}
