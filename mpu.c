led_init (16);
mpu_Initialize();  // Using the existing MPU library

while (1)
	{
	mpu_BurstRead(MPU6050_REG_ ACCEL _XOUT_H,14,str);

// ------------------ Accelerometer -----------------------
	accel _x=(str[0)]<<3) | str[1];
	accel_y=(str[Z]<<8) | str[3];
	accel_z=(str[4]<<8) | str[5];

	// convert to g (m/s*2) 
	accel _xg=accel_x/2048.0;
	accel yg=accel y/2048.0;
	accel _ zg=accel_ 2/2048.0;

	//Display on LCD
	icd_clear();
	led_gotoxy(0,0);
	icd_putsf("Accelerometer");

	// ---- Xg----
	ftoa (accel_xg,1,str_xg);
	led_gotoxy(0,1);
	led_putsf("X= ");
	led_puts(str_xg);
	led_putst(" g");

	// ---- Yg----
	ftoa (accel _yg,1,str_yg);
	led_gotoxy(5,1);
	led_putsf("Y= ");
	led_puts(str_yg);
	led_putsft(" g");

	// ---- Zg----
	ftoa (accel zg,1,str_zg);
	led_gotoxy(10,1);
	led_putsf("Z= ");
	lcd_puts(str_zg);
	led_putsf(" g");
	delay_ms(100);

// ------------------ Gyroscope-----------------------
	gyro_x=(str[8]<<8) | str[9];
	gyro_y=(str[10]<<8) | str[1];
	gyro_z=(str[12]<<3) | str[13];

	// convert to deg/sec
	gyro_xrs= (gyro_x-(MPU6050_GXOFFSET)) /16.4;
	gyro_yrs= (gyro_y-(MPU6050_ GCYOFFSET))/16.4;
	gyro_zrs= (gyro_z-(MPU6050_ GZOFFSET)) /16.4;

	// ---- Xrs----
	ftoa (gyro_xrs,1,str_xrs);
	led_gotoxy(0,2);
	led_putsf("X= ");
	led_puts(str_xrs);
	led_putsf(" d/s");

	// ---- Yrs----
	ftoa (gyro_yrs,1,str_yrs);
	led_gotoxy(5,2);
	led_putsft("Y= ");
	led_puts(str_yrs);
	led_putsf(" d/s");
	// ---- Zrs----
	ftoa (gyro_zrs,1,str_zrs);
	led_gotoxy(10,2);
	led_putsf("Z= ");
	lcd_puts(str_zrs);
	led_putsf(" dfs");
	delay _ms(100);

// ------------------ Roll & Pitch -----------------------
	roll=atan2 (accel _yg, accel_zg);
	roll=rol1*57.32;
	ftoa (roll,1,str_roll);
	led_gotoxy(0,3);
	led_putsf("Roll= ");
	led_puts(str_roll);

	pitch=atan2 (accel_xg, accel_ zg);
	pitch=pitch*57.32;

	ftoa (pitch,1,str_pit);
	led_gotoxy(0,4);
	led_putsf("Pitch= ");
	led_puts(str_pit);

	delay _ms(100);
	}
