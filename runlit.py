#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys

config_map = {}

def map_config(source_dir, site_config):
    global config_map
    source_dir = os.path.realpath(source_dir)
    source_dir = os.path.normcase(source_dir)
    site_config = os.path.normpath(site_config)
    config_map[source_dir] = site_config

# Variables configured at build time.
llvm_source_root = "C:/src/llvm-project/llvm"

# Make sure we can find the lit package.
sys.path.insert(0, os.path.join(llvm_source_root, 'utils', 'lit'))

map_config('C:/src/compiler-tests/lit.cfg.py', 'C:/src/compiler-tests/lit.site.cfg.py')

builtin_parameters = { }

builtin_parameters['config_map'] = config_map

if __name__ == '__main__':
    from lit.main import main
    main(builtin_parameters)
