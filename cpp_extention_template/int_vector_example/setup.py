from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("func_module", ["cpp_extention.cpp"])

setup(name = "func_module", ext_modules=[extension_mod])