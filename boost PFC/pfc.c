		
	
	//// input /////
	 static double T_Sampling=0.00002,IRec_in=0.01,VRec_in=0,VDc_out;///T_Sampling=0.00002
	 static double VRec_in_pol = 0, VRec_ABS_in,IRec_ABS_in ;

	//// time and switch ////
	static int time=0,Switch_Boost1,Switch_Boost2;
	static double Duty_Boost=0,Duty_Buck=0,delay=0;
	
	 ///// Voltage average calculate /////
	 static double Sun_VRec_in=0,Sample_count=1,VRec_in_avg=0.24,VRec_in_avg_sq=1,VRec_in_old,VRec_in_new;

	//////// voltage loop control /////
	 static double Vdc_err,Vdc_reff = 400/420 ,Vdc_err_sum,Vdc_P,Vdc_I, Iac_reff=0,Vdc_err_old,Vdc_Sum,Vdc_Exc;
	 //static double Vdc_KP=0.03,Vdc_KI=4,Km=0.0001,Vdc_PI,Vdc_I_old,voltage_time;
	 static double Vdc_KP=1,Vdc_KI=0.001, Vdc_C=0.0218, Km=0.15,Vdc_PI,Vdc_I_old,voltage_time,count,sine_factor;
 
	//////// current loop control /////
	 static double Iac_err,Iac_err_sum,Iac_P,Iac_I,Iac_Sum,Iac_Exc, current_time = 0;
	 static double Iac_KP=1,Iac_KI=0.3,Iac_C= 0.57,Iac_PI,Iac_I_old;

	 ////// Input
	IRec_in = in[1]; ///Inguon;
	VRec_in = in[2];
	VDc_out = in[3];

    ////// Absolutely Value and detect the polarity of Vin and Iin /////////
	if(VRec_in >= 0)
	{ VRec_in_pol = 0;} /// Vin is possitive
	else
	{VRec_in_pol = 1;} /// Vin is negative
	
	VRec_ABS_in = abs(VRec_in);
	IRec_ABS_in = abs(IRec_in);


	 ///// Voltage average calculate /////


	VRec_in_new = VRec_ABS_in;
	Sun_VRec_in += VRec_ABS_in;
	Sample_count ++;

	if(((VRec_in_new >= 0.0732) && (VRec_in_old <= 0.0732)) || (Sample_count >= 23255))
	{
	VRec_in_avg = Sun_VRec_in/Sample_count;
	VRec_in_avg_sq = VRec_in_avg*VRec_in_avg;
	Sun_VRec_in =0;
	Sample_count=0;
	}

	VRec_in_old = VRec_in_new;

	if(current_time == 20)
	{current_time = 0;



	////// 25Khz ////////
	if(voltage_time == 2)
	{
		voltage_time = 0;
	//////// voltage loop control /////

	Vdc_err = Vdc_reff - VDc_out;
	Vdc_P = Vdc_Sum + Vdc_KP*Vdc_err;
	if(Vdc_P > 1)
	{Vdc_PI = 1;}
	else if( Vdc_P < 0)
	{Vdc_PI = 0;}
	else
	{Vdc_PI = Vdc_P;}
	Vdc_Exc = Vdc_P - Vdc_PI;
	Vdc_Sum = Vdc_Sum + Vdc_KI*Vdc_err - Vdc_C*Vdc_Exc;

	//km varies and is proportional to the input current
	sine_factor = VRec_ABS_in/VRec_in_avg_sq;
	Iac_reff =Km* Vdc_PI*sine_factor;

	if( Iac_reff > 3)
	{Iac_reff = 3;}
	if( Iac_reff < -1)
	{Iac_reff = 0;}

	}
	voltage_time ++;
	//////// current loop control /////

	Iac_err = Iac_reff - IRec_ABS_in;
	Iac_P = Iac_Sum + Iac_KP*Iac_err;
	if(Iac_P > 1)
	{Iac_PI = 1;}
	else if( Iac_P < 0)
	{Iac_PI = 0;}
	else
	{Iac_PI = Iac_P;}
	Iac_Exc = Iac_P - Iac_PI;
	Iac_Sum = Iac_Sum + Iac_KI*Iac_err - Iac_C*Iac_Exc;

        Duty_Boost = Iac_PI;


	}
         current_time++;

		if(Duty_Boost > 1)
		{Duty_Boost= 1;}
		if(Duty_Boost < 0)
		{Duty_Boost= 0;}
		
	if(VRec_in_pol == 0)
	{
	out[0] = Duty_Boost;
	out[1] = Duty_Boost;
	}
	else
	{
	out[0] = (1-Duty_Boost);
	out[1] = (1-Duty_Boost);
	}

	out[2] = Vdc_PI;