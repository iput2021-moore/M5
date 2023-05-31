# https://plantprogramer.com/serial/
# https://qiita.com/kosystem/items/0023cfee941fdf099087

#pip install pyserial
#Not serial
import serial

ser=serial.Serial(
    port='COM4',
    baudrate =9600,
    timeout=None,
    parity=serial.PARITY_NONE
)

ser.close()
ser.open()

while True:
    data =  ser.read_all()
    print(data)