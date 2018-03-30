#if !defined STATFINDER
	#define STATFINDER
	long* readData (const char* filename, long& size);
	double findMean (long* numbers, long size);
	double findMedian (long* numbers, long size);
	long findMode (long* numbers, long size);
	void displayInformation (double mean, double median, long mode);
#endif
