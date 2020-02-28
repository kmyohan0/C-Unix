//
// Created by Yohan on 2/13/2020.
//

#ifndef RSHELL_UNIT_TESTS_HPP
#define RSHELL_UNIT_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/orToken.h"
#include "../header/andToken.h"
#include "../header/testingToken.h"
#include "../header/nextToken.h"
#include "../header/testToken.h"
#include "../header/parser.h"
/* testingToken is like a executable token where you can set
 * them as bool of true or false to easily test component classes*/

using namespace std;
/* test for OrToken */
TEST(orTokenTest, simpleOrtest) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, failFirst) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", true);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "B");
}

TEST(orTokenTest, failSecond) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", false);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, failBoth) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", false);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(orTokenTest, usingMultipleOrToken) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    testingToken* C = new testingToken("C", false);
    testingToken* D = new testingToken("D", true);
    orToken* token = new orToken();
    orToken* token2 = new orToken();
    orToken* token3 = new orToken();
    token->setLeft(A);
    token->setRight(B);
    token2->setLeft(C);
    token2->setRight(D);
    token3->setLeft(token);
    token3->setRight(token2);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, orTokenTest_noLeafs_Test) {
    orToken* token = new orToken();
    EXPECT_EQ(token->execute(), false);
}

TEST(orTokenTest, orTokenTest_onlyOneLeaf_atLeft_Test) {
    orToken* token = new orToken();
    testingToken* A = new testingToken("A", true);
    token->setLeft(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, orTokenTest_onlyOneLeaf_atRight_Test) {
    orToken *token = new orToken();
    testingToken *A = new testingToken("A", true);
    token->setRight(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

/* Test for AndToken */

TEST(andTokenTest, simpleAndtest) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AB");
}

TEST(andTokenTest, failFirst) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", true);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(andTokenTest, failSecond) {
    testingToken *A = new testingToken("A", true);
    testingToken *B = new testingToken("B", false);
    andToken *token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(andTokenTest, failBoth) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", false);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(andTokenTest, usingMultipleAndToken) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", false);
    andToken* token = new andToken();
    testingToken* C = new testingToken("C", false);
    testingToken* D = new testingToken("D", true);
    andToken* token2 = new andToken();
    andToken* token3 = new andToken();
    token->setLeft(A);
    token->setRight(B);
    token2->setLeft(C);
    token2->setRight(D);
    token3->setLeft(token);
    token3->setRight(token2);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(andTokenTest, usingMultipleAndToken_second) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    andToken* token = new andToken();
    testingToken* C = new testingToken("C", false);
    testingToken* D = new testingToken("D", true);
    andToken* token2 = new andToken();
    andToken* token3 = new andToken();
    token->setLeft(A);
    token->setRight(B);
    token2->setLeft(C);
    token2->setRight(D);
    token3->setLeft(token);
    token3->setRight(token2);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AB");
}

TEST(andTokenTest, noLeafs_Test) {
    andToken* token = new andToken();
    EXPECT_EQ(token->execute(), false);
}

TEST(andTokenTest, onlyOneLeaf_atLeft_Test) {
    andToken* token = new andToken();
    testingToken* testToken1 = new testingToken("A", true);
    token->setLeft(testToken1);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(andTokenTest, onlyOneLeaf_atRight_Test) {
    andToken *token = new andToken();
    testingToken *testToken1 = new testingToken("B", true);
    token->setRight(testToken1);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

/* Test  for nextToken */

TEST(nextTokenTest, simpleNexttest) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AB");
}

TEST(nextTokenTest, failFirst) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", true);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "B");
}

