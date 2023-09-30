Thank you so much for watching this text!!

C and Java Versions work independently.

This is the revision of the former one in terms of the process speed, though one parameter for String type, LanguageKind0, is deleted.

// Copyright and Ownership attribute to GitSystemLab.

// The content helps us change the arguments from double to char array(pointer).

//The code of the included header file has just One loop.

-------------------------------------------------------------------------------------------------------------------------------------------------
[C Version]

The included files are valid mainly for gcc, c++ and cl(Visual Studio Compiler).

char* DoubleToCharArray(double Value0,int DecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumber0,
	int SetDecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumberMarker0,int SetDecimalOrderOrderNumberMarker0,
	int PlusOrMinusSignMarker0,int RoundUpOneDigit0, int IntValueBase0)

/*Value0                                // "double" value which is converted to a "char array".
DecimalOrderOrderNumber0                // The decimal order which is rounded.
SetWholeDigitOrderOrderNumber0          // The whole digit order which is the start of the output char array.
SetDecimalOrderOrderNumber0             // The decimal order which is the end of the output string.
SetWholeDigitOrderOrderNumberMarker0    // The argument which enables us to use the argument, SetWholeDigitOrderOrderNumber0 (0:OFF, Not 0:ON).
SetDecimalOrderOrderNumberMarker0       // The argument which enables us to use the argument, SetDecimalOrderOrderNumber0 (0:OFF, Not 0:ON)
PlusOrMinusSignMarker0                  // 0: No Plus Sign exists when the output value is non-negative. 
                                        // Not 0: Plus Sign exists when the output value is non-negative. 
RoundUpOneDigit0                        // This determines round-up or round-down at the decimal order the argument, DecimalOrderOrderNumber, indicates.
IntValueBase0                           // If IntValueBase0 is 10, output is the decimal. 
                                        // If IntValueBase0 is 16, output is the hexadecimal.
                                        // The output says error where IntValueBase0 <= 1. 
					// The putput is not complement format but decimal format. 
                                        // Note that RoundUpOneDigit0 isn't valid for decimal, especially where IntValueBase0 is not 10.*/

-------------------------------------------------------------------------------------------------------------------------------------------------
[Java Version]

char[] DoubleToCharArray(double Value0,int DecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumber0,
	int SetDecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumberMarker0,int SetDecimalOrderOrderNumberMarker0,
	int PlusOrMinusSignMarker0,int RoundUpOneDigit0, int IntValueBase0)

/*Value0                                // "double" value which is converted to a "char array".
DecimalOrderOrderNumber0                // The decimal order which is rounded.
SetWholeDigitOrderOrderNumber0          // The whole digit order which is the start of the output char array.
SetDecimalOrderOrderNumber0             // The decimal order which is the end of the output string.
SetWholeDigitOrderOrderNumberMarker0    // The argument which enables us to use the argument, SetWholeDigitOrderOrderNumber0 (0:OFF, Not 0:ON).
SetDecimalOrderOrderNumberMarker0       // The argument which enables us to use the argument, SetDecimalOrderOrderNumber0 (0:OFF, Not 0:ON)
PlusOrMinusSignMarker0                  // 0: No Plus Sign exists when the output value is non-negative. 
                                        // Not 0: Plus Sign exists when the output value is non-negative. 
RoundUpOneDigit0                        // This determines round-up or round-down at the decimal order the argument, DecimalOrderOrderNumber, indicates.
IntValueBase0                           // If IntValueBase0 is 10, output is the decimal. 
                                        // If IntValueBase0 is 16, output is the hexadecimal.
                                        // The output says error where IntValueBase0 <= 1. 
					// The putput is not complement format but decimal format. 
                                        // Note that RoundUpOneDigit0 isn't valid for decimal, especially where IntValueBase0 is not 10.*/
-------------------------------------------------------------------------------------------------------------------------------------------------
