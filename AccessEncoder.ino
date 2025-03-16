void encoder1_ISR(){
  VAL_ENC_1A = digitalRead(ENCODER1A);
  VAL_ENC_1B = digitalRead(ENCODER1B);
  if ((VAL_ENC_1A == HIGH) != (VAL_ENC_1B == LOW)){
    encoder_cnt[0]++;
  }
  else{
    encoder_cnt[0]--;
  }
  Serial.println("Data Encoder 1: " + String(encoder_cnt[0]));
}

void encoder2_ISR(){
  VAL_ENC_2A = digitalRead(ENCODER2A);
  VAL_ENC_2B = digitalRead(ENCODER2B);
  if ((VAL_ENC_2A == HIGH) != (VAL_ENC_2B == LOW)){
    encoder_cnt[1]++;
  }
  else{
    encoder_cnt[1]--;
  }
  Serial.println("Data Encoder 2: " + String(encoder_cnt[1]));
}

void encoder1_RPM(){
  currentTime = millis();
  if (currentTime - previousTime >= interval){
    previousTime = currentTime;
    encoder_velocity[0] = (encoder_cnt[0] * 60) / 11;
     Serial.print("Data RPM Encoder 1: "); Serial.println(encoder_velocity[0]);
    encoder_cnt[0] = 0;
  }
}

void encoder2_RPM(){
  currentTime = millis();
  if (currentTime - previousTime >= interval){
    previousTime = currentTime;
    encoder_velocity[1] = (encoder_cnt[1] * 60) / 11;
     Serial.print("Data RPM Encoder 2: "); Serial.println(encoder_velocity[1]);
    encoder_cnt[1] = 0;
  }
}
