
def isPrime(number):
    divisable_count = 0
    for num in range(number):
        num += 1
        prime_calc = float(number) / float(num)
        if prime_calc == int(prime_calc):
            divisable_count += 1
    
    if divisable_count == 2:
        return True
    
    return False


def primeNumbers(count_to):
    prime_count = 0
    for i in range(count_to):
        i += 1
        if isPrime(i):
            prime_count += 1
    
    print ("Prime Count: ", prime_count)


# primeNumbers(1000)