TEST(nextTokenTest, failSecond) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", false);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(nextTokenTest, failBoth) {
    testingToken* A = new testingToken("A", false);
    testingToken* B = new testingToken("B", false);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(nextTokenTest, usingMultipleNextToken) {
    testingToken* A = new testingToken("A", true);
    testingToken* B = new testingToken("B", true);
    testingToken* C = new testingToken("C", false);
    testingToken* D = new testingToken("D", true);
    nextToken* token = new nextToken();
    nextToken* token2 = new nextToken();
    nextToken* token3 = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    token2->setLeft(C);
    token2->setRight(D);
    token3->setLeft(token);
    token3->setRight(token2);
    testing::internal::CaptureStdout();
    token3->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ABD");
}

TEST(nextTokenTest, nextTokenTest_noLeafs_Test) {
    nextToken* token = new nextToken();
    EXPECT_EQ(token->execute(), false);
}

TEST(nextTokenTest, nextTokenTest_onlyOneLeaf_atLeft_Test) {
    nextToken* token = new nextToken();
    testingToken* A = new testingToken("A", true);
    token->setLeft(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(nextTokenTest, nextTokenTest_onlyOneLeaf_atRight_Test) {
    nextToken *token = new nextToken();
    testingToken *A = new testingToken("A", true);
    token->setRight(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

//testToken unit_test
TEST(testTokenTest, testTokenTest_flagEtest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-e");
    commands.push_back("bin");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n");
}

TEST(testTokenTest, testTokenTest_flagDtest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-d");
    commands.push_back("bin");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n");
}

TEST(testTokenTest, testTokenTest_flagFtest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-f");
    commands.push_back("main.exe"); //---> indicating the output file from make command
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n");
}

TEST(testTokenTest, testTokenTest_invalidGeneralTest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-e");
    commands.push_back("abcd");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(False)\n");
}

TEST(testTokenTest, testTokenTest_invalidFilePathTest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-f");
    commands.push_back("abcd");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(False)\n");
}

TEST(testTokenTest, testTokenTest_invalidDirectoryPathTest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-d");
    commands.push_back("abcd");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(False)\n");
}

TEST(testTokenTest, testTokenTest_wrongFlagTest_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-d");
    commands.push_back("main.exe"); //---> indicating the output file from make command
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(False)\n");
}

TEST(testTokenTest, testTokenTest_noFilePath_Test) {
    vector<string> commands;
    commands.push_back("test");
    commands.push_back("-e");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    //from Ubuntu bash, it still returns true so we follow same rule as theirs
    EXPECT_EQ(output, "(True)\n");
}

TEST(testTokenTest, testTokenTest_symbolictest_Test) {
    vector<string> commands;
    commands.push_back("[");
    commands.push_back("-e");
    commands.push_back("bin");
    commands.push_back("]");
    testToken *token = new testToken(commands);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(True)\n");
}

//ParenthesisTest
TEST(parenthesisTest, parenthesisTest_simpleParentheis_Test) {
    parser* token = new parser;
    string parenthesis = "(echo a && echo b) || (echo c || echo d)";
    testing::internal::CaptureStdout();
    token->parseCommand(parenthesis);
    std::string output = testing::internal::GetCapturedStdout();
    //from Ubuntu bash, it still returns true so we follow same rule as theirs
    EXPECT_EQ(output, "a\nb\n");
}

TEST(parenthesisTest, parenthesisTest_doubleParentheis_Test) {
    parser* token = new parser;
    string parenthesis = "((echo a))";
    testing::internal::CaptureStdout();
    token->parseCommand(parenthesis);
    std::string output = testing::internal::GetCapturedStdout();
    //from Ubuntu bash, it still returns true so we follow same rule as theirs
    EXPECT_EQ(output, "a\n");
}

TEST(parenthesisTest, parenthesisTest_multipleParentheis_Test) {
    parser* token = new parser;
    string parenthesis = "(((((echo a)))))";
    testing::internal::CaptureStdout();
    token->parseCommand(parenthesis);
    std::string output = testing::internal::GetCapturedStdout();
    //from Ubuntu, it causes an syntax error so not sure if this is correct
    EXPECT_EQ(output, "a\n");
}
#endif //RSHELL_UNIT_TESTS_HPP
