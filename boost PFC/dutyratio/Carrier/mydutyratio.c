#include <math.h>

__declspec( dllexport ) void RUNSIMUSER(double t, double delt, double *in, double *out)
{
	
	
    
	 static double step;
	 #define         pi 3.14159
	 static double Uref;
	 static double UAi,UBi,UCi,Um,Tri;
	 static double d,f;
	 static int Sp,Rp,Tp,Sn,Rn,Tn;
	 static double alpha;
	 static double sinal;
	 static double k, dba, dca,dcb,dac,dab,dbc;
	 static double Udc;
	 static double D0,D1,D2,D3,D4,D5,D6,D7,D8;
	 static double m;
	 static double sector;
	 static  double T1x,T2x,T1y,T2y,dx,dy,Ux,Uy,TT1x,TT2x,TT1y,TT2y,Dx,Dy,TT0x,TT0y,T0x,T0y;
	 static  double secin,Vdc, U2, U1, Ts, Uds, Uqs, Uin;
	 static  double Val,Vbe,Vd,Vq,Vqerr,Vqerr_old,UA2,UB2,UC2;
	 static  double theta,theta_inc,phase,delta,delta_old;

     const double KP_Vq =10;
	 const double KI_Vq=1000;
	 const double Tpp = 0.0001;
	 const double delta_MAX = 150;
	 const double delta_MIN = -150;
	
	if((step == 0) || (step == 100))
	{
		UAi= in[0];
		UBi= in[1];
		UCi= in[2];

		// PLL//
		Val = (2 * UAi - UBi - UCi)/3; 
		Vbe = (UBi - UCi)/1.732;

		Vd = Val * cos(theta) + Vbe * sin (theta);
		Vq = -Val * sin(theta) + Vbe * cos (theta);

		Vqerr = 0 - Vd;
		delta = delta_old + Vqerr * (KP_Vq + KI_Vq * Tpp) + Vqerr_old * (-KP_Vq + KI_Vq * Tpp);

		if (delta > delta_MAX) delta = delta_MAX;
		if (delta < delta_MIN) delta = delta_MIN;

		theta_inc  = Tpp * (delta + 120 * 3.14);

		delta_old = delta;
		Vqerr_old = Vqerr; 
		theta = theta + theta_inc;
		if (theta>= 6.28)
			theta = theta - 6.28;

		phase = 3.14 / 180 * in [6];

		UA2 = Uin * - sin (theta - phase);
		UB2 = Uin * - sin (theta - phase - 2 * 3.14 /3);
		UC2 = Uin * - sin (theta - phase - 4 * 3.14 /3);
//////////////////////////////////////////////////////////////////////////////////////////////////
		f=in[3];
		m=in[4];
		k=in[5];
		Ts=1;
		Uds = UAi;
		Uqs = (UBi - UCi)/1.7320508;
		U1 = Uds*Uds + Uqs *Uqs;
		Uin = sqrt(U1);
		U2 =m * sqrt(U1);
		alpha=alpha +  2*f*pi*0.0001 ;
	if (alpha>=2*pi)
		{
		alpha=0;
		} 		
/////////////////////////////////////////////	AC--------AB-------AC //////////////////////////////////////////
if ((UA2>0) & (UB2<=0) & (UC2<=0)) 
		{
		secin=1;	
		dx = - UC2/UA2;
		dy = - UB2/UA2;	
		Um = dx * (UAi - UCi) + dy * (UAi - UBi);
		Ux=UAi-UBi;
		Uy=UAi-UCi;

////////////////// SECTOR 1//////////////////////// AC--------AB-------AC
// Uab Uac
			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=1;	
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha)*Ts;
				*/
				
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
				
	}
////////////////// SECTOR 2/////////////////////
			 if ((alpha>=pi/3)&(alpha<2 * pi/3))  
			{
				sector=2;	
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(2*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(2*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-pi/3)*Ts;
				*/
				
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
	}
////////////////// SECTOR 3 ////////////////////
			if ((alpha>=2*pi/3)&(alpha<3*pi/3))  
			{
				sector=3;			
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(3*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-2*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(3*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-2*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
////////////////// SECTOR 4 ////////////////////		
		  if ((alpha>=3 * pi/3)&(alpha < 4 * pi/3))  
			{
				sector=4;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(4*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-3*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(4*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-3*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
                
			}
////////////////// SECTOR 5 ////////////////////	
			if ((alpha>=4 * pi/3)&(alpha < 5 * pi/3))  
			{
				sector=5;	
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(5*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-4*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(5*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-4*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
////////////////// SECTOR 6 ////////////////////	
			if ((alpha>=5 * pi/3)&(alpha < 6 * pi/3))  
			{
				sector=6;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UCi*sin(6*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-5*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UBi*sin(6*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-5*pi/3)*Ts;
				*/		
			
			    T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			
	}
}
///////////////////////////// SECTOR 2  BC-- AC----BC--/////////////////////

if ((UC2<0) & (UA2>=0) & (UB2>=0)) 
{
	secin=2;
	dx = - UB2/UC2;
	dy = - UA2/UC2;
	Um = dx * (UBi - UCi) + dy * (UAi - UCi);
	Ux = UAi - UCi;
	Uy = UBi - UCi;			
					//////////////////SECTOR 1/////////////////////
			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=7;				
				/*
				T1x = (1/1.7320508)*U2/(U1)*UBi*sin(pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha)*Ts;
				*/
				
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
				

			}
					//////////////////SECTOR 2/////////////////////

			 if ((alpha>=pi/3)&(alpha<2 * pi/3))  
			{
				
				sector=8;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UBi*sin(2*pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-pi/3)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(2*pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-pi/3)*Ts;
				*/
				
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
			//////////////////SECTOR 3 ////////////////////
			if ((alpha>=2*pi/3)&(alpha<3 * pi/3))  
			{
				sector=9;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UBi*sin(3*pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-2*pi/3)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(3*pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-2*pi/3)*Ts;	
				*/
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
			//////////////////SECTOR 4 ////////////////////		
		  if ((alpha>=3 * pi/3)&(alpha < 4 * pi/3))  
			{
			    sector=10;
				/*
			    T1x = (1/1.7320508)*U2/(U1)*UBi*sin(4*pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-3*pi/3)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(4*pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-3*pi/3)*Ts;	
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
	        }
			////////////////// SECTOR 5 ////////////////////	
			if ((alpha>=4 * pi/3)&(alpha < 5 * pi/3))  
			{
				sector=11;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UBi*sin(5*pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-4*pi/3)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(5*pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-4*pi/3)*Ts;	
				*/
				
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
			////////////////// SECTOR 6 ////////////////////	
			if ((alpha>=5 * pi/3)&(alpha < 6 * pi/3))  
			{
				sector=12;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UBi*sin(6*pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-5*pi/3)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UAi*sin(6*pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-5*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}		
		}

/////////////////////// SECTOR 3 ////////////////////////// BA--BC--BA /////////////////////////

if ((UB2>0) & (UA2<=0) & (UC2<=0)) 
{
	secin=3;
	dx = - UA2/UB2;
	dy = - UC2/UB2;
	Um = dx * (UBi - UAi) + dy * (UBi - UCi);
		//////////////////SECTOR 1/////////////////////
			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=13;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha)*Ts;
				*/
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
		//////////////////SECTOR 2/////////////////////
			 if ((alpha>=pi/3)&(alpha<2 * pi/3))  
			{
			    sector=14;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(2*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(2*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}			
		//////////////////SECTOR 3 ////////////////////
			if ((alpha>=2 * pi/3)&(alpha<3 * pi/3))  
			{
				sector=15;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(3*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-2*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(3*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-2*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
	
         //////////////////SECTOR 4 ////////////////////		
		  if ((alpha>=3 * pi/3)&(alpha < 4 * pi/3))  
			{
				sector=16;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(4*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-3*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(4*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-3*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
                
			}
			////////////////// SECTOR 5 ////////////////////	
			if ((alpha>=4 * pi/3)&(alpha < 5 * pi/3))  
			{
				sector=17;	
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(5*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-4*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(5*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-4*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
			////////////////// SECTOR 6 ////////////////////	
			if ((alpha>=5 * pi/3)&(alpha < 6 * pi/3))  
			{
				sector=18;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UAi*sin(6*pi/3-alpha)*Ts;
				T2x = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-5*pi/3)*Ts;
				T1y = -(1/1.7320508)*U2/(U1)*UCi*sin(6*pi/3-alpha)*Ts;
				T2y = -(1/1.7320508)*U2/(U1)*UCi*sin(alpha-5*pi/3)*Ts;
				*/
				T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
                 
			}
	}
///////// SECTOR 4//////////////////////  CA ------ BA----------CA/////////////////////////

if ((UA2<0) & (UB2>=0) & (UC2>=0)) 
{	    
	secin=4;
	dx = - UC2/UA2;
	dy = - UB2/UA2;
	Um = dx * (UCi - UAi) + dy * (UBi - UAi);

/////////////////// SECTOR 1/////////////////////////////
			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=19;	
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha)*Ts;//CA
				*/
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
				
			}
///////////////////// SECTOR 2/////////////////////////////
			if ((alpha>pi/3)&(alpha<=2 * pi/3))  
			{
				sector=20;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(2*pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-pi/3)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(2*pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-pi/3)*Ts;//CA
		        */
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
		 }   			
///////////////////// SECTOR 3/////////////////////////////
			if ((alpha>=2 * pi/3)&(alpha<=3 * pi/3))  
			{
				sector=21;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(3*pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-2*pi/3)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(3*pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-2*pi/3)*Ts;//CA
				*/
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
		    }  			
//////////////////// SECTOR 4 /////////////////////////////
			if ((alpha>=3 * pi/3)&(alpha<=4 * pi/3))  
			{
				sector=22;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(4*pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-3*pi/3)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(4*pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-3*pi/3)*Ts;//CA
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
		    }  			
//////////////////// SECTOR 5 /////////////////////////////
			if ((alpha>=4 * pi/3)&(alpha<=5 * pi/3))  
			{
				sector=23;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(5*pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-4*pi/3)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(5*pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-4*pi/3)*Ts;//CA
				*/
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
		    }  			
//////////////////// SECTOR 6 /////////////////////////////
			if ((alpha>=5 * pi/3)&(alpha<=6 * pi/3))  
			{
				sector=24;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UCi*sin(6*pi/3-alpha)*Ts;//BA
				T2x = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-5*pi/3)*Ts;//BA
				T1y = (1/1.7320508)*U2/(U1)*UBi*sin(6*pi/3-alpha)*Ts;//CA
				T2y = (1/1.7320508)*U2/(U1)*UBi*sin(alpha-5*pi/3)*Ts;//CA
				*/
				T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
		      }
		}

////////////////////////////// SECTOR 5 ----CB--CA--CB-------- SOURCE

if ((UC2>0) & (UA2<=0) & (UB2<=0)) 
{

	secin=5;
	dx = - UB2/UC2;
	dy = - UA2/UC2;
	Um = dx * (UCi - UBi) + dy * (UCi - UAi);
	Ux = UCi - UAi;
	Uy = UCi - UBi;      	
		//////////////////SECTOR 1/////////////////////

			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=25;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha)*Ts;//CB				
				*/
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		//////////////////SECTOR 2/////////////////////
			 if ((alpha>=pi/3)&(alpha<2 * pi/3))  
			{
				sector=26;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(2*pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-pi/3)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(2*pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-pi/3)*Ts;//CB				
				*/
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		//////////////////SECTOR 3 ////////////////////
			if ((alpha>=2*pi/3)&(alpha<3 * pi/3))  
			{
				sector=27;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(3*pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-2*pi/3)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(3*pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-2*pi/3)*Ts;//CB	
			   */
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		//////////////////SECTOR 4 ////////////////////		
		  if ((alpha>=3 * pi/3)&(alpha < 4 * pi/3))  
			{	
				sector=28;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(4*pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-3*pi/3)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(4*pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-3*pi/3)*Ts;//CB
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
				
	    }
       ////////////////// SECTOR 5 ////////////////////	
			if ((alpha>=4 * pi/3)&(alpha < 5 * pi/3))  
			{
				sector=29;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(5*pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-4*pi/3)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(5*pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-4*pi/3)*Ts;//CB
				*/
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
////////////////// SECTOR 6 ////////////////////	
			if ((alpha>=5 * pi/3)&(alpha < 6 * pi/3))  
			
			{
				sector=30;
				/*
				T1x = -(1/1.7320508)*U2/(U1)*UBi*sin(6*pi/3-alpha)*Ts;//CA
				T2x = -(1/1.7320508)*U2/(U1)*UBi*sin(alpha-5*pi/3)*Ts;//CA
				T1y = -(1/1.7320508)*U2/(U1)*UAi*sin(6*pi/3-alpha)*Ts;//CB
				T2y = -(1/1.7320508)*U2/(U1)*UAi*sin(alpha-5*pi/3)*Ts;//CB
				*/
				T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
	}
/////////////////////////////////// SECTOR 6 ---------AB---CB----AB-- SOURCE

if ((UB2<0) & (UA2>=0) & (UC2>=0)) 
{
	secin=6;

	dx = - UA2/UB2;
	dy = - UC2/UB2;
	Um = dx * (UAi - UBi) + dy * (UCi - UBi);
	Ux = UCi - UBi;
	Uy = UAi - UBi;
		//////////////////SECTOR 1/////////////////////
			if ((alpha>=0)&(alpha<=pi/3))  
			{
				sector=31;	
				/*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(pi/3-alpha)*Ts;
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha)*Ts;
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(pi/3-alpha)*Ts;
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha)*Ts;
				*/
				T1x = k * dx * U2 * sin(pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin( alpha) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		//////////////////SECTOR 2/////////////////////
			 if ((alpha>=pi/3)&(alpha<2 * pi/3))  
			{
				sector=32;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(2*pi/3-alpha)*Ts;//CB
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-pi/3)*Ts;//CB
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(2*pi/3-alpha)*Ts;//AB
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-pi/3)*Ts;//AB
				*/
				T1x = k * dx * U2 * sin(2 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(2 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		/////////////////SECTOR 3 //////////////////// 
			if ((alpha>=2 * pi/3)&(alpha<3 * pi/3))  
			{
				sector=33;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(3*pi/3-alpha)*Ts;//CB
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-2*pi/3)*Ts;//CB
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(3*pi/3-alpha)*Ts;//AB
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-2*pi/3)*Ts;//AB
			    */
				T1x = k * dx * U2 * sin(3 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-2*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(3 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-2*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		//////////////////SECTOR 4 ////////////////////		
		  if ((alpha>=3 * pi/3)&(alpha < 4 * pi/3))  
			{
				sector=34;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(4*pi/3-alpha)*Ts;//CB
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-3*pi/3)*Ts;//CB
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(4*pi/3-alpha)*Ts;//AB
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-3*pi/3)*Ts;//AB
				*/
				T1x = k * dx * U2 * sin(4 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-3*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(4 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-3*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
	        }
		////////////////// SECTOR 5 ////////////////////	
			if ((alpha>=4 * pi/3)&(alpha < 5 * pi/3))  
			{
				sector=35;
				/*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(5*pi/3-alpha)*Ts;//CB
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-4*pi/3)*Ts;//CB
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(5*pi/3-alpha)*Ts;//AB
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-4*pi/3)*Ts;//AB				
				*/
				
				T1x = k * dx * U2 * sin(5 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-4*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(5 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-4*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
		////////////////// SECTOR 6 ////////////////////	
			if ((alpha>=5 * pi/3)&(alpha < 6 * pi/3))  
			{	sector=36;
			   /*
				T1x = (1/1.7320508)*U2/(U1)*UAi*sin(6*pi/3-alpha)*Ts;//CB
				T2x = (1/1.7320508)*U2/(U1)*UAi*sin(alpha-5*pi/3)*Ts;//CB
				T1y = (1/1.7320508)*U2/(U1)*UCi*sin(6*pi/3-alpha)*Ts;//AB
				T2y = (1/1.7320508)*U2/(U1)*UCi*sin(alpha-5*pi/3)*Ts;//AB				
				*/
				T1x = k * dx * U2 * sin(6 * pi/3 - alpha) / Um ;
				T2x = k * dx * U2 * sin(alpha-5*pi/3) / Um;
				//T0x = dx - T1x - T2x;
				T1y = k * dy * U2 * sin(6 * pi/3 - alpha) / Um ; 
				T2y = k * dy * U2 * sin(alpha-5*pi/3) / Um ; 
				//T0y = dy - T1y - T2y;
			}
	}

		step = 0;
}
step = step + 1;

T0x = dx - T1x - T2x;
T0y = dy - T1y - T2y;

if (T1x < 0) TT1x= -T1x;
else TT1x= T1x;

if (T2x < 0) TT2x= -T2x;
else TT2x= T2x;

if (T0x < 0) TT0x= -T0x;
else TT0x= T0x;

if (T1y < 0) TT1y= -T1y;
else TT1y= T1y;;

if (T2y < 0) TT2y= -T2y;
else TT2y= T2y;

if (T0y < 0) TT0y= -T0y;
else TT0y= T0y;


Dx=dx*Ts;
Dy=dy*Ts;
		
//out[0] = Tri;
out[0] = TT1x;
out[1] = TT2x;
out[2] = TT0x;
out[3] = TT1y;
out[4] = TT2y;
out[5] = TT0y;
out[6] = Dx;
out[7] = Dy;
out[8] = sector;
out[9] = U2;
out[10] = Um;
out[11] = alpha;
out[12] = UCi;
}