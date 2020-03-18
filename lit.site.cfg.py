config.llvm_src_root = "C:/src/llvm-project/llvm"
config.obj_root = "C:/src/compiler-tests/out"

config.cxx_compiler = "C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.23.28105/bin/HostX64/x64/cl.exe"

# Let the main config do the real work.
lit_config.load_config(config, "C:/src/compiler-tests/lit.cfg.py")
