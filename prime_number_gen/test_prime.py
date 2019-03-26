import prime_module
import py_prime_number_gen

import time

count = 10000000 #10k


# print prime_module.primeNumbers(count, True)



# cpp_nonsoe_time = time.time()
# print len(prime_module.primeNumbers(count, False))
# cpp_nonsoe_time = time.time() - cpp_nonsoe_time
# print 'cpp_nonsoe_time:', cpp_nonsoe_time 

cpp_soe_time = time.time()
print len(prime_module.primeNumbers(count, True))
cpp_soe_time = time.time() - cpp_soe_time
print 'cpp_soe_time:', cpp_soe_time 

# cpp_time = time.time()
# print 'cpp_prime count:', len(prime_module.primeNumbers(count))
# cpp_time = time.time() - cpp_time

# py_time = time.time()
# print 'py_prime:', py_prime_number_gen.primeNumbers(count)
# py_time = time.time() - py_time

# print 'cpp_time:', cpp_time 
# print 'py_time', py_time

# # Python
# # py_time: 0.367391109467 @ 1k
# # py_time: 40.2843279839 @ 10k

# # Original
# # cpp_time: 0.281508922577 @ 10k
# # cpp_time: 27.2384781837 @ 100k

# # Fast
# # cpp_time: 0.0302560329437 @ 10k (count: 1229)
# # cpp_time: 2.45500612259 @ 100k (count: 9592)
# # cpp_time: 201.495270014 @ 1mil (count: 78498)


# # Soe
# # cpp_soe_time: 0.000253915786743 @ 10k (count: 1229)
# # cpp_soe_time: 0.00199508666992 @ 100k (count: 9592)
# # cpp_soe_time: 0.0249371528625 @ 1mil (count: 78498)
# # cpp_soe_time: 0.347447872162 @ 10mil (count: 664579)
# # cpp_soe_time: 4.33931589127 @ 100mil (count: 5761455)
# # cpp_soe_time: 58.1283240318 @ 1bil (count: 50847534)
# # cpp_soe_time: OverflowError: @ 10bil (count: -)
