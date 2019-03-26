import prime_module
import py_prime_number_gen

import time

count = 10000 #10k

cpp_time = time.time()
print 'cpp_prime count:', len(prime_module.primeNumbers(count))
cpp_time = time.time() - cpp_time

# py_time = time.time()
# print 'py_prime:', py_prime_number_gen.primeNumbers(count)
# py_time = time.time() - py_time

print 'cpp_time:', cpp_time 
# print 'py_time', py_time

# Original
# cpp_time: 0.281508922577 @ 10k
# cpp_time: 27.2384781837 @ 100k

# Fast
# cpp_time: 0.0302560329437 @ 10k (count: 1229)
# cpp_time: 2.45500612259 @ 100k (count: 9592)
# cpp_time: 201.495270014 @ 1mil (count: 78498)
