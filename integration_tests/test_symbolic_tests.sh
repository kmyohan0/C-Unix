#!/bin/bash

[ -e bin ] >> test_symbolic_test_outputs
[ -d bin ] >> test_symbolic_test_outputs
[ -f bin ] >> test_symbolic_test_outputs
[-e bin] >> test_symbolic_test_outputs
([ -e bin ]) >> test_symbolic_test_outputs
([ -e bin] && echo hello) || echo notWorking  >> test_symbolic_test_outputs
([ -f bin] && echo hello) || echo notWorking  >> test_symbolic_test_outputs
([ -e bin ] && echo hello) || (echo this && echo should_not_print) >> test_symbolic_test_outputs
