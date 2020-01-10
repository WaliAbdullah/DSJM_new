#ifndef RESULT_HH
#define RESULT_HH

#include "CLI.h"
#include <iostream>
#include <string>
#include "Configuration.hh"

using namespace std;

class Result
{
public:
    int matrix_M;
    int matrix_N;
    int matrix_NNZ;
    int rowMax;
    int rowAvg;
    int rowMin;
    int colMax;
    int colAvg;
    int colMin;

    bool is_Cseg;
    Configuration* configuration;

    CLI::ordering_method method;

    int totalColors;
    double ordering_time;
    double coloring_time;

    string inputFile;
    string partitionFile;


    void printInfo()
    {
        /*cout << "- " << endl;
        cout << "    commandLine: " << configuration->commandLine << endl;
        cout << "    inputFile: " << inputFile << endl;
        if(is_Cseg)
        {
            if(configuration->is_load_each_row_as_partition)
                cout << "    partitionFile: Load Each Row As Partition" << endl;
            else
                cout << "    partitionFile: " << partitionFile << endl;
            cout << "    segmented: " << "yes" << endl;
        }
        else
            cout << "    segmented: " << "no" << endl; ;

	*/
	//cout << inputFile <<",";
    }

    void printMatrixInfo()
    {
        //cout << "    matrix_M: " << matrix_M << endl;
        //cout << "    matrix_N: " << matrix_N << endl;
        //cout << "    matrix_NNZ: " << matrix_NNZ << endl;

	cout<<"[M, N, nz, Method] = ["<<matrix_M<<","<<matrix_N<<","<<matrix_NNZ<<","<<CLI::method_to_string(configuration->oMethod)<<"]"<<endl;
    }

    void printResult()
    {
	
	// I have a plan to print the clique cover information for my problem.

	//if(ordering_time<0)
	//	ordering_time = 0;
	//cout<<ordering_time<<","<<coloring_time<<","<<totalColors<<endl;
       

    }
};

#endif
