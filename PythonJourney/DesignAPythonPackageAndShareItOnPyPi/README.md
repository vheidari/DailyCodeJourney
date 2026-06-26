# Design Python Package and Share It on PyPI

To design a Python package I followed the instructions at this URL:

```
https://packaging.python.org/en/latest/tutorials/packaging-projects/#packaging-python-projects
```

The guide above is excellent and very helpful for learning the Python packaging system. Here I prefer to review a simple real‑world example of a Python package.

## Necessary Python utilities to build a package

### pip package manager

To install a Python package we usually use pip. Pip fetches packages from pypi.org. This means our package must be uploaded to pypi.org so anyone can install it as a dependency via pip. For example, to install Django use:

```bash
python3 -m pip install Django
```

Or another package:

```bash
python3 -m pip install PdfPageManipulator
```

### Virtual environment

When developing a new package or Python project, it is best practice to use a Python virtual environment. A virtual environment creates an isolated environment with its own Python binaries and installed packages inside your project directory. For example, if you create a directory named `myproject` and run:

```bash
python3 -m venv myexample_env
```

Python will create a `myexample_env` directory inside `myproject` containing the environment tools. Inside `myexample_env` you will find a `bin` folder with Python and pip binaries. Installed libraries live under `myexample_env/lib/python3.*/site-packages`. Any library or dependency you install for your project will be hosted locally inside this environment — similar to how Node/npm keep dependencies inside a project.

#### Activate the virtual environment

To switch to the project virtual environment, run this inside the project directory:

```bash
source ./myproject_env/bin/activate
```

The command above will activate the virtual environment named `myproject_env`. After activation, you can run Python and pip commands inside that environment. You can confirm activation by checking your shell prompt — it should change from:

```bash
# Before
yourusername@yourusername-system:~/Desktop/myproject$
```

to:

```bash
# After
(myproject_env) yourusername@yourusername-system:~/Desktop/myproject$
```

### Package-building tools

To create a Python package you need a package build backend. There are several available; choose one to build and prepare your package for upload to PyPI. Common options include:

```bash
- uv-build
- Hatchling
- setuptools
- Flit
- PDM
```

Note: We won't cover installation for these tools here. In the next section, when we design the package, we will choose one and use it to build the Python package.

### Tools to distribute package archives

After building the package, you’ll upload it to PyPI. Python recommends using `twine` to upload and distribute packages on PyPI. Install it in your virtual environment with:

```bash
(myproject_env) yourusername@yourusername-system:~/Desktop/myproject$ python -m pip install --upgrade twine
```

### test.pypi.org (PyPI test server)

test.pypi.org is a testing site similar to PyPI. Use it to verify how your package will be hosted before uploading to the real PyPI. When everything looks good on test.pypi.org, you can upload the project to pypi.org. test.pypi.org is typically used for learning and testing purposes.


## Design a simple Python package from scratch

In the last section we became familiar with tools that can help us build a package. Here I will start a new Python package project, build it, and finally upload it.

### Project directory and virtual environment

Create a directory named `packaging_tutorial`, then run this command in your terminal:

```bash
python3 -m venv packaging_tutorial_env
```

After the virtual environment `packaging_tutorial_env` is created, activate it with:

```bash
source packaging_tutorial_env/bin/activate
```

Your shell prompt should look like this:
`(packaging_tutorial_env) yourusername@yourusername-system:~/Desktop/packaging_tutorial$`

After activating the environment, create the necessary directories and files for the package. The `packaging_tutorial` project should have this structure:

```bash
packaging_tutorial/
└── src/
    └── packaging_tutorial_your_user_name/
        ├── __init__.py
        └── packaging_tutorial.py
```

This structure is recommended by the Python packaging guide. Below I use the Python packaging guide to explain each file and folder.

The directory containing the Python files (here: `packaging_tutorial_your_user_name`) should match the **project name** (I will explain what the **Project Name** is and where to define it). This simplifies configuration and makes the package structure clearer for users who install it.

Creating the file `__init__.py` is recommended because its presence allows users to import the directory as a regular package, even if `__init__.py` is empty (as in this tutorial).

`packaging_tutorial.py` is an example module within the package that contains the package logic (functions, classes, constants, etc.). Open that file and add:

```python
def add_one(number):
    return number + 1
```

Also open `__init__.py` and add:

```python
from .packaging_tutorial import add_one

__all__ = [
    "add_one"
]
```

After updating `packaging_tutorial.py` and `__init__.py`, add additional files to prepare the package for building. For that reason, the final package structure should look like this:

```bash
packaging_tutorial/
+├── LICENSE
+├── pyproject.toml
+├── README.md
 ├── src/
 │   └── packaging_tutorial_your_user_name/
 │       ├── __init__.py
 │       └── example.py
+└── tests/
```

Files and directories marked (`+`) above are ones you should add; below I explain the purpose of each:

- LICENSE:
  - Every open-source project should include a `LICENSE`. This file contains information about the project's permissions, limitations, and permitted use cases. If the project is open source, the `MIT` license text is a common choice. Spend some time reading about licenses and choose the one appropriate for your project.

- README.md:
  - The README should include all necessary information about the project: features, use cases, installation instructions, and so on.

- pyproject.toml:
  - `pyproject.toml` is the configuration file for the package. Settings defined here affect how the project is built. We use this file to tell pip and build tools the project name, the package author, and which build backend to use. Below you'll find a sample `pyproject.toml` that shows how to configure it for common build backends and tools.

- tests:
  - The `tests` directory contains all test files. Use this folder to write tests for your package to ensure everything works as expected. Tests in this directory can be run with `unittest` or `pytest`.

## Complete pyproject.toml and build the Python package

