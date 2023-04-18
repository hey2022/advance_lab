import os
import subprocess
import time
from func_timeout import func_set_timeout
TIMEOUT = 600
@func_set_timeout(TIMEOUT)
def testfor(prac,start):
    prac.wait()
    stop = time.time()
    return str(stop-start)
alij = [sorted(os.listdir("./bin"))]
print(sorted(os.listdir("./bin")))
for testdata in sorted(os.listdir("./data/")):
    subprocess.run(f"cp ./data/{testdata} ./testingdata.in", shell=True)
    ali=[testdata]
    for filename in sorted(os.listdir("./bin")):
        tr=0
        for i in range(5):
            start = time.time()
            prac = subprocess.Popen(f"./bin/{filename}", shell=True, stdout=subprocess.DEVNULL)
            try:
                t=testfor(prac,start)
                tr=0
                prac.kill()
                break
            except:
                pass
            prac.kill()
            print(str(i)+" "+filename+" "+testdata+" "+t)
            tr+=float(t)
        if(tr!=0):
            print("FINAL : "+str(tr/5))
            ali.append(str(tr/5))
        else:
            print("ERROR : TLE "+filename+" "+testdata)
            ali.append("TLE")
    alij.append(ali)
print(alij)