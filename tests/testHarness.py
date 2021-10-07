import os
import subprocess
import sys

# Setting the base directory /major-pracitcal
basepath = sys.path[0]

for classDirectory in os.listdir(basepath):
    if os.path.isdir(os.path.join(basepath, classDirectory)):
        
        for file in os.listdir(classDirectory):
            
            if file.endswith('.sh'):
                print(file)
                print(os.path.join(basepath, classDirectory, file))
                subprocess.call(['bash', os.path.join(basepath, classDirectory, file)])