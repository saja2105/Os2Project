//Done By : Saja Saadoun 2019/04826 - Nathalie Sameh 2019/05320
//Memory Allocation Simulator 

#include <iostream>
using namespace std;
//----------------------------------------------FIRST FIT------------------------------------//
void FirstFit() {

	cout << endl;
	cout << "\t\t\t\t First Fit Algorithm" << endl;
	cout << endl;

	int Bsize[20], Psize[20], Bnum, Pnum, flags[20], allocation[20];

	int ii = 0;
	while (ii < 20)
	{
		flags[ii] = 0; //the flags target the blocks as it mark the flag 1 it's not empty
		allocation[ii] = -1; // allocation targets the blocks and tells which process is allocated in which block
		ii++;
	}

	cout << "Insert the desired number of blocks please:";
	cin >> Bnum;  //Insert the desired  b numbers 
	cout << endl; //new_line 
	cout << "Insert the desired number of processes please:";
	cin >> Pnum; //Insert the desired  p numbers 
	cout << endl; //new_line 
	cout << "Insert the desired the size of the blocks please :" << endl;
	for (int v = 0; v < Bnum; v++) // loop to insert all the block values
	{
		cout << "Insert the desired Block Number" << v << ":"; //blocks values 
		cin >> Bsize[v];
	}
	cout << endl;//new_line 
	cout << "\nInsert the desired size processes please :- " << endl;
	for (int z = 0; z < Pnum; z++) // loop to insert all the process values
	{
		cout << "Insert the desired Procces sizes please " << z << ":";
		cin >> Psize[z]; //process values 
	}
	cout << endl;//new_line 


	int s = 0;
	while (s < Pnum)  //while loop for the procces number 
	{
		int n = 0;
		while (n < Bnum) { // while loop for the block number 

			if (flags[n] == 0 && Bsize[n] >= Psize[s])// allocate the process in the block only if the flag is 0 which means we don't have anything allocated in this
				//block and if the block is larger than the process size.  (the first one come that have this conditions)
			{

				allocation[n] = s; // allocated the process in the block
				flags[n] = 1; // make the flag =1 because it's not empty
				break;
			}
			n++;
		}
		s++;
	}
	//the output table
	cout << "\nBlockkNumber\tBlockkSize\tProccessNumber\t\tProccessSize";
	for (int c = 0; c < Bnum; c++)
	{
		cout << "\n" << c + 1 << "\t\t" << Bsize[c] << "\t\t";
		if (flags[c] == 1)
			cout << allocation[c] + 1 << "\t\t\t" << Psize[allocation[c]];
		else
			cout << "Nott_allocated"; //if the process has no place to allocate 
	}
	cout << "\n\n\n";
}

//-------------------------------------------------BEST FIT----------------------------------------------//

void BestFit() {
	cout << endl;
	cout << "\t\t\t\t Best Fit Algorithm \n";
	int Bsize[20], Psize[20], Bnum, Pnum, flags[20], allocation[20]; //requirments 

	int ii = 0;
	while (ii < 20)
	{
		flags[ii] = 0; //the flags target the blocks as it mark the flag 1 it's not empty
		allocation[ii] = -1; // allocation targets the blocks and tells which process is allocated in which block
		ii++;
	}

	cout << endl;//new line 

	cout << "Insert the desired number of blocks please:";
	cin >> Bnum;  //to insert the block numbers 
	cout << endl;//new_line 
	cout << "Insert the desired number of processes please:";
	cin >> Pnum; //to insert the process numbers 
	cout << endl;//new_line 
	cout << "Insert the desired size of the blocks please :" << endl;
	for (int a = 0; a < Bnum; a++) // loop to insert all the block values
	{
		cout << "Enter the Block Number" << a << ":"; //block values 
		cin >> Bsize[a];
	}
	cout << endl;
	cout << "\nEnter the size of the processes please :- " << endl;
	for (int b = 0; b < Pnum; b++) // loop to insert all the process values
	{
		cout << "Enter the Procces sizes please " << b << ":";	//process values 
		cin >> Psize[b];
	}
	cout << endl;//new_line 


	int e = 0;
	while (e < Pnum) //loop for processes
	{
		int temp = 0, temp2 = -1;
		int w = 0;
		while (w < Bnum) //loop for blocks
		{
			if (flags[w] == 0 && Psize[e] == Bsize[w] || (Psize[e] <= Bsize[w] && (Bsize[w] <= temp || temp == 0)))//2 condition the first is the flag is 0 which means it's empty to be allocated and if the process size = the block size (because it's the best fit) or the second 
				//the process size is smaller than the block size and the blocksize is less than the temp which carries the value of the last block or the temp to be=0

			{
				temp = Bsize[w]; //the temp carries the value of the block size
				temp2 = w; //carry the block number
			}
			w++;
		}

		if (temp2 != -1) // if the temp2 is not equal to -1
		{
			allocation[temp2] = e; //  allocat the process[i] to the block location(temp2)
			flags[temp2] = 1;  //make the flag=1 of the filled block
		}
		temp2 = -1; //reset the temp2 to -1 to enter the loop for the next process and also reset the temp to 0
		temp = 0;

		e++;
	}

	//The output table 
	cout << "\nBlockkNumber\tBlockkSize\tProccessNumber\t\tProccessSize"; //first of the table 
	for (int u = 0; u < Bnum; u++)
	{
		cout << "\n" << u + 1 << "\t\t" << Bsize[u] << "\t\t";
		if (flags[u] == 1)
			cout << allocation[u] + 1 << "\t\t\t" << Psize[allocation[u]]; // to display the results 
		else
			cout << "Nott_allocated"; //if the process in bigger than the available blocks 
	}
	cout << "\n\n\n";
}

