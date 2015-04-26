
// ****************************
// ****** MRT Time Table ******
// *** Qizhang to Xiaobitan ***
// *** 26, JAN 2015 updated ***
// ****************************

// 6 oclock time table
int MQ61[] = {11, 27, 43, 56, 9};      // Monday to Friday, the last 9 is next first train in next hour(7:09)
int MQ62[] = {11, 28, 44, 0};          // Saturday, Sunday and holidaies
int MQ61Size = 5;                      // array size of MQ61
int MQ62Size = 4;                      // array size of MQ62
// 7 oclock time table
int MQ71[] = {9, 21, 33, 45, 57, 9};  // Monday to Friday
int MQ72[] = {0, 16, 32, 49, 5};      // Saturday, Sunday and holidaies
int MQ71Size = 6;                     // array size of MQ71
int MQ72Size = 5;                     // array size of MQ72
// 8 oclock time table
int MQ81[] = {9, 21, 33, 45, 57, 11}; // Monday to Friday
int MQ82[] = {5, 22, 39, 55, 11};     // Saturday, Sunday and holidaies
int MQ81Size = 6;                     // array size of MQ81
int MQ82Size = 5;                     // array size of MQ82
// 9 oclock time table
int MQ91[] = {11, 28, 45, 1};         // Monday to Friday
int MQ92[] = {11, 27, 43, 59, 15};    // Saturday, Sunday and holidaies
int MQ91Size = 4;                     // array size of MQ91
int MQ92Size = 5;                     // array size of MQ92
// 10 oclock time table
int MQ101[] = {1, 18, 35, 51, 7};     // Monday to Friday
int MQ102[] = {15, 31, 47, 3};        // Saturday, Sunday and holidaies
int MQ101Size = 5;                    // array size of MQ101
int MQ102Size = 4;                    // array size of MQ102
// 11 oclock time table
int MQ111[] = {7, 23, 39, 55, 11};     // Monday to Friday
int MQ112[] = {3, 19, 35, 51, 7};      // Saturday, Sunday and holidaies
int MQ111Size = 5;                     // array size of MQ111/MQ112
// 12 oclock time table
int MQ121[] = {11, 27, 43, 59, 15};    // Monday to Friday
int MQ122[] = {7, 23, 39, 55, 11};     // Saturday, Sunday and holidaies
int MQ121Size = 5;                     // array size of MQ121/MQ122
// 13 oclock time table
int MQ131[] = {15, 31, 47, 3};         // Monday to Friday
int MQ132[] = {11, 27, 43, 59, 15};    // Saturday, Sunday and holidaies
int MQ131Size = 4;                     // array size of MQ131
int MQ132Size = 5;                     // array size of MQ132
// 14 oclock time table
int MQ141[] = {3, 19, 35, 51, 7};      // Monday to Friday
int MQ142[] = {15, 31, 47, 3};         // Saturday, Sunday and holidaies
int MQ141Size = 5;                     // array size of MQ141
int MQ142Size = 4;                     // array size of MQ142
// 15 oclock time table
int MQ151[] = {7, 23, 39, 55, 11};     // Monday to Friday
int MQ152[] = {3, 19, 35, 51, 5};      // Saturday, Sunday and holidaies
int MQ151Size = 5;                     // array size of MQ151/MQ152
// 16 oclock time table
int MQ161[] = {11, 27, 43, 58, 13};    // Monday to Friday
int MQ162[] = {5, 19, 33, 47, 1};      // Saturday, Sunday and holidaies
int MQ161Size = 5;                     // array size of MQ161/MQ162
// 17 oclock time table
int MQ171[] = {13, 25, 40, 54, 6};     // Monday to Friday
int MQ172[] = {1, 15, 29, 43, 57, 11}; // Saturday, Sunday and holidaies
int MQ171Size = 5;                     // array size of MQ171
int MQ172Size = 6;                     // array size of MQ172
// 18 oclock time table
int MQ181[] = {6, 18, 30, 42, 54, 6};  // Monday to Friday
int MQ182[] = {11, 25, 39, 53, 7};     // Saturday, Sunday and holidaies
int MQ181Size = 6;                      // array size of MQ181
int MQ182Size = 5;                      // array size of MQ182
// 19 oclock time table
int MQ191[] = {6, 19, 31, 46, 1};      // Monday to Friday
int MQ192[] = {7, 23, 40, 57, 14};     // Saturday, Sunday and holidaies
int MQ191Size = 5;                     // array size of MQ191/MQ192
// 20 oclock time table
int MQ201[] = {1, 16, 30, 44, 58, 12}; // Monday to Friday
int MQ202[] = {14, 30, 47, 4};         // Saturday, Sunday and holidaies
int MQ201Size = 6;                     // array size of MQ201
int MQ202Size = 4;                     // array size of MQ202
// 21 oclock time table
int MQ211[] = {12, 26, 40, 54, 8};     // Monday to Friday
int MQ212[] = {4, 20, 37, 54, 10};     // Saturday, Sunday and holidaies
int MQ211Size = 5;                     // array size of MQ211/MQ212
// 22 oclock time table
int MQ221[] = {8, 22, 36, 48, 1};      // Monday to Friday
int MQ222[] = {10, 27, 44, 1};         // Saturday, Sunday and holidaies
int MQ221Size = 5;                     // array size of MQ221
int MQ222Size = 4;                     // array size of MQ222
// 23 oclock time table
int MQ231[] = {1, 18, 35, 52, 9};      // Monday to Friday
int MQ232[] = {1, 18, 35, 52, 9};      // Saturday, Sunday and holidaies (add 0 for boundary condition)
int MQ231Size = 5;                     // array size of MQ231/MQ232
// 00 oclock time table
int MQ241[] = {9, 11};                 // Monday to Friday (add 11 for boundary condition)
int MQ242[] = {9, 11};                 // Saturday, Sunday and holidaies (add 11 for boundary condition)
int MQ241Size = 2;                     // array size of MQ241/MQ242
