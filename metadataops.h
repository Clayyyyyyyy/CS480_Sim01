// protect from multiple compliling
#ifndef METADATAOPS_H
#define METADATAOPS_H


// header files
#include <stdio.h>
#include "datatypes.h"
#include "StringUtils.h"


// constants
// op code messages, starts at index 3 to allow for string error messages
typedef enum{ MD_FILE_ACCESS_ERR = 3,
			  MD_CORRUPT_DESCRIPTOR_ERR,
			  OPCMD_ACCESS_ERR,
			  CORRUPT_OPCMD_ERR,
			  CORRUPT_OPCMD_ARG_ERR,
			  UNBALANCED_START_END_ERR,
			  COMPLETE_OPCMD_FOUND_MSG,
			  LAST_OPCMD_FOUND_MSG } OpCodeMessages;


extern const int BAD_ARG_VAL;


//functions
OpCodeType *clearMetaDataList( OpCodeType *localPtr);
void displayMetaData( OpCodeType *localPtr);
Boolean getMetaData ( char *fileName,
                        OpCodeType **opCodeDataHead, char *endStateMsg);
int getCommand(char* cmd, char* inputStr, int index);
int getOpCommand( FILE *filePtr, OpCodeType *inData );
OpCodeType* addNode(OpCodeType* localPtr, OpCodeType* newNode);
int updateStartCount( int count, char *opString);
int updateEndCount( int count, char *opString);
int getNumberArg(int* number, char* inputStr, int index);
int getStringArg(char* strArg, char* inputStr, int index);
Boolean verifyValidCommand( char *testCmd );
Boolean verifyFirstStringArg( char *strArg );
Boolean isDigit(char testChar);


#endif    // METADATAOPS_H