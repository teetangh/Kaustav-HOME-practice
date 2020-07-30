Remember
python != /usr/bin/env python
and python3 !=/usr/bin/env python3

cd to the "setup.py" level directory
rm -rf build/ dist/ package_name.egg-info/

Keep updating the version numbes for ease of use later on


# install relevant packages for the experiments 
pip install --upgrade wheel
pip3 install --upgrade wheel

# Making the setup file
python setup.py sdist bdist_wheel
/usr/bin/env python setup.py sdist bdist_wheel   (Requires !/usr/bin/env python at the top of every py file)

python3 setup.py sdist bdist_wheel
/usr/bin/env python3 setup.py sdist bdist_wheel  (Requires !/usr/bin/env python3 at the top of every py file)

# Moving to the dist folder where all the install wheels files are located
cd dist/
python -m pip install --upgrade package_name-x.y-py2-none-any.whl (Modify x.y as per the requirement)
python3 -m pip3 install --upgrade package_name-x.y-py3-none-any.whl (Modify x.y as per the requirement) [verify this]

# Verifying the installation
pip list | grep package_name
pip3 list | grep package_name

# For Removing the packages
pip uninstall package_name
pip3 uninstall package_name

