#include<iostream>

using namespace std;

void stateA(uint8_t *A, uint8_t* ind, uint8_t* csum, uint8_t* ns)
{
	if(A[*ind]==0)
	{
		A[*ind]=1;
		*csum+=1;
		*ind+=1;
		*ns = 1;
	}
	else
	{
		A[*ind]=0;
		*csum-=1;
		*ind-=1;
		*ns = 1;
	}
}

void stateB(uint8_t *A, uint8_t* ind, uint8_t* csum, uint8_t* ns)
{
        if(A[*ind]==0)
	 {
		 A[*ind]=1;
		 *csum+=1;
		 *ind-=1;
		 *ns = 0;
	 }
	else
	{
		A[*ind]=1;
		*ind+=1;
		*ns = 0;
	}
}

typedef enum State
{
state_A,
state_B,
state_C,
state_D,
state_E,
state_F	
};

int main()
{
	uint8_t A[20] = {0};
	uint8_t ind = 10;
	uint8_t chksum = 0;

	uint8_t next_state = 0; // 0 for A, 1 for B

	for(uint8_t step_c = 0; step_c <=6; step_c++)
	{
		//Begin in State A
		printf ("curr indx: %u",ind);
		for(uint8_t idx=0;idx<20;idx++)
		{
			printf("[%u] ",A[idx]);
		}
		printf("\n");

		if(next_state == 0)
			stateA(A,&ind,&chksum,&next_state);
		else
			stateB(A,&ind,&chksum,&next_state);

	}

	printf("chksum: %u\n",chksum);

//	cout<<"checksum:"<<chksum;
}


