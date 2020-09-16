#define LF          0x0A 

char angle_str[10]; 
int idx; 

void setup() {
    Serial.begin(9600);
    Serial.print("start\r\n");

    idx = 0;
}

void loop() {

    if (Serial.available() > 0) {
    angle_str[idx] = Serial.read();
    if (angle_str[idx] == LF) {
        Serial.print("Received new angle: ");
        angle_str[idx-1] = 0;
        Serial.println(angle_str);
        idx = -1;
        }
    idx++;
    }
}
