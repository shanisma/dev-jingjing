import json
import serial

s = serial.Serial("/dev/tty.usbmodem14401")

while True:
    try:
        d = json.loads(s.readline())
        pression_dp0 = d["PA_0"]
        pression_dp1 = d["PA_1"]
        print("dp0 = " + str(pression_dp0))
        print("dp1 = " + str(pression_dp1))
        with open("dp.json", "w+") as stream:
            json.dump(d, stream)
    except json.JSONDecodeError:
        pass
