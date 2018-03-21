#if !defined STATFINDER
#define STATFINDER

int* readData (const char* filename, int& size);
double findMean (int* numbers, int size);
double findMedian (int* numbers, int size);
int findMode (int* numbers, int size);
void displayInformation (float mean, float median, int mode);

#endif
