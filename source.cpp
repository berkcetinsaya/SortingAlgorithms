/******************************************
*This program is written by Berk Cetinsaya*
************September 27, 2016*************
******************************************/

#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <functional>
using namespace std;

const int n = 10000;
int B[n], S[n], I[n], H[n], M[n], Q[n];
int tempBforBub, tempBforSel, tempBforIns, tempBforHea, tempBforHeap, tempBforMer[n];

void bubble(){
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y<n - 1; y++)
		{
			if (B[y]>B[y + 1])
			{
				tempBforBub = B[y + 1];
				B[y + 1] = B[y];
				B[y] = tempBforBub;
			}
		}
	}
}

void selection(){
	for (int x = 0; x < n; x++)
	{
		int index_of_min = x;
		for (int y = x; y<n; y++)
		{
			if (S[index_of_min]>S[y])
			{
				index_of_min = y;
			}
		}
		tempBforSel = S[x];
		S[x] = S[index_of_min];
		S[index_of_min] = tempBforSel;
	}
}

void insertion(){
	int j;
	for (int i = 0; i < n; i++){
		j = i;
		while (j > 0 && I[j] < I[j - 1]){
			tempBforIns = I[j];
			I[j] = I[j - 1];
			I[j - 1] = tempBforIns;
			j--;
		}
	}
}

void max_heapify(int x[], int i, int num){
	int j;
	tempBforHea = x[i];
	j = 2 * i;
	while (j <= num)
	{
		if (j < num && x[j + 1] > x[j])
			j = j + 1;
		if (tempBforHea > x[j])
			break;
		else if (tempBforHea <= x[j])
		{
			x[j / 2] = x[j];
			j = 2 * j;
		}
	}
	x[j / 2] = tempBforHea;
	return;
}

void build_maxheap(int x[], int num){
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		max_heapify(x, i, num);
	}
}

void heapsort(int x[], int num){
	int i, tempBforHeap;
	for (i = num; i >= 2; i--)
	{
		tempBforHeap = x[i];
		x[i] = x[1];
		x[1] = tempBforHeap;
		max_heapify(x, 1, i - 1);
	}
}

int partition(int *arr, const int left, const int right){
	const int mid = left + (right - left) / 2;
	const int pivot = arr[mid];
	swap(arr[mid], arr[left]);
	int i = left + 1;
	int j = right;
	while (i <= j) {
		while (i <= j && arr[i] <= pivot) {
			i++;
		}
		while (i <= j && arr[j] > pivot) {
			j--;
		}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i - 1], arr[left]);
	return i - 1;
}

void quicksort(int *arr, const int left, const int right, const int sz){
	if (left >= right) {
		return;
	}
	int part = partition(arr, left, right);
	quicksort(arr, left, part - 1, sz);
	quicksort(arr, part + 1, right, sz);
}

