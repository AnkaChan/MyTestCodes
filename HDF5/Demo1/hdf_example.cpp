#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;

const H5std_string	FILE_NAME("h5tutr_dset.h5");
const H5std_string	DATASET_NAME("dset");
const H5std_string	ATTR_NAME("name");
const H5std_string	ATTR_NAME_NUM("number");

const int imgHeight = 64;
const int imgWidth = 64;

const hsize_t dims[3] = {10, imgHeight, imgWidth };
const int	 RANK = 3;

uint8_t *** prepareData(int num, int iH, int iW) {
	uint8_t ***grayScale = new uint8_t **[num];
	for (int i = 0; i < num; i++)
	{
		grayScale[i] = new uint8_t*[iH];
		for (int j = 0; j < iH; j++)
		{
			grayScale[i][j] = new uint8_t[iW];
		}
	}

	for (int n = 0; n < num; n++)
	{
		for (int i = 0; i < iH; i++)
		{
			for (int j = 0; j < iW; ++j) {
				grayScale[n][i][j] = 1; // n + i * iW + j;
			}
		}
	}

	//for (int n = 0; n < num; n++)
	//{
	//	printf("-----------------------------------\n");
	//	for (int i = 0; i < iH; i++)
	//	{
	//		for (int j = 0; j < iW; ++j) {
	//			printf("%d ", grayScale[n][i][j]); // n + i * iW + j;
	//		}
	//		printf("\n");
	//	}
	//}
	return grayScale;
};

uint8_t * prepareData2(int num, int iH, int iW) {
	uint8_t *grayScale = new uint8_t[num * iH * iW];

	for (int n = 0; n < num; n++)
	{
		for (int i = 0; i < iH; i++)
		{
			for (int j = 0; j < iW; ++j) {
				int id = n * (iH * iW) + i * (iW)+j;
				grayScale[id] =  i  + j;
			}
		}
	}

	//for (int n = 0; n < num; n++)
	//{
	//	printf("-----------------------------------\n");
	//	for (int i = 0; i < iH; i++)
	//	{
	//		for (int j = 0; j < iW; ++j) {
	//			printf("%d ", grayScale[n][i][j]); // n + i * iW + j;
	//		}
	//		printf("\n");
	//	}
	//}
	return grayScale;
};

int main(void)
{
	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		Exception::dontPrint();

		// Create a new file using the default property lists. 
		H5File file(FILE_NAME, H5F_ACC_TRUNC);

		// Create the data space for the dataset.
		DataSpace dataspace(RANK, dims);


		uint8_t * data = prepareData2(dims[0], dims[1], dims[2]);

		// Create the dataset.      
		DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_U8LE, dataspace);
		dataset.write(data, PredType::STD_U8LE);

		// Create new dataspace for attribute
		DataSpace attr_dataspaceName = DataSpace(H5S_SCALAR);

		// Create new string datatype for attribute
		StrType strdatatype(PredType::C_S1, 128); // of length 256 characters

		// Set up write buffer for attribute
		const H5std_string strwritebuf("Name");

		// Create attribute and write to it
		Attribute myatt_in = dataset.createAttribute(ATTR_NAME, strdatatype, attr_dataspaceName);
		myatt_in.write(strdatatype, strwritebuf);

		// Set up read buffer for attribute
		H5std_string strreadbuf("");

		// Open attribute and read its contents
		Attribute myatt_out = dataset.openAttribute(ATTR_NAME);
		myatt_out.read(strdatatype, strreadbuf);

		// Display attribute contents
		std::cout << "Attribute contents: " << strreadbuf << std::endl;

		hsize_t dimSingleValue[1] = { 1 };
		DataSpace attr_dataspaceNum = DataSpace(1, dimSingleValue);

		int attr_data[1] = { 10 };
		// Create a dataset attribute. 
		Attribute attribute = dataset.createAttribute(ATTR_NAME_NUM, PredType::STD_I32BE,
			attr_dataspaceNum);

		attribute.write(PredType::NATIVE_INT, attr_data);

		uint8_t dataOut[10][imgHeight][imgWidth];

		dataset.read(**dataOut, PredType::STD_U8LE);

		for (int n = 0; n < 10; n++)
		{
			printf("--------------------------------------------------------------\n");
			for (int i = 0; i < imgHeight; i++)
			{
				for (int j = 0; j < imgWidth; ++j) {
					printf("%3d ",dataOut[n][i][j]); // n + i * iW + j;
				}
				printf("\n");

			}
		}

	}  // end of try block

	   // catch failure caused by the H5File operations
	catch (FileIException error)
	{
		error.printErrorStack();
		return -1;
	}

	// catch failure caused by the DataSet operations
	catch (DataSetIException error)
	{
		error.printErrorStack();
		return -1;
	}

	// catch failure caused by the DataSpace operations
	catch (DataSpaceIException error)
	{
		error.printErrorStack();
		return -1;
	}

	return 0;  // successfully terminated
}


//#include <iostream>
//#include <string>
//#include "H5Cpp.h"
//using namespace H5;
//
//const H5std_string	FILE_NAME("h5tutr_dset.h5");
//const H5std_string	DATASET_NAME("dset");
//const int 	DIM0 = 4;	               // dataset dimensions
//const int 	DIM1 = 6;
//
//int main(void)
//{
//
//	// Data initialization.
//
//	int i, j;
//	int data[DIM0][DIM1];	    // buffer for data to write
//
//	for (j = 0; j < DIM0; j++)
//		for (i = 0; i < DIM1; i++)
//			data[j][i] = i * 6 + j + 1;
//
//	// Try block to detect exceptions raised by any of the calls inside it
//	try
//	{
//		// Turn off the auto-printing when failure occurs so that we can
//		// handle the errors appropriately
//		//Exception::dontPrint();
//
//		// Open an existing file and dataset.
//		H5File file(FILE_NAME, H5F_ACC_RDWR);
//		hsize_t dims[2];               // dataset dimensions
//		dims[0] = DIM0;
//		dims[1] = DIM1;
//		DataSpace dataspace(2, dims);
//		//DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_I32BE, dataspace);
//		DataSet dataset = file.openDataSet(DATASET_NAME);
//		
//
//		// Write the data to the dataset using default memory space, file
//		// space, and transfer properties.
//		dataset.write(data, PredType::NATIVE_INT);
//
//	}  // end of try block
//
//	   // catch failure caused by the H5File operations
//	catch (FileIException error)
//	{
//		error.printErrorStack();
//		return -1;
//	}
//
//	// catch failure caused by the DataSet operations
//	catch (DataSetIException error)
//	{
//		error.printErrorStack();
//		return -1;
//	}
//
//	return 0;  // successfully terminated
//}