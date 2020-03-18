# -*- Python -*-

# Configuration file for the 'lit' test runner.

import os
import sys
import re
import platform
import subprocess

import lit.util
import lit.formats

# name: The name of this test suite.
config.name = 'LLVM'

# testFormat: The test format to use to interpret tests.
config.test_format = lit.formats.ShTest()

# suffixes: A list of file extensions to treat as test files. This is overriden
# by individual lit.local.cfg files in the test subdirectories.
config.suffixes = ['.cpp', '.cxx', '.c']

config.test_source_root = os.path.dirname(__file__)

config.test_exec_root = os.path.join(config.obj_root, 'test')

config.substitutions.append(('%cxx', '"%s"' % config.cxx_compiler))
