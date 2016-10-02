echo Compiling c++...
g++ -std=c++11 -o passGen passwordCreator.cpp
sudo cp passGen /bin/
echo Instalation succesful. To use Type command: passGen
