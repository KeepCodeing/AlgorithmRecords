#include <iostream>
using namespace std;
int main() {
	// 在Stack里创建数组 
	int arr1[3];
	
	// 动态在Stack里创建数组，在旧编译器中会报错
	// 使用这种方法创建数组无法对其进行初始化，
	// 主要是防止数组的越界 
	int n;
	cin >> n;
	int arr2[n];
	
	// 在heap中创建数组，使用这种方法创建的数组
	// 在使用完后要将其删除（C语言中new相当于malloc) 
	int *arr3 = new int[n];
	delete[] arr3; 
	
	// 在heap中创建二维数组（C:int **arr = (int**)malloc(n * sizeof(int*)) 
	int **arr4 = new int*[n];
	for (int i = 0; i < n; i++) arr4[i] = new int[n];
	return 0;
}
