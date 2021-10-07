# Compile.
echo Compiling adultTest.cpp
g++ adult/../../src/classes/person.cpp adult/../../src/classes/adult.cpp adult/adultTest.cpp -o adultTest -Wall -std=c++11
echo Finished Compiling

# Test.
echo Testing adult

# Standard Test.
echo "adult test 1"
./adultTest < adult/inputs/adultIn-01.txt | diff - adult/outputs/adultOut-01.txt
echo "adult test 2"
./adultTest < adult/inputs/adultIn-02.txt | diff - adult/outputs/adultOut-02.txt
echo "adult test 3"
./adultTest < adult/inputs/adultIn-03.txt | diff - adult/outputs/adultOut-03.txt

# Produce an output file.
#./adultTest < inputs/adultIn-01.txt > adultOut.txt

# Take user Input.
#./adultTest  > adultOut.txt
rm adultOut.txt

# Cleanup
rm adultTest
echo Finished Testing adult Class
