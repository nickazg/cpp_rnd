from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("prime_module", ["cpp_prime_number_gen.cpp"])

setup(name = "prime_module", ext_modules=[extension_mod])