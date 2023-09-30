#include<stdio.h>
#include<stdlib.h>

char* DoubleToCharArray(double Value0,int DecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumber0,
		int SetDecimalOrderOrderNumber0,int SetWholeDigitOrderOrderNumberMarker0,int SetDecimalOrderOrderNumberMarker0,
		int PlusOrMinusSignMarker0,int RoundUpOneDigit0, int IntValueBase0){
			
		const char StringDotOperator[] = ".";
		const char StringPlusSignOperator[] = "+";
		const char StringMinusSignOperator[] = "-";
		const char StringNullDigit[] = "NULL";
		const char StringCarryUpDigit[] = "1";
		const char StringPrefixDigit[] = "0";
		const char StringSuffixDigit[] = "0";
		const char StringZeroNormalDigit[] = "0";
		const char StringOneNormalDigit[] = "1";
		const char StringTwoNormalDigit[] = "2";
		const char StringThreeNormalDigit[] = "3";
		const char StringFourNormalDigit[] = "4";
		const char StringFiveNormalDigit[] = "5";
		const char StringSixNormalDigit[] = "6";
		const char StringSevenNormalDigit[] = "7";
		const char StringEightNormalDigit[] = "8";
		const char StringNineNormalDigit[] = "9";
		const char StringANormalDigit[] = "A";
		const char StringBNormalDigit[] = "B";
		const char StringCNormalDigit[] = "C";
		const char StringDNormalDigit[] = "D";
		const char StringENormalDigit[] = "E";
		const char StringFNormalDigit[] = "F";
			
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//In stead of a series of the previous char arrays, the followings can be used.
		//The former version allows us to switch the arguments.
		//However I decided to delete the trait of the function in order to obtain faster one.
		//In stead of the char arrays above, you can arrange the char arrays below except that StringNullDigit = "".
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/*const char StringDotOperator[] = "<.>";
		const char StringPlusSignOperator[] = "[Plus]";
		const char StringMinusSignOperator[] = "[Minus]";
		const char StringNullDigit[] = "{NULL}";
		const char StringCarryUpDigit[] = "[CarryUpDigitOne]";
		const char StringPrefixDigit[] = "<Prefix Digit>";
		const char StringSuffixDigit[] = "<Suffix Digit>";
		const char StringZeroNormalDigit[] = "Zero";
		const char StringOneNormalDigit[] = "One";
		const char StringTwoNormalDigit[] = "Two";
		const char StringThreeNormalDigit[] = "Three";
		const char StringFourNormalDigit[] = "Four";
		const char StringFiveNormalDigit[] = "Five";
		const char StringSixNormalDigit[] = "Six";
		const char StringSevenNormalDigit[] = "Seven";
		const char StringEightNormalDigit[] = "Eight";
		const char StringNineNormalDigit[] = "Nine";
		const char StringANormalDigit[] = "<A>";
		const char StringBNormalDigit[] = "{B}";
		const char StringCNormalDigit[] = "((C))";
		const char StringDNormalDigit[] = "[D]";
		const char StringENormalDigit[] = "#E#";
		const char StringFNormalDigit[] = "&F&";*/
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		const int UndefinedApplicationTokenType = 0;
		const int DigitApplicationTokenType = 1;
		const int NullDigitApplicationTokenType = 2;
		const int SuffixDigitApplicationTokenType = 3;
		const int PrefixDigitApplicationTokenType = 4;
		const int CarryUpDigitApplicationTokenType = 5;
		const int MinusSignOperatorApplicationTokenType = 6;
		const int PlusSignOperatorApplicationTokenType = 7;
		const int DotOperatorApplicationTokenType = 8;
		const int MaxParameterApplicationTokenType = 8;

		const int UndefinedApplicationTokenSubStringNumber = 0;
		const int ZeroNormalDigitApplicationTokenSubStringNumber = 1;
		const int OneNormalDigitApplicationTokenSubStringNumber = 2;
		const int TwoNormalDigitApplicationTokenSubStringNumber = 3;
		const int ThreeNormalDigitApplicationTokenSubStringNumber = 4;
		const int FourNormalDigitApplicationTokenSubStringNumber = 5;
		const int FiveNormalDigitApplicationTokenSubStringNumber = 6;
		const int SixNormalDigitApplicationTokenSubStringNumber = 7;
		const int SevenNormalDigitApplicationTokenSubStringNumber = 8;
		const int EightNormalDigitApplicationTokenSubStringNumber = 9;
		const int NineNormalDigitApplicationTokenSubStringNumber = 10;
		const int ANormalDigitApplicationTokenSubStringNumber = 11;
		const int BNormalDigitApplicationTokenSubStringNumber = 12;
		const int CNormalDigitApplicationTokenSubStringNumber = 13;
		const int DNormalDigitApplicationTokenSubStringNumber = 14;
		const int ENormalDigitApplicationTokenSubStringNumber = 15;
		const int FNormalDigitApplicationTokenSubStringNumber = 16;
		const int MaxNormalDigitApplicationTokenSubStringNumber = 16;
		const int NullDigitApplicationTokenSubStringNumber = 1;
		const int MaxNullDigitApplicationTokenSubStringNumber = 1;
		const int SuffixDigitApplicationTokenSubStringNumber = 1;
		const int MaxSuffixDigitApplicationTokenSubStringNumber = 1;
		const int PrefixDigitApplicationTokenSubStringNumber = 1;
		const int MaxPrefixDigitApplicationTokenSubStringNumber = 1;
		const int CarryUpDigitApplicationTokenSubStringNumber = 1;
		const int MaxCarryUpDigitApplicationTokenSubStringNumber = 1;
		const int MinusSignOperatorApplicationTokenSubStringNumber = 1;
		const int MaxMinusSignOperatorApplicationTokenSubStringNumber = 1;
		const int PlusSignOperatorApplicationTokenSubStringNumber = 1;
		const int MaxPlusSignOperatorApplicationTokenSubStringNumber = 1;
		const int DotOperatorApplicationTokenSubStringNumber = 1;
		const int MaxDotOperatorApplicationTokenSubStringNumber = 1;
			
		const int DoubleToCharArrayMaxLoopTimeModulo2Plus1 = 2;
			
		const int UndefinedApplicationOrderType = 0;
		const int UndefinedApplicationOrderKind = 0;
		const int DecimalOrderOrderNumberValueApplicationOrderType = 1;
		const int WholeDigitOrderOrderNumberValueApplicationOrderType = 2;
		const int CarryUpDigitValueApplicationOrderType = 3;
		const int SuffixValueApplicationOrderType = 4;
		const int PrefixValueApplicationOrderType = 5;
		const int PlusOrMinusSignValueApplicationOrderType = 6;
		const int DotValueApplicationOrderType = 7;
		const int NullValueApplicationOrderType = 8;
		const int MaxValueApplicationOrderType = 8;
			
		int* OriginalOrderNumberUnitTotalPartialOrderNumbers = NULL;
		int* OriginalOrderNumberUnitMaxPartialOrderNumbers = NULL;
		int* OriginalOrderNumberUnitTotalPartialValidOrderNumbers = NULL;
		int* OriginalOrderNumberUnitMaxPartialValidOrderNumbers = NULL;
		int* OriginalOrderNumberUnitTotalPartialOrderCharNumbers = NULL;
		int* OriginalOrderNumberUnitMaxPartialOrderCharNumbers = NULL;
			
		int* OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers = NULL;
		int* OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers = NULL;
		int* PartialOrderTypeCutTotalPartialOrderCharNumbers = NULL;
		int* OriginalOrderCharNumberUnitWholePartialOrderNumbers = NULL;
			
		char* CharDoubleValue = NULL;
			
		int DoubleToCharArrayEndMarker = 0;
			
		int OriginalOrderTypeLoopTime = 0;
		int OriginalOrderTypeLoopTimeEndMarker = 0;
		int MaxOriginalOrderTypeLoopTime = 0;
		int PartialOrderTypeLoopTime = 0;
		int PartialOrderTypeLoopTimeEndMarker = 0;
		int MaxPartialOrderTypeLoopTime = 0;
		int OriginalOrderType = 0;
		int MaxOriginalOrderType = 0;
		int TotalOriginalOrderType = 0;
		int OriginalOrderTypeEndMarker = 0;
		int WholeOriginalOrderType = 0;
		int OriginalOrderTypeUnitMaxPartialOrderType = 0;
		int OriginalOrderTypeUnitPartialOrderType = 0;
		int OriginalOrderTypeUnitTotalPartialOrderType = 0;
		int OrderTypeEndMarker = 0;
		int OriginalOrderTypeUnitWholePartialOrderType = 0;
		int PartialOrderType = 0;
		int MaxPartialOrderType = 0;
		int MaxOriginalPartialOrderType = 0;
		int PartialOrderTypeEndMarker = 0;
		int OrderTypeCountStartMarker = 0;
			
		int OriginalOrderNumber = 0;
		int MaxOriginalOrderNumber = 0;
		int TotalOriginalOrderNumber = 0;
		int OriginalOrderNumberEndMarker = 0;
		int WholeOriginalOrderNumber = 0;
		int PartialValidOrderNumber = 0;
		int MaxPartialValidOrderNumber = 0;
		int ValidOrderNumber = 0;
		int MaxValidOrderNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber = 0;
		int OriginalOrderNumberUnitMaxPartialOrderNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber = 0;
		int OriginalOrderNumberUnitMaxPartialValidOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = 0;
		int OriginalOrderNumberUnitTotalPartialOrderNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = 0;
		int OriginalOrderNumberUnitTotalPartialValidOrderNumber = 0;
		int OriginalOrderNumberUnitWholePartialValidOrderNumber = 0;
		int OriginalOrderNumberUnitPartialOrderNumber = 0;
		int OrderNumberEndMarker = 0;
		int OriginalOrderNumberUnitWholePartialOrderNumber = 0;
		int PartialOrderNumber = 0;
		int MaxPartialOrderNumber = 0;
		int MaxOriginalPartialOrderNumber = 0;
		int PartialOrderNumberEndMarker = 0;
		int OrderNumberCountStartMarker = 0;
		int PartialOrderNumberLoopTime = 0;
		int MaxPartialOrderNumberLoopTime = 0;
		int PartialOrderNumberLoopTimeEndMarker = 0;
			
		int PartialOrderCharNumberLoopTime = 0;
		int PartialOrderCharNumberLoopTimeEndMarker = 0;
		int MaxPartialOrderCharNumberLoopTime = 0;
		int OriginalOrderCharNumber = 0;
		int MaxOriginalOrderCharNumber = 0;
		int TotalOriginalOrderCharNumber = 0;
		int OriginalOrderCharNumberEndMarker = 0;
		int WholeOriginalOrderCharNumber = 0;
		int OriginalOrderCharNumberUnitMaxPartialOrderCharNumber = 0;
		int OriginalOrderNumberUnitOrderCharNumber = 0;
		int OriginalOrderCharNumberUnitPartialOrderCharNumber = 0;
		int MaxOrderCharNumber = 0;
		int OriginalOrderNumberUnitMaxOrderCharNumber = 0;
		int OriginalOrderNumberUnitTotalOrderCharNumber = 0;
		int OriginalOrderTypeUnitTotalOrderCharNumber = 0;
		int OrderCharNumberEndMarker = 0;
		int OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderTypeCutTotalPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
			
		int OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
			
		int OriginalOrderCharNumberCutTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberCutTotalPartialOrderCharNumber = 0;
			
		int OriginalOrderTypeCutOriginalOrderCharNumberUnitWholePartialOrderCharNumber = 0;
		int OriginalOrderCharNumberUnitWholePartialOrderCharNumber = 0;
		int PartialOrderCharNumber = 0;
		int MaxPartialOrderCharNumber = 0;
		int MaxOriginalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberEndMarker = 0;
		int OrderCharNumberCountStartMarker = 0;
			
	 	int ValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
	 	int ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
	 	int DummyValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
	 	int DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
		int DummyCarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = 0;
	 	int DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 0;
		int CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = 0;
		int CarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 0;
		int OriginalOrderTypeUnitMaxOrderNumber = 0;
		int CarryUpDigitOrderNumber = 0;
		int IntValueBase = 0;
		int IntValueBaseErrorMarker = 0;
		int RoundUpOneDigit = 5;
	 	int SetWholeDigitOrderOrderNumber = 0;
		int SetDecimalOrderOrderNumber = 0;
	 	int SetWholeDigitOrderOrderNumberMarker = 0;
		int SetDecimalOrderOrderNumberMarker = 0;
		int WholeDigitOrderOrderNumberBeforeExponential = 0;
		int UndefinedApplicationPlusOrMinusSignStatus = 0;
		int MinusApplicationPlusOrMinusSignStatus = 1;
		int PlusApplicationPlusOrMinusSignStatus = 2;
		int PlusOrMinusSignStatus = UndefinedApplicationPlusOrMinusSignStatus;
		int IntPlusOrMinusSign = 0;
		int PlusOrMinusSignMarker = 0;
		int DummyRoundDownToZeroMarker = 0;
		int RoundDownToZeroMarker = 0;
		int DecimalOrderOrderNumber = 0;
		int WholeDigitOrderOrderNumber = 0;
		double Value = 0.0;
		double AbsoluteValue = 0.0;
		double AbsoluteValueWholeDigitOrderPart = 0.0;
		double DummyAbsoluteValueWholeDigitOrderPart = 0.0;
		double AbsoluteValueDecimalOrderPart = 0.0;
		double DummyAbsoluteValueDecimalOrderPart = 0.0;
		int OriginalOneDigit = 0;
		int OriginalCarryUpOneDigit = 0;
		int OneDigit = 0;
		int CandidateCarryUpDecimalOrderMarker = 0;
		int OriginalTokenType = UndefinedApplicationTokenType;
		int TotalArrayOriginalOrderType = 0;
		int MaxArrayOriginalOrderType = 0;
		int ArrayOriginalOrderType = 0;
		int ArrayOriginalOrderTypeUnitOutputElementDenialMarker = 0;
		int TotalArrayOriginalOrderNumber = 0;
		int MaxArrayOriginalOrderNumber = 0;
		int ArrayOriginalOrderNumberUnitOutputElementDenialMarker = 0;
		int ArrayOriginalOrderNumber = 0;
		int TotalArrayOriginalOrderCharNumber = 0;
		int MaxArrayOriginalOrderCharNumber = 0;
		int ArrayOriginalOrderCharNumber = 0;
		int ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker = 0;
		char ArrayOriginalOrderOneChar = (char)0;
		char OriginalOneChar = (char)0;
		char OneChar = (char)0;
		int DoubleToCharArrayLoopTime = 0;
		int DoubleToCharArrayMaxLoopTime = 0;
		int DoubleToCharArrayLoopTimeEndMarker = 0;
		int DoubleToCharArrayLoopTimeCountStartMarker = 0;
		int DoubleToCharArrayLoopTimeModulo2Plus1 = 0;
		int DoubleToCharArrayLoopTimeModulo2Plus1EndMarker = 0;
		int OriginalOrderNumberUnitWholePartialOrderCharNumber = 0;
		int OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber = 0;
		int OriginalOrderNumberUnitTotalPartialOrderCharNumber = 0;
		int OriginalOrderNumberUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindTotalOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxExponentialOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxDecimalOrderOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxSuffixOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxPrefixOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxDotOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxNullOrderCharNumber = 0;
		int PartialOrderTypeValidityDenialMarker = 0;
		int PartialOrderNumberValidityDenialMarker = 0;
		int PartialOrderCharNumberValidityDenialMarker = 0;
		int OriginalOrderNumberUnitSubstitutingOrderCharNumber = 0;
		int SuffixOrderNumber = 0;
		int PrefixOrderNumber = 0;
		int PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = 0;
		int PartialOrderTypeUnitTotalPartialOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber = 0;
		int PartialOrderTypeUnitMaxPartialOrderNumber = 0;
			
		int PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderTypeUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber = 0;
		int PartialOrderTypeUnitMaxPartialValidOrderNumber = 0;
			
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber = 0;
			
		int OriginalOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int OriginalOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = 0;
		int PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = 0;
		int PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = 0;
			
		
		
		do{//DoubleToCharArrayEndMarker&0
			if(DoubleToCharArrayLoopTimeCountStartMarker <= 0){
				if(DoubleToCharArrayLoopTime == 0){
					DoubleToCharArrayEndMarker = 1;
					DoubleToCharArrayMaxLoopTime = 2;
					PartialOrderTypeUnitMaxExponentialOrderCharNumber = 0;
					PartialOrderTypeUnitMaxDecimalOrderOrderCharNumber = 0;
					PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber = 0;
					PartialOrderTypeUnitMaxSuffixOrderCharNumber = 0;
					PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber = 0;
					PartialOrderTypeUnitMaxPrefixOrderCharNumber = 0;
					PartialOrderTypeUnitMaxDotOrderCharNumber = 0;
					PartialOrderTypeUnitMaxNullOrderCharNumber = 0;
					PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber = 0;
				}//DoubleToCharArrayLoopTime&0
				if(DoubleToCharArrayMaxLoopTime >= 1){
					DoubleToCharArrayLoopTime = DoubleToCharArrayLoopTime + 1;
					DoubleToCharArrayLoopTimeModulo2Plus1 = DoubleToCharArrayLoopTimeModulo2Plus1 + 1;
				}//DoubleToCharArrayMaxLoopTime&1
				if(DoubleToCharArrayLoopTime == DoubleToCharArrayMaxLoopTime){
					DoubleToCharArrayLoopTimeEndMarker = 1;
				}//DoubleToCharArrayLoopTime&DoubleToCharArrayMaxLoopTime
				if(DoubleToCharArrayLoopTimeModulo2Plus1 == DoubleToCharArrayMaxLoopTimeModulo2Plus1){
					DoubleToCharArrayLoopTimeModulo2Plus1EndMarker = 1;
				}//DoubleToCharArrayLoopTimeModulo2Plus1&DoubleToCharArrayMaxLoopTimeModulo2Plus1
				
				OriginalOrderTypeUnitTotalOrderCharNumber = 0;
				OriginalOrderNumberUnitTotalOrderCharNumber = 0;
				OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
				OriginalOrderTypeUnitTotalPartialOrderType = 0;
				OriginalOrderNumberUnitTotalPartialOrderCharNumber = 0;
				OriginalOrderNumberUnitTotalPartialOrderNumber = 0;
				OriginalOrderNumberUnitTotalPartialValidOrderNumber = 0;
				OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = 0;
				PartialOrderTypeUnitTotalPartialOrderCharNumber = 0;
				OriginalOrderTypeUnitTotalPartialOrderCharNumber = 0;
				
				PartialOrderTypeUnitTotalPartialOrderNumber = 0;
				PartialOrderTypeUnitTotalPartialValidOrderNumber = 0;
				
			}//DoubleToCharArrayLoopTimeCountStartMarker&0
			
			
			
			if(OrderTypeCountStartMarker <= 0){
				if(PartialOrderType == 0){
					if(PartialOrderTypeLoopTime == 0){
						if(OriginalOrderType == 0){
							DoubleToCharArrayLoopTimeCountStartMarker = 1;
							MaxOriginalOrderType = 0;
							TotalOriginalOrderType = 0;
							OriginalOrderTypeUnitMaxPartialOrderType = 0;
							
							TotalArrayOriginalOrderType = 0;
							MaxArrayOriginalOrderType = 0;
							
							if(DoubleToCharArrayMaxLoopTime >= 1){
								TotalArrayOriginalOrderType = 0;
								MaxArrayOriginalOrderType = MaxParameterApplicationTokenType;
								TotalOriginalOrderType = OriginalOrderTypeUnitTotalPartialOrderType;
								MaxOriginalOrderType = MaxValueApplicationOrderType;
							}//DoubleToCharArrayMaxLoopTime&1
							
							OriginalOrderTypeUnitMaxOrderNumber = 0;
							
							Value = Value0;
							RoundUpOneDigit = RoundUpOneDigit0;
							SetWholeDigitOrderOrderNumber = SetWholeDigitOrderOrderNumber0;
							SetDecimalOrderOrderNumber = SetDecimalOrderOrderNumber0;
							SetWholeDigitOrderOrderNumberMarker = SetWholeDigitOrderOrderNumberMarker0;
							SetDecimalOrderOrderNumberMarker = SetDecimalOrderOrderNumberMarker0;
							PlusOrMinusSignMarker = PlusOrMinusSignMarker0;
							DecimalOrderOrderNumber = DecimalOrderOrderNumber0;
							IntValueBase = IntValueBase0;
							SuffixOrderNumber = 0;
							PrefixOrderNumber = 0;
							CarryUpDigitOrderNumber = 0;
							
							if(SetDecimalOrderOrderNumberMarker == 0){
								SuffixOrderNumber = 0;
							}else if(SetDecimalOrderOrderNumberMarker != 0){
								if(SetDecimalOrderOrderNumber <= 0){
									SuffixOrderNumber = 0;
								}else if(SetDecimalOrderOrderNumber >= 1){
									if(SetDecimalOrderOrderNumber <= DecimalOrderOrderNumber){
										SuffixOrderNumber = 0;
									}else if(SetDecimalOrderOrderNumber > DecimalOrderOrderNumber){
										if(DecimalOrderOrderNumber <= 0){
											SuffixOrderNumber = SetDecimalOrderOrderNumber;
										}else if(DecimalOrderOrderNumber >= 1){
											SuffixOrderNumber = SetDecimalOrderOrderNumber - DecimalOrderOrderNumber;
										}//DecimalOrderOrderNumber&0
									}//SetDecimalOrderOrderNumber & DecimalOrderOrderNumber
								}//SetDecimalOrderOrderNumber&1
							}//SetDecimalOrderOrderNumberMarker&0
							
							
							IntPlusOrMinusSign = 0;
							AbsoluteValue = 0.0;
							if(Value < 0.0){
								IntPlusOrMinusSign = -1;
								AbsoluteValue = -Value;
							}else if(Value > 0.0){
								IntPlusOrMinusSign = 1;
								AbsoluteValue = Value;
							}else{//Value
								IntPlusOrMinusSign = 0;
								AbsoluteValue = Value;
							}//Value&0.0
							
							
							IntValueBaseErrorMarker = 0;
							if(IntValueBase0 < 2){
								IntValueBaseErrorMarker = 1;
							}else if(IntValueBase0 >= 2){
								IntValueBaseErrorMarker = 0;
							}//IntValueBase0

							
							AbsoluteValueWholeDigitOrderPart = (double)((int)AbsoluteValue);
							AbsoluteValueDecimalOrderPart = AbsoluteValue - AbsoluteValueWholeDigitOrderPart;
							
							OriginalOrderTypeUnitMaxPartialOrderCharNumber = 0;
							
							PlusOrMinusSignStatus = UndefinedApplicationPlusOrMinusSignStatus;
							
							ValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
			 				ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
							RoundDownToZeroMarker = 0;
							WholeDigitOrderOrderNumber = 0;
							CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = 0;
							CarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 0;
							
						}//OriginalOrderType&0
						
						WholeOriginalOrderType = 0;
						
						if(MaxOriginalOrderType >= 1){
							OriginalOrderType = OriginalOrderType + 1;
							WholeOriginalOrderType = TotalOriginalOrderType + OriginalOrderType;
						}//MaxOriginalOrderType&1
						if(OriginalOrderType == MaxOriginalOrderType){
							OriginalOrderTypeEndMarker = 1;
						}//OriginalOrderType&MaxOriginalOrderType
						
						MaxPartialOrderTypeLoopTime = 0;
						
						if(MaxOriginalOrderType >= 1){
							MaxPartialOrderTypeLoopTime = 1;
						}//MaxOriginalOrderType&1
						
						PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = OriginalOrderNumberUnitTotalPartialOrderNumber;
						PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = OriginalOrderNumberUnitTotalPartialValidOrderNumber;
						PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = OriginalOrderNumberUnitTotalPartialOrderCharNumber;
						PartialOrderTypeLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
						PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeUnitTotalPartialOrderCharNumber;
						
						PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = OriginalOrderTypeUnitTotalPartialOrderCharNumber;
						PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = OriginalOrderTypeUnitMaxPartialOrderCharNumber;
						
						PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderTypeUnitTotalPartialOrderNumber;
						PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderTypeUnitTotalPartialValidOrderNumber;
						
					}//PartialOrderTypeLoopTime&0
					
					MaxPartialOrderType = 0;
					MaxOriginalPartialOrderType = 0;
					
					if(MaxPartialOrderTypeLoopTime >= 1){
						PartialOrderTypeLoopTime = PartialOrderTypeLoopTime + 1;
					}//MaxPartialOrderTypeLoopTime&1
					if(PartialOrderTypeLoopTime == MaxPartialOrderTypeLoopTime){
						PartialOrderTypeLoopTimeEndMarker = 1;
					}//PartialOrderTypeLoopTime&MaxPartialOrderTypeLoopTime
					if(MaxPartialOrderTypeLoopTime >= 1){
						MaxOriginalPartialOrderType = 1;
					}//MaxPartialOrderTypeLoopTime&1
					
					OriginalOrderNumberUnitTotalPartialOrderNumber = PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber;
					OriginalOrderNumberUnitTotalPartialValidOrderNumber = PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber;
					OriginalOrderNumberUnitTotalPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber;
					OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
					OriginalOrderCharNumberUnitMaxPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
					
					OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = 0;
					PartialOrderTypeCutTotalPartialOrderCharNumber = 0;
					
					PartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber;
					PartialOrderTypeUnitMaxPartialOrderCharNumber = 0;
					OriginalOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber;
					OriginalOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderTypeLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber;
					
					PartialOrderTypeUnitMaxPartialOrderNumber = 0;
					PartialOrderTypeUnitMaxPartialValidOrderNumber = 0;
					PartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber;
					PartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderTypeLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber;
					
				}//PartialOrderType&0
				
				OriginalOrderTypeUnitWholePartialOrderType = 0;
				OriginalOrderTypeUnitPartialOrderType = 0;
				PartialOrderTypeValidityDenialMarker = 0;
				
				
				if(MaxOriginalPartialOrderType >= 1){
					if(PartialOrderTypeValidityDenialMarker == 0){
						PartialOrderType = PartialOrderType + 1;
						OriginalOrderTypeUnitPartialOrderType = OriginalOrderTypeUnitMaxPartialOrderType + PartialOrderType;
						OriginalOrderTypeUnitWholePartialOrderType = OriginalOrderTypeUnitTotalPartialOrderType + OriginalOrderTypeUnitPartialOrderType;
					}//PartialOrderTypeValidityDenialMarker&0
				}//MaxOriginalPartialOrderType&1
				if(PartialOrderTypeValidityDenialMarker == 0){
					if(PartialOrderType == MaxOriginalPartialOrderType){
						PartialOrderTypeEndMarker = 1;
					}//PartialOrderType&MaxOriginalPartialOrderType
				}else if(PartialOrderTypeValidityDenialMarker != 0){
					PartialOrderTypeEndMarker = 2;
				}//PartialOrderTypeValidityDenialMarker&0
				
			}//OrderTypeCountStartMarker&0
			
			if(OrderNumberCountStartMarker <= 0){
				if(PartialOrderNumber == 0){
					if(PartialOrderNumberLoopTime == 0){
						if(OriginalOrderNumber == 0){
							OrderTypeCountStartMarker = 1;
							
							ArrayOriginalOrderType = 0;
				
							if(MaxOriginalPartialOrderType >= 1){
								if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
									ArrayOriginalOrderType = DigitApplicationTokenType;
								}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
									ArrayOriginalOrderType = DigitApplicationTokenType;
								}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
									ArrayOriginalOrderType = CarryUpDigitApplicationTokenType;
								}else if(OriginalOrderType == SuffixValueApplicationOrderType){
									ArrayOriginalOrderType = SuffixDigitApplicationTokenType;
								}else if(OriginalOrderType == PlusOrMinusSignValueApplicationOrderType){
									if(PlusOrMinusSignStatus == UndefinedApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderType = UndefinedApplicationTokenType;
									}else if(PlusOrMinusSignStatus == MinusApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderType = MinusSignOperatorApplicationTokenType;
									}else if(PlusOrMinusSignStatus == PlusApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderType = PlusSignOperatorApplicationTokenType;
									}//PlusOrMinusSignStatus
								}else if(OriginalOrderType == PrefixValueApplicationOrderType){
									ArrayOriginalOrderType = PrefixDigitApplicationTokenType;
								}else if(OriginalOrderType == DotValueApplicationOrderType){
									ArrayOriginalOrderType = DotOperatorApplicationTokenType;
								}else if(OriginalOrderType == NullValueApplicationOrderType){
									ArrayOriginalOrderType = NullDigitApplicationTokenType;
								}//OriginalOrderType
							}//MaxOriginalPartialOrderType&1
							
							ArrayOriginalOrderTypeUnitOutputElementDenialMarker = 0;
							if(ArrayOriginalOrderType <= 0){
								ArrayOriginalOrderTypeUnitOutputElementDenialMarker = 1;
							}//ArrayOriginalOrderType&0
							if(ArrayOriginalOrderType > MaxArrayOriginalOrderType){
								ArrayOriginalOrderTypeUnitOutputElementDenialMarker = 2;
							}//ArrayOriginalOrderType&MaxArrayOriginalOrderType
							
							TotalArrayOriginalOrderNumber = 0;
							MaxArrayOriginalOrderNumber = 0;
							
							if(ArrayOriginalOrderTypeUnitOutputElementDenialMarker == 0){
								TotalArrayOriginalOrderNumber = 0;
								if(ArrayOriginalOrderType == DigitApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxNormalDigitApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == NullDigitApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxNullDigitApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == SuffixDigitApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxSuffixDigitApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == PrefixDigitApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxPrefixDigitApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == CarryUpDigitApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxCarryUpDigitApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == MinusSignOperatorApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxMinusSignOperatorApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == PlusSignOperatorApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxPlusSignOperatorApplicationTokenSubStringNumber;
								}else if(ArrayOriginalOrderType == DotOperatorApplicationTokenType){
									MaxArrayOriginalOrderNumber = MaxDotOperatorApplicationTokenSubStringNumber;
								}//ArrayOriginalOrderType
							}//ArrayOriginalOrderTypeUnitOutputElementDenialMarker&0
							
							TotalOriginalOrderNumber = 0;
							OriginalOrderNumberUnitMaxOrderCharNumber = 0;
							MaxOriginalOrderNumber = 0;
							
							if(MaxOriginalPartialOrderType >= 1){
								
								if(PartialOrderTypeValidityDenialMarker == 0){
									TotalOriginalOrderNumber = 0;
									MaxOriginalOrderNumber = 1;
								}//PartialOrderTypeValidityDenialMarker&0
							}//MaxOriginalPartialOrderType&1
							
							
							OriginalOrderNumberUnitMaxPartialOrderNumber = 0;
							OriginalOrderNumberUnitMaxPartialValidOrderNumber = 0;
							OriginalOrderNumberUnitMaxPartialOrderCharNumber = 0;
							
						}//OriginalOrderNumber&0
						
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = OriginalOrderNumberUnitTotalPartialOrderNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = OriginalOrderNumberUnitTotalPartialValidOrderNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = OriginalOrderNumberUnitTotalPartialOrderCharNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
						
						PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber;
						PartialOrderNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderTypeCutTotalPartialOrderCharNumber;
						
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber = OriginalOrderNumberUnitMaxPartialOrderNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber = OriginalOrderNumberUnitMaxPartialValidOrderNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber = OriginalOrderNumberUnitMaxPartialOrderCharNumber;
						
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeUnitTotalPartialOrderCharNumber;
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = OriginalOrderTypeUnitTotalPartialOrderCharNumber;
						PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = OriginalOrderTypeUnitMaxPartialOrderCharNumber;
						
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber = PartialOrderTypeUnitMaxPartialOrderNumber;
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber = PartialOrderTypeUnitMaxPartialValidOrderNumber;
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderTypeUnitTotalPartialOrderNumber;
						PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderTypeUnitTotalPartialValidOrderNumber;
						
						
						
						WholeOriginalOrderNumber = 0;
						
						if(MaxOriginalOrderNumber >= 1){
							OriginalOrderNumber = OriginalOrderNumber + 1;
							WholeOriginalOrderNumber = TotalOriginalOrderNumber + OriginalOrderNumber;
						}//MaxOriginalOrderNumber&1
						if(OriginalOrderNumber == MaxOriginalOrderNumber){
							OriginalOrderNumberEndMarker = 1;
						}//OriginalOrderNumber&MaxOriginalOrderNumber
						
						MaxPartialOrderNumber = 0;
						MaxPartialOrderNumberLoopTime = 0;
						
						MaxValidOrderNumber = 0;
						
						if(MaxOriginalOrderNumber >= 1){
							if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
								MaxPartialOrderNumberLoopTime = 2;
							}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
								MaxPartialOrderNumberLoopTime = 2;
							}else{//OriginalOrderType
								MaxPartialOrderNumberLoopTime = 1;
							}//OriginalOrderType
						}//MaxOriginalOrderNumber&1
						
					}//PartialOrderNumberLoopTime&0
					if(MaxPartialOrderNumberLoopTime >= 1){
						PartialOrderNumberLoopTime = PartialOrderNumberLoopTime + 1;
					}//MaxPartialOrderNumberLoopTime&1
					if(PartialOrderNumberLoopTime == MaxPartialOrderNumberLoopTime){
						PartialOrderNumberLoopTimeEndMarker = 1;
					}//PartialOrderNumberLoopTime&MaxPartialOrderNumberLoopTime
					
					MaxOriginalPartialOrderNumber = 0;
					
					if(MaxPartialOrderNumberLoopTime >= 1){
						MaxOriginalPartialOrderNumber = 1;
					}//MaxPartialOrderNumberLoopTime&1
					
					if(MaxPartialOrderNumberLoopTime >= 1){
						if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
							DummyCarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = 0;
							DummyAbsoluteValueDecimalOrderPart = AbsoluteValueDecimalOrderPart;
							DummyValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
					 		DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
						}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
							DummyRoundDownToZeroMarker = 0;

							DummyAbsoluteValueWholeDigitOrderPart = AbsoluteValueWholeDigitOrderPart;
							
							if(CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker == 0){
								DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 0;
							}else{//CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker
								DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = -1;
							}//CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker&0

						}//OriginalOrderType
					}//MaxPartialOrderNumberLoopTime&1
					MaxPartialValidOrderNumber = 0;
					
					OriginalOrderNumberUnitTotalPartialOrderNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber;
					OriginalOrderNumberUnitTotalPartialValidOrderNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber;
					OriginalOrderNumberUnitTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber;
					OriginalOrderNumberUnitMaxPartialValidOrderNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber;
					OriginalOrderNumberUnitMaxPartialOrderNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber;
					OriginalOrderNumberUnitMaxPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber;
					OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
					OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber;
					PartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber;
					
					PartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber;
					PartialOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber;
					
					OriginalOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber;
					OriginalOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber;
					
					PartialOrderTypeUnitMaxPartialOrderNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber;
					PartialOrderTypeUnitMaxPartialValidOrderNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber;
					PartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber;
					PartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber;
					
					
				}//PartialOrderNumber&0
				
				OriginalOrderNumberUnitPartialOrderNumber = 0;
				MaxOrderCharNumber = 0;
				OriginalOrderNumberUnitWholePartialOrderNumber = 0;
				OriginalOrderNumberUnitWholePartialValidOrderNumber = 0;
				
				if(MaxOriginalPartialOrderNumber >= 1){
					
					PartialOrderNumber = PartialOrderNumber + 1;
					OriginalOrderNumberUnitPartialOrderNumber = OriginalOrderNumberUnitMaxPartialOrderNumber + PartialOrderNumber;
					OriginalOrderNumberUnitWholePartialOrderNumber = OriginalOrderNumberUnitTotalPartialOrderNumber + OriginalOrderNumberUnitPartialOrderNumber;
				}//MaxOriginalPartialOrderNumber&1
				
				PartialOrderNumberValidityDenialMarker = 0;
				if(PartialOrderTypeValidityDenialMarker != 0){
					PartialOrderNumberValidityDenialMarker = -1;
				}//PartialOrderTypeValidityDenialMarker&0
				if(MaxOriginalPartialOrderNumber >= 1){
					if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(PartialOrderNumber > SetDecimalOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 2;
							}//PartialOrderNumber&SetDecimalOrderOrderNumber
						}//SetDecimalOrderOrderNumberMarker&0
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(SetWholeDigitOrderOrderNumber <= -1){
								if(PartialOrderNumber < 1 - SetWholeDigitOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 3;
								}//PartialOrderNumber & 1 - SetWholeDigitOrderOrderNumber
							}//SetWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						
						if(DecimalOrderOrderNumber <= 0){
							PartialOrderNumberValidityDenialMarker = 4;
						}else if(DecimalOrderOrderNumber >= 1){
							if(PartialOrderNumber > DecimalOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 5;
							}//PartialOrderNumber&
						}//DecimalOrderOrderNumber&0
					}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(PartialOrderNumber > SetWholeDigitOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 6;
							}//PartialOrderNumber&ValueStringMaxWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(SetDecimalOrderOrderNumber <= -1){
								if(PartialOrderNumber < 1 - SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 7;
								}//PartialOrderNumber&ValueStringMinWholeDigitOrderOrderNumber
							}//SetDecimalOrderOrderNumber&-1
						}//SetDecimalOrderOrderNumberMarker&0
						if(PartialOrderNumberLoopTime >= 2){
							if(PartialOrderNumber > WholeDigitOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 8;
							}//PartialOrderNumber&
						}//PartialOrderNumberLoopTime&2
					}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(WholeDigitOrderOrderNumber + PartialOrderNumber > SetWholeDigitOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 9;
							}//WholeDigitOrderOrderNumber + PartialOrderNumber&ValueStringMaxWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(SetDecimalOrderOrderNumber <= -1){
								if(WholeDigitOrderOrderNumber + PartialOrderNumber < 1 - SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 10;
								}//WholeDigitOrderOrderNumber + PartialOrderNumber&ValueStringMinWholeDigitOrderOrderNumber
							}//SetDecimalOrderOrderNumber&-1
						}//SetDecimalOrderOrderNumberMarker&0
						if(CarryUpDigitOrderNumber == 0){
							PartialOrderNumberValidityDenialMarker = 11;
						}//CarryUpDigitOrderNumber&0
					}else if(OriginalOrderType == SuffixValueApplicationOrderType){
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(DecimalOrderOrderNumber <= -1){
								if(PartialOrderNumber > SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 12;
								}//DecimalOrderOrderNumber + PartialOrderNumber&SetDecimalOrderOrderNumber
							}else if(DecimalOrderOrderNumber >= 0){
								if(DecimalOrderOrderNumber + PartialOrderNumber > SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 13;
								}//DecimalOrderOrderNumber + PartialOrderNumber&SetDecimalOrderOrderNumber
							}//DecimalOrderOrderNumber&0
						}//SetDecimalOrderOrderNumberMarker&0
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(SetWholeDigitOrderOrderNumber <= -1){
								if(DecimalOrderOrderNumber <= -1){
									if(PartialOrderNumber < 1 - SetWholeDigitOrderOrderNumber){
										PartialOrderNumberValidityDenialMarker = 14;
									}//PartialOrderNumber & 1 - SetWholeDigitOrderOrderNumber
								}else if(DecimalOrderOrderNumber >= 0){
									if(DecimalOrderOrderNumber + PartialOrderNumber < 1 - SetWholeDigitOrderOrderNumber){
										PartialOrderNumberValidityDenialMarker = 15;
									}//DecimalOrderOrderNumber + PartialOrderNumber & 1 - SetWholeDigitOrderOrderNumber
								}//DecimalOrderOrderNumber
							}//SetWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						if(SuffixOrderNumber == 0){
							PartialOrderNumberValidityDenialMarker = 16;
						}//SuffixOrderNumber&0
					}else if(OriginalOrderType == PlusOrMinusSignValueApplicationOrderType){
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber > SetWholeDigitOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 17;
							}//WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber&ValueStringMaxWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(SetDecimalOrderOrderNumber <= -1){
								if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber < 1 - SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 18;
								}//WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber&ValueStringMinWholeDigitOrderOrderNumber
							}//SetDecimalOrderOrderNumber&-1
						}//SetDecimalOrderOrderNumberMarker&0
					}else if(OriginalOrderType == PrefixValueApplicationOrderType){
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber + PartialOrderNumber > SetWholeDigitOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 19;
							}//WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber + PartialOrderNumber&ValueStringMaxWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
						if(SetDecimalOrderOrderNumberMarker != 0){
							if(SetDecimalOrderOrderNumber <= -1){
								if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber + PartialOrderNumber < 1 - SetDecimalOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 20;
								}//WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber + PartialOrderNumber&ValueStringMinWholeDigitOrderOrderNumber
							}//SetDecimalOrderOrderNumber&-1
						}//SetDecimalOrderOrderNumberMarker&0
						if(PrefixOrderNumber == 0){
							PartialOrderNumberValidityDenialMarker = 21;
						}//PrefixOrderNumber&0
					}else if(OriginalOrderType == DotValueApplicationOrderType){
						if(SetDecimalOrderOrderNumberMarker == 0){
							if(DecimalOrderOrderNumber <= 0){
								PartialOrderNumberValidityDenialMarker = 22;
							}//DecimalOrderOrderNumber
						}else if(SetDecimalOrderOrderNumberMarker != 0){
							if(PartialOrderNumber > SetDecimalOrderOrderNumber){
								PartialOrderNumberValidityDenialMarker = 23;
							}//PartialOrderNumber&SetDecimalOrderOrderNumber
						}//SetDecimalOrderOrderNumberMarker&0
						if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(SetWholeDigitOrderOrderNumber <= -1){
								if(PartialOrderNumber < 1 - SetWholeDigitOrderOrderNumber){
									PartialOrderNumberValidityDenialMarker = 24;
								}//PartialOrderNumber & 1 - SetWholeDigitOrderOrderNumber
							}//SetWholeDigitOrderOrderNumber
						}//SetWholeDigitOrderOrderNumberMarker&0
					}else if(OriginalOrderType == NullValueApplicationOrderType){
						if(OriginalOrderNumberUnitTotalPartialOrderCharNumber >= 1){
							PartialOrderNumberValidityDenialMarker = 25;
						}//OriginalOrderNumberUnitTotalPartialOrderCharNumber&1
					}//OriginalOrderType
				}//MaxOriginalPartialOrderNumber&1
				
				if(MaxOriginalPartialOrderNumber >= 1){
					if(PartialOrderNumberValidityDenialMarker == 0){
						PartialValidOrderNumber = PartialValidOrderNumber + 1;
						ValidOrderNumber = OriginalOrderNumberUnitMaxPartialValidOrderNumber + PartialValidOrderNumber;
						OriginalOrderNumberUnitWholePartialValidOrderNumber = OriginalOrderNumberUnitTotalPartialValidOrderNumber + ValidOrderNumber;
					}//PartialOrderNumberValidityDenialMarker&0
				}//MaxOriginalPartialOrderNumber&1
				
				OriginalOneDigit = 0;
				OriginalCarryUpOneDigit = 0;
				OneDigit = 0;
				if(MaxOriginalPartialOrderNumber >= 1){
					if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
						if(IntValueBaseErrorMarker == 0){
							OriginalOneDigit = (int)(DummyAbsoluteValueDecimalOrderPart * (double)IntValueBase);
							DummyAbsoluteValueDecimalOrderPart = DummyAbsoluteValueDecimalOrderPart * (double)IntValueBase - (double)((int)(DummyAbsoluteValueDecimalOrderPart * (double)IntValueBase));
						}else if(IntValueBaseErrorMarker != 0){
							OriginalOneDigit = 0;
						}//IntValueBaseErrorMarker&0
					}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
						if(IntValueBaseErrorMarker == 0){
							OriginalOneDigit = (int)(DummyAbsoluteValueWholeDigitOrderPart - (double)IntValueBase * (double)((int)(DummyAbsoluteValueWholeDigitOrderPart/(double)IntValueBase)));
							DummyAbsoluteValueWholeDigitOrderPart = (double)((int)(DummyAbsoluteValueWholeDigitOrderPart/(double)IntValueBase));
						}else if(IntValueBaseErrorMarker != 0){
							OriginalOneDigit = 0;
						}//IntValueBaseErrorMarker&0
					}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
						OriginalOneDigit = 1;
					}//OriginalOrderType
				}//MaxOriginalPartialOrderNumber&1
				
				if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
					if(DecimalOrderOrderNumber <= -1){
						PartialOrderNumberEndMarker = 1;
					}else if(DecimalOrderOrderNumber >= 0){
						if(PartialOrderNumber == DecimalOrderOrderNumber + 1){
							PartialOrderNumberEndMarker = 2;
						}//PartialOrderNumber
					}//DecimalOrderOrderNumber
				}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
					if(IntValueBaseErrorMarker == 0){
						if(DummyAbsoluteValueWholeDigitOrderPart < 1.0){
							PartialOrderNumberEndMarker = 3;
						}//DummyAbsoluteValueWholeDigitOrderPart&1.0
					}else if(IntValueBaseErrorMarker != 0){
						PartialOrderNumberEndMarker = 4;
					}//IntValueBaseErrorMarker&0
				}else if(OriginalOrderType == SuffixValueApplicationOrderType){
					if(SuffixOrderNumber == 0){
						PartialOrderNumberEndMarker = -6;
					}else if(SuffixOrderNumber >= 1){
						if(PartialOrderNumber == SuffixOrderNumber){
							PartialOrderNumberEndMarker = 6;
						}//OriginalOrderNumberUnitPartialOrderNumber&SuffixOrderNumber
					}//SuffixOrderNumber
				}else if(OriginalOrderType == PrefixValueApplicationOrderType){
					if(PrefixOrderNumber == 0){
						PartialOrderNumberEndMarker = -6;
					}else if(PrefixOrderNumber >= 1){
						if(PartialOrderNumber == PrefixOrderNumber){
							PartialOrderNumberEndMarker = 8;
						}//OriginalOrderNumberUnitPartialOrderNumber&PrefixOrderNumber
					}//PartialOrderNumber
				}else{//OriginalOrderType
					PartialOrderNumberEndMarker = 9;
				}//OriginalOrderType
				
				if(MaxOriginalPartialOrderNumber >= 1){
			
					if(OriginalOrderType ==  DecimalOrderOrderNumberValueApplicationOrderType){
						CandidateCarryUpDecimalOrderMarker = 0;
						if(IntValueBaseErrorMarker == 0){
							if(PartialOrderNumber < DecimalOrderOrderNumber + 1){
								if(OriginalOneDigit >= IntValueBase - 1){
									CandidateCarryUpDecimalOrderMarker = 1;
								}//OriginalOneDigit
							}else if(PartialOrderNumber == DecimalOrderOrderNumber + 1){
								if(OriginalOneDigit >= RoundUpOneDigit){
									CandidateCarryUpDecimalOrderMarker = 2;
								}//OriginalOneDigit
							}//PartialOrderNumber&DecimalOrderOrderNumber
						}//IntValueBaseErrorMarker&0
						
						if(CandidateCarryUpDecimalOrderMarker == 0){
							if(DecimalOrderOrderNumber >= 0){
								DummyCarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = 1;
							}//DecimalOrderOrderNumber&0
							DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
							DummyValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = 0;
						}else if(CandidateCarryUpDecimalOrderMarker != 0){
							DummyValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = PartialOrderNumber;
							if(DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber == 0){
								DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = PartialOrderNumber;
							}//DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber&0
						}//CandidateCarryUpDecimalOrderMarker&0
						
						
						if(PartialOrderNumberLoopTime == 1){
							OneDigit = OriginalOneDigit;
						}else if(PartialOrderNumberLoopTime >= 2){
							if(RoundDownToZeroMarker == 0){
								if(IntValueBaseErrorMarker == 0){
									if(PartialOrderNumber <= DecimalOrderOrderNumber){
										if(ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber == 0){
											OneDigit = OriginalOneDigit;
										}else if(ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber >= 1){
											if(PartialOrderNumber >= ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber){
												OneDigit = 0;
											}else if(PartialOrderNumber == ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber - 1){
												if(OriginalOneDigit < OriginalCarryUpOneDigit){
													OneDigit = OriginalOneDigit;
												}else if(OriginalOneDigit >= OriginalCarryUpOneDigit){
													OneDigit = OriginalOneDigit + 1;
												}//OriginalOneDigit & OriginalCarryUpOneDigit&0
											}else if(PartialOrderNumber < ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber - 1){
												OneDigit = OriginalOneDigit;
											}//PartialOrderNumber
										}//ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber&1
									}else if(PartialOrderNumber > DecimalOrderOrderNumber){
										OneDigit = 0;
									}//PartialOrderNumber & DecimalOrderOrderNumber
								}else if(IntValueBaseErrorMarker != 0){
									OneDigit = 0;
								}//IntValueBaseErrorMarker&0
							}else if(RoundDownToZeroMarker != 0){
								OneDigit = 0;
							}//RoundDownToZeroMarker&0
						}//PartialOrderNumberLoopTime&2
					}else if(OriginalOrderType ==  WholeDigitOrderOrderNumberValueApplicationOrderType){
						if(IntValueBaseErrorMarker == 0){
							if(DecimalOrderOrderNumber <= -1){
								if(PartialOrderNumber < - DecimalOrderOrderNumber){
									OneDigit = 0;
									if(PartialOrderNumberEndMarker != 0){
										DummyRoundDownToZeroMarker = 1;
									}//PartialOrderNumberEndMarker&0
								}else if(PartialOrderNumber == - DecimalOrderOrderNumber){
									OneDigit = 0;
									if(OriginalOneDigit < RoundUpOneDigit){
										DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 2;
										if(PartialOrderNumberEndMarker != 0){
											DummyRoundDownToZeroMarker = 2;
										}//PartialOrderNumberEndMarker&0
									}//OriginalOneDigit
								}else if(PartialOrderNumber > - DecimalOrderOrderNumber){
									if(RoundDownToZeroMarker == 0){
										if(DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker == 0){
											if(OriginalOneDigit < IntValueBase - 1){
												OneDigit = OriginalOneDigit + 1;
											}else if(OriginalOneDigit == IntValueBase - 1){
												OneDigit = 0;
											}//OriginalOneDigit
										}else if(DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker != 0){
											OneDigit = OriginalOneDigit;
										}//DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker&0
									}else if(RoundDownToZeroMarker != 0){
										OneDigit = 0;
									}//RoundDownToZeroMarker&0
									if(OriginalOneDigit < IntValueBase - 1){
										DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 1;
									}//OriginalOneDigit
								}//PartialOrderNumber
							}else if(DecimalOrderOrderNumber >= 0){
								if(RoundDownToZeroMarker == 0){
									if(DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker == 0){
										if(OriginalOneDigit < IntValueBase - 1){
											OneDigit = OriginalOneDigit + 1;
										}else if(OriginalOneDigit == IntValueBase - 1){
											OneDigit = 0;
										}//OriginalOneDigit
									}else if(DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker != 0){
										OneDigit = OriginalOneDigit;
									}//DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker&0
								}else if(RoundDownToZeroMarker != 0){
									OneDigit = 0;
								}//RoundDownToZeroMarker&0
								if(OriginalOneDigit < IntValueBase - 1){
									DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 3;
								}//OriginalOneDigit
							}//DecimalOrderOrderNumber&0
						}else if(IntValueBaseErrorMarker != 0){
							OneDigit = 0;
							DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = 4;
						}//IntValueBaseErrorMarker
					}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
						OneDigit = OriginalOneDigit;
					}//OriginalOrderType
				}//MaxOriginalPartialOrderNumber&1
				
			}//OrderNumberCountStartMarker&0
			
			if(OrderCharNumberCountStartMarker <= 0){
				if(PartialOrderCharNumber == 0){
					if(PartialOrderCharNumberLoopTime == 0){
						if(OriginalOrderCharNumber == 0){
							
							OrderNumberCountStartMarker = 1;
							MaxOriginalOrderCharNumber = 0;
							TotalOriginalOrderCharNumber = 0;
							OriginalOrderCharNumberUnitMaxPartialOrderCharNumber = 0;
							TotalArrayOriginalOrderCharNumber = 0;
							MaxArrayOriginalOrderCharNumber = 0;
							
							ArrayOriginalOrderNumberUnitOutputElementDenialMarker = 0;
							ArrayOriginalOrderNumber = 0;
				
							if(MaxOriginalPartialOrderNumber >= 1){
								if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
									ArrayOriginalOrderNumber = OneDigit + 1;
								}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
									ArrayOriginalOrderNumber = OneDigit + 1;
								}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
									ArrayOriginalOrderNumber = CarryUpDigitApplicationTokenSubStringNumber;
								}else if(OriginalOrderType == SuffixValueApplicationOrderType){
									ArrayOriginalOrderNumber = SuffixDigitApplicationTokenSubStringNumber;
								}else if(OriginalOrderType == PlusOrMinusSignValueApplicationOrderType){
									if(PlusOrMinusSignStatus == UndefinedApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderNumber = UndefinedApplicationTokenSubStringNumber;
									}else if(PlusOrMinusSignStatus == MinusApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderNumber = MinusSignOperatorApplicationTokenSubStringNumber;
									}else if(PlusOrMinusSignStatus == PlusApplicationPlusOrMinusSignStatus){
										ArrayOriginalOrderNumber = PlusSignOperatorApplicationTokenSubStringNumber;
									}//PlusOrMinusSignStatus
								}else if(OriginalOrderType == PrefixValueApplicationOrderType){
									ArrayOriginalOrderNumber = PrefixDigitApplicationTokenSubStringNumber;
								}else if(OriginalOrderType == DotValueApplicationOrderType){
									ArrayOriginalOrderNumber = DotOperatorApplicationTokenSubStringNumber;
								}else if(OriginalOrderType == NullValueApplicationOrderType){
									ArrayOriginalOrderNumber = NullDigitApplicationTokenSubStringNumber;
								}//OriginalOrderType
							}//MaxOriginalPartialOrderNumber&1
							
							ArrayOriginalOrderNumberUnitOutputElementDenialMarker = 0;
							if(ArrayOriginalOrderTypeUnitOutputElementDenialMarker != 0){
								ArrayOriginalOrderNumberUnitOutputElementDenialMarker = -1;
							}//ArrayOriginalOrderTypeUnitOutputElementDenialMarker&0
							if(ArrayOriginalOrderNumber <= 0){
								ArrayOriginalOrderNumberUnitOutputElementDenialMarker = 1;
							}//ArrayOriginalOrderNumber&0
							if(ArrayOriginalOrderNumber > MaxArrayOriginalOrderNumber){
								ArrayOriginalOrderNumberUnitOutputElementDenialMarker = 2;
							}//ArrayOriginalOrderNumber&MaxArrayOriginalOrderNumber
							
							if(ArrayOriginalOrderNumberUnitOutputElementDenialMarker == 0){
								TotalArrayOriginalOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
								if(ArrayOriginalOrderType == DigitApplicationTokenType){
									if(ArrayOriginalOrderNumber == ZeroNormalDigitApplicationTokenSubStringNumber){
										if(StringZeroNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringZeroNormalDigit)/sizeof(char) - 1;
										}//StringZeroNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == OneNormalDigitApplicationTokenSubStringNumber){
										if(StringOneNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringOneNormalDigit)/sizeof(char) - 1;
										}//StringOneNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == TwoNormalDigitApplicationTokenSubStringNumber){
										if(StringTwoNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringTwoNormalDigit)/sizeof(char) - 1;
										}//StringTwoNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == ThreeNormalDigitApplicationTokenSubStringNumber){
										if(StringThreeNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringThreeNormalDigit)/sizeof(char) - 1;
										}//StringThreeNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == FourNormalDigitApplicationTokenSubStringNumber){
										if(StringFourNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringFourNormalDigit)/sizeof(char) - 1;
										}//StringFourNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == FiveNormalDigitApplicationTokenSubStringNumber){
										if(StringFiveNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringFiveNormalDigit)/sizeof(char) - 1;
										}//StringFiveNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == SixNormalDigitApplicationTokenSubStringNumber){
										if(StringSixNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringSixNormalDigit)/sizeof(char) - 1;
										}//StringSixNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == SevenNormalDigitApplicationTokenSubStringNumber){
										if(StringSevenNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringSevenNormalDigit)/sizeof(char) - 1;
										}//StringSevenNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == EightNormalDigitApplicationTokenSubStringNumber){
										if(StringEightNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringEightNormalDigit)/sizeof(char) - 1;
										}//StringEightNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == NineNormalDigitApplicationTokenSubStringNumber){
										if(StringNineNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringNineNormalDigit)/sizeof(char) - 1;
										}//StringNineNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == ANormalDigitApplicationTokenSubStringNumber){
										if(StringANormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringANormalDigit)/sizeof(char) - 1;
										}//StringANormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == BNormalDigitApplicationTokenSubStringNumber){
										if(StringBNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringBNormalDigit)/sizeof(char) - 1;
										}//StringBNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == CNormalDigitApplicationTokenSubStringNumber){
										if(StringCNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringCNormalDigit)/sizeof(char) - 1;
										}//StringCNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == DNormalDigitApplicationTokenSubStringNumber){
										if(StringDNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringDNormalDigit)/sizeof(char) - 1;
										}//StringDNormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == ENormalDigitApplicationTokenSubStringNumber){
										if(StringENormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringENormalDigit)/sizeof(char) - 1;
										}//StringENormalDigit&NULL
									}else if(ArrayOriginalOrderNumber == FNormalDigitApplicationTokenSubStringNumber){
										if(StringFNormalDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringFNormalDigit)/sizeof(char) - 1;
										}//StringFNormalDigit&NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == NullDigitApplicationTokenType){
									if(ArrayOriginalOrderNumber == NullDigitApplicationTokenSubStringNumber){
										if(StringNullDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringNullDigit)/sizeof(char) - 1;
										}//StringNullDigit & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == SuffixDigitApplicationTokenType){
									if(ArrayOriginalOrderNumber == SuffixDigitApplicationTokenSubStringNumber){
										if(StringSuffixDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringSuffixDigit)/sizeof(char) - 1;
										}//StringSuffixDigit & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == PrefixDigitApplicationTokenType){
									if(ArrayOriginalOrderNumber == PrefixDigitApplicationTokenSubStringNumber){
										if(StringPrefixDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringPrefixDigit)/sizeof(char) - 1;
										}//StringPrefixDigit & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == CarryUpDigitApplicationTokenType){
									if(ArrayOriginalOrderNumber == CarryUpDigitApplicationTokenSubStringNumber){
										if(StringCarryUpDigit != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringCarryUpDigit)/sizeof(char) - 1;
										}//StringCarryUpDigit & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == MinusSignOperatorApplicationTokenType){
									if(ArrayOriginalOrderNumber == MinusSignOperatorApplicationTokenSubStringNumber){
										if(StringMinusSignOperator != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringMinusSignOperator)/sizeof(char) - 1;
										}//StringMinusSignOperator & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == PlusSignOperatorApplicationTokenType){
									if(ArrayOriginalOrderNumber == PlusSignOperatorApplicationTokenSubStringNumber){
										if(StringPlusSignOperator != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringPlusSignOperator)/sizeof(char) - 1;
										}//StringPlusSignOperator & NULL
									}//ArrayOriginalOrderNumber
								}else if(ArrayOriginalOrderType == DotOperatorApplicationTokenType){
									if(ArrayOriginalOrderNumber == DotOperatorApplicationTokenSubStringNumber){
										if(StringDotOperator != NULL){
											MaxArrayOriginalOrderCharNumber = sizeof(StringDotOperator)/sizeof(char) - 1;
										}//StringDotOperator & NULL
									}//ArrayOriginalOrderNumber
								}//ArrayOriginalOrderType
							}//ArrayOriginalOrderNumberUnitOutputElementDenialMarker&0
							
							if(MaxOriginalPartialOrderNumber >= 1){
								if(PartialOrderNumberValidityDenialMarker == 0){
									MaxOriginalOrderCharNumber = MaxArrayOriginalOrderCharNumber;
									TotalOriginalOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
								}//PartialOrderNumberValidityDenialMarker&0
							}//MaxOriginalPartialOrderNumber&1
							
							OriginalOrderCharNumberCutTotalPartialOrderCharNumber = 0;
							
						}//OriginalOrderCharNumber&0
							
						WholeOriginalOrderCharNumber = 0;
					
						if(MaxOriginalOrderCharNumber >= 1){
							OriginalOrderCharNumber = OriginalOrderCharNumber + 1;
							WholeOriginalOrderCharNumber = TotalOriginalOrderCharNumber + OriginalOrderCharNumber;
						}//MaxOriginalOrderCharNumber&1
						if(OriginalOrderCharNumber == MaxOriginalOrderCharNumber){
							OriginalOrderCharNumberEndMarker = 1;
						}//OriginalOrderCharNumber&MaxOriginalOrderCharNumber
						
						MaxPartialOrderCharNumberLoopTime = 0;
						
						if(MaxOriginalOrderCharNumber >= 1){
							MaxPartialOrderCharNumberLoopTime = 1;
						}//MaxOriginalOrderCharNumber&1
						
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber = OriginalOrderNumberUnitTotalPartialOrderNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber = OriginalOrderNumberUnitTotalPartialValidOrderNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber = OriginalOrderNumberUnitTotalPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber = OriginalOrderNumberUnitMaxPartialValidOrderNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber = OriginalOrderNumberUnitMaxPartialOrderNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber = OriginalOrderNumberUnitMaxPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
						
						PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderTypeCutTotalPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberCutTotalPartialOrderCharNumber = OriginalOrderCharNumberCutTotalPartialOrderCharNumber;
						
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeUnitTotalPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber = OriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
						
						PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber = OriginalOrderTypeUnitTotalPartialOrderCharNumber;
						PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber = OriginalOrderTypeUnitMaxPartialOrderCharNumber;
						
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber = PartialOrderTypeUnitMaxPartialOrderNumber;
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber = PartialOrderTypeUnitMaxPartialValidOrderNumber;
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderTypeUnitTotalPartialOrderNumber;
						PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderTypeUnitTotalPartialValidOrderNumber;
						
						
					}//PartialOrderCharNumberLoopTime&0
					
					if(MaxPartialOrderCharNumberLoopTime >= 1){
						PartialOrderCharNumberLoopTime = PartialOrderCharNumberLoopTime + 1;
					}//MaxPartialOrderCharNumberLoopTime&1
					if(PartialOrderCharNumberLoopTime == MaxPartialOrderCharNumberLoopTime){
						PartialOrderCharNumberLoopTimeEndMarker = 1;
					}//PartialOrderCharNumberLoopTime&MaxPartialOrderCharNumberLoopTime
					
					MaxPartialOrderCharNumber = 0;
					MaxOriginalPartialOrderCharNumber = 0;
					if(MaxPartialOrderCharNumberLoopTime >= 1){
						MaxOriginalPartialOrderCharNumber = 1;
					}//MaxPartialOrderCharNumberLoopTime&1
					
					OriginalOrderNumberUnitTotalPartialOrderNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderNumber;
					OriginalOrderNumberUnitTotalPartialValidOrderNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialValidOrderNumber;
					OriginalOrderNumberUnitTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitTotalPartialOrderCharNumber;
					OriginalOrderNumberUnitMaxPartialValidOrderNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialValidOrderNumber;
					OriginalOrderNumberUnitMaxPartialOrderNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderNumber;
					OriginalOrderNumberUnitMaxPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderNumberUnitMaxPartialOrderCharNumber;
					OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
					
					OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber;
					PartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeCutTotalPartialOrderCharNumber;
					OriginalOrderCharNumberCutTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberCutTotalPartialOrderCharNumber;
					
					PartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderCharNumber;
					PartialOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderCharNumber;
					OriginalOrderCharNumberUnitMaxPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
					
					OriginalOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitTotalPartialOrderCharNumber;
					OriginalOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderCharNumberLoopTimeRewindOriginalOrderTypeUnitMaxPartialOrderCharNumber;
					
					PartialOrderTypeUnitMaxPartialOrderNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialOrderNumber;
					PartialOrderTypeUnitMaxPartialValidOrderNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitMaxPartialValidOrderNumber;
					PartialOrderTypeUnitTotalPartialOrderNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialOrderNumber;
					PartialOrderTypeUnitTotalPartialValidOrderNumber = PartialOrderCharNumberLoopTimeRewindPartialOrderTypeUnitTotalPartialValidOrderNumber;
					
					
				}//PartialOrderCharNumber&0
				
				OriginalOrderNumberUnitOrderCharNumber = 0;
				OriginalOrderNumberUnitSubstitutingOrderCharNumber = 0;
				OriginalOrderCharNumberUnitPartialOrderCharNumber = 0;
				OriginalOrderCharNumberUnitWholePartialOrderCharNumber = 0;
				OriginalOrderNumberUnitWholePartialOrderCharNumber = 0;
				OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = 0;
				OriginalOrderTypeCutOriginalOrderCharNumberUnitWholePartialOrderCharNumber = 0;
				if(MaxOriginalPartialOrderCharNumber >= 1){
					PartialOrderCharNumber = PartialOrderCharNumber + 1;
					OriginalOrderCharNumberUnitPartialOrderCharNumber = OriginalOrderCharNumberUnitMaxPartialOrderCharNumber + PartialOrderCharNumber;
					OriginalOrderCharNumberUnitWholePartialOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber + OriginalOrderCharNumberUnitPartialOrderCharNumber;
					OriginalOrderNumberUnitOrderCharNumber = OriginalOrderNumberUnitMaxPartialOrderCharNumber + PartialOrderCharNumber;
					OriginalOrderNumberUnitWholePartialOrderCharNumber = OriginalOrderNumberUnitTotalPartialOrderCharNumber + OriginalOrderNumberUnitOrderCharNumber;
					OriginalOrderTypeCutOriginalOrderCharNumberUnitWholePartialOrderCharNumber = PartialOrderTypeCutTotalPartialOrderCharNumber + PartialOrderCharNumber;
					
					if(PartialOrderNumberLoopTimeEndMarker != 0){
						if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
							OriginalOrderNumberUnitSubstitutingOrderCharNumber = PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber - (OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber + MaxOriginalPartialOrderCharNumber * MaxOriginalOrderCharNumber) + OriginalOrderCharNumberUnitPartialOrderCharNumber;
						}else{//OriginalOrderType
							OriginalOrderNumberUnitSubstitutingOrderCharNumber = OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber + OriginalOrderCharNumberUnitPartialOrderCharNumber;
						}//OriginalOrderType
						if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + PartialOrderTypeUnitMaxPrefixOrderCharNumber + PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber + PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber + PartialOrderTypeUnitMaxDotOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + PartialOrderTypeUnitMaxPrefixOrderCharNumber + PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + PartialOrderTypeUnitMaxPrefixOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == SuffixValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + PartialOrderTypeUnitMaxPrefixOrderCharNumber + PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber + PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber + PartialOrderTypeUnitMaxDotOrderCharNumber + PartialOrderTypeUnitMaxDecimalOrderOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == PlusOrMinusSignValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == PrefixValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == DotValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber + PartialOrderTypeUnitMaxPrefixOrderCharNumber + PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber + PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber + OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}else if(OriginalOrderType == NullValueApplicationOrderType){
							OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber = OriginalOrderNumberUnitSubstitutingOrderCharNumber;
						}//OriginalOrderType
					}//PartialOrderNumberLoopTimeEndMarker&0
				}//MaxOriginalPartialOrderCharNumber&1
				
				if(PartialOrderCharNumber == MaxOriginalPartialOrderCharNumber){
					PartialOrderCharNumberEndMarker = 1;
				}//PartialOrderCharNumber&MaxOriginalPartialOrderCharNumber
				
				ArrayOriginalOrderCharNumber = 0;
				
				if(MaxOriginalPartialOrderCharNumber >= 1){
					ArrayOriginalOrderCharNumber = OriginalOrderCharNumber;
				}//MaxOriginalPartialOrderCharNumber&1
				
				PartialOrderCharNumberValidityDenialMarker = 0;
				if(PartialOrderNumberValidityDenialMarker != 0){
					PartialOrderCharNumberValidityDenialMarker = -1;
				}//PartialOrderNumberValidityDenialMarker&0
				
			}//OrderCharNumberCountStartMarker&0
			
			ArrayOriginalOrderOneChar = (char)0;
			OriginalOneChar = (char)0;
			OneChar = (char)0;
			
			
			ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker = 0;
			if(ArrayOriginalOrderNumberUnitOutputElementDenialMarker != 0){
				ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker = -1;
			}//ArrayOriginalOrderNumberUnitOutputElementDenialMarker&0
			if(ArrayOriginalOrderCharNumber <= 0){
				ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker = 1;
			}//ArrayOriginalOrderCharNumber&0
			if(ArrayOriginalOrderCharNumber > MaxArrayOriginalOrderCharNumber){
				ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker = 2;
			}//ArrayOriginalOrderCharNumber&MaxArrayOriginalOrderCharNumber
			
			
			if(ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker == 0){
				if(ArrayOriginalOrderType == DigitApplicationTokenType){
					if(ArrayOriginalOrderNumber == ZeroNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringZeroNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == OneNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringOneNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == TwoNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringTwoNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == ThreeNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringThreeNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == FourNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringFourNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == FiveNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringFiveNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == SixNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringSixNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == SevenNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringSevenNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == EightNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringEightNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == NineNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringNineNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == ANormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringANormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == BNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringBNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == CNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringCNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == DNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringDNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == ENormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringENormalDigit[ArrayOriginalOrderCharNumber - 1];
					}else if(ArrayOriginalOrderNumber == FNormalDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringFNormalDigit[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == NullDigitApplicationTokenType){
					if(ArrayOriginalOrderNumber == NullDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringNullDigit[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == SuffixDigitApplicationTokenType){
					if(ArrayOriginalOrderNumber == SuffixDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringSuffixDigit[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == PrefixDigitApplicationTokenType){
					if(ArrayOriginalOrderNumber == PrefixDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringPrefixDigit[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == CarryUpDigitApplicationTokenType){
					if(ArrayOriginalOrderNumber == CarryUpDigitApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringCarryUpDigit[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == MinusSignOperatorApplicationTokenType){
					if(ArrayOriginalOrderNumber == MinusSignOperatorApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringMinusSignOperator[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == PlusSignOperatorApplicationTokenType){
					if(ArrayOriginalOrderNumber == PlusSignOperatorApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringPlusSignOperator[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}else if(ArrayOriginalOrderType == DotOperatorApplicationTokenType){
					if(ArrayOriginalOrderNumber == DotOperatorApplicationTokenSubStringNumber){
						ArrayOriginalOrderOneChar = StringDotOperator[ArrayOriginalOrderCharNumber - 1];
					}//ArrayOriginalOrderNumber
				}//ArrayOriginalOrderType
			}//ArrayOriginalOrderCharNumberUnitOutputElementDenialMarker&0
			
			if(MaxOriginalOrderCharNumber >= 1){
				if(PartialOrderCharNumberValidityDenialMarker == 0){
					OriginalOneChar = ArrayOriginalOrderOneChar;
				}//PartialOrderCharNumberValidityDenialMarker&0
			}//MaxOriginalOrderCharNumber&1
			
			if(MaxOriginalPartialOrderCharNumber >= 1){
				if(PartialOrderNumberLoopTimeEndMarker != 0){
					if(DoubleToCharArrayLoopTime == 2){
						CharDoubleValue[OriginalOrderNumberUnitWholeSubstitutingPartialOrderCharNumber - 1] = ArrayOriginalOrderOneChar;
					}//DoubleToCharArrayLoopTime
				}//PartialOrderNumberLoopTimeEndMarker&0
			}//MaxOriginalPartialOrderCharNumber&1
			
			
			if(OrderCharNumberCountStartMarker <= 0){
				if(PartialOrderCharNumberEndMarker != 0){
					MaxPartialOrderCharNumber = PartialOrderCharNumber;
					
					PartialOrderTypeCutTotalPartialOrderCharNumber = PartialOrderTypeCutTotalPartialOrderCharNumber + MaxPartialOrderCharNumber;
					OriginalOrderNumberUnitMaxPartialOrderCharNumber = OriginalOrderNumberUnitMaxPartialOrderCharNumber + MaxPartialOrderCharNumber;
					OriginalOrderCharNumberUnitMaxPartialOrderCharNumber = OriginalOrderCharNumberUnitMaxPartialOrderCharNumber + MaxPartialOrderCharNumber;
					PartialOrderTypeUnitMaxPartialOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber + MaxPartialOrderCharNumber;
					
					OriginalOrderCharNumberCutTotalPartialOrderCharNumber = OriginalOrderCharNumberCutTotalPartialOrderCharNumber + MaxPartialOrderCharNumber;
					
					if(PartialOrderCharNumberLoopTimeEndMarker != 0){
						if(OriginalOrderCharNumberEndMarker != 0){
							MaxOrderCharNumber = OriginalOrderNumberUnitMaxPartialOrderCharNumber;
							
							if(PartialOrderNumberLoopTimeEndMarker != 0){
								if(MaxOriginalPartialOrderNumber >= 1){
									if(DoubleToCharArrayLoopTime == 2){
										OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers[OriginalOrderNumberUnitWholePartialOrderNumber - 1] = OriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
										OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers[OriginalOrderNumberUnitWholePartialOrderNumber - 1] = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber;
										PartialOrderTypeCutTotalPartialOrderCharNumbers[OriginalOrderNumberUnitWholePartialOrderNumber - 1] = PartialOrderTypeCutTotalPartialOrderCharNumber;
										OriginalOrderCharNumberUnitWholePartialOrderNumbers[OriginalOrderNumberUnitWholePartialOrderNumber - 1] = OriginalOrderNumberUnitWholePartialOrderNumber;
									}//DoubleToCharArrayLoopTime
								}//MaxOriginalPartialOrderNumber&1
							}//PartialOrderNumberLoopTimeEndMarker&0
							
							OriginalOrderCharNumberUnitTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitTotalPartialOrderCharNumber + OriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
							OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber = OriginalOrderCharNumberUnitPartialOrderTypeCutTotalPartialOrderCharNumber + OriginalOrderCharNumberUnitMaxPartialOrderCharNumber;
							
							OrderNumberCountStartMarker = -1;
							OriginalOrderCharNumber = 0;
							OriginalOrderCharNumberEndMarker = 0;
						}//OriginalOrderCharNumberEndMarker&0
						PartialOrderCharNumberLoopTime = 0;
						PartialOrderCharNumberLoopTimeEndMarker = 0;
					}//PartialOrderCharNumberLoopTimeEndMarker&0
					PartialOrderCharNumber = 0;
					PartialOrderCharNumberEndMarker = 0;
					
				}//PartialOrderCharNumberEndMarker&0
			}//OrderCharNumberCountStartMarker&0
			
			if(OrderNumberCountStartMarker <= 0){
				
				if(PartialOrderNumberEndMarker != 0){
					MaxPartialOrderNumber = PartialOrderNumber;
					OriginalOrderNumberUnitMaxPartialOrderNumber = OriginalOrderNumberUnitMaxPartialOrderNumber + MaxPartialOrderNumber;
					MaxPartialValidOrderNumber = PartialValidOrderNumber;
					OriginalOrderNumberUnitMaxPartialValidOrderNumber = OriginalOrderNumberUnitMaxPartialValidOrderNumber + MaxPartialValidOrderNumber;
					MaxValidOrderNumber = OriginalOrderNumberUnitMaxPartialValidOrderNumber;
					
					if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
						if(MaxOriginalOrderNumber >= 1){
							ValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber = DummyValueSubStringSmallestRoundUpOrderNumberDecimalOrderOrderNumber;
							ValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber = DummyValueSubStringLargestRoundUpOrderNumberDecimalOrderOrderNumber;
						}//MaxOriginalOrderNumber&1
					}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
						
						if(MaxOriginalOrderNumber >= 1){
							
							RoundDownToZeroMarker = DummyRoundDownToZeroMarker;
							
							if(RoundDownToZeroMarker == 0){
								if(DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker == 0){
									CarryUpDigitOrderNumber = 1;
								}//DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker&0
							}//RoundDownToZeroMarker&0
							
							if(RoundDownToZeroMarker == 0){
								WholeDigitOrderOrderNumber = MaxPartialOrderNumber;
							}else if(RoundDownToZeroMarker != 0){
								WholeDigitOrderOrderNumber = 1;
							}//RoundDownToZeroMarker&0
							
						}//MaxOriginalOrderNumber&1
					}//OriginalOrderType
					
					if(PartialOrderNumberLoopTimeEndMarker != 0){
						
						if(OriginalOrderNumberEndMarker != 0){
							
							if(MaxOriginalPartialOrderNumber >= 1){
								if(DoubleToCharArrayLoopTime == 2){
									OriginalOrderNumberUnitTotalPartialOrderCharNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitTotalPartialOrderCharNumber;
									OriginalOrderNumberUnitMaxPartialOrderCharNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitMaxPartialOrderCharNumber;
									OriginalOrderNumberUnitTotalPartialOrderNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitTotalPartialOrderNumber;
									OriginalOrderNumberUnitMaxPartialOrderNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitMaxPartialOrderNumber;
									OriginalOrderNumberUnitTotalPartialValidOrderNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitTotalPartialValidOrderNumber;
									OriginalOrderNumberUnitMaxPartialValidOrderNumbers[OriginalOrderTypeUnitWholePartialOrderType - 1] = OriginalOrderNumberUnitMaxPartialValidOrderNumber;
								}//DoubleToCharArrayLoopTime
							}//MaxOriginalPartialOrderNumber&1
							
							OriginalOrderNumberUnitTotalPartialOrderNumber = OriginalOrderNumberUnitTotalPartialOrderNumber + OriginalOrderNumberUnitMaxPartialOrderNumber;
							OriginalOrderNumberUnitTotalPartialValidOrderNumber = OriginalOrderNumberUnitTotalPartialValidOrderNumber + OriginalOrderNumberUnitMaxPartialValidOrderNumber;
							OriginalOrderNumberUnitTotalPartialOrderCharNumber = OriginalOrderNumberUnitTotalPartialOrderCharNumber + OriginalOrderNumberUnitMaxPartialOrderCharNumber;
							
							OrderTypeCountStartMarker = -1;
							
							OriginalOrderNumber = 0;
							OriginalOrderNumberEndMarker = 0;
						}//OriginalOrderNumberEndMarker&0
						PartialOrderNumberLoopTime = 0;
						PartialOrderNumberLoopTimeEndMarker = 0;
					}//PartialOrderNumberLoopTimeEndMarker&0
					PartialValidOrderNumber = 0;
					PartialOrderNumber = 0;
					PartialOrderNumberEndMarker = 0;
				}//PartialOrderNumberEndMarker&0
			}//OrderNumberCountStartMarker&0
			
			if(OrderTypeCountStartMarker <= 0){
				
				if(PartialOrderTypeEndMarker != 0){
					MaxPartialOrderType = PartialOrderType;
					OriginalOrderTypeUnitMaxPartialOrderType = OriginalOrderTypeUnitMaxPartialOrderType + MaxPartialOrderType;
					
					PartialOrderTypeUnitTotalPartialOrderCharNumber = PartialOrderTypeUnitTotalPartialOrderCharNumber + PartialOrderTypeUnitMaxPartialOrderCharNumber;
					
					if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
						if(SetWholeDigitOrderOrderNumberMarker == 0){
							PrefixOrderNumber = 0;
						}else if(SetWholeDigitOrderOrderNumberMarker != 0){
							if(SetWholeDigitOrderOrderNumber <= 0){
								PrefixOrderNumber = 0;
							}else if(SetWholeDigitOrderOrderNumber >= 1){
								if(SetWholeDigitOrderOrderNumber <= WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber){
									PrefixOrderNumber = 0;
								}else if(SetWholeDigitOrderOrderNumber > WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber){
									if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber <= 0){
										PrefixOrderNumber = SetWholeDigitOrderOrderNumber;
									}else if(WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber >= 1){
										PrefixOrderNumber = SetWholeDigitOrderOrderNumber - (WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber);
									}//WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber&0
								}//SetWholeDigitOrderOrderNumber & WholeDigitOrderOrderNumber + CarryUpDigitOrderNumber
							}//SetWholeDigitOrderOrderNumber&1
						}//SetWholeDigitOrderOrderNumberMarker&0
					}//OriginalOrderType
					
					if(PartialOrderTypeLoopTimeEndMarker != 0){
						
						if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
							PlusOrMinusSignStatus = UndefinedApplicationPlusOrMinusSignStatus;
							if(PlusOrMinusSignMarker == 0){
								if(RoundDownToZeroMarker == 0){
									if(IntPlusOrMinusSign <= -1){
										PlusOrMinusSignStatus = MinusApplicationPlusOrMinusSignStatus;
									}else if(IntPlusOrMinusSign >= 0){
										PlusOrMinusSignStatus = UndefinedApplicationPlusOrMinusSignStatus;
									}//IntPlusOrMinusSign&0
								}else if(RoundDownToZeroMarker != 0){
									PlusOrMinusSignStatus = UndefinedApplicationPlusOrMinusSignStatus;
								}//RoundDownToZeroMarker
							}else if(PlusOrMinusSignMarker != 0){
								if(RoundDownToZeroMarker == 0){
									if(IntPlusOrMinusSign <= -1){
										PlusOrMinusSignStatus = MinusApplicationPlusOrMinusSignStatus;
									}else if(IntPlusOrMinusSign >= 0){
										PlusOrMinusSignStatus = PlusApplicationPlusOrMinusSignStatus;
									}//IntPlusOrMinusSign
								}else if(RoundDownToZeroMarker != 0){
									PlusOrMinusSignStatus = PlusApplicationPlusOrMinusSignStatus;
								}//RoundDownToZeroMarker&0
							}//PlusOrMinusSignMarker
						}//OriginalOrderType
						
						if(OriginalOrderType == DecimalOrderOrderNumberValueApplicationOrderType){
							PartialOrderTypeUnitMaxDecimalOrderOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
							CarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker = DummyCarryUpDigitDecimalOrderOrderNumberDiscontinuityMarker;
						}else if(OriginalOrderType == WholeDigitOrderOrderNumberValueApplicationOrderType){
							PartialOrderTypeUnitMaxWholeDigitOrderOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
							CarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker = DummyCarryUpDigitWholeDigitOrderOrderNumberDiscontinuityMarker;
						}else if(OriginalOrderType == CarryUpDigitValueApplicationOrderType){
							PartialOrderTypeUnitMaxCarryUpDigitOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}else if(OriginalOrderType == SuffixValueApplicationOrderType){
							PartialOrderTypeUnitMaxSuffixOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}else if(OriginalOrderType == PlusOrMinusSignValueApplicationOrderType){
							PartialOrderTypeUnitMaxPlusOrMinusSignOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}else if(OriginalOrderType == PrefixValueApplicationOrderType){
							PartialOrderTypeUnitMaxPrefixOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}else if(OriginalOrderType == DotValueApplicationOrderType){
							PartialOrderTypeUnitMaxDotOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}else if(OriginalOrderType == NullValueApplicationOrderType){
							PartialOrderTypeUnitMaxNullOrderCharNumber = PartialOrderTypeUnitMaxPartialOrderCharNumber;
						}//OriginalOrderType
						
						if(OriginalOrderTypeEndMarker != 0){
							
							OriginalOrderTypeUnitTotalPartialOrderType = OriginalOrderTypeUnitTotalPartialOrderType + OriginalOrderTypeUnitMaxPartialOrderType;
							DoubleToCharArrayLoopTimeCountStartMarker = -1;
							OriginalOrderType = 0;
							OriginalOrderTypeEndMarker = 0;
						}//OriginalOrderTypeEndMarker&0
						PartialOrderTypeLoopTime = 0;
						PartialOrderTypeLoopTimeEndMarker = 0;
					}//PartialOrderTypeLoopTimeEndMarker&0
					
					PartialOrderType = 0;
					PartialOrderTypeEndMarker = 0;
					
				}//PartialOrderTypeEndMarker&0
			}//OrderTypeCountStartMarker&0
			
			if(DoubleToCharArrayLoopTimeCountStartMarker <= 0){
				
				
				if(DoubleToCharArrayLoopTime == 1){
					if(OriginalOrderNumberUnitTotalPartialOrderCharNumbers != NULL){
						OriginalOrderNumberUnitTotalPartialOrderCharNumbers = NULL;
					}//OriginalOrderNumberUnitTotalPartialOrderCharNumbers&NULL
					if(OriginalOrderNumberUnitMaxPartialOrderCharNumbers != NULL){
						OriginalOrderNumberUnitMaxPartialOrderCharNumbers = NULL;
					}//OriginalOrderNumberUnitMaxPartialOrderCharNumbers&NULL
					if(OriginalOrderNumberUnitTotalPartialOrderNumbers != NULL){
						OriginalOrderNumberUnitTotalPartialOrderNumbers = NULL;
					}//OriginalOrderNumberUnitTotalPartialOrderNumbers&NULL
					if(OriginalOrderNumberUnitMaxPartialOrderNumbers != NULL){
						OriginalOrderNumberUnitMaxPartialOrderNumbers = NULL;
					}//OriginalOrderNumberUnitMaxPartialOrderNumbers&NULL
					if(OriginalOrderNumberUnitTotalPartialValidOrderNumbers != NULL){
						OriginalOrderNumberUnitTotalPartialValidOrderNumbers = NULL;
					}//OriginalOrderNumberUnitTotalPartialValidOrderNumbers&NULL
					if(OriginalOrderNumberUnitMaxPartialValidOrderNumbers != NULL){
						OriginalOrderNumberUnitMaxPartialValidOrderNumbers = NULL;
					}//OriginalOrderNumberUnitMaxPartialValidOrderNumbers&NULL
					if(OriginalOrderTypeUnitTotalPartialOrderType >= 1){
						OriginalOrderNumberUnitTotalPartialOrderCharNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
						OriginalOrderNumberUnitMaxPartialOrderCharNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
						OriginalOrderNumberUnitTotalPartialOrderNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
						OriginalOrderNumberUnitMaxPartialOrderNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
						OriginalOrderNumberUnitTotalPartialValidOrderNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
						OriginalOrderNumberUnitMaxPartialValidOrderNumbers = (int*)malloc(sizeof(int) * OriginalOrderTypeUnitTotalPartialOrderType);
					}//OriginalOrderTypeUnitTotalPartialOrderType&1
					
					if(OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers != NULL){
						OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers = NULL;
					}//OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers&NULL
					if(OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers != NULL){
						OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers = NULL;
					}//OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers&NULL
					if(PartialOrderTypeCutTotalPartialOrderCharNumbers != NULL){
						PartialOrderTypeCutTotalPartialOrderCharNumbers = NULL;
					}//PartialOrderTypeCutTotalPartialOrderCharNumbers&NULL
					if(OriginalOrderCharNumberUnitWholePartialOrderNumbers != NULL){
						OriginalOrderCharNumberUnitWholePartialOrderNumbers = NULL;
					}//OriginalOrderCharNumberUnitWholePartialOrderNumbers&NULL
					if(OriginalOrderNumberUnitTotalPartialOrderNumber >= 1){
						OriginalOrderCharNumberUnitMaxPartialOrderCharNumbers = (int*)malloc(sizeof(int) * OriginalOrderNumberUnitTotalPartialOrderNumber);
						OriginalOrderCharNumberUnitTotalPartialOrderCharNumbers = (int*)malloc(sizeof(int) * OriginalOrderNumberUnitTotalPartialOrderNumber);
						PartialOrderTypeCutTotalPartialOrderCharNumbers = (int*)malloc(sizeof(int) * OriginalOrderNumberUnitTotalPartialOrderNumber);
						OriginalOrderCharNumberUnitWholePartialOrderNumbers = (int*)malloc(sizeof(int) * OriginalOrderNumberUnitTotalPartialOrderNumber);
					}//OriginalOrderNumberUnitTotalPartialOrderNumber&1
					
					if(CharDoubleValue != NULL){
						CharDoubleValue = NULL;
					}//CharDoubleValue&NULL
					if(OriginalOrderNumberUnitTotalPartialOrderCharNumber >= 1){
						CharDoubleValue = (char*)malloc(sizeof(char) * (OriginalOrderNumberUnitTotalPartialOrderCharNumber + 1));
						CharDoubleValue[(OriginalOrderNumberUnitTotalPartialOrderCharNumber + 1) - 1] = '\0';
					}//OriginalOrderNumberUnitTotalPartialOrderCharNumber&1
				}//DoubleToCharArrayLoopTime
				if(DoubleToCharArrayLoopTimeModulo2Plus1EndMarker != 0){
					DoubleToCharArrayLoopTimeModulo2Plus1 = 0;
					DoubleToCharArrayLoopTimeModulo2Plus1EndMarker = 0;
				}//DoubleToCharArrayLoopTimeModulo2Plus1EndMarker&0
				if(DoubleToCharArrayLoopTimeEndMarker != 0){
					DoubleToCharArrayEndMarker = -1;
					DoubleToCharArrayLoopTime = 0;
					DoubleToCharArrayLoopTimeEndMarker = 0;
					
					DoubleToCharArrayLoopTimeModulo2Plus1 = 0;
					DoubleToCharArrayLoopTimeModulo2Plus1EndMarker = 0;
				}//DoubleToCharArrayLoopTimeEndMarker
			}//DoubleToCharArrayLoopTimeCountStartMarker&0
			
		}while(DoubleToCharArrayEndMarker >= 1);
			
		return(CharDoubleValue);
	}//DoubleToCharArray