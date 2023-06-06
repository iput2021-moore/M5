/*https://ossyaritoori.hatenablog.com/entry/2019/01/11/M5stack%E3%81%A8Raspberry_Pi_zero%E3%81%AEBluetooth_%E3%82%B7%E3%83%AA%E3%82%A2%E3%83%AB%E9%80%9A%E4%BF%A1

*/
#include <M5StickCPlus.h>


//  加速度センサ、角速度センサの値
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll  = 0.0F;
float yaw   = 0.0F;
//




float x, y, z; // 加速度データを格納
bool isSend = false; // データ送信フラグ

void setup() {
  M5.begin();
  M5.IMU.Init();

  Serial.begin(9600);
  
  M5.Lcd.setRotation(3);
  M5.Lcd.setCursor(0,0,4);
  M5.Lcd.println("Not Send");
}

void loop() {
  M5.update();
  if(M5.BtnA.wasPressed()){
    isSend = !isSend;
  }
    
    
  if(isSend){
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0,4);
    M5.Lcd.println("Send");
    delay(1000);
    // 加速度データ取得
    M5.IMU.getAccelData(&accX, &accY, &accZ);
    //　ジャイロデータ
    M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
    //角度データ
    M5.IMU.getAhrsData(&pitch, &roll, &yaw);
  
    // 加速度データを送信
    Serial.printf("%5.3f,%5.3f,%5.3f,%5.3f,%5.3f,%5.3f,%5.3f,%5.3f,%5.3f\n", accX,accY,accZ,gyroX,gyroY,gyroZ,pitch,roll,yaw);
  }
  else{
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0,0,4);
    M5.Lcd.println("Not Send");
  }
}

  // if(isSend){
  //   }
  
