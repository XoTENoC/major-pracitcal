# Compile.
echo Compiling adultTest.cpp
g++ adult/../../src/classes/person.cpp adult/../../src/classes/adult.cpp adult/adultTest.cpp -o adultTest -Wall -std=c++11
echo Finished Compiling

# Test.
echo Testing adult

# Standard Test.
./adultTest < adult/inputs/adultIn-01.txt | diff - adult/outputs/adultOut-01.txt

# Produce an output file.
#./adultTest < inputs/adultIn-01.txt > adultOut.txt

# Take user Input.
#./adultTest  > adultOut.txt
# rm adultOut.txt

# Cleanup
rm adultTest
echo Finished Testing adult Class
