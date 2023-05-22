#include <M5StickCPlus.h>

// --------------------------------------------------------
// 変数・定数定義部
// --------------------------------------------------------
float acc[3];                                                 // 加速度測定値格納用（X、Y、Z）
float accOffset[3];                                           // 加速度オフセット格納用（X、Y、Z）
float gyro[3];                                                // 角速度測定値格納用（X、Y、Z）
float gyroOffset[3];                                          // 角速度オフセット格納用（X、Y、Z）

float roll  = 0.0F;                                           // ロール格納用
float pitch = 0.0F;                                           // ピッチ格納用
float yaw   = 0.0F;                                           // ヨー格納用

const float pi = 3.14;

// --------------------------------------------------------
// 関数定義部
// --------------------------------------------------------

// 加速度、角速度　測定値取得用　関数
void readGyro(){
  M5.IMU.getAccelData(&acc[0], &acc[1], &acc[2]);             // 加速度の取得
  M5.IMU.getGyroData(&gyro[0], &gyro[1], &gyro[2]);           // 角速度の取得
  roll  =  atan(acc[0] / sqrt((acc[1] *acc[1]) + (acc[2] * acc[2]))) * 180 / pi; 
  pitch =  atan(acc[1] / sqrt((acc[0] *acc[0]) + (acc[2] * acc[2]))) * 180 / pi; 
  yaw   =  atan(sqrt((acc[0] *acc[0]) + (acc[1] * acc[1])) / acc[2]) * 180 / pi;
}

void draw_display(){
  M5.Lcd.setCursor(15, 80);
  M5.Lcd.printf(" %5.1f   %5.1f   %5.1f   ", roll, pitch, yaw);
}

void setup() {
  // M5StickCの初期化と動作設定　Initialization and operation settings of M5StickC.
  M5.begin(); // 開始

  // IMUの初期化
  M5.Imu.Init();

  M5.Lcd.setRotation(3);  //Rotate the screen. 将屏幕旋转
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextFont(4);
  M5.Lcd.setTextSize(1);

  M5.Lcd.setCursor(15, 30);
  M5.Lcd.println("  Roll   Pitch    Yaw");

}

void loop() {
  readGyro();
  draw_display();

  delay(1000);
}