//-------------------------------------WORST FIT--------------------------------//

void WorstFit()
{
	cout << endl; //new_line 
	cout << "\t\t\t\t Worst Fit Algorithm \n";
	cout << endl;//new_line  

	int Bsize[20], Psize[20], Bnum, Pnum, flags[20], allocation[20]; //code variables 
	int ii = 0;
	while (ii < 20)
	{
		flags[ii] = 0; //the flags target the blocks as it mark the flag 1 it's not empty
		allocation[ii] = -1; // allocation targets the blocks and tells which process is allocated in which block
		ii++;
	}

	cout << "Insert the desired number of blocks please:";
	cin >> Bnum;  //to insert the block numbers 
	cout << endl;//new_line  
	cout << "Insert the desired number of processes please:";
	cin >> Pnum; //to insert the process numbers 
	cout << endl;//new_line 
	cout << "Insert the desired  size of the blocks please :" << endl;
	for (int l = 0; l < Bnum; l++) // loop to insert all the block values
	{
		cout << "Insert the desired  Block Number" << l << ":";
		cin >> Bsize[l];
	}
	cout << endl;
	cout << "\nInsert the desired size of the processes please :- " << endl;
	for (int k = 0; k < Pnum; k++) // loop to insert all the process values
	{
		cout << "Insert the desired Procces sizes please " << k << ":";
		cin >> Psize[k];
	}
	cout << endl;//new_line 



	int q = 0;
	while (q < Pnum)
	{
		int temp2 = -1, temp = 0, p = 0;
		while (p < Bnum)
		{
			if (flags[p] == 0 && Bsize[p] >= temp && Bsize[p] >= Psize[q]) // the condition is the flag =0 which means that the block is empty to be allocated 
				// and the blocksize will be greater than the temp=the value that carries and the blocksize be larger than the process size so it can carries it
			{
				temp = Bsize[p]; // allocate the block size to the temp
				temp2 = p; //carry the block number
			}
			p++;
		}

		if (temp2 != -1) // if the temp2 is not equal to -1
		{
			allocation[temp2] = q; //  allocat the process[i] to the block location(temp2)
			flags[temp2] = 1; //make the flag=1 of the filled block
		}
		temp2 = -1; //reset the temp2 to -1 to enter the loop for the next process and also reset the temp to 0
		q++;
	}

	//the output table
	cout << "\nBlockkNumber\tBlockkSize\tProccessNumber\t\tProccessSize";
	for (int r = 0; r < Bnum; r++)
	{
		cout << "\n" << r + 1 << "\t\t" << Bsize[r] << "\t\t";
		if (flags[r] == 1)
			cout << allocation[r] + 1 << "\t\t\t" << Psize[allocation[r]];
		else
			cout << "Nott_allocated"; //the process isn't allocated
	}
	cout << "\n\n\n";
}


int main()
{
	int check;
	cout << endl; //new_line 
	cout << "\t\t\t\t\tMemory Allocation Simulator " << endl;
	cout << endl; //new_line 
	cout << "\t\tFirst Fit \t\t\t Best Fit \t\t\t Worst Fit" << endl;
	cout << endl; //new_line 
	char c;
	cout << "Enter f:for the First Fit , b:For the Best Fit and w:for Worst Fit Algorithms:  ";
	while (true) {
		cin >> c;
		char choice = ::tolower(c); // to cast any character to lower case
		if (choice == 'f') {
			FirstFit();
		}
		else if (choice == 'b') {
			BestFit();
		}
		else if (choice == 'w') {
			WorstFit();
		}
		else { break; }
		cout << endl;
		cout << "if you want to try another allocation type enter it's letter or any other letter to exit" << endl;
	}
	return 0;
}