#include<iostream>  
using namespace std;
int main(){
    int a[25];
    int n;
    int count = 0;

    cout << "Enter the length of array:" << endl;
    cin >> n;
    while (n > 20) {
        cout << "Error: the length should be less than 20." << endl;
        cout << "Enter the length of array again:" << endl;
        cin >> n;
    }
    cout<<"please input "<< n << " integers:"<<endl;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for (int l = 0; l < n / 2; l++) {
        int temp = a[l];
        a[l] = a[n-l-1];
        a[n -l -1] = temp;
        count ++;
    }
    cout<<"Reverse:"<<endl;

    for(int i = 0;i < n;i++) {
        cout << a[i] << " ";
    }

    cout<<endl;
    cout << "The time complexity is:" << count;

    return 0;
} 