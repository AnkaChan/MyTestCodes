//#include <iostream>
//#include <string>
//#include "H5Cpp.h"
//using namespace H5;
//
//const H5std_string	FILE_NAME("h5tutr_dset.h5");
//const H5std_string	DATASET_NAME("dset");
//const int	 NX = 4;                     // dataset dimensions
//const int	 NY = 6;
//const int	 RANK = 2;
//
//int main(void)
//{
//	// Try block to detect exceptions raised by any of the calls inside it
//	try
//	{
//		// Turn off the auto-printing when failure occurs so that we can
//		// handle the errors appropriately
//		Exception::dontPrint();
//
//		// Create a new file using the default property lists. 
//		H5File file(FILE_NAME, H5F_ACC_TRUNC);
//
//		// Create the data space for the dataset.
//		hsize_t dims[2];               // dataset dimensions
//		dims[0] = NX;
//		dims[1] = NY;
//		DataSpace dataspace(RANK, dims);
//
//		// Create the dataset.      
//		DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_I32BE, dataspace);
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
//	// catch failure caused by the DataSpace operations
//	catch (DataSpaceIException error)
//	{
//		error.printErrorStack();
//		return -1;
//	}
//
//	return 0;  // successfully terminated
//}


#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;

const H5std_string	FILE_NAME("h5tutr_dset.h5");
const H5std_string	DATASET_NAME("dset");
const int 	DIM0 = 4;	               // dataset dimensions
const int 	DIM1 = 6;

int main(void)
{

	// Data initialization.

	int i, j;
	int data[DIM0][DIM1];	    // buffer for data to write

	for (j = 0; j < DIM0; j++)
		for (i = 0; i < DIM1; i++)
			data[j][i] = i * 6 + j + 1;

	// Try block to detect exceptions raised by any of the calls inside it
	try
	{
		// Turn off the auto-printing when failure occurs so that we can
		// handle the errors appropriately
		//Exception::dontPrint();

		// Open an existing file and dataset.
		H5File file(FILE_NAME, H5F_ACC_RDWR);
		hsize_t dims[2];               // dataset dimensions
		dims[0] = DIM0;
		dims[1] = DIM1;
		DataSpace dataspace(2, dims);
		//DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_I32BE, dataspace);
		DataSet dataset = file.openDataSet(DATASET_NAME);
		

		// Write the data to the dataset using default memory space, file
		// space, and transfer properties.
		dataset.write(data, PredType::NATIVE_INT);

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

	return 0;  // successfully terminated
}