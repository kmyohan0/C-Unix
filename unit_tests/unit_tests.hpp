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
    EXPECT_EQ(output, "");
}


#endif //RSHELL_UNIT_TESTS_HPP
