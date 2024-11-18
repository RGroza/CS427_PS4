//                    -*- mode:c++; tab-width:4 -*-
// modified September 2011; July 2022; September 2024
// file: tools.hpp ---------------------------------------------------
// Header file for the tools library.
// -------------------------------------------------------------------
// Local definitions and portability code.
// Please enter your own name and class.
// -------------------------------------------------------------------
#pragma once
#define NAME    "Patience S. Goodenough"
#define CLASS   "CPSC 427/527"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <utility>

#include <cmath>
#include <ctime>        
#include <cctype>      // for isspace() and isdigit()  

//#include <cstdio>    // for NULL
//#include <cstring>
//#include <cstdlib>   // for malloc() and calloc()
//#include <cstdarg>

using namespace std;

// -------------------------------------------------------------------
// Macros for debugging.
// -------------------------------------------------------------------
#define DUMPp(p) "\n" <<"    " #p " @ " <<&p <<"    value = " <<p <<"    " #p " --> " <<*p 
#define DUMPv(k) "\n" <<"    " #k " @ " <<&k <<"    value = " <<k 

// -------------------------------------------------------------------
// I/O Extension.
// -------------------------------------------------------------------
istream& cleanline(istream& is); // discards remainder of line
istream& flush(istream& is);     // Use: cin >> x >> flush;
ostream& general(ostream& os);   // Use: cout <<fixed <<x <<general<<y;

// -------------------------------------------------------------------
// Routine output labeling. ------------------------------------------
// -------------------------------------------------------------------
void     fbanner( ostream& fout );
void     banner();
void     bye( void );                                    

// -------------------------------------------------------------------
// Error handling ----------------------------------------------------
// -------------------------------------------------------------------
void    fatal( const string& msg );

// -------------------------------------------------------------------
// time and date. ----------------------------------------------------
// -------------------------------------------------------------------
void   when( string& date, string& hour );
string today();
string oclock();
