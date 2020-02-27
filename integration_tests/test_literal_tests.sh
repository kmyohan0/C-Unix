#!/bin/bash

test -e bin >> test_symbolic_test_outputs
test -d bin >> test_symbolic_test_outputs
test -f bin >> test_symbolic_test_outputs
test -e bin >> test_symbolic_test_outputs
(test -e bin ) >> test_symbolic_test_outputs
(test -e bin && echo hello) || echo notWorking  >> test_symbolic_test_outputs
(test -f bin && echo hello) || echo notWorking  >> test_symbolic_test_outputs
(test -e bin && echo hello) || (echo this && echo should_not_print) >> test_symbolic_test_outputs