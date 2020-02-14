//
// Created by Yohan on 2/13/2020.
//

#ifndef RSHELL_UNIT_TESTS_HPP
#define RSHELL_UNIT_TESTS_HPP

#include "gtest/gtest.h"
#include "../header/orToken.h"
#include "../header/andToken.h"
#include "../header/testToken.h"
#include "../header/nextToken.h"
/* testToken is like a executable token where you can set
 * them as bool of true or false to easily test component classes*/

using namespace std;
/* test for OrToken */
TEST(orTokenTest, simpleOrtest) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", true);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, failFirst) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", true);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "B");
}

TEST(orTokenTest, failSecond) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", false);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, failBoth) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", false);
    orToken* token = new orToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(orTokenTest, usingMultipleOrToken) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", true);
    testToken* C = new testToken("C", false);
    testToken* D = new testToken("D", true);
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
    testToken* A = new testToken("A",true);
    token->setLeft(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(orTokenTest, orTokenTest_onlyOneLeaf_atRight_Test) {
    orToken *token = new orToken();
    testToken *A = new testToken("A",true);
    token->setRight(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

/* Test for AndToken */

TEST(andTokenTest, simpleAndtest) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", true);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AB");
}

TEST(andTokenTest, failFirst) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", true);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(andTokenTest, failSecond) {
    testToken *A = new testToken("A", true);
    testToken *B = new testToken("B", false);
    andToken *token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(andTokenTest, failBoth) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", false);
    andToken* token = new andToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(andTokenTest, usingMultipleAndToken) {
    testToken* A = new testToken("A",true);
    testToken* B = new testToken("B", false);
    andToken* token = new andToken();
    testToken* C = new testToken("C", false);
    testToken* D = new testToken("D", true);
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
    testToken* A = new testToken("A",true);
    testToken* B = new testToken("B", true);
    andToken* token = new andToken();
    testToken* C = new testToken("C", false);
    testToken* D = new testToken("D", true);
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
    testToken* testToken1 = new testToken("A", true);
    token->setLeft(testToken1);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(andTokenTest, onlyOneLeaf_atRight_Test) {
    andToken *token = new andToken();
    testToken *testToken1 = new testToken("B", true);
    token->setRight(testToken1);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

/* Test  for nextToken */

TEST(nextTokenTest, simpleNexttest) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", true);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "AB");
}

TEST(nextTokenTest, failFirst) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", true);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "B");
}

TEST(nextTokenTest, failSecond) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", false);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(nextTokenTest, failBoth) {
    testToken* A = new testToken("A", false);
    testToken* B = new testToken("B", false);
    nextToken* token = new nextToken();
    token->setLeft(A);
    token->setRight(B);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(nextTokenTest, usingMultipleNextToken) {
    testToken* A = new testToken("A", true);
    testToken* B = new testToken("B", true);
    testToken* C = new testToken("C", false);
    testToken* D = new testToken("D", true);
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
    testToken* A = new testToken("A",true);
    token->setLeft(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "A");
}

TEST(nextTokenTest, nextTokenTest_onlyOneLeaf_atRight_Test) {
    nextToken *token = new nextToken();
    testToken *A = new testToken("A",true);
    token->setRight(A);
    testing::internal::CaptureStdout();
    token->execute();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}


#endif //RSHELL_UNIT_TESTS_HPP
