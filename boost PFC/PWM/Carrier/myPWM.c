#include <math.h>

__declspec( dllexport ) void RUNSIMUSER(double t, double delt, double *in, double *out)
{

	//// input /////
	 static double Tri1=0,T_Sampling=0.00001,IRec_in=0.01,VRec_in=0,VDc_out;///T_Sampling=0.00002
	//// time and switch ////
	static int time=0,Switch_Boost,Switch_Buck;
	static double Duty_Boost=0,Duty_Buck=0,delay=0;
	 ///// Voltage average calculate /////
	 static double Sun_VRec_in=0,Sample_count=1,VRec_in_avg=1,VRec_in_avg_sq=1,VRec_in_old,VRec_in_new;

	//////// voltage loop control /////
	 static double Vdc_err,Vdc_reff,Vdc_err_sum,Vdc_P,Vdc_I, Iac_reff=0,Vdc_err_old;
	 //static double Vdc_KP=0.33,Vdc_KI=33.3,Km=3.11,Vdc_PI,Vdc_I_old,voltage_time;
	 static double Vdc_KP=0.33,Vdc_KI=0.5,Km=1,Vdc_PI,Vdc_I_old,voltage_time,count;

	 	//////// Battery control
	 static double Vbat_err,Vbat_reff,Ibat_reff=0.1,Vbat_err_sum,Vbat_P,Vbat_I, VIBat_reff=0,Vbat_err_old;
	 static double Vbat_KP=5,Vbat_KI=2,Vbat_PI,Vbat_I_old,VI_bat,CC_CV_Mode,VIbat_reff,Bat_type = 0, Start_signal=0;


	 	//////// current loop control /////
	 static double Iac_err,Iac_err_sum,Iac_P,Iac_I,Iac_err_old;
//	 static double Iac_KP=3,Iac_KI=40000,Iac_PI,Iac_I_old;
	 static double Iac_KP=2,Iac_KI=80000,Iac_PI,Iac_I_old;

	 ////////// Battery
	 static double V_bat,I_bat;


	 ////// Input
	Tri1 = in[0];
	IRec_in = in[1];
	VRec_in = in[2];
	VDc_out = in[3];
	Vdc_reff = in[4];
	V_bat = in[5];
	I_bat = in[6];
	Bat_type = in[7];
	CC_CV_Mode = in[8];

	////// 100Khz
	///// detect battery voltage
	///// LEAD acid battery minimum 125mAh

		if (Bat_type == 0)
	{	
		if((V_bat >= 0.21) && (V_bat <= 0.256))
		{
			Vbat_reff = 0.256;
			Ibat_reff = 0.8; ////// 24A
		}

		if((V_bat >= 0.42) && (V_bat <= 0.512))
		{
			Vbat_reff = 0.512;
			Ibat_reff = 0.8; ////// 24A
		}

		if((V_bat >= 0.63) && (V_bat <= 0.768))
		{
			Vbat_reff = 0.768;
			Ibat_reff = 0.5; ////// 15A
		}
	}

	//// Lithium ion battery minimum 125mAh
	if (Bat_type==1)
	{
		if((V_bat >= 0.21) && (V_bat <= 0.2946))
		{
			Vbat_reff = 0.295;
			Ibat_reff = 0.8; ////// 24A
		}

		if((V_bat >= 0.39) && (V_bat <= 0.548))
		{
			Vbat_reff = 0.548;
			Ibat_reff = 0.8; ////// 24A
		}

		if((V_bat >= 0.60) && (V_bat <= 0.84))
		{

			Vbat_reff = 0.84;
			Ibat_reff = 0.5; ////// 15A
		}
	}
	
	 if(time == 100)//200
	 {
		 time=0;

	 ///// Voltage average calculate /////
	
	if( VRec_in<0)
	{VRec_in = -VRec_in;
	}

	VRec_in_new = VRec_in;
	Sun_VRec_in += VRec_in;
	Sample_count ++;

	if(((VRec_in_new >= 0.0732) && (VRec_in_old < 0.0732)) || (Sample_count >= 1250))
	{
	VRec_in_avg = Sun_VRec_in/Sample_count;
	VRec_in_avg_sq = VRec_in_avg*VRec_in_avg;
	Sun_VRec_in =0;
	Sample_count=0;
	}

	VRec_in_old = VRec_in_new;

	////// 10Khz
	if(voltage_time = 10)
	{
		voltage_time = 0;
	//////// voltage loop control /////

	Vdc_err = Vdc_reff - VDc_out;

	Vdc_P = Vdc_KP*Vdc_err;
	Vdc_I = (Vdc_I_old + 0.5*Vdc_KI*(Vdc_err +Vdc_err_old)*T_Sampling*10) ;
	Vdc_PI = Vdc_P +  Vdc_I;

	Vdc_I_old = Vdc_I;
	Vdc_err_old = Vdc_err;
	Iac_reff = Km*VRec_in*Vdc_PI/VRec_in_avg_sq;


	if( Iac_reff > 1.99)
	{Iac_reff = 1.99;}
	if( Iac_reff < 0.01)
	{Iac_reff = 0.01;}


		//////// battery CC/CV control /////
	if( CC_CV_Mode == 0) ///// CC
	{
	VIbat_reff = Ibat_reff;
	VI_bat = I_bat;
	Vbat_KP=5,Vbat_KI=2;
	}
	if( CC_CV_Mode == 1) ///// CV
	{
	VIbat_reff = Vbat_reff;
	VI_bat = V_bat;
    Vbat_KP=500,Vbat_KI=300;
	}


	Vbat_err = VIbat_reff - VI_bat;

	Vbat_P = Vbat_KP*Vbat_err;
	Vbat_I = (Vbat_I_old + 0.5*Vbat_KI*(Vbat_err +Vbat_err_old)*T_Sampling*10) ;
	Vbat_PI = Vbat_P +  Vbat_I;

	Vbat_I_old = Vbat_I;
	Vbat_err_old = Vbat_err;
	Duty_Buck = Vbat_PI;

	if( Duty_Buck > 1.99)
	{Duty_Buck = 1.99;}
	if( Duty_Buck < 0.01)
	{Duty_Buck = 0.01;}

	}
	voltage_time ++;
	//////// current loop control /////

	Iac_err = Iac_reff - IRec_in;

	Iac_P= Iac_KP*Iac_err;
    Iac_I = (Iac_I_old + 0.5*Iac_KI*(Iac_err + Iac_err_old)*T_Sampling) ;
	Iac_PI= Iac_P+Iac_I;

	Iac_I_old = Iac_I;
	Iac_err_old = Iac_err;
	Duty_Boost = Iac_PI;


		if(Duty_Boost > 1.99)
		{Duty_Boost=1.99;}
		if(Duty_Boost < 0.01)
		{Duty_Boost=0.01;}
		
	}
	 time++;

//	 Boost Switching
	 if(Duty_Boost >= Tri1)
	 {Switch_Boost = 1;}
	 else
	 {Switch_Boost = 0;}

//	 Buck Switching

	 if(Duty_Buck >= Tri1)
	 {Switch_Buck = 1;}
	 else
	 {Switch_Buck = 0;}


	out[0] = Switch_Boost;
	out[1] = Switch_Buck;
	out[2] = VIbat_reff;
	out[3] = VI_bat;

}
