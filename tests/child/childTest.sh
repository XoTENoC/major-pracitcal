# Compile.
echo Compiling childTest.cpp
g++ child/../../src/classes/person.cpp child/../../src/classes/child.cpp child/childTest.cpp -o childTest -Wall -std=c++11
echo Finished Compiling

# Test.
echo Testing child

# Standard Test.
echo "child test 1"
./childTest < child/inputs/childIn-01.txt | diff - child/outputs/childOut-01.txt
echo "child test 2"
./childTest < child/inputs/childIn-02.txt | diff - child/outputs/childOut-02.txt
echo "child test 3"
./childTest < child/inputs/childIn-03.txt | diff - child/outputs/childOut-03.txt

# Produce an output file.
# ./childTest < inputs/childIn-01.txt > childOut.txt

# Take user Input.
#./childTest  > childOut.txt
# rm childOut.txt

# Cleanup
rm childTest
echo Finished Testing child Class
