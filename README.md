# Using AARE

```bash
#Assuming that aare is installed in SOME_PATH
git clone https://github.com/slsdetectorgroup/aare-examples.git
cd aare-examples
mkdir build
cd build
cmake .. -DCMAKE_PREFIX_PATH=SOME_PATH
make -j4

#test the program
$ ./file_info path/to/my/file_master_0.json
Frames: 10, Rows: 512, cols: 1024

```