void Merge(int a[], int low, int mid, int high){
	int i = low, j = mid + 1, k = low, s;

	while (i <= mid && j <= high){
		if (a[i] < a[j]){
			tempBforMer[k] = a[i];
			i++;
		}
		else{
			tempBforMer[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > mid){
		for (s = j; s <= high; s++){
			tempBforMer[k] = a[s];
			k++;
		}
	}
	else{
		for (s = i; s <= mid; s++){
			tempBforMer[k] = a[s];
			k++;
		}
	}
	for (k = low; k <= high; k++){
		a[k] = tempBforMer[k];
	}
}

void MergeSort(int a[], int low, int high){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}

void ran(){
	srand((unsigned)time(0));
	ofstream FS, FB, FI, FM, FQ, FH;

	FS.open("files/arrayS.txt", ios::trunc);
	FB.open("files/arrayB.txt", ios::trunc);
	FI.open("files/arrayI.txt", ios::trunc);
	FM.open("files/arrayM.txt", ios::trunc);
	FQ.open("files/arrayQ.txt", ios::trunc);
	FH.open("files/arrayH.txt", ios::trunc);
	for (int i = 0; i < n; i++){
		B[i] = (rand() % n) + 1;
		S[i] = B[i];
		I[i] = B[i];
		H[i] = B[i];
		M[i] = B[i];
		Q[i] = B[i];
		if (i % 10 != 0){
			FS << S[i] << " ";
			FB << B[i] << " ";
			FI << I[i] << " ";
			FM << M[i] << " ";
			FQ << Q[i] << " ";
			FH << H[i] << " ";
		}
		else{
			FI << I[i] << " " << endl;
			FS << S[i] << " " << endl;
			FB << B[i] << " " << endl;
			FM << M[i] << " " << endl;
			FQ << Q[i] << " " << endl;
			FH << H[i] << " " << endl;
		}
	}

	FS.close();
	FB.close();
	FI.close();
	FM.close();
	FQ.close();
	FH.close();

}

void sorted(){
	ofstream FS, FB, FI, FM, FQ, FH;

	FS.open("files/sortarrayS.txt", ios::trunc);
	FB.open("files/sortarrayB.txt", ios::trunc);
	FI.open("files/sortarrayI.txt", ios::trunc);
	FM.open("files/sortarrayM.txt", ios::trunc);
	FQ.open("files/sortarrayQ.txt", ios::trunc);
	FH.open("files/sortarrayH.txt", ios::trunc);
	for (int i = 0; i < n; i++){
		B[i] = i;
		S[i] = B[i];
		I[i] = B[i];
		H[i] = B[i];
		M[i] = B[i];
		Q[i] = B[i];
		if (i % 10 != 0){
			FS << S[i] << " ";
			FB << B[i] << " ";
			FI << I[i] << " ";
			FM << M[i] << " ";
			FQ << Q[i] << " ";
			FH << H[i] << " ";
		}
		else{
			FI << I[i] << " " << endl;
			FS << S[i] << " " << endl;
			FB << B[i] << " " << endl;
			FM << M[i] << " " << endl;
			FQ << Q[i] << " " << endl;
			FH << H[i] << " " << endl;
		}
	}

	FS.close();
	FB.close();
	FI.close();
	FM.close();
	FQ.close();
	FH.close();
}

void reversed(){
	ofstream FS, FB, FI, FM, FQ, FH;

	FS.open("files/revarrayS.txt", ios::trunc);
	FB.open("files/revarrayB.txt", ios::trunc);
	FI.open("files/revarrayI.txt", ios::trunc);
	FM.open("files/revarrayM.txt", ios::trunc);
	FQ.open("files/revarrayQ.txt", ios::trunc);
	FH.open("files/revarrayH.txt", ios::trunc);
	for (int i = 0; i < n; i++){
		B[i] = i;
	}
	sort(B, B + n, greater<int>());
	for (int i = 0; i < n; i++){
		S[i] = B[i];
		I[i] = B[i];
		H[i] = B[i];
		M[i] = B[i];
		Q[i] = B[i];

		if (i % 10 != 0){
			FS << S[i] << " ";
			FB << B[i] << " ";
			FI << I[i] << " ";
			FM << M[i] << " ";
			FQ << Q[i] << " ";
			FH << H[i] << " ";
		}
		else{
			FI << I[i] << " " << endl;
			FS << S[i] << " " << endl;
			FB << B[i] << " " << endl;
			FM << M[i] << " " << endl;
			FQ << Q[i] << " " << endl;
			FH << H[i] << " " << endl;
		}
	}

	FS.close();
	FB.close();
	FI.close();
	FM.close();
	FQ.close();
	FH.close();
}

int main(){
	int in, counter = 0;
startx:

	cout << "-----------------------------\n"
	"Please select the array type:\n"
	"1) Random\n"
	"2) Sorted\n"
	"3) Reversed\n"
	"0) Exit\n";

	cin >> in;

	if (in == 1){
		counter++;
		ran();
		cout << "processing" << endl;
	}
	else if (in == 2){
		counter++;
		sorted();
		cout << "processing" << endl;
	}
	else if (in == 3){
		counter++;
		reversed();
		cout << "processing" << endl;
	}
	else if (in == 0){
		return 0;
	}
	else goto startx;

	clock_t startbubble = clock();
	bubble();
	double durationbubble = (clock() - startbubble) / (double)CLOCKS_PER_SEC;
	cout << "Bubble: " << durationbubble << "           " << counter << '\n';

	clock_t startselection = clock();
	selection();
	double durationselection = (clock() - startselection) / (double)CLOCKS_PER_SEC;
	cout << "Selection: " << durationselection << '\n';

	clock_t startinsertion = clock();
	insertion();
	double durationinsertion = (clock() - startinsertion) / (double)CLOCKS_PER_SEC;
	if(durationinsertion > 0.0001)
		cout << "Insertion: " << durationinsertion << '\n';
	else
		cout << "Insertion: " << "Less than 0.0001" << '\n';

	clock_t startquick = clock();
	int sz = sizeof(Q) / sizeof(Q[0]);
	quicksort(Q, 0, sz - 1, sz);
	double durationquick = (clock() - startquick) / (double)CLOCKS_PER_SEC;
	cout << "Quick: " << durationquick << '\n';

	clock_t startheap = clock();
	build_maxheap(H, n);
	heapsort(H, n);
	double durationheap = (clock() - startheap) / (double)CLOCKS_PER_SEC;
	cout << "Heap: " << durationheap << '\n';

	clock_t startmerge = clock();
	MergeSort(M, 1, n);
	double durationmerge = (clock() - startmerge) / (double)CLOCKS_PER_SEC;
	cout << "Merge: " << durationmerge << "\n";

	goto startx;
	return 0;

}
