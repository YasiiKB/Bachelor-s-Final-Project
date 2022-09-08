while (1)
{
//--------- LCD-----------
	led_clear();
	led_gotoxy(0,0);
	lcd_putsf ("Accelerometer");

//--------- X---------------
	inputx=read_adc (0);
	// 720 covers the range from -30 to +360
	outputx=(inputx*720) / (1024);  
	outx = outputx-360;
	itoa (outx,strx);
	led_gotoxy(0,1);
	led_putsf("X= "};
	icd_puts(strx);

//--------- Y---------------
	inputy=read_ adc (1);
	outputy=(inputy* 720) / (1024);
	outy = outputy-360;
	itoa (outy,stry);
	led_gotoxy(0,2);
	led_putsf("Y= ");
	led_puts(stry);

//--------- Z----------------
	inputz=read_adc (2);
	outputz=(inputz*720) / (1024);
	outz = outputz-360;
	itoa (outz,strz);
	led_gotoxy(0,3);
	led_putsf("Z= ");
	led_puts(strz);
	delay ms(200);

//--------- STEPPER MOTORS -----------

	//--------- X-----------
	inputxnew=read_ adc (0);
	outputxnew= (inputxnew*720) / (1024);
	outxnew = outputxnew-360;
	PORTD=0x00;
	if (outxnew>outx)  //Clockwise
		{
		stepx=(outxnew - outx) /1.8;   // Steps in Proteus are set on 1.8
		PORTD = 0x08;
		for (ix=0; ix<stepx; ix++)
			{
			delay ms(1);
			PORTD = PORTD >>1;
			}
		outx = outxnews;  //Clockwise
		}
	else   	//Counter Clockwise
		{
		stepx=(outxnew<outx) /1.8;
		PORTD = 0x01;
		for (ix=0;ix<stepx; ix++)
			{
			delay _ms(1);
			PORTD = PORTD <<1;
			}
		outx = outxnew;
		}
	//--------- Y-----------
	inputynew=read_ adc(1);
	outputynew= (inputynew*720) / (1024);
	outynew = outputynew-360;
	PORTE=0x00;
	if (outynew>outy)       //Clockwise
		{
		stepy=(outynew - outy) /1.8;
		PORTE = 0x08;
		for (iy=0; iy<stepy; iy++)
			{
			delay_ms(1l);
			PORTE = PORTE =>1;
			}
		outy = outynew;
		}
	else 	//Counter Clockwise
		{
		stepy =l(outynew<outy) /1.8;
		PORTE = 0x01;
		for (iy=0;iy<stepy; iy++)
			{
			delay _ms(1);
			PORTE = PORTE <<1;
			}
		outy = outynew;
		}
	//--------- Z-----------
	inputznew=read_ adc(2);
	outputznew= (inputznew*720) / (1024);
	outznew = outputznew-360;
	PORTA=0x00;
	if (outznew>outz)        //Clockwise
		{
		stepz=(outznew - outz) /1.8;
		PORTA = 0x08;
		for (iz=0; iz<stepz;  iz++)
			{
			delay_ms(1);
			PORTA = PORTA >>1;
			}
		outz = outznew;
		}
	else	//Counter Clockwise
		{
		stepz =(outzgnew<outz) /1.8;
		PORTA =0x01;
		for (iz=0; iz<stepz; iz++)
			{
			delay _ms(1);
			PORTA = PORTA <<1;
			}
		outz = outznew;
		}
}