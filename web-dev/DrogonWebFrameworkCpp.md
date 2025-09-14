# Drogon Web Framework

## Ubuntu - Install Drogon Web Framework (C++)

### Ubuntu - Requirements

```
sudo apt install libjsoncpp-dev
sudo apt install uuid-dev
sudo apt install zlib1g-dev
sudo apt install openssl libssl-dev
```

### Ubuntu - Database Requirements

```
sudo apt-get install postgresql-all
sudo apt install libmariadb-dev-compat libmariadb-dev
sudo apt-get install libsqlite3-dev
sudo apt-get install libhiredis-dev
```

### Ubuntu - Drogon Installation

```
cd $WORK_PATH
git clone https://github.com/drogonframework/drogon
cd drogon
git submodule update --init
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
# to use clang instead:
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang ..
make && sudo make install
```
