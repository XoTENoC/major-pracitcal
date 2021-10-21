# Compile.
echo Compiling full tests
g++ events/../../src/classes/person.cpp events/../../src/classes/adult.cpp events/../../src/classes/child.cpp events/../../src/classes/events.cpp events/../../src/functions/addingPerson.cpp events/../../src/functions/viewRoster.cpp events/../../src/functions/inputValidation.cpp events/../../src/functions/addingRoster.cpp events/eventsTest.cpp -o eventsTest -Wall -std=c++11
echo Finished Compiling

# Test.
echo Testing events

# Standard Test.
echo "full test 1"
./eventsTest < events/inputs/eventsIn-01.txt | diff - events/outputs/eventsOut-01.txt
echo "full test 2"
./eventsTest < events/inputs/eventsIn-02.txt | diff - events/outputs/eventsOut-02.txt

# Produce an output file.
# ./eventsTest < inputs/eventsIn-01.txt > eventsOut.txt

# Take user Input.
# ./eventsTest  > eventsOut.txt
# rm eventsOut.txt

# Cleanup
rm eventsTest
echo Finished Testing events Class
