# https://plantprogramer.com/serial/
# https://qiita.com/kosystem/items/0023cfee941fdf099087

#pip install pyserial
#Not serial
import serial
ser = serial.Serial('/dev/ttyUSB0', 9600)  # デバイス名とボーレートを設定しポートをオープン 
ser.write("hello")      # 出力
ser.close()             # ポートのクローズ