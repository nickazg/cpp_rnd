import prime_module
import py_prime_number_gen

import time

count = 1000

cpp_time = time.time()
print 'cpp_prime:', prime_module.primeNumbers(count)
cpp_time = time.time() - cpp_time

# py_time = time.time()
# print 'py_prime:', py_prime_number_gen.primeNumbers(count)
# py_time = time.time() - py_time


print 'cpp_time', cpp_time
# print 'py_time', py_time