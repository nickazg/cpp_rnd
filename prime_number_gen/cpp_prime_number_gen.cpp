#include <iostream>
#include <stdio.h>
#include <vector>

// Python extention requirements
#include <Python.h>


bool isPrimeV2(int in_num) {
    
    // Will loop thrugh every int betweeen 1 and in_num
    for (float num = 2; num < in_num; num++){
        float prime_calc = in_num / num;
        if (prime_calc == static_cast<int>(prime_calc)){
            return false;
        } 
    }

    return true;
}

// Classic
bool isPrime(float number) {  

    int divisable_count = 0;
    for (float num = 1; num <= number; num++){
        float prime_calc = number / num;
        if (prime_calc == static_cast<int>(prime_calc)){
            divisable_count++;
        }
    }

    if (divisable_count == 2) {
        return true;
    }
    return false;
}

std::vector<int> primeNumbers(int count_to){
    std::vector<int> prime_numbers;    
    for (int i = 2; i < count_to+1; i++) {
        if (isPrimeV2(i)) {
            prime_numbers.push_back(i);
        }        
    }

    // return prime_numbers;
    return prime_numbers;
}

std::vector<int> primeNumbersSoE(int count_to){   
    // Creating a vector to initally set all numbers to prime == true
    std::vector<int> is_prime(count_to, true); 
    std::vector<int> prime_numbers;

    // Looping through all numbers
    for (int i = 2; i < count_to; i++){
        
        // If current number is still potentially a prime number
        if (is_prime[i] == true){            
            
            // find every multipule within count_to
            for (int mult = i+i; mult < count_to; mult += i){             
                is_prime[mult] = false;
            }
        }
    }

    // Adds every prime number into a new vector to finally return
    for (int num = 2; num < count_to; num++){
        if ( is_prime[num] == true ){
            prime_numbers.push_back(num);
        }
    }

    return prime_numbers;
}

std::vector<int> calcPrimeNumbers(int count_to, int soe){
    if (soe == true){
        return primeNumbersSoE(count_to);
    } else {
        return primeNumbers(count_to);
    }

}


PyObject* vectorToList_Int(const std::vector<int> &data) {
  PyObject* listObj = PyList_New( data.size() );
	if (!listObj) throw std::logic_error("Unable to allocate memory for Python list");
	for (unsigned int i = 0; i < data.size(); i++) {        
		PyObject *num = Py_BuildValue("i", data[i]);
		if (!num) {
			Py_DECREF(listObj);
			throw std::logic_error("Unable to allocate memory for Python list");
		}
		PyList_SET_ITEM(listObj, i, num);
	}
	return listObj;
}


// Python wrapper
static PyObject * primeNumbers_wrapper(PyObject * self, PyObject * args)
{
  int input;
  int soe;
  std::vector<int> result;
  PyObject * ret;

  // parse arguments as int https://docs.python.org/2.0/ext/parseTuple.html
  if (!PyArg_ParseTuple(args, "ii", &input, &soe)) {
    return NULL;
  }

  // run the actual function
  result = calcPrimeNumbers(input, soe);

  // build the resulting string into a Python object. https://docs.python.org/2/c-api/int.html
  // https://docs.python.org/2/c-api/arg.html?highlight=py_buildvalue#c.Py_BuildValue
  ret = vectorToList_Int(result);

  return ret;
}

// Symbol table register
static PyMethodDef PrimeMethods[] = {
 { "primeNumbers", primeNumbers_wrapper, METH_VARARGS, "Desc" },
 { NULL, NULL, 0, NULL }
};

// Init the function
PyMODINIT_FUNC initprime_module(void)
{
  (void) Py_InitModule("prime_module", PrimeMethods);
}






int main() {
    // std::cout << "primeNumbersSoE: " << primeNumbersSoE(1000).size() << "\n";
}



    
