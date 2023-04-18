import os
import subprocess
import re
obj_gn=re.compile("(?P<n>.*?)\.cpp")
PATH = "./cpps"
for filename in os.listdir("./bin"):
    subprocess.run(f"rm ./bin/{filename}",shell=True)
for filename in os.listdir(PATH):
    print(filename)
    subprocess.run(f"g++ -Wall {PATH}/{filename} -o {'./bin/'+obj_gn.search(filename).group('n')}", shell=True)