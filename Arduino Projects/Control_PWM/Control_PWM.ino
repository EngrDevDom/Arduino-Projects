byte brightness = 0;
const int LED = 11;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("enter brightness %");
  while(Serial.available()==0)
  {
    // không làm gì cả
  }
  while(Serial.available()>0)
  {
    char ch = Serial.read();
    if(ch >= '0' && ch <='255')
    {
    //chuyển từ ASCII sang số thập phân
    brightness = brightness*10 + ch - '0';
    delay(5);//chờ tín hiệu tiếp theo được truyền qua cổng serial
             //KHÔNG THỂ THIẾU. Hãy thử bỏ dòng này bạn sẽ thấy điều khác biệt!
    }
    else 
    {
    Serial.print(ch);
    Serial.println(":not valid");
    brightness = 0;
    }
  }
  // chặn giá trị brightness trong khoảng [0,100]
  brightness = constrain(brightness,0,100);
  // in ra giá trị brightness
  Serial.print("brightness = ");
  Serial.println(brightness);
  // chuyển đổi từ giá trị brightness sang PWM
  byte value = map(brightness,0,100,0,255);
  // bật LED với giá trị xung PWM (duty cycle) nhận được
  analogWrite(LED,value);
  // reset biến brightness về giá trị 0 
  //để tiếp tục tính toán
  brightness = 0;
}
