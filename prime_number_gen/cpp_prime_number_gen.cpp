#include <iostream>
#include <stdio.h>
#include <vector>

// Python extention requirements
#include <Python.h>


// bool isPrimeV3(int in_num, std::vector<int> *cache) {
//     // Returns False if divisable by anything other than 1 or itself
    
//     // Will loop thrugh every int betweeen 1 and in_num
//     for (float num = 2; num < in_num; num++){
//         float prime_calc = in_num / num;
//         if (prime_calc == static_cast<int>(prime_calc)){
//             return false;
//         } 
//     }

//     return true;
// }

bool isPrimeV2(int in_num) {
    // Returns False if divisable by anything other than 1 or itself
    
    // Will loop thrugh every int betweeen 1 and in_num
    for (float num = 2; num < in_num; num++){
        float prime_calc = in_num / num;
        if (prime_calc == static_cast<int>(prime_calc)){
            return false;
        } 
    }

    return true;
}

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
    // std::vector<int> cache;
    for (int i = 2; i < count_to+1; i++) {
        if (isPrimeV2(i)) {
            prime_numbers.push_back(i);
        }        
    }

    // return prime_numbers;
    return prime_numbers;
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
  std::vector<int> result;
  PyObject * ret;

  // parse arguments as int https://docs.python.org/2.0/ext/parseTuple.html
  if (!PyArg_ParseTuple(args, "i", &input)) {
    return NULL;
  }

  // run the actual function
  result = primeNumbers(input);

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
    // primeNumbers(10000);
}



    
