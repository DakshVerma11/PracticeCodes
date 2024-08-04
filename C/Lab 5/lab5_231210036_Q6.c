
/* Assume yourself as a Programmer in TATA Power DDL. Write a C program to calculate 
the total electricity bill for Delhi customers, according to the given condition for 
ELECTRICITY TARIFF using Delhi Government rules for TATA Power DDL:
 *
 * Code by : Daksh Verma
 * Roll No : 231210036*/

#include <stdio.h>



int main(){

	float custID,billperiod,sanctioned_load,units_consumed,fixed_charge,subsidy,charge,surcharge,net;

	char name[20],conn;
	//Taking Input
	
	printf("Input Customer ID\t\t\t\t: ");
	scanf("%f",&custID);

	
	printf("Input the name of the Customer\t\t\t: ");
	scanf(" %[^\n]s", name);

	
	printf("Input Bill Period (Months)\t\t\t: ");
	scanf("%f",&billperiod);

	
	
	printf("Input the Type of connection Domestic (D) / Non-Domestic \n (N), Industrial (I) and Agriculture(A))\t: ");
	scanf(" %c",&conn);
	
	printf("Input the Sanctioned Load (KW/KVA)\t\t: ");
	scanf("%f",&sanctioned_load);

	
	printf("Input the unit used/consumed by the customer\t: ");
	scanf("%f",&units_consumed);
	
	//Printing Bill
	
	printf("\n\n\n\n\n\n\n");
	printf("**************************************************************\n");
	printf("\t\t\tTATA Power DDL\n\t\tBill of Supply for Electricity\n");
	printf("**************************************************************\n");
	
	printf("Customer IDNO\t\t\t\t\t:%.0f\n",custID);
	printf("Customer Name\t\t\t\t\t:%s\n",name);
	printf("Bill Period (Months)\t\t\t\t:%.0f\n",billperiod);
	printf("Type of Connection\t\t\t\t:%c\n",conn);
	printf("Sanctioned Load (KW/KVA)\t\t\t:%.2f\n",sanctioned_load);
	printf("Units Consumed\t\t\t\t\t:%.2f\n\n",units_consumed);
	
	
	
	//Defining Fixed Charges, Energy Charges and subsidy for Domestic Customers
	if (conn=='D')
	{

	if (sanctioned_load<=2)
		{
		fixed_charge=20*sanctioned_load*billperiod;
		printf("\nFixed Charge :%.2f x 20 x %.0f\t\t\t:%.2f",sanctioned_load,billperiod,fixed_charge);
		}
		
	if (sanctioned_load>2&&sanctioned_load<=5)
		{
		fixed_charge=50*sanctioned_load*billperiod;
		printf("\nFixed Charge :%.2f x 50 x %.0f\t\t\t:%.2f",sanctioned_load,billperiod,fixed_charge);
		}
		
	if (sanctioned_load>5&&sanctioned_load<=15)
		{
		fixed_charge=100*sanctioned_load*billperiod;
		printf("\nFixed Charge :%.2f x 100 x %.0f\t\t\t:%.2f",sanctioned_load,billperiod,fixed_charge);
		}
		
	if (sanctioned_load>15&&sanctioned_load<=25)
		{
		fixed_charge=200*sanctioned_load*billperiod;
		printf("\nFixed Charge :%.2f x 200 x %.0f\t\t\t:%.2f",sanctioned_load,billperiod,fixed_charge);
		}
		
	if (sanctioned_load>25)
		{
		fixed_charge=250*sanctioned_load*billperiod;
		printf("\nFixed Charge :%.2f x 250 x %.0f\t\t\t:%.2f",sanctioned_load,billperiod,fixed_charge);
		}
		
		
		
		
	int unit_case;
	
	unit_case=(units_consumed-1)/200;
	printf("\n\nUnits\tRate (Rs.)\t\t\tAmount (Rs.)\n\n");
	switch (unit_case)
	{
	case 0:
		charge+=3*units_consumed;
		printf("%.2f\t@Rs. 3.00/unit\t\t%.2f\n",units_consumed,charge);
		subsidy=charge;
		break;
	case 1:
		charge+=3*200;
		charge+=4.5*(units_consumed-200);
		printf("%200 \t@Rs. 3.00/unit\t\t600\n");
		printf("%.2f \t@Rs. 4.50/unit\t\t%.2f\n",units_consumed-200,4.5*(units_consumed-200));
		subsidy=800;
		break;
	case 2:
	case 3:
		charge+=3*200;
		charge+=4.5*200;
		charge+=6.5*(units_consumed-400);
		printf("%200 \t@Rs. 3.00/unit\t\t600\n");
		printf("%200 \t@Rs. 4.50/unit\t\t900\n");
		printf("%.2f \t@Rs. 6.50/unit\t\t%.2f\n",units_consumed-400,6.5*(units_consumed-400));
		break;
	case 4:
	case 5:
		charge+=3*200;
		charge+=4.5*200;
		charge+=6.5*400;
		charge+=7*(-800+units_consumed);
		printf("%200 \t@Rs. 3.00/unit\t\t600\n");
		printf("200 \t@Rs. 4.50/unit\t\t900\n");
		printf("%400 \t@Rs. 6.50/unit\t\t2600\n");
		printf("%.2f \t@Rs. 7.00/unit\t\t%.2f\n",units_consumed-800,7*(units_consumed-800));
		break;
	default:
		charge+=3*200;
		charge+=4.5*200;
		charge+=6.5*400;
		charge+=7*400;
		charge+=8*(units_consumed-1200);
		printf("%200 \t@Rs. 3.00/unit\t\t600\n");
		printf("%200 \t@Rs. 4.50/unit\t\t900\n");
		printf("%400 \t@Rs. 6.50/unit\t\t2600\n");
		printf("%400 \t@Rs. 7.00/unit\t\t2800\n");
		printf("%.2f \t@Rs. 8.00/unit\t\t%.2f\n",units_consumed-1200,8*(units_consumed-1200));
		break;
	}
	
	}
	//Defining Fixed Charges, Energy Charges and subsidy for Non Domestic Customers
	if (conn=='N')
	{
	if (sanctioned_load<=3)
		{
		fixed_charge=250*sanctioned_load*billperiod;
		charge=6*units_consumed;
		}
	else
		{
		fixed_charge=250*sanctioned_load*billperiod;
		charge=8.5*units_consumed;
		}
	}
	
	//Defining Fixed Charges, Energy Charges and subsidy for Industrial Customers
	if (conn=='I')
	{
	fixed_charge=250*sanctioned_load*billperiod;
	charge=7.75*(float)units_consumed;
	}
	
	//Defining Fixed Charges, Energy Charges and subsidy for Agricultural Customers
	if (conn=='A')
	{
	fixed_charge=125*sanctioned_load*billperiod;
	charge=1.5*(float)units_consumed;
	}
	
	printf("\nTotal Energy Charge \t\t\t\t:%.2f\n\n",charge);
	
	surcharge = 0.16*charge;
	net=surcharge+charge+fixed_charge;
	
	
	printf("\nSurcharge Amount @16% \t\t\t\t:%.2f",surcharge);
	printf("\nNet current demand \t\t\t\t:%.2f",net);
	printf("\nSubsidy \t\t\t\t\t:%.2f",subsidy);
	printf("\n=============================================================");
	
	printf("\nNet Amount to be paid by the customer \t\t:%.2f\n",net-subsidy);
	printf("\n=============================================================\n\n");
	


	return 0;

}
