#include <iostream>
#include <vector>
#include <string>



using namespace std;

void convert_Dec_to_Bin(int INTinputVal, vector<int> &bin_value) {
    // convert elements from dec to bin
    int a[20], i;
    
    for (i = 0; INTinputVal > 0; i++)
    {
        a[i] = INTinputVal % 2;  // Step 1: Divide the number by 2 through % (modulus operator) and store the remainder in array
        INTinputVal = INTinputVal / 2; // Step 2: Divide the number by 2 through / (division operator)
    }

    for (i = i - 1; i >= 0; i--)
    {
        bin_value.push_back(a[i]);
    }
}


int Solve(int N) {

    int element = 0;
    vector<int> elements;
    vector<int> binary_values = {};

    unsigned long long result = 0;


    // for elements 1 - N
    for (int i = 1; i <= N; i++) {
        element = element + 1;
        //std::cout << "element = " << element << "\n";
        elements.push_back(element);
    }

    int intgr = 0;
    while (intgr < elements.size()) {

        //cout << "elements[intgr] = " << elements[intgr] << "\n";

        convert_Dec_to_Bin(elements[intgr], binary_values);
        string bit_string = "";

        for (int ii = 0; ii < binary_values.size(); ii++) {
            bit_string = bit_string + to_string(binary_values[ii]);
        }

        binary_values.clear();
        int bits = stoi(bit_string);
        result = result + bits;
        intgr++;
    }

    //std::cout << result << "\n";
    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    //T = 2;
    for (int t_i = 0; t_i < T; t_i++) {
        int N;
        cin >> N;
        //N = 3;
        int out = Solve(N);
        cout << out << "\n";
    }
}
    



/*
#include<stdbool.h>
#include<malloc.h>



char* Solve (int N) {
    int a[20];

    int sum = 0;

    for (int i = 1; i < N; i++)
        if (N % i == 0){
            a[i] = i;
            sum = sum + i;
        }

        //for( int j = 0; j<= 20 ; j++){
        //    sum = sum + a[j];
        //}

        //printf("sum %i\n", sum );

        if (sum == N){
            return "YES";
        }else{
            return "NO";
        }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t_i=0; t_i<T; t_i++) {
        int N;
        scanf("%d", &N);
        char* out_ = Solve(N);
        printf("%s\n", out_);
    }
}

*/