In the last section we learned how a Python package structure should look. Below we complete `pyproject.toml`, define project requirements, build the project, and prepare it for upload to PyPI.

### pyproject.toml structure

For this simple package, use the template below:

```toml
[build-system]
requires = ["uv_build >= 0.11.7, <0.12.0"]
build-backend = "uv_build"

[project]
name = "packaging-tutorial-your-user-name"
version = "0.0.1"
authors = [
  { name="Your Name", email="yourmail@example.com" },
]
description = "A small example package"
readme = "README.md"
requires-python = ">=3.9"
classifiers = [
    "Programming Language :: Python :: 3",
    "Operating System :: OS Independent",
]
license = "MIT"
license-files = ["LICENSE"]

[project.urls]
Homepage = "https://github.com/yourusername/packaging_tutorial"
Issues = "https://github.com/yourusername/packaging_tutorial/issues"
```

Everything above is straightforward, but some fields directly affect the build; incorrect values will cause build errors. As mentioned, `pyproject.toml` is the core config for a package. Front-end tools like pip and Python read it to build and install the package; the build backend (here `uv_build`) also uses it to produce the distribution. Be careful with each part.

[build-system] section:
```toml
[build-system]
requires = ["uv_build >= 0.11.7, <0.12.0"]
build-backend = "uv_build"
```
- This tells pip and Python which build backend to use. I use `uv_build` here, but you may choose another supported backend listed in **Package-building tools**.

[project] section:
```toml
[project]
name = "packaging-tutorial-your-user-name"
version = "0.0.1"
authors = [
  { name="Your Name", email="yourmail@example.com" },
]
description = "A small example package"
readme = "README.md"
requires-python = ">=3.9"
classifiers = [
    "Programming Language :: Python :: 3",
    "Operating System :: OS Independent",
]
license = "MIT"
license-files = ["LICENSE"]
```

Key points that commonly cause build errors:
- name: The package name under `[project]` should match the top-level package directory under `src`. For example:
  ```
  ├── src/
  │   └── packaging_tutorial_your_user_name/
  ```
  Keep the names consistent. if you notice in name field we user `-` (hyphen) instead `_` (underscore). and you know that its ok.

- Lowercase: Use a lowercase name (no CamelCase). Using CamelCase may prevent the build system from locating `__init__.py` and raise errors. Choose a lowercase name that matches the package directory.

- readme: The `readme` value must match the README file name exactly (case-sensitive on some systems). Use `readme = "README.md"`, not `README.MD` or other variants.

- license-files: The filenames listed in `license-files` must match files in your project root. For example `license-files = ["LICENSE"]` is correct if a `LICENSE` file exists.

Other fields are self-explanatory; define them correctly to avoid build problems.

### Build and prepare for upload to test.pypi.org (brief)

1. Ensure your virtual environment is active.
2. Install the build backend and build tools, for example:
   ```bash
   python3 -m pip install --upgrade build
   ```
3. From the project root, run:
   ```bash
   python3 -m build
   ```
   This produces artifacts in the `dist/` directory.
4. To upload the built package to test.pypi.org you need `twine`. Install and upload with:
   ```bash
   python3 -m pip install --upgrade twine
   python3 -m twine upload --repository testpypi ./dist/*
   ```

Note: Before running `python3 -m twine upload --repository testpypi ./dist/*` you need an API token from test.pypi.org. Register and verify an account on test.pypi.org, then go to Account settings → API tokens → Add API token and generate a token.

Note: On the Create API token page, provide a name, permissions, and scope. Set the scope to Entire Account.

Note: To upload a package to test.pypi.org with twine, ensure twine can access the test.pypi.org API token. Add a `.pypirc` file in your home directory and paste the token you created on test.pypi.org:

```
# ~/.pypirc

[testpypi]
username = yourusername
password = pypi-<your-api-token>
```

When everything is set, run:
```bash
python3 -m twine upload --repository testpypi ./dist/*
```
You will be prompted for the API token and, on success, twine will upload the package and show a project URL similar to:
```
Uploading distributions to https://test.pypi.org/legacy/
Enter your API token:
Uploading packaging_tutorial_your_user_name-0.0.1-py3-none-any.whl
100% ━━━━━━━━━━━━━━━━━━━━━ 8.2/8.2 kB
Uploading packaging_tutorial_your_user_name-0.0.1.tar.gz
100% ━━━━━━━━━━━━━━━━ 6.8/6.8 kB

# URL:
https://test.pypi.org/project/packaging_tutorial_your_user_name/
```

Follow these steps after verifying `pyproject.toml`, `README.md`, `LICENSE`, and your package sources are correct.

## Installing our package from test.pypi.org

Previously we created a Python package and uploaded it to test.pypi.org. Now create a new project and install that package from test.pypi.org:

- Generate a new project and set everything up to be ready for installation :
```bash
# Create new project directory
mkdir mynewproject
cd mynewproject

# Create a new Python virtual environment
python3 -m venv mynewproject_env

# Activate the virtual environment
source ./mynewproject_env/bin/activate

# Download and install packaging-tutorial-your-user-name from test.pypi.org
# Note: --no-deps tells pip not to resolve dependencies.
python3 -m pip install --upgrade -i https://test.pypi.org/simple/ --no-deps packaging-tutorial-your-user-name

# After installation, open a Python REPL
python3
```

- In the Python REPL import and use the package (use valid Python identifiers; replace hyphens with underscores or import the package module name as published):

```python
from packaging_tutorial_your_user_name import add_one

add_one(1000)
```

# Publishing a Python package on PyPI

Based on the previous explanation, to publish a package on pypi.org you need an API token from pypi.org, and to upload the package with twine you must ensure twine can access that API token. To upload to the main PyPI site you do not need the `--repository testpypi` option; run:

```bash
python3 -m twine upload ./dist/*
```