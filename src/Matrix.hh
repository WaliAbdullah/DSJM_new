#ifndef MATRIX_H
#define MATRIX_H

#include "IMatrix.hh"
#include "NNZTag.hh"
#include "BucketPQ.hh"

#include <iostream>
#include <cmath>
#include "CLI.h"
#include <vector>
#include <bits/stdc++.h>
//#include <boost/dynamic_bitset.hpp>


//test
///
///
/// \todo
//	This class need better namings for the variables.
class Matrix : public IMatrix
{

public:
    ~Matrix();
    Matrix(int M, int N, int nz, bool value);

    int updateDegreesToUVertices(int n, int ic, int u_maxdeg, int *jpntr,int *indRow,int *ipntr,int *indCol,
                                 bool * f_added, int *tag, int *f_tag, int *u_list,
                                 int *u_head, int *u_next, int *u_previous,int *list,int *blackList,const int q);

    // ========================================
    // IMatrix Methods
    bool slo(int *order);

    /**
     * Method ido()
     **/
    bool ido(int *order);
    bool idoDsatur(int *order, int *clique);	
    bool slo_exact(int *order, int *clique);
    bool lfo(int *order);


    
    /*int getColumn();
    //int branchColor(int order,int currentColor, int *color);	
    int branchColor(int order,int currentColor);    
    //bool colorAvailable(int jcol, int colorNo, int *color);	
    bool colorAvailable(int jcol, int colorNo); 
    void satDegInc(int jcol,int order, int colorNo);
    void satDegDec(int jcol,int order, int colorNo);*/		



    bool computedegree();
    int greedycolor(int *list, int *ngrp);
    int rlf(int *ngrp);
    int sdo(int *ngrp);
    int sdo2(int *ngrp);
    int slo_rlf(int *list, int *ngrp);
    //int dsatur(int *ngrp, int *clique, int UB);
    //int dsatur(int *clique, int UB, int tbChoice);    
    int exact(int UB,int *clique,int cliqueChoice,int tbChoice);    
    Matrix* getSeedMatrix(int *ngrp);
    int getNumberOfColors() const;

//=====================================
// Included by Wali
	void ECC_edge(int method);
	void set_priority_vertices();
	void print_graph();  
	void find_neighbors(int v1, int *Neighbors_v1);
    void print_list(int *A, int size);
	void find_common_neighbors(int *Neighbors_v1,int *Neighbors_v2);

    /*Idea from Shahadat sir. Note 1*/
    void getColInd(int i, int &j1, int &j2);
    int  getRowInd(int j1, int j2);
    int intersect(int j1l, int j1u, int j2l, int j2u);

    int Max_Clique;// will be initialized in slo_exact method
//=====================================

    // IMatrix Methods
    // ========================================

private:
    /**
     * Private Constructor
     */
    Matrix();

    int *ndeg;
    int maxi, maxj;
    int rho_max;	
    int numberOfColors; // TODO: Remove

    double *val; // This is supposed to hold the values,
    // Currently we are not using it anywhere.

    int k;
    int v_max_degree;
    int *order;
    int *deg_priority;
    int *Common_Neighbors;
};

#endif
