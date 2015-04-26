
// ****************************
// ****** MRT Time Table ******
// *** Xiaobitan to Qizhang ***
// *** 26, JAN 2015 updated ***
// ****************************

// 6 oclock time table
int M61[] = {3, 19, 35, 49, 2};      // Monday to Friday, the last 2 is next first train in next hour(7:02)
int M62[] = {3, 19, 35, 52, 8};      // Saturday, Sunday and holidaies
int M61Size = 5;                      // array size of M61/M62
// 7 oclock time table
int M71[] = {2, 14, 26, 38, 50, 2};  // Monday to Friday
int M72[] = {8, 25, 39, 55, 12};     // Saturday, Sunday and holidaies
int M71Size = 6;                     // array size of M71
int M72Size = 5;                     // array size of M72
// 8 oclock time table
int M81[] = {2, 14, 26, 38, 50, 4};  // Monday to Friday
int M82[] = {12, 29, 46, 2};         // Saturday, Sunday and holidaies
int M81Size = 6;                     // array size of M81
int M82Size = 4;                     // array size of M82
// 9 oclock time table
int M91[] = {4, 21, 37, 53, 9};      // Monday to Friday
int M92[] = {2, 18, 34, 50, 6};      // Saturday, Sunday and holidaies
int M91Size = 5;                     // array size of M91/M92
// 10 oclock time table
int M101[] = {9, 26, 42, 58, 14};     // Monday to Friday
int M102[] = {6, 22, 38, 54, 10};     // Saturday, Sunday and holidaies
int M101Size = 5;                     // array size of M101/M102
// 11 oclock time table
int M111[] = {14, 30, 46, 2};         // Monday to Friday
int M112[] = {10, 26, 42, 58, 14};    // Saturday, Sunday and holidaies
int M111Size = 4;                     // array size of M111
int M112Size = 5;                     // array size of M112
// 12 oclock time table
int M121[] = {2, 18, 34, 50, 6};      // Monday to Friday
int M122[] = {14, 30, 46, 2};         // Saturday, Sunday and holidaies
int M121Size = 5;                     // array size of M121
int M122Size = 4;                     // array size of M122
// 13 oclock time table
int M131[] = {6, 22, 38, 54, 10};     // Monday to Friday
int M132[] = {2, 18, 34, 50, 6};      // Saturday, Sunday and holidaies
int M131Size = 5;                     // array size of M131/M132
// 14 oclock time table
int M141[] = {10, 26, 42, 58, 14};    // Monday to Friday
int M142[] = {6, 22, 38, 54, 9};      // Saturday, Sunday and holidaies
int M141Size = 5;                     // array size of M141/M142
// 15 oclock time table
int M151[] = {14, 30, 46, 2};         // Monday to Friday
int M152[] = {9, 26, 42, 57, 11};     // Saturday, Sunday and holidaies
int M151Size = 4;                     // array size of M151
int M152Size = 5;                     // array size of M152
// 16 oclock time table
int M161[] = {2, 18, 33, 49, 5};      // Monday to Friday
int M162[] = {11, 25, 39, 53, 7};     // Saturday, Sunday and holidaies
int M161Size = 5;                     // array size of M161/M162
// 17 oclock time table
int M171[] = {5, 18, 30, 45, 59, 11}; // Monday to Friday
int M172[] = {7, 21, 35, 49, 3};      // Saturday, Sunday and holidaies
int M171Size = 6;                     // array size of M171
int M172Size = 5;                     // array size of M172
// 18 oclock time table
int M181[] = {11, 23, 35, 47, 59, 12}; // Monday to Friday
int M182[] = {3, 17, 31, 45, 59, 14};  // Saturday, Sunday and holidaies
int M181Size = 6;                      // array size of M181/M182
// 19 oclock time table
int M191[] = {12, 24, 39, 54, 8};     // Monday to Friday
int M192[] = {14, 31, 47, 4};         // Saturday, Sunday and holidaies
int M191Size = 5;                     // array size of M191
int M192Size = 4;                     // array size of M192
// 20 oclock time table
int M201[] = {8, 22, 36, 50, 4};      // Monday to Friday
int M202[] = {4, 21, 37, 54, 11};     // Saturday, Sunday and holidaies
int M201Size = 5;                     // array size of M201/M202
// 21 oclock time table
int M211[] = {4, 18, 32, 46, 0};      // Monday to Friday
int M212[] = {11, 27, 44, 1};         // Saturday, Sunday and holidaies
int M211Size = 5;                     // array size of M211
int M212Size = 4;                     // array size of M212
// 22 oclock time table
int M221[] = {0, 15, 28, 41, 55, 9};  // Monday to Friday
int M222[] = {1, 18, 35, 52, 9};      // Saturday, Sunday and holidaies
int M221Size = 6;                     // array size of M221
int M222Size = 5;                     // array size of M222
// 23 oclock time table
int M231[] = {9, 26, 42, 57, 0};      // Monday to Friday (add 0 for boundary condition)
int M232[] = {9, 26, 42, 57, 0};      // Saturday, Sunday and holidaies (add 0 for boundary condition)
int M231Size = 5;                     // array size of M231/M232

