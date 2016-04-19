#include <iostream>
#include <stdlib.h>

void set_array();    			//sets initial array for water movement
void print_array(int i, int b);  		//displays  array on screen
void water();        			//the logic for the water animation (texture)
void rules();	    			 //logic for the water movement
void set_array2();  			 //sets array for water animation

const int le = 50; 			 //size of arrays -bad name
int arr[le][le];    			//water movement
int arr2[le][le];  			 //water texture animation

int main()
{	
	system("clear");		//system call -bad
	set_array();
	set_array2();
	
	int b=2;
	for(int i = 0; i < 340; i++ )
	{
		if((i%3 == 0 || i%5 == 0) && i< 170){ set_array2(); }  
		if(i> 169)
		{	if(i%10 == 0){b+=1;}
			if(i%b == 0)
			{set_array2();}
		}
		
		rules();		  //this will determine the area of water 
		water(); 		 //determines the water texture animation 
		print_array(i, b); 	 //prints out water texure animation constrained by the area of water
		
		system("sleep 0.15");   //controls animation speed
		system("clear"); 	 //refresh screen
	}
}

void set_array()
{
	for(int i=0; i < le; i++)
	{
		for(int j = 0; j < le; j++)
		{
			arr[i][j] = -1;
		}
	}
	
	//set 'the seed' for rules() to work (See README)
	arr[0][1]=1;
	arr[3][3]=1;
	arr[2][2]=1;
	arr[2][3]=1;
	arr[1][1]=1;
	arr[2][0]=1;
}

void set_array2()
{	
	arr2[0][0]=1;
	arr2[0][1]=1;
	arr2[1][0]=1;
	arr2[1][2]=1;
}

void rules()          //see README for full details of the rules applied here
{	
	int x;
	int n;
	
	for(int i = 0; i < le; i++)
	{
		for(int j = 0; j < le; j++)
		{	
			n = 0;
			if(arr[i][j] == -1 || arr[i][j] == 0){ x = 0; }
			if(arr[i][j] == 1){ x = 1; }
			
			if(i < le)
			{
				if(arr[i + 1][j] == 1){ n+=1; }	
			}
			if(i > 0)
			{
				if(arr[i - 1][j] == 1){ n+=1; }
			}	
			if(j < le)
			{	
				if(arr[i][j+1] == 1){ n+=1; }	
			}
			if(j > 0)
			{
				if(arr[i][j-1] == 1){ n+=1; }	
			}
			if(i < le && j < le)
			{
				if(arr[i + 1][j + 1] == 1){ n+=1; }
			}
			if(i < le && j > 0)
			{
				if(arr[i + 1][j - 1] == 1){ n+=1; }
			}
			if(i > 0 && j < le)
			{
				if(arr[i - 1][j + 1] == 1){ n+=1; }
			}
			if(i > 0 && j > 0)
			{
				if(arr[i - 1][j - 1] == 1){ n+=1; }
			}
			
			if(x == 0)
			{
				if(n == 3){ arr[i][j] = 1; }
			}
			else if(x == 1)
			{
				if(n < 2){ arr[i][j] = 0; }
				if(n == 2 || n == 3){ arr[i][j] = 1; }
				if(n > 3){ arr[i][j] = 2; }
			}	
		}
	}
}

void water()
{	
	int x;
	int n;
	
	for(int i = 0; i < le; i++)
	{
		for(int j = 0; j < le; j++)
		{	
			if(arr[i][j] == -1){arr2[i][j] = -1;}
			
			if(arr[i][j] != -1)
			{
				n = 0;
				if(arr2[i][j] == 0 || arr2[i][j] == -1){ x = 0; }
				if(arr2[i][j] == 1){ x = 1; }


				if(i > 0)
				{
					if(arr2[i - 1][j] == 1){ n=2; }
				}	

				if(j > 0)
				{
					if(arr2[i][j-1] == 1){ n=2; }	
				}


				if(i > 0 && j > 0)
				{
					if(arr2[i - 1][j - 1] == 1){ n=2; }
				}

				if(arr2[i][j] == 0 || arr2[i][j] == -1)
				{
					arr2[i][j] = n;
				}
			}	
		}
	}
	
	for(int i = 0; i < le; i++)
	{
		for(int j = 0; j < le; j++)
		{
			if(arr2[i][j]==1){ arr2[i][j] = 0; }
		}
	}
	
	for(int i = 0; i < le; i++)
	{
		for(int j = 0; j < le; j++)
		{
			if(arr2[i][j]==2){ arr2[i][j] = 1; }
		}
	}
}

void print_array(int i, int b)
{
	
	if(i<200)	//water flowing from tap animation
	{
		if(i%2==0)
		{
			std::cout<<"   ||/ \\||  "<<std::endl;
			std::cout<<"     \\ /    "<<std::endl;
			std::cout<<"     / \\   "<<std::endl;
		}
		else
		{
			std::cout<<"   ||\\ /||  "<<std::endl;
			std::cout<<"     / \\    "<<std::endl;
			std::cout<<"     \\ /    "<<std::endl;
		}
	}
	
	if(i> 199)	//tap turned off, water drop animation
	{	
	 
		int A = i + 2;
		int B = i + 1;
		int C = i ;
	 
		
		if(i%b == 0)
		{
			std::cout<<"   ||   ||  "<<std::endl;
			std::cout<<"             "<<std::endl;
			std::cout<<"   ' () '  "<<std::endl;
		}
	 
		
	 	
	 
	 	else if(A%b == 0)
		{
			std::cout<<"   ||() ||  "<<std::endl;
			std::cout<<"            "<<std::endl;
			std::cout<<"            "<<std::endl;
		}
	 
	 
	 	else if(B%b == 0)
		{
			std::cout<<"   ||   ||  "<<std::endl;
			std::cout<<"     ()     "<<std::endl;
			std::cout<<"            "<<std::endl;
		}
		
		else
		{
			std::cout<<"   ||   ||  "<<std::endl;
			std::cout<<"             "<<std::endl;
			std::cout<<"             "<<std::endl;
		}
	 
	}
	
	
	for(int i = 0; i < le; i++)  	//water puddle animation
	{
		for(int j = 0; j < le; j++)
		{
			if(arr2[i][j] == 0)
			{
				std::cout<<" - ";
			}
			if(arr2[i][j] == 1)
			{
				std::cout<<" 0 ";
			}
			if(arr2[i][j] == -1)
			{
				std::cout<<"   ";
			}
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}
