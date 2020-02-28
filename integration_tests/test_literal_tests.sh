#!/bin/bash

test -e bin || echo wrong >> test_symbolic_test_outputs
test -d bin || echo wrong >> test_symbolic_test_outputs
test -f bin || echo right_output >> test_symbolic_test_outputs
(test -e bin ) && echo correct >> test_symbolic_test_outputs
(test -e bin && echo hello) || echo notWorking  >> test_symbolic_test_outputs
(test -f bin && echo hello) || echo notWorking  >> test_symbolic_test_outputs
(test -e bin && echo hello) || (echo this && echo should_not_print) >> test_symbolic_test_outputs