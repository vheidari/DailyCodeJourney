# Python Package Test through Pytest
After designing and implementing the entire Python package, we should implement appropriate tests for each method or class to ensure everything works correctly. Here, I will explain how to use pytest to write and implement tests for our package."

## Package Structure and tests file
Here is a simple package directory structure with tests directory and test file for each module of package. 

```bash
MyPackage/
├── src/
│   └── my_package/
│       ├── __init__.py
│       └── MyPackage.py
├── tests/
│   └── test_MyPackage.py  
```
as you can see the `tests` directory contains a test file `test_MyPackage.py` which will contain the test cases for the `MyPackage.py` module.

in test_MyPackage.py I will write test cases for the methods defined in MyPackage.py. For example, if MyPackage.py has a method called `add_numbers(a, b)`, I will write a test case to check if this method returns the correct sum of two numbers.

```python
# test_MyPackage.py
import pytest
from my_package.MyPackage import add_numbers

def test_add_numbers():
    # if add_numbers is working correctly, it should return the sum of two numbers
    # if add_numbers(2, 3) returns 5, the test will pass, otherwise it will fail
    assert add_numbers(2, 3) == 5 "Expected 2 + 3 to equal 5"
    assert add_numbers(-1, 1) == 0 "Expected -1 + 1 to equal 0"
    assert add_numbers(0, 0) == 0 "Expected 0 + 0 to equal 0"
```
another example here is if MyPackage.py has a method called `count_words(file_name="filename.txt" , path="./" )`, I will write a test case to check if this method returns the correct count of words in a given a text file.

```python
# test_MyPackage.py
import pytest
from my_package.MyPackage import count_words

def test_count_words():
    file_name_one = "test_file.txt"
    file_name_two = "another_test_file.txt"
    path = "./tests/"
    
    # Create a test file with some content
    # This file will contained 7 words: "Hello", "world!", "This", "is", "a", "test", "file."
    with open(file_name_one, "w") as f:
        f.write("Hello world! This is a test file.")
    
    # Create another test file with some content
    # This file will contained 6 words: "Another", "test", "file", "with", "some", "words."
    with open(file_name_two, "w") as f:
        f.write("Another test file with some words.")


    # Now we will go to read the file and count the words using count_words method
    # We should pass path as "./tests/" because the file is created in tests directory and
    # Pytest will run the test from the root directory of the package
    assert count_words(file_name, path) == 7 "Expected the word count to be 7"
    assert count_words(file_name_two, path) == 6 "Expected the word count to be 6"

```

## Insatlling pytest in Python Environment
To install `pytest`, you can use pip, which is the package installer for Python. You can run the following command in your terminal or command prompt, 

but I recommend using a virtual environment to avoid conflicts with other packages in your system. for that reason, I will explain how to create a virtual environment and install pytest in it and run it. 

here in blow steps you can learn how to create python virtual environment, install pytest and run the tests using pytest.
```bash
# define the name of the virtual environment
NAME_ENV=MyPackageEnv

# Create a virtual environment
python3 -m venv $NAME_ENV

# Activate the virtual environment
source ./${NAME_ENV}/bin/activate  # On Windows, use: .\${NAME_ENV}\Scripts\activate

# Install pytest in the virtual environment
python3 -m pip install --upgrade pytest

# Before we go to run pytest we should make sure that we are in 
# The root directory of the package where the tests directory is located.

# Also we should ensure pytest can access to the package and the tests, since our package is under src directory we should set the PYTHONPATH to include the src directory.

# Current example our package is under src directory to ensure pytest can find 
# The package and tests we can set the PYTHONPATH as follows:
export PYTHONPATH="./src:$PYTHONPATH"

# Now we can run pytest to execute the tests in the tests directory. You can simply run the following command in your terminal:
pytest --verbose ./tests/

echo "All tests have been executed. Check the output above for any failed tests and their details."

``` 
If all above steps are followed correctly, pytest will run the tests defined in `test_MyPackage.py` and provide a report on the results. If any test fails, pytest will show which test failed and the reason for the failure, allowing you to debug and fix the issues in your package.