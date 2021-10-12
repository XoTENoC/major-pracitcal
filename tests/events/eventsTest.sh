# Compile.
echo Compiling eventsTest.cpp
g++ events/../../src/classes/person.cpp events/../../src/classes/events.cpp events/eventsTest.cpp -o eventsTest -Wall -std=c++11
echo Finished Compiling

# Test.
echo Testing events

# Standard Test.
echo "events test 1"
./eventsTest < events/inputs/eventsIn-01.txt | diff - events/outputs/eventsOut-01.txt
echo "events test 2"
./eventsTest < events/inputs/eventsIn-02.txt | diff - events/outputs/eventsOut-02.txt
echo "events test 3"
./eventsTest < events/inputs/eventsIn-03.txt | diff - events/outputs/eventsOut-03.txt

# Produce an output file.
# ./eventsTest < inputs/eventsIn-01.txt > eventsOut.txt

# Take user Input.
# ./eventsTest  > eventsOut.txt
# rm eventsOut.txt

# Cleanup
# rm eventsTest
echo Finished Testing events Class
