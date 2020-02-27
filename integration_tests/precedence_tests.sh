
#!/bin/bash

(echo a && echo b) || (echo c && echo d) >> precedence_tests_outputs
(echo this will output) >> precedence_tests_outputs
((echo this || echo b) && echo will output) >> precedence_tests_outputs
(echo b) >> precedence_tests_outputs
((echo A) && echo b) >> precedence_tests_outputs
(echo a || ls) && echo perfect precendence output >> precedence_tests_outputs
(echo this) && (echo is perfect) >> precedence_tests_outputs
