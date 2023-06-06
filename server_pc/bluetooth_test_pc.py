# https://plantprogramer.com/serial/
# https://qiita.com/kosystem/items/0023cfee941fdf099087

import serial
import time

ser = serial.Serial("tty.BT_Slave", 9600, timeout=0.1)

time.sleep(2) 
       
try:
    while True: 
        # print("test")    
        if ser.in_waiting > 0: # シリアル通信 受信待ち
            bytes = ser.readline()
            result, buf = bytes.decode('utf-8').split('\n')
            data = list(map(float, result.split(',')))
            print("AccX: {0}, AccY: {1}, AccZ: {2}".format(data[0], data[1], data[2]))
            
        time.sleep(0.2)

except KeyboardInterrupt:
    pass

print('program end')
ser.close()